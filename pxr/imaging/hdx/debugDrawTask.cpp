//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hdx/debugDrawTask.h"

#include "pxr/imaging/hdx/package.h"

#include "pxr/imaging/hd/perfLog.h"
#include "pxr/imaging/hd/tokens.h"

#include "pxr/imaging/hdSt/renderPassState.h"

#include "pxr/imaging/hf/perfLog.h"

#include "pxr/imaging/hio/glslfx.h"

#include "pxr/imaging/hgi/blitCmdsOps.h"
#include "pxr/imaging/hgi/capabilities.h"
#include "pxr/imaging/hgi/graphicsCmdsDesc.h"
#include "pxr/imaging/hgi/hgi.h"
#include "pxr/imaging/hgi/tokens.h"

#include "pxr/base/gf/transform.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PRIVATE_TOKENS(_tokens,
                         ((debugDrawVertex, "DebugDrawVertex"))((debugDrawFragment,
                                                                 "DebugDrawFragment"))(debugDrawShader));

namespace {

// Constants struct that has a layout matching what is expected by the GPU.
// This includes constant data for both vertex and fragment stages.
struct _ShaderConstants {
    GfVec4f viewport;
    GfMatrix4d vp;
};

}  // namespace

HdxDebugDrawTask::HdxDebugDrawTask(HdSceneDelegate* delegate, const SdfPath& id)
    : HdxTask(id),
      _vertexBuffer(),
      _maxTransforms(2),
      _transformsBuffer(),
      _shaderProgram(),
      _resourceBindings(),
      _pipeline(),
      _params() {}

HdxDebugDrawTask::~HdxDebugDrawTask() {
    if (_vertexBuffer) {
        _GetHgi()->DestroyBuffer(&_vertexBuffer);
    }

    if (_transformsBuffer) {
        _GetHgi()->DestroyBuffer(&_transformsBuffer);
    }

    if (_shaderProgram) {
        _DestroyShaderProgram();
    }

    if (_resourceBindings) {
        _GetHgi()->DestroyResourceBindings(&_resourceBindings);
    }

    if (_pipeline) {
        _GetHgi()->DestroyGraphicsPipeline(&_pipeline);
    }
}

bool HdxDebugDrawTask::_CreateShaderResources() {
    if (_shaderProgram) {
        return true;
    }

    const HioGlslfx glslfx(HdxPackageBoundingBoxShader(), HioGlslfxTokens->defVal);

    // Using a constant buffer that contains data for both vertex and
    // fragment stages for simplicity.
    auto addConstantParams = [](HgiShaderFunctionDesc* stageDesc) {
        HgiShaderFunctionAddConstantParam(stageDesc, "color", "vec4");
        HgiShaderFunctionAddConstantParam(stageDesc, "viewport", "vec4");
        HgiShaderFunctionAddConstantParam(stageDesc, "dashSize", "float");
    };

    // Setup the vertex shader
    std::string vsCode;
    HgiShaderFunctionDesc vertDesc;
    vertDesc.debugName = _tokens->debugDrawVertex.GetString();
    vertDesc.shaderStage = HgiShaderStageVertex;
    HgiShaderFunctionAddStageInput(&vertDesc, "position", "vec3");
    HgiShaderFunctionAddStageInput(&vertDesc, "hd_InstanceID", "uint", HgiShaderKeywordTokens->hdInstanceID);
    HgiShaderFunctionAddStageOutput(&vertDesc, "gl_Position", "vec4", "position");
    HgiShaderFunctionParamDesc dashStartParam;
    dashStartParam.nameInShader = "dashStart";
    dashStartParam.type = "vec2";
    dashStartParam.interpolation = HgiInterpolationFlat;
    HgiShaderFunctionAddStageOutput(&vertDesc, dashStartParam);
    addConstantParams(&vertDesc);
    HgiShaderFunctionAddBuffer(&vertDesc, "worldViewProj", "mat4", 1, HgiBindingTypeUniformArray,
                               static_cast<uint32_t>(_maxTransforms));
    vsCode += glslfx.GetSource(_tokens->debugDrawVertex);
    vertDesc.shaderCode = vsCode.c_str();
    HgiShaderFunctionHandle vertFn = _GetHgi()->CreateShaderFunction(vertDesc);

    // Setup the fragment shader
    std::string fsCode;
    HgiShaderFunctionDesc fragDesc;
    HgiShaderFunctionAddStageInput(&fragDesc, "gl_FragCoord", "vec4", HgiShaderKeywordTokens->hdFragCoord);
    HgiShaderFunctionAddStageInput(&fragDesc, dashStartParam);
    HgiShaderFunctionAddStageOutput(&fragDesc, "hd_FragColor", "vec4", "color");
    addConstantParams(&fragDesc);
    fragDesc.debugName = _tokens->debugDrawFragment.GetString();
    fragDesc.shaderStage = HgiShaderStageFragment;
    fsCode += glslfx.GetSource(_tokens->debugDrawFragment);

    fragDesc.shaderCode = fsCode.c_str();
    HgiShaderFunctionHandle fragFn = _GetHgi()->CreateShaderFunction(fragDesc);

    // Setup the shader program
    HgiShaderProgramDesc programDesc;
    programDesc.debugName = _tokens->debugDrawShader.GetString();
    programDesc.shaderFunctions.push_back(std::move(vertFn));
    programDesc.shaderFunctions.push_back(std::move(fragFn));
    _shaderProgram = _GetHgi()->CreateShaderProgram(programDesc);

    if (!_shaderProgram->IsValid() || !vertFn->IsValid() || !fragFn->IsValid()) {
        TF_CODING_ERROR("Failed to create bounding box shader");
        _PrintCompileErrors();
        _DestroyShaderProgram();
        return false;
    }

    return true;
}

bool HdxDebugDrawTask::_CreateBufferResources() {
    if (_vertexBuffer && _transformsBuffer) {
        // Must re-create any objects that depend on the transform buffer size
        // directly and any objects that depend on those re-created objects.
        _GetHgi()->DestroyGraphicsPipeline(&_pipeline);
        _DestroyShaderProgram();
        _GetHgi()->DestroyResourceBindings(&_resourceBindings);
        _GetHgi()->DestroyBuffer(&_transformsBuffer);
    }

    if (!_vertexBuffer) {
        // 12 edges of a cube with sides of length 2, centered at the origin
        constexpr float vertData[24][3] = {
                {-1, -1, -1}, {-1, -1, +1}, {-1, +1, -1}, {-1, +1, +1},
                {+1, -1, -1}, {+1, -1, +1}, {+1, +1, -1}, {+1, +1, +1},

                {-1, -1, -1}, {-1, +1, -1}, {+1, -1, -1}, {+1, +1, -1},
                {-1, -1, +1}, {-1, +1, +1}, {+1, -1, +1}, {+1, +1, +1},

                {-1, -1, -1}, {+1, -1, -1}, {-1, +1, -1}, {+1, +1, -1},
                {-1, -1, +1}, {+1, -1, +1}, {-1, +1, +1}, {+1, +1, +1},
        };

        HgiBufferDesc vboDesc;
        vboDesc.debugName = "HdxBoundingBoxTask VertexBuffer";
        vboDesc.usage = HgiBufferUsageVertex;
        vboDesc.initialData = vertData;
        vboDesc.byteSize = sizeof(vertData);
        vboDesc.vertexStride = sizeof(vertData[0]);
        _vertexBuffer = _GetHgi()->CreateBuffer(vboDesc);
    }

    HgiBufferDesc transformsDesc;
    transformsDesc.debugName = "HdxBoundingBoxTask TransformsBuffer";
    transformsDesc.usage = HgiBufferUsageUniform;
    transformsDesc.byteSize = 16 * sizeof(float) * _maxTransforms;
    _transformsBuffer = _GetHgi()->CreateBuffer(transformsDesc);

    return true;
}

bool HdxDebugDrawTask::_CreateResourceBindings() {
    if (_resourceBindings) {
        return true;
    }

    HgiResourceBindingsDesc resourceDesc;
    resourceDesc.debugName = "BoundingBox";

    // Transform array used only in the vertex shader.
    // Note this binds at index 1 since shader constants are also used, which
    // will bind at index 0 on some backends.
    HgiBufferBindDesc bufBind1;
    bufBind1.bindingIndex = 1;
    bufBind1.resourceType = HgiBindResourceTypeUniformBuffer;
    bufBind1.stageUsage = HgiShaderStageVertex;
    bufBind1.offsets.push_back(0);
    bufBind1.sizes.push_back(0);
    bufBind1.buffers.push_back(_transformsBuffer);
    bufBind1.writable = false;
    resourceDesc.buffers.push_back(std::move(bufBind1));

    _resourceBindings = _GetHgi()->CreateResourceBindings(resourceDesc);

    return true;
}

static bool _MatchesFormatAndSampleCount(const HgiTextureHandle& texture,
                                         const HgiFormat format,
                                         const HgiSampleCount sampleCount) {
    if (texture) {
        const HgiTextureDesc& desc = texture->GetDescriptor();
        return format == desc.format && sampleCount == desc.sampleCount;
    }
    return false;
}

bool HdxDebugDrawTask::_CreatePipeline(const HgiTextureHandle& colorTexture, const HgiTextureHandle& depthTexture) {
    if (_pipeline) {
        const HgiSampleCount sampleCount = _pipeline->GetDescriptor().multiSampleState.sampleCount;

        if (_MatchesFormatAndSampleCount(colorTexture, _colorAttachment.format, sampleCount) &&
            _MatchesFormatAndSampleCount(depthTexture, _depthAttachment.format, sampleCount)) {
            return true;
        }

        _GetHgi()->DestroyGraphicsPipeline(&_pipeline);
    }

    HgiGraphicsPipelineDesc desc;
    desc.debugName = "BoundingBox Pipeline";
    desc.primitiveType = HgiPrimitiveTypeLineList;
    desc.shaderProgram = _shaderProgram;

    // Describe the vertex buffer
    HgiVertexAttributeDesc posAttr;
    posAttr.format = HgiFormatFloat32Vec3;
    posAttr.offset = 0;
    posAttr.shaderBindLocation = 0;

    HgiVertexBufferDesc vboDesc;
    vboDesc.bindingIndex = 0;
    vboDesc.vertexStride = 3 * sizeof(float);  // pos
    vboDesc.vertexAttributes.push_back(posAttr);

    desc.vertexBuffers.push_back(std::move(vboDesc));

    // The MSAA on renderPipelineState has to match the render target.
    const HgiSampleCount sampleCount = colorTexture->GetDescriptor().sampleCount;
    desc.multiSampleState.multiSampleEnable = sampleCount != HgiSampleCount1;
    desc.multiSampleState.sampleCount = sampleCount;

    // Setup color attachment descriptor
    _colorAttachment.format = colorTexture->GetDescriptor().format;
    _colorAttachment.usage = colorTexture->GetDescriptor().usage;
    desc.colorAttachmentDescs.push_back(_colorAttachment);

    // Setup depth attachment descriptor
    _depthAttachment.format = depthTexture->GetDescriptor().format;
    _depthAttachment.usage = depthTexture->GetDescriptor().usage;
    desc.depthAttachmentDesc = _depthAttachment;

    // Shared constants used in both vertex and fragment stages.
    desc.shaderConstantsDesc.stageUsage = HgiShaderStageVertex | HgiShaderStageFragment;
    desc.shaderConstantsDesc.byteSize = sizeof(_ShaderConstants);

    _pipeline = _GetHgi()->CreateGraphicsPipeline(desc);

    return true;
}

GfMatrix4d HdxDebugDrawTask::_ComputeViewProjectionMatrix(const HdStRenderPassState& hdStRenderPassState) const {
    // Get the view and projection matrices.
    const GfMatrix4d view = hdStRenderPassState.GetWorldToViewMatrix();
    GfMatrix4d projection = hdStRenderPassState.GetProjectionMatrix();

    const HgiCapabilities* capabilities = _GetHgi()->GetCapabilities();
    if (!capabilities->IsSet(HgiDeviceCapabilitiesBitsDepthRangeMinusOnetoOne)) {
        // Different backends use different clip space depth ranges. The
        // codebase generally assumes an OpenGL-style depth of [-1, 1] when
        // computing projection matrices, so we must add an additional
        // conversion when the Hgi backend expects a [0, 1] depth range.
        GfMatrix4d depthAdjustmentMat(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 1.0);
        projection = projection * depthAdjustmentMat;
    }

    return view * projection;
}

void HdxDebugDrawTask::_UpdateShaderConstants(HgiGraphicsCmds* gfxCmds,
                                              const GfVec4i& gfxViewport,
                                              const HdStRenderPassState& hdStRenderPassState) {
    // View-Projection matrix is the same for either bbox
    const GfMatrix4d viewProj = _ComputeViewProjectionMatrix(hdStRenderPassState);

    // Update and upload the other constant data.
    const GfVec4f viewport(gfxViewport);
    const _ShaderConstants constants = {viewport, viewProj};
    gfxCmds->SetConstantValues(_pipeline, HgiShaderStageVertex | HgiShaderStageFragment, 0, sizeof(_ShaderConstants),
                               &constants);
}

void HdxDebugDrawTask::_DrawBBoxes(const HgiTextureHandle& colorTexture,
                                   const HgiTextureHandle& depthTexture,
                                   const HdStRenderPassState& hdStRenderPassState) {
    // Prepare graphics cmds.
    HgiGraphicsCmdsDesc gfxDesc;
    gfxDesc.colorAttachmentDescs.push_back(_colorAttachment);
    gfxDesc.colorTextures.push_back(colorTexture);
    gfxDesc.depthAttachmentDesc = _depthAttachment;
    gfxDesc.depthTexture = depthTexture;

    // Begin rendering
    HgiGraphicsCmdsUniquePtr gfxCmds = _GetHgi()->CreateGraphicsCmds(gfxDesc);
    gfxCmds->PushDebugGroup("BoundingBox");
    gfxCmds->BindPipeline(_pipeline);
    gfxCmds->BindVertexBuffers({{_vertexBuffer, 0, 0}});

    const GfVec4i viewport = hdStRenderPassState.ComputeViewport();
    gfxCmds->SetViewport(viewport);

    _UpdateShaderConstants(gfxCmds.get(), viewport, hdStRenderPassState);
    gfxCmds->BindResources(_resourceBindings);

    gfxCmds->Draw(24, 0, 0, 0);

    gfxCmds->PopDebugGroup();

    // Done recording commands, submit work.
    _GetHgi()->SubmitCmds(gfxCmds.get());
}

void HdxDebugDrawTask::_Sync(HdSceneDelegate* delegate, HdTaskContext* ctx, HdDirtyBits* dirtyBits) {
    HD_TRACE_FUNCTION();
    HF_MALLOC_TAG_FUNCTION();

    if ((*dirtyBits) & HdChangeTracker::DirtyParams) {
        _GetTaskParams(delegate, &_params);
    }

    *dirtyBits = HdChangeTracker::Clean;
}

void HdxDebugDrawTask::Prepare(HdTaskContext* ctx, HdRenderIndex* renderIndex) {}

void HdxDebugDrawTask::Execute(HdTaskContext* ctx) {
    HD_TRACE_FUNCTION();
    HF_MALLOC_TAG_FUNCTION();

    // Only draw the bounding boxes when rendering to the color aov
    if (_params.aovName != HdAovTokens->color) {
        return;
    }

    // We want to render the bounding boxes into the color aov
    // and have them respect the depth aov.
    if (!_HasTaskContextData(ctx, HdAovTokens->color) || !_HasTaskContextData(ctx, HdAovTokens->depth)) {
        return;
    }

    HgiTextureHandle colorTexture, depthTexture;
    _GetTaskContextData(ctx, HdAovTokens->color, &colorTexture);
    _GetTaskContextData(ctx, HdAovTokens->depth, &depthTexture);

    if (!TF_VERIFY(_CreateBufferResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateShaderResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateResourceBindings())) {
        return;
    }
    if (!TF_VERIFY(_CreatePipeline(colorTexture, depthTexture))) {
        return;
    }

    HdRenderPassStateSharedPtr renderPassState;
    _GetTaskContextData(ctx, HdxTokens->renderPassState, &renderPassState);
    HdStRenderPassState* const hdStRenderPassState = dynamic_cast<HdStRenderPassState*>(renderPassState.get());
    if (!hdStRenderPassState) {
        return;
    }

    _DrawBBoxes(colorTexture, depthTexture, *hdStRenderPassState);
}

void HdxDebugDrawTask::_DestroyShaderProgram() {
    if (!_shaderProgram) return;

    for (HgiShaderFunctionHandle fn : _shaderProgram->GetShaderFunctions()) {
        _GetHgi()->DestroyShaderFunction(&fn);
    }
    _GetHgi()->DestroyShaderProgram(&_shaderProgram);
}

void HdxDebugDrawTask::_PrintCompileErrors() {
    if (!_shaderProgram) return;

    for (HgiShaderFunctionHandle fn : _shaderProgram->GetShaderFunctions()) {
        std::cout << fn->GetCompileErrors() << std::endl;
    }
    std::cout << _shaderProgram->GetCompileErrors() << std::endl;
}

// -------------------------------------------------------------------------- //
// VtValue Requirements
// -------------------------------------------------------------------------- //

std::ostream& operator<<(std::ostream& out, const HdxDebugDrawTaskParams& pv) {
    out << "BoundingBoxTask Params: (...) { ";
    out << "Point Count" << pv.points.size() << ", ";
    out << "Line Count" << pv.lines.size() << ", ";
    out << "Triangle Count" << pv.triangles.size() << ", ";
    out << " }";
    return out;
}

bool operator==(const HdxDebugDrawTaskParams& lhs, const HdxDebugDrawTaskParams& rhs) {
    return lhs.aovName == rhs.aovName && lhs.points.size() == rhs.points.size() && lhs.lines.size() == rhs.lines.size() &&
           lhs.triangles.size() == rhs.triangles.size();
}

bool operator!=(const HdxDebugDrawTaskParams& lhs, const HdxDebugDrawTaskParams& rhs) { return !(lhs == rhs); }

PXR_NAMESPACE_CLOSE_SCOPE

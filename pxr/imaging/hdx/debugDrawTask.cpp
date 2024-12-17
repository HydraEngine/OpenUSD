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

HdxDebugDrawTask::HdxDebugDrawTask(HdSceneDelegate* delegate, const SdfPath& id) : HdxTask(id), _params() {}

HdxDebugDrawTask::~HdxDebugDrawTask() {
    if (_pointResource.vertexBuffer) {
        _GetHgi()->DestroyBuffer(&_pointResource.vertexBuffer);
    }
    if (_lineResource.vertexBuffer) {
        _GetHgi()->DestroyBuffer(&_lineResource.vertexBuffer);
    }
    if (_triangleResource.vertexBuffer) {
        _GetHgi()->DestroyBuffer(&_triangleResource.vertexBuffer);
    }

    if (_pointResource.shaderProgram) {
        _DestroyShaderProgram(_pointResource.shaderProgram);
    }
    if (_lineResource.shaderProgram) {
        _DestroyShaderProgram(_lineResource.shaderProgram);
    }
    if (_triangleResource.shaderProgram) {
        _DestroyShaderProgram(_triangleResource.shaderProgram);
    }

    if (_pointResource.pipeline) {
        _GetHgi()->DestroyGraphicsPipeline(&_pointResource.pipeline);
    }
    if (_lineResource.pipeline) {
        _GetHgi()->DestroyGraphicsPipeline(&_lineResource.pipeline);
    }
    if (_triangleResource.pipeline) {
        _GetHgi()->DestroyGraphicsPipeline(&_triangleResource.pipeline);
    }
}

bool HdxDebugDrawTask::_CreatePointShaderResources() {
    if (_pointResource.shaderProgram) {
        return true;
    }

    const HioGlslfx glslfx(HdxPackageBoundingBoxShader(), HioGlslfxTokens->defVal);

    // Using a constant buffer that contains data for both vertex and
    // fragment stages for simplicity.
    auto addConstantParams = [](HgiShaderFunctionDesc* stageDesc) {
        HgiShaderFunctionAddConstantParam(stageDesc, "viewport", "vec4");
        HgiShaderFunctionAddConstantParam(stageDesc, "vp", "mat4");
    };

    // Setup the vertex shader
    std::string vsCode;
    HgiShaderFunctionDesc vertDesc;
    vertDesc.debugName = _tokens->debugDrawVertex.GetString();
    vertDesc.shaderStage = HgiShaderStageVertex;
    HgiShaderFunctionAddStageInput(&vertDesc, "position", "vec3");
    HgiShaderFunctionAddStageInput(&vertDesc, "color", "uint");
    HgiShaderFunctionAddStageOutput(&vertDesc, "gl_Position", "vec4", "position");
    HgiShaderFunctionParamDesc colorParam;
    colorParam.nameInShader = "colorOut";
    colorParam.type = "float";
    colorParam.interpolation = HgiInterpolationFlat;
    HgiShaderFunctionAddStageOutput(&vertDesc, colorParam);
    addConstantParams(&vertDesc);
    vsCode += glslfx.GetSource(_tokens->debugDrawVertex);
    vertDesc.shaderCode = vsCode.c_str();
    HgiShaderFunctionHandle vertFn = _GetHgi()->CreateShaderFunction(vertDesc);

    // Setup the fragment shader
    std::string fsCode;
    HgiShaderFunctionDesc fragDesc;
    HgiShaderFunctionAddStageInput(&fragDesc, "gl_FragCoord", "vec4", HgiShaderKeywordTokens->hdFragCoord);
    HgiShaderFunctionAddStageInput(&fragDesc, colorParam);
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
    programDesc.shaderFunctions.push_back(vertFn);
    programDesc.shaderFunctions.push_back(fragFn);
    _pointResource.shaderProgram = _GetHgi()->CreateShaderProgram(programDesc);

    if (!_pointResource.shaderProgram->IsValid() || !vertFn->IsValid() || !fragFn->IsValid()) {
        TF_CODING_ERROR("Failed to create point debug draw shader");
        _PrintCompileErrors(_pointResource.shaderProgram);
        _DestroyShaderProgram(_pointResource.shaderProgram);
        return false;
    }

    return true;
}

bool HdxDebugDrawTask::_CreateLineShaderResources() {
    // todo
    return true;
}

bool HdxDebugDrawTask::_CreateTriangleShaderResources() {
    // todo
    return true;
}

bool HdxDebugDrawTask::_CreatePointBufferResources() {
    if (_pointResource.vertexBuffer) {
        if (_params.points.size() < _pointResource.maxTransforms) {
            return true;
        }
        // Must re-create any objects that depend on the transform buffer size
        // directly and any objects that depend on those re-created objects.
        _GetHgi()->DestroyGraphicsPipeline(&_pointResource.pipeline);
        _DestroyShaderProgram(_pointResource.shaderProgram);
        _GetHgi()->DestroyBuffer(&_pointResource.vertexBuffer);
    }

    _pointResource.maxTransforms = _params.points.size();

    HgiBufferDesc transformsDesc;
    transformsDesc.debugName = "HdxDebugDrawTask Point VertexBuffer";
    transformsDesc.usage = HgiBufferUsageVertex;
    transformsDesc.byteSize = 4 * sizeof(float) * _pointResource.maxTransforms;
    _pointResource.vertexBuffer = _GetHgi()->CreateBuffer(transformsDesc);

    return true;
}

bool HdxDebugDrawTask::_CreateLineBufferResources() {
    if (_lineResource.vertexBuffer) {
        if (_params.points.size() < _lineResource.maxTransforms) {
            return true;
        }
        // Must re-create any objects that depend on the transform buffer size
        // directly and any objects that depend on those re-created objects.
        _GetHgi()->DestroyGraphicsPipeline(&_lineResource.pipeline);
        _DestroyShaderProgram(_lineResource.shaderProgram);
        _GetHgi()->DestroyBuffer(&_lineResource.vertexBuffer);
    }

    _lineResource.maxTransforms = _params.points.size();

    HgiBufferDesc transformsDesc;
    transformsDesc.debugName = "HdxDebugDrawTask Line VertexBuffer";
    transformsDesc.usage = HgiBufferUsageVertex;
    transformsDesc.byteSize = 8 * sizeof(float) * _lineResource.maxTransforms;
    _lineResource.vertexBuffer = _GetHgi()->CreateBuffer(transformsDesc);

    return true;
}

bool HdxDebugDrawTask::_CreateTriangleBufferResources() {
    if (_triangleResource.vertexBuffer) {
        if (_params.points.size() < _triangleResource.maxTransforms) {
            return true;
        }
        // Must re-create any objects that depend on the transform buffer size
        // directly and any objects that depend on those re-created objects.
        _GetHgi()->DestroyGraphicsPipeline(&_triangleResource.pipeline);
        _DestroyShaderProgram(_triangleResource.shaderProgram);
        _GetHgi()->DestroyBuffer(&_triangleResource.vertexBuffer);
    }

    _triangleResource.maxTransforms = _params.points.size();

    HgiBufferDesc transformsDesc;
    transformsDesc.debugName = "HdxDebugDrawTask Triangle VertexBuffer";
    transformsDesc.usage = HgiBufferUsageVertex;
    transformsDesc.byteSize = 12 * sizeof(float) * _triangleResource.maxTransforms;
    _triangleResource.vertexBuffer = _GetHgi()->CreateBuffer(transformsDesc);

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

bool HdxDebugDrawTask::_CreatePointPipeline(const HgiTextureHandle& colorTexture,
                                            const HgiTextureHandle& depthTexture) {
    if (_pointResource.pipeline) {
        const HgiSampleCount sampleCount = _pointResource.pipeline->GetDescriptor().multiSampleState.sampleCount;

        if (_MatchesFormatAndSampleCount(colorTexture, _colorAttachment.format, sampleCount) &&
            _MatchesFormatAndSampleCount(depthTexture, _depthAttachment.format, sampleCount)) {
            return true;
        }

        _GetHgi()->DestroyGraphicsPipeline(&_pointResource.pipeline);
    }

    HgiGraphicsPipelineDesc desc;
    desc.debugName = "DebugDraw Point Pipeline";
    desc.primitiveType = HgiPrimitiveTypePointList;
    desc.shaderProgram = _pointResource.shaderProgram;

    // Describe the vertex buffer
    HgiVertexAttributeDesc posAttr;
    posAttr.format = HgiFormatFloat32Vec3;
    posAttr.offset = 0;
    posAttr.shaderBindLocation = 0;

    HgiVertexAttributeDesc colorAttr;
    posAttr.format = HgiFormatFloat32;
    posAttr.offset = 3 * sizeof(float);
    posAttr.shaderBindLocation = 1;

    HgiVertexBufferDesc vboDesc;
    vboDesc.bindingIndex = 0;
    vboDesc.vertexStride = 4 * sizeof(float);  // pos, color
    vboDesc.vertexAttributes.push_back(posAttr);
    vboDesc.vertexAttributes.push_back(colorAttr);

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

    _pointResource.pipeline = _GetHgi()->CreateGraphicsPipeline(desc);

    return true;
}

bool HdxDebugDrawTask::_CreateLinePipeline(const HgiTextureHandle& colorTexture, const HgiTextureHandle& depthTexture) {
    if (_lineResource.pipeline) {
        const HgiSampleCount sampleCount = _lineResource.pipeline->GetDescriptor().multiSampleState.sampleCount;

        if (_MatchesFormatAndSampleCount(colorTexture, _colorAttachment.format, sampleCount) &&
            _MatchesFormatAndSampleCount(depthTexture, _depthAttachment.format, sampleCount)) {
            return true;
        }

        _GetHgi()->DestroyGraphicsPipeline(&_lineResource.pipeline);
    }

    HgiGraphicsPipelineDesc desc;
    desc.debugName = "DebugDraw Line Pipeline";
    desc.primitiveType = HgiPrimitiveTypeLineList;
    desc.shaderProgram = _lineResource.shaderProgram;

    // Describe the vertex buffer
    HgiVertexAttributeDesc posAttr;
    posAttr.format = HgiFormatFloat32Vec3;
    posAttr.offset = 0;
    posAttr.shaderBindLocation = 0;

    HgiVertexAttributeDesc colorAttr;
    posAttr.format = HgiFormatFloat32;
    posAttr.offset = 3 * sizeof(float);
    posAttr.shaderBindLocation = 1;

    HgiVertexBufferDesc vboDesc;
    vboDesc.bindingIndex = 0;
    vboDesc.vertexStride = 4 * sizeof(float);  // pos, color
    vboDesc.vertexAttributes.push_back(posAttr);
    vboDesc.vertexAttributes.push_back(colorAttr);

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

    _lineResource.pipeline = _GetHgi()->CreateGraphicsPipeline(desc);

    return true;
}

bool HdxDebugDrawTask::_CreateTrianglePipeline(const HgiTextureHandle& colorTexture,
                                               const HgiTextureHandle& depthTexture) {
    if (_triangleResource.pipeline) {
        const HgiSampleCount sampleCount = _triangleResource.pipeline->GetDescriptor().multiSampleState.sampleCount;

        if (_MatchesFormatAndSampleCount(colorTexture, _colorAttachment.format, sampleCount) &&
            _MatchesFormatAndSampleCount(depthTexture, _depthAttachment.format, sampleCount)) {
            return true;
        }

        _GetHgi()->DestroyGraphicsPipeline(&_triangleResource.pipeline);
    }

    HgiGraphicsPipelineDesc desc;
    desc.debugName = "DebugDraw Triangle Pipeline";
    desc.primitiveType = HgiPrimitiveTypeTriangleList;
    desc.shaderProgram = _triangleResource.shaderProgram;

    // Describe the vertex buffer
    HgiVertexAttributeDesc posAttr;
    posAttr.format = HgiFormatFloat32Vec3;
    posAttr.offset = 0;
    posAttr.shaderBindLocation = 0;

    HgiVertexAttributeDesc colorAttr;
    posAttr.format = HgiFormatFloat32;
    posAttr.offset = 3 * sizeof(float);
    posAttr.shaderBindLocation = 1;

    HgiVertexBufferDesc vboDesc;
    vboDesc.bindingIndex = 0;
    vboDesc.vertexStride = 4 * sizeof(float);  // pos, color
    vboDesc.vertexAttributes.push_back(posAttr);
    vboDesc.vertexAttributes.push_back(colorAttr);

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

    _triangleResource.pipeline = _GetHgi()->CreateGraphicsPipeline(desc);

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
                                              HgiGraphicsPipelineHandle pipeline,
                                              const HdStRenderPassState& hdStRenderPassState) {
    // View-Projection matrix is the same for either bbox
    const GfMatrix4d viewProj = _ComputeViewProjectionMatrix(hdStRenderPassState);

    // Update and upload the other constant data.
    const GfVec4f viewport(gfxViewport);
    const _ShaderConstants constants = {viewport, viewProj};
    gfxCmds->SetConstantValues(pipeline, HgiShaderStageVertex | HgiShaderStageFragment, 0, sizeof(_ShaderConstants),
                               &constants);
}

void HdxDebugDrawTask::_DrawPoints(const HgiTextureHandle& colorTexture,
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
    gfxCmds->PushDebugGroup("Debug Point");
    gfxCmds->BindPipeline(_pointResource.pipeline);
    gfxCmds->BindVertexBuffers({{_pointResource.vertexBuffer, 0, 0}});

    const GfVec4i viewport = hdStRenderPassState.ComputeViewport();
    gfxCmds->SetViewport(viewport);

    _UpdateShaderConstants(gfxCmds.get(), viewport, _pointResource.pipeline, hdStRenderPassState);

    gfxCmds->Draw(24, 0, 0, 0);

    gfxCmds->PopDebugGroup();

    // Done recording commands, submit work.
    _GetHgi()->SubmitCmds(gfxCmds.get());
}

void HdxDebugDrawTask::_DrawLines(const HgiTextureHandle& colorTexture,
                                  const HgiTextureHandle& depthTexture,
                                  const HdStRenderPassState& hdStRenderPassState) {}

void HdxDebugDrawTask::_DrawTriangles(const HgiTextureHandle& colorTexture,
                                      const HgiTextureHandle& depthTexture,
                                      const HdStRenderPassState& hdStRenderPassState) {}

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

    if (!TF_VERIFY(_CreatePointBufferResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateLineBufferResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateTriangleBufferResources())) {
        return;
    }
    if (!TF_VERIFY(_CreatePointShaderResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateLineShaderResources())) {
        return;
    }
    if (!TF_VERIFY(_CreateTriangleShaderResources())) {
        return;
    }
    if (!TF_VERIFY(_CreatePointPipeline(colorTexture, depthTexture))) {
        return;
    }
    if (!TF_VERIFY(_CreateLinePipeline(colorTexture, depthTexture))) {
        return;
    }
    if (!TF_VERIFY(_CreateTrianglePipeline(colorTexture, depthTexture))) {
        return;
    }

    HdRenderPassStateSharedPtr renderPassState;
    _GetTaskContextData(ctx, HdxTokens->renderPassState, &renderPassState);
    auto* const hdStRenderPassState = dynamic_cast<HdStRenderPassState*>(renderPassState.get());
    if (!hdStRenderPassState) {
        return;
    }

    _DrawPoints(colorTexture, depthTexture, *hdStRenderPassState);
    _DrawLines(colorTexture, depthTexture, *hdStRenderPassState);
    _DrawTriangles(colorTexture, depthTexture, *hdStRenderPassState);
}

void HdxDebugDrawTask::_DestroyShaderProgram(HgiShaderProgramHandle shaderProgram) {
    if (!shaderProgram) return;

    for (HgiShaderFunctionHandle fn : shaderProgram->GetShaderFunctions()) {
        _GetHgi()->DestroyShaderFunction(&fn);
    }
    _GetHgi()->DestroyShaderProgram(&shaderProgram);
}

void HdxDebugDrawTask::_PrintCompileErrors(HgiShaderProgramHandle shaderProgram) {
    if (!shaderProgram) return;

    for (HgiShaderFunctionHandle fn : shaderProgram->GetShaderFunctions()) {
        std::cout << fn->GetCompileErrors() << std::endl;
    }
    std::cout << shaderProgram->GetCompileErrors() << std::endl;
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
    return lhs.aovName == rhs.aovName && lhs.points.size() == rhs.points.size() &&
           lhs.lines.size() == rhs.lines.size() && lhs.triangles.size() == rhs.triangles.size();
}

bool operator!=(const HdxDebugDrawTaskParams& lhs, const HdxDebugDrawTaskParams& rhs) { return !(lhs == rhs); }

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/pxr.h"

#include "pxr/base/gf/matrix4f.h"

#include "pxr/imaging/hdx/api.h"
#include "pxr/imaging/hdx/task.h"
#include "pxr/imaging/hdx/tokens.h"

#include "pxr/imaging/hd/camera.h"

#include "pxr/imaging/hgi/attachmentDesc.h"
#include "pxr/imaging/hgi/buffer.h"
#include "pxr/imaging/hgi/graphicsCmds.h"
#include "pxr/imaging/hgi/graphicsPipeline.h"
#include "pxr/imaging/hgi/resourceBindings.h"
#include "pxr/imaging/hgi/shaderProgram.h"
#include "pxr/imaging/hgi/texture.h"

#include "pxr/usd/sdf/path.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdStRenderPassState;

struct HdxDebugPoint {
    HdxDebugPoint(const GfVec3f& p, const int32_t& c) : pos(p), color(c) {}

    GfVec3f pos;
    int32_t color;
};

struct HdxDebugLine {
    HdxDebugLine(const GfVec3f& p0, const GfVec3f& p1, const int32_t& c) : pos0(p0), color0(c), pos1(p1), color1(c) {}

    GfVec3f pos0;
    int32_t color0;
    GfVec3f pos1;
    int32_t color1;
};

struct HdxDebugTriangle {
    HdxDebugTriangle(const GfVec3f& p0, const GfVec3f& p1, const GfVec3f& p2, const int32_t& c)
        : pos0(p0), color0(c), pos1(p1), color1(c), pos2(p2), color2(c) {}

    GfVec3f pos0;
    int32_t color0;
    GfVec3f pos1;
    int32_t color1;
    GfVec3f pos2;
    int32_t color2;
};

/// \class HdxBoundingBoxTaskParams
///
/// BoundingBoxTask parameters.
///
struct HdxDebugDrawTaskParams {
    using PointVector = std::vector<HdxDebugPoint>;
    using LineVector = std::vector<HdxDebugLine>;
    using TriangleVector = std::vector<HdxDebugTriangle>;

    HDX_API
    HdxDebugDrawTaskParams() : aovName(), points(), lines(), triangles() {}

    TfToken aovName;

    // Data provided by the application
    PointVector points;
    LineVector lines;
    TriangleVector triangles;
};

/// \class HdxDebugDrawTask
///
/// A task for rendering bounding boxes.
///
class HdxDebugDrawTask : public HdxTask {
public:
    HDX_API
    HdxDebugDrawTask(HdSceneDelegate* delegate, const SdfPath& id);

    HDX_API
    ~HdxDebugDrawTask() override;

    /// Prepare the bounding box task resources
    HDX_API
    void Prepare(HdTaskContext* ctx, HdRenderIndex* renderIndex) override;

    /// Execute the bounding box task
    HDX_API
    void Execute(HdTaskContext* ctx) override;

protected:
    /// Sync the render pass resources
    HDX_API
    void _Sync(HdSceneDelegate* delegate, HdTaskContext* ctx, HdDirtyBits* dirtyBits) override;

private:
    HdxDebugDrawTask() = delete;
    HdxDebugDrawTask(const HdxDebugDrawTask&) = delete;
    HdxDebugDrawTask& operator=(const HdxDebugDrawTask&) = delete;

    // Utility function to create the shader for drawing dashed lines.
    bool _CreateShaderResources();

    // Utility function to create buffer resources.
    bool _CreatePointBufferResources();
    bool _CreateLineBufferResources();
    bool _CreateTriangleBufferResources();

    // Utility to create a pipeline.
    bool _CreatePointPipeline(const HgiTextureHandle& colorTexture, const HgiTextureHandle& depthTexture);
    bool _CreateLinePipeline(const HgiTextureHandle& colorTexture, const HgiTextureHandle& depthTexture);
    bool _CreateTrianglePipeline(const HgiTextureHandle& colorTexture, const HgiTextureHandle& depthTexture);

    // Utility to get the view and projection matrix from the camera.
    GfMatrix4d _ComputeViewProjectionMatrix(const HdStRenderPassState& hdStRenderPassState) const;

    // Utility to set the shader constants for drawing.
    void _UpdatePointShaderConstants(HgiGraphicsCmds* gfxCmds,
                                     HgiGraphicsPipelineHandle pipeline,
                                     const HdStRenderPassState& hdStRenderPassState);
    void _UpdateLineShaderConstants(HgiGraphicsCmds* gfxCmds,
                                    HgiGraphicsPipelineHandle pipeline,
                                    const HdStRenderPassState& hdStRenderPassState);
    void _UpdateTriangleShaderConstants(HgiGraphicsCmds* gfxCmds,
                                        HgiGraphicsPipelineHandle pipeline,
                                        const HdStRenderPassState& hdStRenderPassState);

    // Create and submit the draw commands.
    void _DrawPoints(const HgiTextureHandle& colorTexture,
                     const HgiTextureHandle& depthTexture,
                     const HdStRenderPassState& hdStRenderPassState);
    void _DrawLines(const HgiTextureHandle& colorTexture,
                    const HgiTextureHandle& depthTexture,
                    const HdStRenderPassState& hdStRenderPassState);
    void _DrawTriangles(const HgiTextureHandle& colorTexture,
                        const HgiTextureHandle& depthTexture,
                        const HdStRenderPassState& hdStRenderPassState);

    // Destroy shader program and the shader functions it holds.
    void _DestroyShaderProgram();

    // Print shader compile errors.
    void _PrintCompileErrors();

    HgiAttachmentDesc _colorAttachment;
    HgiAttachmentDesc _depthAttachment;

    struct GPUResource {
        HgiBufferHandle vertexBuffer;
        size_t maxTransforms{};
        HgiGraphicsPipelineHandle pipeline;
    };
    GPUResource _pointResource;
    GPUResource _lineResource;
    GPUResource _triangleResource;
    HgiShaderProgramHandle _shaderProgram;

    HdxDebugDrawTaskParams _params;
};

// VtValue requirements
HDX_API
std::ostream& operator<<(std::ostream& out, const HdxDebugDrawTaskParams& pv);
HDX_API
bool operator==(const HdxDebugDrawTaskParams& lhs, const HdxDebugDrawTaskParams& rhs);
HDX_API
bool operator!=(const HdxDebugDrawTaskParams& lhs, const HdxDebugDrawTaskParams& rhs);

PXR_NAMESPACE_CLOSE_SCOPE
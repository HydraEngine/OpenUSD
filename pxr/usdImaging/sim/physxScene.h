//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>
#include <pxr/imaging/hd/sceneIndex.h>

namespace sim {
struct PhysxSceneConfig;

class PhysxScene {
public:
    PhysxScene(pxr::GfVec3f gravity, PhysxSceneConfig config);

private:
    physx::PxScene* _scene;
    physx::PxCpuDispatcher* _dispatcher;
};
}  // namespace sim
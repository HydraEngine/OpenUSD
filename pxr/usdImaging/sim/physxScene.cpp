//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "physXScene.h"
#include "physxEngine.h"
#include "filterShader.h"

using namespace pxr;
using namespace physx;

namespace sim {
PhysxScene::PhysxScene(GfVec3f gravity, PhysxSceneConfig config) {
    auto creator = PhysxEngine::Get()->getPxPhysics();

    PxSceneDesc sceneDesc(creator->getTolerancesScale());
    sceneDesc.gravity = {config.gravity[0], config.gravity[1], config.gravity[2]};
    sceneDesc.filterShader = TypeAffinityIgnoreFilterShader;
    sceneDesc.solverType = config.enableTGS ? PxSolverType::eTGS : PxSolverType::ePGS;
    sceneDesc.bounceThresholdVelocity = config.bounceThreshold;

    PxSceneFlags sceneFlags;
    if (config.enableEnhancedDeterminism) {
        sceneFlags |= PxSceneFlag::eENABLE_ENHANCED_DETERMINISM;
    }
    if (config.enablePCM) {
        sceneFlags |= PxSceneFlag::eENABLE_PCM;
    }
    if (config.enableCCD) {
        sceneFlags |= PxSceneFlag::eENABLE_CCD;
    }
    if (config.enableFrictionEveryIteration) {
        sceneFlags |= PxSceneFlag::eENABLE_FRICTION_EVERY_ITERATION;
    }

    sceneDesc.flags = sceneFlags;

    _dispatcher = PxDefaultCpuDispatcherCreate(config.cpuWorkers);
    if (!_dispatcher) {
        throw std::runtime_error("PhysX system creation failed: failed to create CPU dispatcher");
    }
    sceneDesc.cpuDispatcher = _dispatcher;
    _scene = creator->createScene(sceneDesc);
}

}  // namespace sim
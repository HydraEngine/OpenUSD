//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>
#include <pxr/imaging/hd/sceneIndex.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usdImaging/usdPhysicsImaging/rigidBodySchema.h>

namespace sim {
class PhysxScene;

struct PhysxSceneConfig {
    pxr::GfVec3f gravity = {0, 0, -9.81};      // default gravity
    float bounceThreshold = 2.f;               // relative velocity below this will not bounce
    bool enablePCM = true;                     // Use persistent contact manifold solver for contact
    bool enableTGS = true;                     // use TGS solver
    bool enableCCD = false;                    // use continuous collision detection
    bool enableEnhancedDeterminism = false;    // improve determinism
    bool enableFrictionEveryIteration = true;  // better friction calculation, recommended for robotics
    uint32_t cpuWorkers = 0;                   // CPU workers, 0 for using main thread
};

class PhysxEngine {
public:
    static std::shared_ptr<PhysxEngine> Get(float toleranceLength = 0.1f, float toleranceSpeed = 0.2f);

    static std::shared_ptr<PhysxEngine> GetIfExists();

    PhysxEngine(float toleranceLength, float toleranceSpeed);
    ::physx::PxPhysics *getPxPhysics() const { return mPxPhysics; }

    ~PhysxEngine();

public:
    std::shared_ptr<PhysxScene> CreatePxScene(pxr::SdfPath primPath, pxr::HdContainerDataSourceHandle dataSource);
    std::shared_ptr<PhysxScene> FindScene(const pxr::SdfPath& primPath);

    physx::PxMaterial *CreateMaterial(pxr::SdfPath primPath, const pxr::HdContainerDataSourceHandle& dataSource);
    physx::PxMaterial *FindMaterial(const pxr::SdfPath& primPath);

    physx::PxRigidStatic *CreateStaticActor(const pxr::SdfPath &primPath, const pxr::GfMatrix4d &transform);
    physx::PxRigidStatic *FindStaticActor(const pxr::SdfPath& primPath);
    physx::PxRigidDynamic *CreateDynamicActor(const pxr::SdfPath &primPath,
                                              const pxr::GfMatrix4d &transform,
                                              pxr::UsdPhysicsImagingRigidBodySchema schema);
    physx::PxRigidDynamic *FindDynamicsActor(pxr::SdfPath primPath);
    physx::PxRigidActor *FindActor(pxr::SdfPath primPath);

    physx::PxBoxGeometry CreateBoxGeometry(pxr::HdContainerDataSourceHandle dataSource);

private:
    ::physx::PxPhysics *mPxPhysics;
    ::physx::PxFoundation *mPxFoundation;
    std::unordered_map<size_t, std::shared_ptr<PhysxScene>> mScenes;
    std::unordered_map<size_t, physx::PxMaterial *> mMaterials;
    std::unordered_map<size_t, physx::PxRigidStatic *> mStaticActors;
    std::unordered_map<size_t, physx::PxRigidDynamic *> mDynamicActors;
    PhysxSceneConfig mConfig;
};
}  // namespace sim

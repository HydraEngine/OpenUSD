//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/imaging/hd/fabric.h>

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
    explicit PhysxEngine(pxr::Fabric &fabric);
    [[nodiscard]] physx::PxPhysics *getPxPhysics() const { return mPxPhysics; }

    ~PhysxEngine();

    void UpdateAll(float dt);

    void Sync();

    void UnSync();

public:
    std::shared_ptr<PhysxScene> CreateScene(const pxr::SdfPath &primPath, const pxr::HdSceneSchema &schema);
    std::shared_ptr<PhysxScene> FindScene(const pxr::SdfPath &primPath);

    physx::PxMaterial *CreateMaterial(const pxr::SdfPath &primPath, const pxr::HdPhysicsMaterialSchema &schema);
    physx::PxMaterial *FindMaterial(const pxr::SdfPath &primPath);
    physx::PxMaterial *DefaultMaterial();

    physx::PxRigidStatic *CreateStaticActor(const pxr::SdfPath &primPath);
    physx::PxRigidStatic *FindStaticActor(const pxr::SdfPath &primPath);
    physx::PxRigidDynamic *CreateDynamicActor(const pxr::SdfPath &primPath, const pxr::HdRigidBodySchema &schema);
    physx::PxRigidDynamic *FindDynamicsActor(const pxr::SdfPath &primPath);
    physx::PxRigidActor *FindActor(const pxr::SdfPath &primPath);

    physx::PxShape *CreateShape(const pxr::SdfPath &primPath,
                                const pxr::HdCubeSchema &schema,
                                pxr::GfMatrix4d shapePose,
                                physx::PxMaterial *material,
                                physx::PxRigidActor *actor);

private:
    pxr::Fabric &_fabric;

    ::physx::PxPhysics *mPxPhysics;
    ::physx::PxFoundation *mPxFoundation;
    physx::PxMaterial *mDefaultMaterial;
    pxr::SdfPath mDefaultScene;
    std::map<pxr::SdfPath, std::shared_ptr<PhysxScene>> mScenes;
    std::map<pxr::SdfPath, physx::PxMaterial *> mMaterials;
    std::map<pxr::SdfPath, physx::PxRigidStatic *> mStaticActors;
    std::map<pxr::SdfPath, physx::PxRigidDynamic *> mDynamicActors;
    std::map<pxr::SdfPath, physx::PxShape *> mShapes;

    PhysxSceneConfig mConfig;
};
}  // namespace sim

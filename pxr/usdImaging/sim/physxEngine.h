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
    PhysxEngine(pxr::Fabric& fabric);
    ::physx::PxPhysics *getPxPhysics() const { return mPxPhysics; }

    ~PhysxEngine();

public:
    std::shared_ptr<PhysxScene> CreatePxScene(const pxr::SdfPath &primPath,
                                              const pxr::HdSceneSchema &schema);
    std::shared_ptr<PhysxScene> FindScene(const pxr::SdfPath &primPath);
    void UpdateAll(float dt);

    physx::PxMaterial *CreateMaterial(const pxr::SdfPath &primPath, const pxr::HdPhysicsMaterialSchema &schema);
    physx::PxMaterial *FindMaterial(const pxr::SdfPath &primPath);
    physx::PxMaterial *DefaultMaterial();

    physx::PxRigidStatic *CreateStaticActor(const pxr::SdfPath &primPath, const pxr::GfMatrix4d &transform);
    physx::PxRigidStatic *FindStaticActor(const pxr::SdfPath &primPath);
    physx::PxRigidDynamic *CreateDynamicActor(const pxr::SdfPath &primPath,
                                              const pxr::GfMatrix4d &transform,
                                              const pxr::HdRigidBodySchema &schema);
    physx::PxRigidDynamic *FindDynamicsActor(const pxr::SdfPath &primPath);
    physx::PxRigidActor *FindActor(const pxr::SdfPath &primPath);

    physx::PxShape *CreateShape(const pxr::SdfPath &primPath,
                                const pxr::HdCubeSchema &schema,
                                pxr::GfMatrix4d shapePose,
                                physx::PxMaterial *material,
                                physx::PxRigidActor *actor);

    void AddActor(const pxr::VtArray<pxr::SdfPath> &scene, physx::PxRigidActor *actor);

    void Sync();

private:
    pxr::Fabric& _fabric;

    ::physx::PxPhysics *mPxPhysics;
    ::physx::PxFoundation *mPxFoundation;
    physx::PxMaterial *mDefaultMaterial;
    pxr::SdfPath mDefaultScene;
    std::unordered_map<size_t, std::shared_ptr<PhysxScene>> mScenes;
    std::unordered_map<size_t, physx::PxMaterial *> mMaterials;
    std::unordered_map<size_t, physx::PxRigidStatic *> mStaticActors;
    std::unordered_map<size_t, physx::PxRigidDynamic *> mDynamicActors;
    std::unordered_map<size_t, physx::PxShape *> mShapes;
    std::unordered_map<size_t, std::vector<physx::PxActor *>> mActorScene;

    PhysxSceneConfig mConfig;
};
}  // namespace sim

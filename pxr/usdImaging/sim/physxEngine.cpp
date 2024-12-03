//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "physxEngine.h"
#include "physxScene.h"
#include "utils.h"
#include "pxr/base/tf/diagnostic.h"

#include "pxr/usdImaging/usdPhysicsImaging/materialSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/sceneSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/collisionSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/jointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/distanceJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/revoluteJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/fixedJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/sphericalJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/prismaticJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/driveSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/limitSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/articulationRootSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/rigidBodySchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/collisionGroupSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/massSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/filteredPairsSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/meshCollisionSchema.h"

#include "pxr/imaging/hd/cubeSchema.h"
#include "pxr/imaging/hd/capsuleSchema.h"
#include "pxr/imaging/hd/sphereSchema.h"
#include "pxr/imaging/hd/coneSchema.h"
#include "pxr/imaging/hd/cylinderSchema.h"
#include "pxr/imaging/hd/meshSchema.h"

using namespace physx;
using namespace pxr;

namespace sim {
static PxDefaultAllocator gDefaultAllocatorCallback;

class UsdErrorCallback : public PxErrorCallback {
    PxErrorCode::Enum mLastErrorCode = PxErrorCode::eNO_ERROR;

public:
    void reportError(PxErrorCode::Enum code, const char* message, const char* file, int line) override {
        mLastErrorCode = code;

#ifdef NDEBUG
        TF_WARN("{%s}", message);
#else
        TF_WARN("{%s}:{%i}: {%s}", file, line, message);
#endif
    }
    PxErrorCode::Enum getLastErrorCode() {
        auto code = mLastErrorCode;
        mLastErrorCode = PxErrorCode::eNO_ERROR;
        return code;
    }
};

static UsdErrorCallback gDefaultErrorCallback;

static std::weak_ptr<PhysxEngine> gEngine;
std::shared_ptr<PhysxEngine> PhysxEngine::Get(float toleranceLength, float toleranceSpeed) {
    auto engine = gEngine.lock();
    if (!engine) {
        gEngine = engine = std::make_shared<PhysxEngine>(toleranceLength, toleranceSpeed);
    }
    return engine;
}

std::shared_ptr<PhysxEngine> PhysxEngine::GetIfExists() { return gEngine.lock(); }

PhysxEngine::PhysxEngine(float toleranceLength, float toleranceSpeed) {
    mPxFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback);
    if (!mPxFoundation) {
        throw std::runtime_error("PhysX foundation creation failed");
    }

    PxTolerancesScale toleranceScale(toleranceLength, toleranceSpeed);

    mPxPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *mPxFoundation, toleranceScale);
    if (!mPxPhysics) {
        throw std::runtime_error("PhysX creation failed");
    }
    if (!PxInitExtensions(*mPxPhysics, nullptr)) {
        throw std::runtime_error("PhysX extension initialization failed");
    }

    mDefaultMaterial = mPxPhysics->createMaterial(0.5, 0.5, 0.5);
}

PhysxEngine::~PhysxEngine() {
    PxCloseExtensions();
    mPxPhysics->release();
    mPxFoundation->release();
}

std::shared_ptr<PhysxScene> PhysxEngine::CreatePxScene(pxr::SdfPath primPath,
                                                       pxr::HdContainerDataSourceHandle dataSource) {
    UsdPhysicsImagingSceneSchema schema = UsdPhysicsImagingSceneSchema::GetFromParent(dataSource);
    if (schema) {
        auto g_length = schema.GetGravityMagnitude()->GetTypedValue(0);
        auto g_dir = schema.GetGravityDirection()->GetTypedValue(0);
        g_dir *= g_length;
        auto scene = std::make_shared<PhysxScene>(g_dir, mConfig);
        mScenes.insert({primPath.GetHash(), scene});
        return scene;
    }
    return nullptr;
}

std::shared_ptr<PhysxScene> PhysxEngine::FindScene(const pxr::SdfPath& primPath) {
    auto iter = mScenes.find(primPath.GetHash());
    if (iter != mScenes.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxMaterial* PhysxEngine::CreateMaterial(pxr::SdfPath primPath,
                                               const pxr::HdContainerDataSourceHandle& dataSource) {
    UsdPhysicsImagingMaterialSchema schema = UsdPhysicsImagingMaterialSchema::GetFromParent(dataSource);
    if (schema) {
        auto restitution = schema.GetRestitution()->GetTypedValue(0);
        auto staticFriction = schema.GetStaticFriction()->GetTypedValue(0);
        auto dynamicFriction = schema.GetDynamicFriction()->GetTypedValue(0);

        auto scene = mPxPhysics->createMaterial(staticFriction, dynamicFriction, restitution);
        mMaterials.insert({primPath.GetHash(), scene});
        return scene;
    }
    return nullptr;
}

physx::PxMaterial* PhysxEngine::FindMaterial(const pxr::SdfPath& primPath) {
    if (const auto iter = mMaterials.find(primPath.GetHash()); iter != mMaterials.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxMaterial* PhysxEngine::DefaultMaterial() { return mDefaultMaterial; }

physx::PxRigidStatic* PhysxEngine::CreateStaticActor(const pxr::SdfPath& primPath, const pxr::GfMatrix4d& transform) {
    auto actor = mPxPhysics->createRigidStatic(convert(transform));
    mStaticActors.insert({primPath.GetHash(), actor});
    return actor;
}

physx::PxRigidStatic* PhysxEngine::FindStaticActor(const pxr::SdfPath& primPath) {
    auto hash = primPath.GetHash();
    if (const auto iter = mStaticActors.find(hash); iter != mStaticActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxRigidDynamic* PhysxEngine::CreateDynamicActor(const pxr::SdfPath& primPath,
                                                       const pxr::GfMatrix4d& transform,
                                                       pxr::UsdPhysicsImagingRigidBodySchema schema) {
    auto actor = mPxPhysics->createRigidDynamic(convert(transform));
    mDynamicActors.insert({primPath.GetHash(), actor});

    if (schema.GetKinematicEnabled()->GetTypedValue(0)) {
        actor->setRigidBodyFlag(physx::PxRigidBodyFlag::eKINEMATIC, true);
    } else {
        actor->setRigidBodyFlag(physx::PxRigidBodyFlag::eKINEMATIC, false);
    }

    const auto vel = schema.GetVelocity()->GetTypedValue(0);
    const auto angVel = schema.GetAngularVelocity()->GetTypedValue(0);
    actor->setLinearVelocity(convert(vel));
    actor->setAngularVelocity(convert(angVel));

    return actor;
}

physx::PxRigidDynamic* PhysxEngine::FindDynamicsActor(pxr::SdfPath primPath) {
    auto hash = primPath.GetHash();
    if (const auto iter = mDynamicActors.find(hash); iter != mDynamicActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxRigidActor* PhysxEngine::FindActor(pxr::SdfPath primPath) {
    auto hash = primPath.GetHash();
    if (const auto iter = mStaticActors.find(hash); iter != mStaticActors.end()) {
        return iter->second;
    }
    if (const auto iter = mDynamicActors.find(hash); iter != mDynamicActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxShape* PhysxEngine::CreateShape(const pxr::SdfPath& primPath,
                                         const pxr::HdContainerDataSourceHandle& dataSource,
                                         physx::PxMaterial* material,
                                         physx::PxRigidActor* actor) {
    PxShape* shape{nullptr};
    HdCubeSchema cubeSchema = HdCubeSchema::GetFromParent(dataSource);
    if (cubeSchema) {
        auto size = cubeSchema.GetSize()->GetTypedValue(0);
        auto geometry = PxBoxGeometry((float)size, (float)size, (float)size);
        shape = mPxPhysics->createShape(geometry, *material);
    }

    actor->attachShape(*shape);
    mShapes.insert({primPath.GetHash(), shape});
    return shape;
}

}  // namespace sim
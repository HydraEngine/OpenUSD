//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "physxEngine.h"
#include "physxScene.h"
#include "utils.h"
#include "pxr/base/tf/diagnostic.h"

#include "pxr/base/gf/transform.h"
#include <iostream>

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

PhysxEngine::PhysxEngine(pxr::Fabric& fabric) : _fabric{fabric} {
    mPxFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback);
    if (!mPxFoundation) {
        throw std::runtime_error("PhysX foundation creation failed");
    }

    PxTolerancesScale toleranceScale(0.1, 0.2);

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

void PhysxEngine::UpdateAll(float dt) {
    for (const auto& scene : mScenes) {
        scene.second->Update(dt);
    }
}

void PhysxEngine::Sync() {
    for (const auto& scene : _fabric._scenes) {
        CreateScene(scene.first, scene.second);
    }
    for (const auto& material : _fabric._materials) {
        CreateMaterial(material.first, material.second);
    }

    for (const auto& rigidBody : _fabric._rigidBodies) {
        auto actor = CreateDynamicActor(rigidBody.first, rigidBody.second);
        if (actor) {
            auto simulator = rigidBody.second.GetSimulationOwner()->GetTypedValue(0);
            if (simulator.empty()) {
                simulator.push_back(mDefaultScene);
            }
            for (const auto& scenePath : simulator) {
                auto iter = mScenes.find(scenePath);
                if (iter != mScenes.end()) {
                    auto scene = iter->second;
                    scene->Handle()->addActor(*actor);
                }
            }
        }
    }

    for (const auto& collision : _fabric._collisions) {
        const auto primPath = collision.first;
        // Find Actor
        const auto xform = _fabric._globalXforms.find(primPath);
        if (xform == _fabric._globalXforms.end()) {
            continue;
        }
        const auto collisionXform = xform->second;
        auto shapePose = GfMatrix4d(1);
        physx::PxRigidActor* actor = nullptr;
        for (const auto& ancestors : primPath.GetAncestorsRange()) {
            if (const auto result = FindActor(ancestors)) {
                std::cout << "Find Actor Ancestor: " << ancestors << "\n";
                actor = result;
                auto globalPose = actor->getGlobalPose();
                auto actorXform = convert(globalPose);
                actorXform = actorXform.RemoveScaleShear();
                shapePose = collisionXform / actorXform;
                break;
            }
        }
        if (!actor) {
            std::cout << "use self as static actor" << "\n";
            auto actorXform = collisionXform.RemoveScaleShear();
            shapePose = collisionXform / actorXform;
            actor = CreateStaticActor(primPath);

            if (actor) {
                auto simulator = collision.second.GetSimulationOwner()->GetTypedValue(0);
                if (simulator.empty()) {
                    simulator.push_back(mDefaultScene);
                }
                for (const auto& scenePath : simulator) {
                    auto iter = mScenes.find(scenePath);
                    if (iter != mScenes.end()) {
                        auto scene = iter->second;
                        scene->Handle()->addActor(*actor);
                    }
                }
            }
        }

        // Find Material
        physx::PxMaterial* material{nullptr};
        if (auto iter = _fabric._materialBindings.find(primPath); iter != _fabric._materialBindings.end()) {
            auto binding = iter->second.GetDirectMaterialBinding(TfToken("physics"));
            if (binding) {
                auto path = binding.GetMaterialPath()->GetTypedValue(0);
                material = FindMaterial(path);
            }
        }
        if (!material) {
            material = DefaultMaterial();
        }

        // create shape
        if (auto iter = _fabric._cubes.find(primPath); iter != _fabric._cubes.end()) {
            CreateShape(primPath, iter->second, shapePose, material, actor);
        }
    }
}

void PhysxEngine::UnSync() {}

// =====================================================================================================================

std::shared_ptr<PhysxScene> PhysxEngine::CreateScene(const pxr::SdfPath& primPath, const pxr::HdSceneSchema& schema) {
    auto g_length = schema.GetGravityMagnitude()->GetTypedValue(0);
    auto g_dir = schema.GetGravityDirection()->GetTypedValue(0);
    g_dir *= g_length;
    auto scene = std::make_shared<PhysxScene>(mPxPhysics, g_dir, mConfig);
    mScenes.insert({primPath, scene});
    mDefaultScene = primPath;
    return scene;
}

std::shared_ptr<PhysxScene> PhysxEngine::FindScene(const pxr::SdfPath& primPath) {
    auto iter = mScenes.find(primPath);
    if (iter != mScenes.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxMaterial* PhysxEngine::CreateMaterial(const pxr::SdfPath& primPath,
                                               const pxr::HdPhysicsMaterialSchema& schema) {
    auto restitution = schema.GetRestitution()->GetTypedValue(0);
    auto staticFriction = schema.GetStaticFriction()->GetTypedValue(0);
    auto dynamicFriction = schema.GetDynamicFriction()->GetTypedValue(0);

    auto scene = mPxPhysics->createMaterial(staticFriction, dynamicFriction, restitution);
    mMaterials.insert({primPath, scene});
    return scene;
}

physx::PxMaterial* PhysxEngine::FindMaterial(const pxr::SdfPath& primPath) {
    if (const auto iter = mMaterials.find(primPath); iter != mMaterials.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxMaterial* PhysxEngine::DefaultMaterial() { return mDefaultMaterial; }

physx::PxRigidStatic* PhysxEngine::CreateStaticActor(const pxr::SdfPath& primPath) {
    const auto xform = _fabric._globalXforms.find(primPath);
    if (xform == _fabric._globalXforms.end()) {
        return nullptr;
    }

    auto actor = mPxPhysics->createRigidStatic(convert(xform->second));
    mStaticActors.insert({primPath, actor});
    return actor;
}

physx::PxRigidStatic* PhysxEngine::FindStaticActor(const pxr::SdfPath& primPath) {
    if (const auto iter = mStaticActors.find(primPath); iter != mStaticActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxRigidDynamic* PhysxEngine::CreateDynamicActor(const pxr::SdfPath& primPath,
                                                       const pxr::HdRigidBodySchema& schema) {
    const auto xform = _fabric._globalXforms.find(primPath);
    if (xform == _fabric._globalXforms.end()) {
        return nullptr;
    }

    auto actor = mPxPhysics->createRigidDynamic(convert(xform->second));
    mDynamicActors.insert({primPath, actor});

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

physx::PxRigidDynamic* PhysxEngine::FindDynamicsActor(const pxr::SdfPath& primPath) {
    if (const auto iter = mDynamicActors.find(primPath); iter != mDynamicActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxRigidActor* PhysxEngine::FindActor(const pxr::SdfPath& primPath) {
    if (const auto iter = mStaticActors.find(primPath); iter != mStaticActors.end()) {
        return iter->second;
    }
    if (const auto iter = mDynamicActors.find(primPath); iter != mDynamicActors.end()) {
        return iter->second;
    }
    return nullptr;
}

physx::PxShape* PhysxEngine::CreateShape(const pxr::SdfPath& primPath,
                                         const pxr::HdCubeSchema& cubeSchema,
                                         pxr::GfMatrix4d shapePose,
                                         physx::PxMaterial* material,
                                         physx::PxRigidActor* actor) {
    auto transform = pxr::GfTransform(shapePose);
    auto scale = convert(transform.GetScale());
    auto translation = convert(transform.GetTranslation());
    auto rotation = convert(transform.GetRotation().GetQuat());

    //    UsdPhysicsImagingCollisionSchema collisionSchema =
    //    UsdPhysicsImagingCollisionSchema::GetFromParent(dataSource); auto collisionEnabled =
    //    collisionSchema.GetCollisionEnabled()->GetTypedValue(0);

    PxShape* shape{nullptr};
    auto size = (float)cubeSchema.GetSize()->GetTypedValue(0);
    auto s = scale * size;
    auto geometry = PxBoxGeometry(s.x / 2, s.y / 2, s.z / 2);
    shape = mPxPhysics->createShape(geometry, *material);

    if (shape) {
        //        if (!collisionEnabled) {
        //            shape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);
        //        }

        shape->setLocalPose(PxTransform(translation, rotation));
        actor->attachShape(*shape);
        mShapes.insert({primPath, shape});
        return shape;
    }

    return nullptr;
}

}  // namespace sim
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/sim/physicsSceneIndex.h"

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
#include "pxr/usdImaging/usdImaging/directMaterialBindingsSchema.h"

#include "pxr/imaging/hd/cubeSchema.h"
#include "pxr/imaging/hd/capsuleSchema.h"
#include "pxr/imaging/hd/sphereSchema.h"
#include "pxr/imaging/hd/coneSchema.h"
#include "pxr/imaging/hd/cylinderSchema.h"
#include "pxr/imaging/hd/meshSchema.h"
#include "pxr/imaging/hd/xformSchema.h"
#include "utils.h"

#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/primvarsSchema.h"
#include <pxr/imaging/hd/tokens.h>
#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

static UsdImagingStageSceneIndexRefPtr FindUsdImagingSceneIndex(
        const std::vector<HdSceneIndexBaseRefPtr> &inputScenes) {
    TfRefPtr<UsdImagingStageSceneIndex> retVal;

    for (const auto &sceneIdx : inputScenes) {
        if (UsdImagingStageSceneIndexRefPtr const imagingSI =
                    TfDynamic_cast<UsdImagingStageSceneIndexRefPtr>(sceneIdx)) {
            retVal = imagingSI;
            break;
        }
        if (HdFilteringSceneIndexBaseRefPtr const filteringSi =
                    TfDynamic_cast<HdFilteringSceneIndexBaseRefPtr>(sceneIdx)) {
            retVal = FindUsdImagingSceneIndex(filteringSi->GetInputScenes());
            if (retVal) {
                break;
            }
        }
    }
    return retVal;
}

UsdImagingPhysicsSceneIndexRefPtr UsdImagingPhysicsSceneIndex::New(const HdSceneIndexBaseRefPtr &inputSceneIndex) {
    return TfCreateRefPtr(new UsdImagingPhysicsSceneIndex(inputSceneIndex));
}

UsdImagingPhysicsSceneIndex::UsdImagingPhysicsSceneIndex(const HdSceneIndexBaseRefPtr &inputSceneIndex)
    : HdSingleInputFilteringSceneIndexBase(inputSceneIndex) {}

void UsdImagingPhysicsSceneIndex::_PrimsAdded(const HdSceneIndexBase &sender,
                                              const HdSceneIndexObserver::AddedPrimEntries &entries) {
    if (!_IsObserved()) {
        return;
    }
    auto engine = GetSimulation();

    UsdImagingStageSceneIndexRefPtr usdImagingSi;
    if (auto filteringIdx = dynamic_cast<HdFilteringSceneIndexBase const *>(&sender)) {
        // SceneIndexPlugins do not have access to the current stage/frame time.
        // Only the UsdImagingStageSceneIndex has this. We store this for each Mesh,
        // nullptr is a valid value. If valid, warp simulation can use the exact
        // stage time. If null, the warp has to emulate frame time
        usdImagingSi = FindUsdImagingSceneIndex(filteringIdx->GetInputScenes());
    }
    if (usdImagingSi) {
        std::cout << "Time: " << usdImagingSi->GetTime().GetValue() << "\n";
    }

    // Standalone Object
    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        if (entry.primType == UsdPhysicsTokens->PhysicsScene) {
            const auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
            if (auto scene = engine->CreatePxScene(entry.primPath, prim.dataSource)) {
                std::cout << entry.primPath << "\t" << entry.primType << "\t Scene Created" << "\n";
                continue;
            }
        }

        if (entry.primType == HdPrimTypeTokens->material) {
            const auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
            if (const auto material = engine->CreateMaterial(entry.primPath, prim.dataSource)) {
                std::cout << entry.primPath << "\t" << material->getConcreteTypeName() << "\t Created" << "\n";
                std::cout << "Restitution: \t" << material->getRestitution() << "\n";
                std::cout << "DynamicFriction: \t" << material->getDynamicFriction() << "\n";
                std::cout << "StaticFriction: \t" << material->getStaticFriction() << "\n";
                continue;
            }
        }

        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        UsdPhysicsImagingRigidBodySchema rigidBodySchema =
                UsdPhysicsImagingRigidBodySchema::GetFromParent(prim.dataSource);
        if (rigidBodySchema) {
            HdXformSchema xformSchema = HdXformSchema::GetFromParent(prim.dataSource);
            const auto rigidBodyEnabled = rigidBodySchema.GetRigidBodyEnabled()->GetTypedValue(0);
            const auto simulator = rigidBodySchema.GetSimulationOwner()->GetTypedValue(0);

            if (!rigidBodyEnabled && xformSchema) {
                auto xform = xformSchema.GetMatrix()->GetTypedValue(0);
                if (const auto actor = engine->CreateStaticActor(entry.primPath, xform)) {
                    std::cout << entry.primPath << "\t" << entry.primType << "\t StaticBody Created" << "\n";
                    engine->AddActor(simulator[0], actor);
                }
            }

            if (rigidBodyEnabled && xformSchema) {
                auto xform = xformSchema.GetMatrix()->GetTypedValue(0);
                if (const auto actor = engine->CreateDynamicActor(entry.primPath, xform, rigidBodySchema)) {
                    std::cout << entry.primPath << "\t" << actor->getConcreteTypeName() << "\t Created" << "\n";
                    engine->AddActor(simulator[0], actor);
                }
            }
        }
    }

    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        const auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        UsdPhysicsImagingCollisionSchema collisionSchema =
                UsdPhysicsImagingCollisionSchema::GetFromParent(prim.dataSource);
        if (collisionSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            // Find Actor
            HdXformSchema xformSchema = HdXformSchema::GetFromParent(prim.dataSource);
            auto xform = xformSchema.GetMatrix()->GetTypedValue(0);
            auto shapePose = GfMatrix4d(1);
            physx::PxRigidActor *actor = nullptr;
            for (const auto &ancestors : entry.primPath.GetAncestorsRange()) {
                if (const auto result = engine->FindActor(ancestors)) {
                    std::cout << "Find Actor Ancestor: " << ancestors << "\n";
                    actor = result;
                    auto globalPose = actor->getGlobalPose();
                    auto actorXform = convert(globalPose);
                    actorXform = actorXform.RemoveScaleShear();
                    shapePose = xform / actorXform;
                    break;
                }
            }
            if (!actor) {
                std::cout << "use self as static actor" << "\n";
                auto actorXform = xform.RemoveScaleShear();
                shapePose = xform / actorXform;
                actor = engine->CreateStaticActor(entry.primPath, actorXform);

                const auto simulator = collisionSchema.GetSimulationOwner()->GetTypedValue(0);
                engine->AddActor(simulator[0], actor);
            }

            // Find Material
            physx::PxMaterial *material{nullptr};
            UsdImagingDirectMaterialBindingsSchema materialBindingSchema =
                    UsdImagingDirectMaterialBindingsSchema::GetFromParent(prim.dataSource);
            if (materialBindingSchema) {
                auto binding = materialBindingSchema.GetDirectMaterialBinding(TfToken("physics"));
                if (binding) {
                    auto path = binding.GetMaterialPath()->GetTypedValue(0);
                    material = engine->FindMaterial(path);
                }
            }
            if (!material) {
                material = engine->DefaultMaterial();
            }

            // create shape
            auto shape = engine->CreateShape(entry.primPath, prim.dataSource, shapePose, material, actor);
            std::cout << entry.primPath << "\t" << shape->getConcreteTypeName() << "\t Created \n";
        }
    }

    engine->Sync();

    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        HdPrimvarsSchema primVarsSchema = HdPrimvarsSchema::GetFromParent(prim.dataSource);

        HdXformSchema xformSchema = HdXformSchema::GetFromParent(prim.dataSource);
        if (xformSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "Matrix: \t" << xformSchema.GetMatrix()->GetTypedValue(0) << "\n";
        }

        HdDistanceJointSchema distanceJointSchema = HdDistanceJointSchema::GetFromParent(prim.dataSource);
        if (distanceJointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "MinDistance: \t" << distanceJointSchema.GetMinDistance()->GetTypedValue(0) << "\n";
            std::cout << "MaxDistance: \t" << distanceJointSchema.GetMaxDistance()->GetTypedValue(0) << "\n";
            std::cout << "BreakForce: \t" << distanceJointSchema.GetBreakForce()->GetTypedValue(0) << "\n";
            std::cout << "BreakTorque: \t" << distanceJointSchema.GetBreakTorque()->GetTypedValue(0) << "\n";
        }

        HdRevoluteJointSchema revoluteJointSchema = HdRevoluteJointSchema::GetFromParent(prim.dataSource);
        if (revoluteJointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "LowerLimit: \t" << revoluteJointSchema.GetLowerLimit()->GetTypedValue(0) << "\n";
            std::cout << "UpperLimit: \t" << revoluteJointSchema.GetUpperLimit()->GetTypedValue(0) << "\n";
            std::cout << "BreakForce: \t" << revoluteJointSchema.GetBreakForce()->GetTypedValue(0) << "\n";
            std::cout << "BreakTorque: \t" << revoluteJointSchema.GetBreakTorque()->GetTypedValue(0) << "\n";
        }
    }

    _SendPrimsAdded(entries);
}

void UsdImagingPhysicsSceneIndex::_PrimsRemoved(const HdSceneIndexBase &sender,
                                                const HdSceneIndexObserver::RemovedPrimEntries &entries) {
    _SendPrimsRemoved(entries);
}

void UsdImagingPhysicsSceneIndex::_PrimsDirtied(const HdSceneIndexBase &sender,
                                                const HdSceneIndexObserver::DirtiedPrimEntries &entries) {
    _SendPrimsDirtied(entries);
}

HdSceneIndexPrim UsdImagingPhysicsSceneIndex::GetPrim(const SdfPath &primPath) const {
    HdSceneIndexPrim prim = _GetInputSceneIndex()->GetPrim(primPath);
    if (prim.dataSource) {
        HdPrimvarsSchema depPrimVarsSchema = HdPrimvarsSchema::GetFromParent(prim.dataSource);
        if (depPrimVarsSchema) {
            HdPrimvarSchema depPrimVar = depPrimVarsSchema.GetPrimvar(HdTokens->points);
            if (depPrimVar) {
                HdSampledDataSourceHandle valueDataSource = depPrimVar.GetPrimvarValue();
                auto pointsVt = valueDataSource->GetValue(0.f);
                const auto &outVertices = pointsVt.UncheckedGet<VtArray<GfVec3f>>();
                std::cout << "Mesh Vertex Count: " << outVertices.size() << "\n";
            }
        }
    }

    return prim;
}

SdfPathVector UsdImagingPhysicsSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

std::shared_ptr<sim::PhysxEngine> UsdImagingPhysicsSceneIndex::GetSimulation() { return sim::PhysxEngine::Get(); }

PXR_NAMESPACE_CLOSE_SCOPE
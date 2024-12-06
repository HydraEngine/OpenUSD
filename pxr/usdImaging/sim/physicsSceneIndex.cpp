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
#include "physxDataSource.h"

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
    : HdSingleInputFilteringSceneIndexBase(inputSceneIndex) {
    _simulationEngine = sim::PhysxEngine::Get();
}

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
        if (entry.primType == UsdPhysicsImagingSceneSchemaTokens->scene) {
            const auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
            if (auto scene = engine->CreatePxScene(entry.primPath, prim.dataSource)) {
                std::cout << entry.primPath << "\t" << entry.primType << "\t Scene Created" << "\n";
                continue;
            }
        }

        if (entry.primType == UsdPhysicsImagingMaterialSchemaTokens->material) {
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
                    engine->AddActor(simulator, actor);
                }
            }

            if (rigidBodyEnabled && xformSchema) {
                auto xform = xformSchema.GetMatrix()->GetTypedValue(0);
                if (const auto actor = engine->CreateDynamicActor(entry.primPath, xform, rigidBodySchema)) {
                    _paths.push_back(entry.primPath);
                    std::cout << entry.primPath << "\t" << actor->getConcreteTypeName() << "\t Created" << "\n";
                    engine->AddActor(simulator, actor);
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
                engine->AddActor(simulator, actor);
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

            auto iterBoolPair = this->_IsPrimWrapped(entry.primPath);
            if (!iterBoolPair.second) {
                this->_WrapPrim(entry.primPath, prim);
            }
        }

        UsdPhysicsImagingDistanceJointSchema distanceJointSchema =
                UsdPhysicsImagingDistanceJointSchema::GetFromParent(prim.dataSource);
        if (distanceJointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "MinDistance: \t" << distanceJointSchema.GetMinDistance()->GetTypedValue(0) << "\n";
            std::cout << "MaxDistance: \t" << distanceJointSchema.GetMaxDistance()->GetTypedValue(0) << "\n";
        }

        UsdPhysicsImagingRevoluteJointSchema revoluteJointSchema =
                UsdPhysicsImagingRevoluteJointSchema::GetFromParent(prim.dataSource);
        if (revoluteJointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "LowerLimit: \t" << revoluteJointSchema.GetLowerLimit()->GetTypedValue(0) << "\n";
            std::cout << "UpperLimit: \t" << revoluteJointSchema.GetUpperLimit()->GetTypedValue(0) << "\n";
        }

        UsdPhysicsImagingJointSchema jointSchema = UsdPhysicsImagingJointSchema::GetFromParent(prim.dataSource);
        if (jointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << "\n";
            std::cout << "BreakForce: \t" << jointSchema.GetBreakForce()->GetTypedValue(0) << "\n";
            std::cout << "BreakTorque: \t" << jointSchema.GetBreakTorque()->GetTypedValue(0) << "\n";
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
    // lookup the prim to see if we have wrapped it yet
    auto iterBoolPair = this->_IsPrimWrapped(primPath);
    if (iterBoolPair.second) {
        // we have it wrapped already, so return the wrapped prim
        return iterBoolPair.first->second;
    }

    HdSceneIndexPrim sceneIndexPrim = this->_GetInputSceneIndex()->GetPrim(primPath);
    HdXformSchema xformSchema = HdXformSchema::GetFromParent(sceneIndexPrim.dataSource);
    if (xformSchema.IsDefined()) {
        return this->_WrapPrim(primPath, sceneIndexPrim);
    }

    // otherwise we don't need to wrap it and can return it directly
    return sceneIndexPrim;
}

HdSceneIndexPrim &UsdImagingPhysicsSceneIndex::_WrapPrim(const SdfPath &primPath,
                                                         const HdSceneIndexPrim &hdPrim) const {
    HdContainerDataSourceHandle wrappedDataSource =
            HdPhysXDataSource::New(this->_GetInputSceneIndex(), primPath, hdPrim.dataSource);
    const auto it = _wrappedPrims.find(primPath);
    if (it != _wrappedPrims.end()) {
        // in this case, the entry is there, but it was auto-created
        // by SdfPathTable, meaning it should have empty entries
        TF_VERIFY(it->second.primType == TfToken());
        TF_VERIFY(it->second.dataSource == nullptr);
        it->second.primType = hdPrim.primType;
        it->second.dataSource = std::move(wrappedDataSource);

        return it->second;
    } else {
        auto iterBoolPair =
                _wrappedPrims.insert({primPath, HdSceneIndexPrim{hdPrim.primType, std::move(wrappedDataSource)}});

        return iterBoolPair.first->second;
    }
}

SdfPathTable<HdSceneIndexPrim>::_IterBoolPair UsdImagingPhysicsSceneIndex::_IsPrimWrapped(
        const SdfPath &primPath) const {
    bool result = false;
    const auto it = _wrappedPrims.find(primPath);
    if (it != _wrappedPrims.end()) {
        // because SdfPathTable inserts all parents
        // when a path gets inserted, there may be an empty
        // entry in our cache if a child path was visited first
        // to verify we have to check the prim type and data source
        if (it->second.primType != TfToken() || it->second.dataSource != nullptr) {
            // not an auto-insertion of the parent
            result = true;
        }
    }

    return std::make_pair(it, result);
}

SdfPathVector UsdImagingPhysicsSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

void UsdImagingPhysicsSceneIndex::_DirtyHierarchy(const SdfPath &primPath,
                                                  const HdDataSourceLocatorSet &locators,
                                                  HdSceneIndexObserver::DirtiedPrimEntries *dirtyEntries) {
    // find subtree range retrieves a start end pair of children
    // in the subtree of the given prim path
    auto startEndRangeIterator = _wrappedPrims.FindSubtreeRange(primPath);
    for (auto it = startEndRangeIterator.first; it != startEndRangeIterator.second;) {
        // if we have a valid wrapper for the prim, we need to check
        // whether it needs to be dirtied - this involves checking the
        // data sources to see if they have cached data and if so
        // this indicates it needs to be updated
        if (it->second.dataSource != nullptr) {
            HdPhysXDataSourceHandle geospatialDataSource = HdPhysXDataSource::Cast(it->second.dataSource);
            if (geospatialDataSource != nullptr) {
                if (it->first != primPath) {
                    dirtyEntries->emplace_back(it->first, locators);
                }

                it++;
            } else {
                it++;
            }
        } else {
            it++;
        }
    }
}

std::shared_ptr<sim::PhysxEngine> UsdImagingPhysicsSceneIndex::GetSimulation() { return _simulationEngine; }

void UsdImagingPhysicsSceneIndex::Update(float dt) {
    _simulationEngine->UpdateAll(dt);

    HdSceneIndexObserver::DirtiedPrimEntries dirtyEntries;
    static HdDataSourceLocatorSet locators = {pxr::HdXformSchema::GetDefaultLocator()};
    for (const auto &path : _paths) {
        _DirtyHierarchy(path, locators, &dirtyEntries);
        dirtyEntries.emplace_back(path, locators);
    }
    _SendPrimsDirtied(dirtyEntries);
}

PXR_NAMESPACE_CLOSE_SCOPE
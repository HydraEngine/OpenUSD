//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physicsSceneIndex.h"
#include "pxr/usdImaging/usdPhysicsImaging/materialSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/sceneSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/collisionSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/jointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/distanceJointSchema.h"
#include "pxr/imaging/hd/cubeSchema.h"
#include "pxr/imaging/hd/primvarsSchema.h"
#include <pxr/imaging/hd/tokens.h>
#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

static UsdImagingStageSceneIndexRefPtr FindUsdImagingSceneIndex(
        const std::vector<HdSceneIndexBaseRefPtr> &inputScenes) {
    TfRefPtr<UsdImagingStageSceneIndex> retVal;

    for (size_t i = 0; i < inputScenes.size(); i++) {
        HdSceneIndexBaseRefPtr const &sceneIdx = inputScenes[i];
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

    UsdImagingStageSceneIndexRefPtr usdImagingSi;
    if (auto filteringIdx = dynamic_cast<HdFilteringSceneIndexBase const *>(&sender)) {
        // SceneIndexPlugins do not have access to the current stage/frame time.
        // Only the UsdImagingStageSceneIndex has this. We store this for each Mesh,
        // nullptr is a valid value. If valid, warp simulation can use the exact
        // stage time. If null, the warp has to emulate frame time
        usdImagingSi = FindUsdImagingSceneIndex(filteringIdx->GetInputScenes());
    }
    if (usdImagingSi) {
        std::cout << "Time: " << usdImagingSi->GetTime().GetValue() << std::endl;
    }

    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        UsdPhysicsImagingMaterialSchema materialSchema =
                UsdPhysicsImagingMaterialSchema::GetFromParent(prim.dataSource);
        HdPrimvarsSchema primVarsSchema = HdPrimvarsSchema::GetFromParent(prim.dataSource);

        if (materialSchema && primVarsSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << std::endl;
            std::cout << "Density: \t" << materialSchema.GetDensity()->GetTypedValue(0) << std::endl;
            std::cout << "Restitution: \t" << materialSchema.GetRestitution()->GetTypedValue(0) << std::endl;
            std::cout << "DynamicFriction: \t" << materialSchema.GetDynamicFriction()->GetTypedValue(0) << std::endl;
            std::cout << "StaticFriction: \t" << materialSchema.GetStaticFriction()->GetTypedValue(0) << std::endl;
        }

        HdCubeSchema cubeSchema = HdCubeSchema::GetFromParent(prim.dataSource);
        if (cubeSchema) {
            std::cout << entry.primPath << "\t" << "is Cube" << std::endl;
        }

        UsdPhysicsImagingCollisionSchema collisionSchema =
                UsdPhysicsImagingCollisionSchema::GetFromParent(prim.dataSource);
        if (collisionSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << std::endl;
            std::cout << "CollisionEnabled: \t" << collisionSchema.GetCollisionEnabled()->GetTypedValue(0) << std::endl;
        }

        UsdPhysicsImagingSceneSchema sceneSchema = UsdPhysicsImagingSceneSchema::GetFromParent(prim.dataSource);
        if (sceneSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << std::endl;
            std::cout << "GravityMagnitude: \t" << sceneSchema.GetGravityMagnitude()->GetTypedValue(0) << std::endl;
            auto dir = sceneSchema.GetGravityDirection()->GetTypedValue(0);
            std::cout << "GravityDir: \t" << dir[0] << "\t" << dir[1] << "\t" << dir[2] << std::endl;
        }

        HdDistanceJointSchema distanceJointSchema = HdDistanceJointSchema::GetFromParent(prim.dataSource);
        if (distanceJointSchema) {
            std::cout << entry.primPath << "\t" << entry.primType << std::endl;
            std::cout << "MinDistance: \t" << distanceJointSchema.GetMinDistance()->GetTypedValue(0) << std::endl;
            std::cout << "MaxDistance: \t" << distanceJointSchema.GetMaxDistance()->GetTypedValue(0) << std::endl;
            std::cout << "BreakForce: \t" << distanceJointSchema.GetBreakForce()->GetTypedValue(0) << std::endl;
            std::cout << "BreakTorque: \t" << distanceJointSchema.GetBreakTorque()->GetTypedValue(0) << std::endl;
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

PXR_NAMESPACE_CLOSE_SCOPE
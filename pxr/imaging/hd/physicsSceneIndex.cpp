//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hd/physicsSceneIndex.h"
#include "pxr/imaging/hd/physicsSchema.h"
#include "pxr/imaging/hd/meshSchema.h"
#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

HdPhysicsSceneIndexRefPtr HdPhysicsSceneIndex::New(const HdSceneIndexBaseRefPtr &inputSceneIndex) {
    return TfCreateRefPtr(new HdPhysicsSceneIndex(inputSceneIndex));
}

HdPhysicsSceneIndex::HdPhysicsSceneIndex(const HdSceneIndexBaseRefPtr &inputSceneIndex)
    : HdSingleInputFilteringSceneIndexBase(inputSceneIndex) {}

void HdPhysicsSceneIndex::_PrimsAdded(const HdSceneIndexBase &sender,
                                        const HdSceneIndexObserver::AddedPrimEntries &entries) {
    if (!_IsObserved()) {
        return;
    }

    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        HdPhysicsSchema physicsSchema = HdPhysicsSchema::GetFromParent(prim.dataSource);
        HdMeshSchema meshSchema = HdMeshSchema::GetFromParent(prim.dataSource);
        if (physicsSchema && meshSchema) {
            std::cout << "Density: \t" << physicsSchema.GetDensity()->GetTypedValue(0) << std::endl;
            std::cout << "Restitution: \t" << physicsSchema.GetRestitution()->GetTypedValue(0) << std::endl;
            std::cout << "DynamicFriction: \t" << physicsSchema.GetDynamicFriction()->GetTypedValue(0) << std::endl;
            std::cout << "StaticFriction: \t" << physicsSchema.GetStaticFriction()->GetTypedValue(0) << std::endl;
        }
    }
    _SendPrimsAdded(entries);
}

void HdPhysicsSceneIndex::_PrimsRemoved(const HdSceneIndexBase &sender,
                                          const HdSceneIndexObserver::RemovedPrimEntries &entries) {
    _SendPrimsRemoved(entries);
}

void HdPhysicsSceneIndex::_PrimsDirtied(const HdSceneIndexBase &sender,
                                          const HdSceneIndexObserver::DirtiedPrimEntries &entries) {
    _SendPrimsDirtied(entries);
}

HdSceneIndexPrim HdPhysicsSceneIndex::GetPrim(const SdfPath &primPath) const {
    HdSceneIndexPrim prim = _GetInputSceneIndex()->GetPrim(primPath);
    return prim;
}

SdfPathVector HdPhysicsSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

PXR_NAMESPACE_CLOSE_SCOPE
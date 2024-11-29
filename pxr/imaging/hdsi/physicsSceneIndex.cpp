//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hdsi/physicsSceneIndex.h"

PXR_NAMESPACE_OPEN_SCOPE

HdsiPhysicsSceneIndexRefPtr HdsiPhysicsSceneIndex::New(const HdSceneIndexBaseRefPtr &inputSceneIndex) {
    return TfCreateRefPtr(new HdsiPhysicsSceneIndex(inputSceneIndex));
}

HdsiPhysicsSceneIndex::HdsiPhysicsSceneIndex(const HdSceneIndexBaseRefPtr &inputSceneIndex)
    : HdSingleInputFilteringSceneIndexBase(inputSceneIndex) {}

void HdsiPhysicsSceneIndex::_PrimsAdded(const HdSceneIndexBase &sender,
                                        const HdSceneIndexObserver::AddedPrimEntries &entries) {}

void HdsiPhysicsSceneIndex::_PrimsRemoved(const HdSceneIndexBase &sender,
                                          const HdSceneIndexObserver::RemovedPrimEntries &entries) {}

void HdsiPhysicsSceneIndex::_PrimsDirtied(const HdSceneIndexBase &sender,
                                          const HdSceneIndexObserver::DirtiedPrimEntries &entries) {}

HdSceneIndexPrim HdsiPhysicsSceneIndex::GetPrim(const SdfPath &primPath) const {
    HdSceneIndexPrim prim = _GetInputSceneIndex()->GetPrim(primPath);
    return prim;
}

SdfPathVector HdsiPhysicsSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

PXR_NAMESPACE_CLOSE_SCOPE
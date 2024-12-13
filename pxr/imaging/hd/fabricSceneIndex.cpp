//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hd/fabricSceneIndex.h"
#include "pxr/imaging/hd/fabric.h"

PXR_NAMESPACE_OPEN_SCOPE

FabricSceneIndexRefPtr FabricSceneIndex::New(const HdSceneIndexBaseRefPtr &inputSceneIndex, Fabric &fabric) {
    return TfCreateRefPtr(new FabricSceneIndex(inputSceneIndex, fabric));
}

FabricSceneIndex::FabricSceneIndex(const HdSceneIndexBaseRefPtr &inputSceneIndex, Fabric &fabric)
    : HdSingleInputFilteringSceneIndexBase(inputSceneIndex), _fabric{fabric} {}

void FabricSceneIndex::_PrimsAdded(const HdSceneIndexBase &sender,
                                   const HdSceneIndexObserver::AddedPrimEntries &entries) {
    if (!_IsObserved()) {
        return;
    }
    for (const HdSceneIndexObserver::AddedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        _fabric.PrimsAdded(prim, entry);
    }

    _SendPrimsAdded(entries);
}

void FabricSceneIndex::_PrimsRemoved(const HdSceneIndexBase &sender,
                                     const HdSceneIndexObserver::RemovedPrimEntries &entries) {
    for (const HdSceneIndexObserver::RemovedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        _fabric.PrimsRemoved(prim, entry);
    }
    _SendPrimsRemoved(entries);
}

void FabricSceneIndex::_PrimsDirtied(const HdSceneIndexBase &sender,
                                     const HdSceneIndexObserver::DirtiedPrimEntries &entries) {
    for (const HdSceneIndexObserver::DirtiedPrimEntry &entry : entries) {
        auto prim = _GetInputSceneIndex()->GetPrim(entry.primPath);
        _fabric.PrimsDirtied(prim, entry);
    }
    _SendPrimsDirtied(entries);
    _SendPrimsDirtied(_fabric.dirtyEntries());
    _fabric.dirtyEntries().clear();
}

HdSceneIndexPrim FabricSceneIndex::GetPrim(const SdfPath &primPath) const {
    HdSceneIndexPrim sceneIndexPrim = this->_GetInputSceneIndex()->GetPrim(primPath);
    return sceneIndexPrim;
}

SdfPathVector FabricSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

PXR_NAMESPACE_CLOSE_SCOPE
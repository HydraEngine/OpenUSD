//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usd/sdf/pathTable.h>
#include <pxr/imaging/fabric/materialSchema.h>

PXR_NAMESPACE_OPEN_SCOPE

class Fabric {
public:
    void PrimsAdded(const HdSceneIndexObserver::AddedPrimEntries &entries);

    void PrimsRemoved(const HdSceneIndexObserver::RemovedPrimEntries &entries);

    void PrimsDirtied(const HdSceneIndexObserver::DirtiedPrimEntries &entries);

private:
    SdfPathTable<HdSceneIndexPrim> _materialPrims;
};

PXR_NAMESPACE_CLOSE_SCOPE
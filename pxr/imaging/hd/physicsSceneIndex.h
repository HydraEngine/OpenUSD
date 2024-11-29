//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/pxr.h>
#include <pxr/imaging/hd/api.h>
#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usdImaging/usdImaging/stageSceneIndex.h>
#include "pxr/imaging/hd/physicsSchema.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DECLARE_REF_PTRS(HdPhysicsSceneIndex);

class HdPhysicsSceneIndex : public HdSingleInputFilteringSceneIndexBase {
public:
    HD_API
    static HdPhysicsSceneIndexRefPtr New(const HdSceneIndexBaseRefPtr &inputSceneIndex);

    HD_API
    HdSceneIndexPrim GetPrim(const SdfPath &primPath) const override;
    HD_API
    SdfPathVector GetChildPrimPaths(const SdfPath &primPath) const override;

protected:
    HdPhysicsSceneIndex(const HdSceneIndexBaseRefPtr &inputSceneIndex);

    void _PrimsAdded(const HdSceneIndexBase &sender, const HdSceneIndexObserver::AddedPrimEntries &entries) override;

    void _PrimsRemoved(const HdSceneIndexBase &sender,
                       const HdSceneIndexObserver::RemovedPrimEntries &entries) override;

    void _PrimsDirtied(const HdSceneIndexBase &sender,
                       const HdSceneIndexObserver::DirtiedPrimEntries &entries) override;
};

PXR_NAMESPACE_CLOSE_SCOPE
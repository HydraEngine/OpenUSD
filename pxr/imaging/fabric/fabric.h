//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usd/sdf/pathTable.h>

PXR_NAMESPACE_OPEN_SCOPE

class FabricMaterialSchema;

class Fabric {
public:
    void PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry &entry);

    void PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry &entry);

    void PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry &entry);

private:
    std::map<SdfPath, FabricMaterialSchema> _materials;
};

PXR_NAMESPACE_CLOSE_SCOPE
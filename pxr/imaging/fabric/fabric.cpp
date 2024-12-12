//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/fabric/fabric.h"
#include <pxr/imaging/fabric/materialSchema.h>

PXR_NAMESPACE_OPEN_SCOPE

void Fabric::PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry &entry) {
    FabricMaterialSchema materialSchema = FabricMaterialSchema::GetFromParent(prim.dataSource);
    if (materialSchema) {
        _materials.insert({entry.primPath, materialSchema});
    }

}

void Fabric::PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry &entry) {

}

void Fabric::PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry &entry) {

}

PXR_NAMESPACE_CLOSE_SCOPE
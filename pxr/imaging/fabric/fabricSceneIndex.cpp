//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/fabric/fabricSceneIndex.h"
#include "pxr/imaging/fabric/fabric.h"

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

#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/primvarsSchema.h"
#include <pxr/imaging/hd/tokens.h>
#include <iostream>

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
    _fabric.PrimsAdded(entries);
    _SendPrimsAdded(entries);
}

void FabricSceneIndex::_PrimsRemoved(const HdSceneIndexBase &sender,
                                     const HdSceneIndexObserver::RemovedPrimEntries &entries) {
    _fabric.PrimsRemoved(entries);
    _SendPrimsRemoved(entries);
}

void FabricSceneIndex::_PrimsDirtied(const HdSceneIndexBase &sender,
                                     const HdSceneIndexObserver::DirtiedPrimEntries &entries) {
    _fabric.PrimsDirtied(entries);
    _SendPrimsDirtied(entries);
}

HdSceneIndexPrim FabricSceneIndex::GetPrim(const SdfPath &primPath) const {
    HdSceneIndexPrim sceneIndexPrim = this->_GetInputSceneIndex()->GetPrim(primPath);
    return sceneIndexPrim;
}

SdfPathVector FabricSceneIndex::GetChildPrimPaths(const SdfPath &primPath) const {
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

PXR_NAMESPACE_CLOSE_SCOPE
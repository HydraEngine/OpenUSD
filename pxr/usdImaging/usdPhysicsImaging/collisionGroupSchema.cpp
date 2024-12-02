//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/collisionGroupSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdStringDataSourceHandle UsdPhysicsImagingCollisionGroupSchema::GetMergeGroupName() const {
    return _GetTypedDataSource<HdStringDataSource>(UsdPhysicsTokens->physicsMergeGroup);
}
HdBoolDataSourceHandle UsdPhysicsImagingCollisionGroupSchema::GetInvertFilteredGroups() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsInvertFilteredGroups);
}
HdPathArrayDataSourceHandle UsdPhysicsImagingCollisionGroupSchema::GetFilteredGroups() const {
    return _GetTypedDataSource<HdPathArrayDataSource>(UsdPhysicsTokens->physicsFilteredGroups);
}

UsdPhysicsImagingCollisionGroupSchema UsdPhysicsImagingCollisionGroupSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingCollisionGroupSchema(
            fromParentContainer
                    ? HdContainerDataSource::Cast(fromParentContainer->Get(HdPhysicsSchemaTokens->physicsScene))
                    : nullptr);
}

const TfToken &UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsScene; }

const HdDataSourceLocator &UsdPhysicsImagingCollisionGroupSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingCollisionGroupSchema::GetMergeGroupNameLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsMergeGroup);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingCollisionGroupSchema::GetInvertFilteredGroupsLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsInvertFilteredGroups);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingCollisionGroupSchema::GetFilteredGroupsLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsFilteredGroups);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
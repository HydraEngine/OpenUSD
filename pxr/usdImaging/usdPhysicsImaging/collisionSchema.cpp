//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/collisionSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdBoolDataSourceHandle UsdPhysicsImagingCollisionSchema::GetCollisionEnabled() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsCollisionEnabled);
}

HdPathArrayDataSourceHandle UsdPhysicsImagingCollisionSchema::GetSimulationOwner() const {
    return _GetTypedDataSource<HdPathArrayDataSource>(UsdPhysicsTokens->physicsSimulationOwner);
}

UsdPhysicsImagingCollisionSchema UsdPhysicsImagingCollisionSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingCollisionSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                          HdPhysicsSchemaTokens->physicsCollision))
                                                                : nullptr);
}

const TfToken &UsdPhysicsImagingCollisionSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsCollision; }

const HdDataSourceLocator &UsdPhysicsImagingCollisionSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingCollisionSchema::GetCollisionEnabledLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingCollisionSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsCollisionEnabled);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingCollisionSchema::GetSimulationOwnerLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingCollisionSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsSimulationOwner);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
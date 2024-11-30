//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physicsSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPhysicsSchemaTokens, HD_PHYSICS_SCHEMA_TOKENS);

HdFloatDataSourceHandle UsdImagingPhysicsSchema::GetDensity() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->density);
}

HdFloatDataSourceHandle UsdImagingPhysicsSchema::GetRestitution() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->restitution);
}

HdFloatDataSourceHandle UsdImagingPhysicsSchema::GetDynamicFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->dynamicFriction);
}

HdFloatDataSourceHandle UsdImagingPhysicsSchema::GetStaticFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->staticFriction);
}

HdFloatDataSourceHandle UsdImagingPhysicsSchema::GetGravityMagnitude() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->gravityMagnitude);
}

HdVec3fDataSourceHandle UsdImagingPhysicsSchema::GetGravityDirection() const {
    return _GetTypedDataSource<HdVec3fDataSource>(HdPhysicsSchemaTokens->gravityDirection);
}

UsdImagingPhysicsSchema UsdImagingPhysicsSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdImagingPhysicsSchema(
            fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(HdPhysicsSchemaTokens->physics))
                                : nullptr);
}

const TfToken &UsdImagingPhysicsSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physics; }

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetDensityLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->density);
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetRestitutionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->restitution);
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetDynamicFrictionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->dynamicFriction);
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetStaticFrictionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->staticFriction);
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetGravityMagnitudeLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->gravityMagnitude);
    return locator;
}

const HdDataSourceLocator &UsdImagingPhysicsSchema::GetGravityDirectionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->gravityDirection);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
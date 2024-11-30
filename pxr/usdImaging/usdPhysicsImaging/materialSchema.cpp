//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/materialSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetDensity() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->density);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetRestitution() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->restitution);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetDynamicFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->dynamicFriction);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetStaticFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->staticFriction);
}

UsdPhysicsImagingMaterialSchema UsdPhysicsImagingMaterialSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingMaterialSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                         HdPhysicsSchemaTokens->physicsMaterial))
                                                               : nullptr);
}

const TfToken &UsdPhysicsImagingMaterialSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsMaterial; }

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDensityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->density);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetRestitutionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->restitution);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDynamicFrictionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->dynamicFriction);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetStaticFrictionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->staticFriction);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
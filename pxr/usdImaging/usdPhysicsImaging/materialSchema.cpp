//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/materialSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetDensity() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsDensity);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetRestitution() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsRestitution);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetDynamicFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsDynamicFriction);
}

HdFloatDataSourceHandle UsdPhysicsImagingMaterialSchema::GetStaticFriction() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsStaticFriction);
}

UsdPhysicsImagingMaterialSchema UsdPhysicsImagingMaterialSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingMaterialSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                         UsdPhysicsTokens->PhysicsMaterialAPI))
                                                               : nullptr);
}

const TfToken &UsdPhysicsImagingMaterialSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsMaterialAPI; }

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDensityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsDensity);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetRestitutionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsRestitution);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetDynamicFrictionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsDynamicFriction);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMaterialSchema::GetStaticFrictionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMaterialSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsStaticFriction);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
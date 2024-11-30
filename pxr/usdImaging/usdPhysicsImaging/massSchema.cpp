//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/massSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingMassSchema UsdPhysicsImagingMassSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingMassSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                     HdPhysicsSchemaTokens->physicsMass))
                                                           : nullptr);
}

HdFloatDataSourceHandle UsdPhysicsImagingMassSchema::GetMass() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsMass);
}
HdFloatDataSourceHandle UsdPhysicsImagingMassSchema::GetDensity() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsDensity);
}
HdVec3fDataSourceHandle UsdPhysicsImagingMassSchema::GetCenterOfMass() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsCenterOfMass);
}
HdVec3fDataSourceHandle UsdPhysicsImagingMassSchema::GetDiagonalInertia() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsDiagonalInertia);
}
HdQuatfDataSourceHandle UsdPhysicsImagingMassSchema::GetPrincipalAxes() const {
    return _GetTypedDataSource<HdQuatfDataSource>(UsdPhysicsTokens->physicsPrincipalAxes);
}

const TfToken &UsdPhysicsImagingMassSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsMass; }

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetMassLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMassSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsMass);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetDensityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMassSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsDensity);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetCenterOfMassLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMassSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsCenterOfMass);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetDiagonalInertiaLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMassSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsDiagonalInertia);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMassSchema::GetPrincipalAxesLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMassSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsPrincipalAxes);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
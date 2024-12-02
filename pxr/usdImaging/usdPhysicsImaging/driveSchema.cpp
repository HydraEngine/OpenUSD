//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/driveSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingDriveSchema UsdPhysicsImagingDriveSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingDriveSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                      UsdPhysicsTokens->PhysicsDriveAPI))
                                                            : nullptr);
}

HdTokenDataSourceHandle UsdPhysicsImagingDriveSchema::GetType() const {
    return _GetTypedDataSource<HdTokenDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsType);
}
HdFloatDataSourceHandle UsdPhysicsImagingDriveSchema::GetMaxForce() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsType);
}
HdFloatDataSourceHandle UsdPhysicsImagingDriveSchema::GetTargetPosition() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsTargetPosition);
}
HdFloatDataSourceHandle UsdPhysicsImagingDriveSchema::GetTargetVelocity() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsTargetVelocity);
}
HdFloatDataSourceHandle UsdPhysicsImagingDriveSchema::GetDamping() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsDamping);
}
HdFloatDataSourceHandle UsdPhysicsImagingDriveSchema::GetStiffness() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsStiffness);
}

const TfToken &UsdPhysicsImagingDriveSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsDriveAPI; }

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetTypeLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsType);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetMaxForceLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsMaxForce);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetTargetPositionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsTargetPosition);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetTargetVelocityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsTargetVelocity);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetDampingLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsDamping);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingDriveSchema::GetStiffnessLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingDriveSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->drive_MultipleApplyTemplate_PhysicsStiffness);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/rigidBodySchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingRigidBodySchema UsdPhysicsImagingRigidBodySchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingRigidBodySchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                      HdPhysicsSchemaTokens->physicsRigidBody))
                                                            : nullptr);
}

HdFloatDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetLow() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsLow);
}

HdFloatDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetHigh() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsHigh);
}

const TfToken &UsdPhysicsImagingRigidBodySchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsLimit; }

const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetLowLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsLow);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetHighLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsHigh);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
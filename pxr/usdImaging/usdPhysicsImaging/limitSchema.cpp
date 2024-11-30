//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/limitSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingLimitSchema UsdPhysicsImagingLimitSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingLimitSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                      HdPhysicsSchemaTokens->physicsLimit))
                                                            : nullptr);
}

HdFloatDataSourceHandle UsdPhysicsImagingLimitSchema::GetLow() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsLow);
}

HdFloatDataSourceHandle UsdPhysicsImagingLimitSchema::GetHigh() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsHigh);
}

const TfToken &UsdPhysicsImagingLimitSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsLimit; }

const HdDataSourceLocator &UsdPhysicsImagingLimitSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingLimitSchema::GetLowLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingLimitSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsLow);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingLimitSchema::GetHighLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingLimitSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->limit_MultipleApplyTemplate_PhysicsHigh);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
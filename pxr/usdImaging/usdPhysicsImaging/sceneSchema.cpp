//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/sceneSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdFloatDataSourceHandle UsdPhysicsImagingSceneSchema::GetGravityMagnitude() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->gravityMagnitude);
}

HdVec3fDataSourceHandle UsdPhysicsImagingSceneSchema::GetGravityDirection() const {
    return _GetTypedDataSource<HdVec3fDataSource>(HdPhysicsSchemaTokens->gravityDirection);
}

UsdPhysicsImagingSceneSchema UsdPhysicsImagingSceneSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingSceneSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                      HdPhysicsSchemaTokens->physicsScene))
                                                            : nullptr);
}

const TfToken &UsdPhysicsImagingSceneSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsScene; }

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetGravityMagnitudeLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingSceneSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->gravityMagnitude);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetGravityDirectionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingSceneSchema::GetSchemaToken(),
                                             HdPhysicsSchemaTokens->gravityDirection);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/sceneSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdFloatDataSourceHandle UsdPhysicsImagingSceneSchema::GetGravityMagnitude() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsGravityMagnitude);
}

HdVec3fDataSourceHandle UsdPhysicsImagingSceneSchema::GetGravityDirection() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsGravityDirection);
}

UsdPhysicsImagingSceneSchema UsdPhysicsImagingSceneSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingSceneSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                      UsdPhysicsTokens->PhysicsScene))
                                                            : nullptr);
}

const TfToken &UsdPhysicsImagingSceneSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsScene; }

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetGravityMagnitudeLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingSceneSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsGravityMagnitude);
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingSceneSchema::GetGravityDirectionLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingSceneSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsGravityDirection);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
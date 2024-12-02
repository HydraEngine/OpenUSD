//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/meshCollisionSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingMeshCollisionSchema UsdPhysicsImagingMeshCollisionSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingMeshCollisionSchema(
            fromParentContainer
                    ? HdContainerDataSource::Cast(fromParentContainer->Get(UsdPhysicsTokens->PhysicsMeshCollisionAPI))
                    : nullptr);
}

HdTokenDataSourceHandle UsdPhysicsImagingMeshCollisionSchema::GetApproximation() const {
    return _GetTypedDataSource<HdTokenDataSource>(UsdPhysicsTokens->physicsApproximation);
}

const TfToken &UsdPhysicsImagingMeshCollisionSchema::GetSchemaToken() {
    return UsdPhysicsTokens->PhysicsMeshCollisionAPI;
}

const HdDataSourceLocator &UsdPhysicsImagingMeshCollisionSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingMeshCollisionSchema::GetApproximationLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingMeshCollisionSchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsApproximation);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
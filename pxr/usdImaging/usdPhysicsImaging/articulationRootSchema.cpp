//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/articulationRootSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingArticulationRootSchema UsdPhysicsImagingArticulationRootSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingArticulationRootSchema(fromParentContainer
                                                           ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                     UsdPhysicsTokens->PhysicsArticulationRootAPI))
                                                           : nullptr);
}

const TfToken &UsdPhysicsImagingArticulationRootSchema::GetSchemaToken() {
    return UsdPhysicsTokens->PhysicsArticulationRootAPI;
}

const HdDataSourceLocator &UsdPhysicsImagingArticulationRootSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
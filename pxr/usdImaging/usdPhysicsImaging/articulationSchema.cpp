//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/articulationSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingArticulationSchema UsdPhysicsImagingArticulationSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingArticulationSchema(
            fromParentContainer
                    ? HdContainerDataSource::Cast(fromParentContainer->Get(HdPhysicsSchemaTokens->physicsArticulaiton))
                    : nullptr);
}

const TfToken &UsdPhysicsImagingArticulationSchema::GetSchemaToken() {
    return HdPhysicsSchemaTokens->physicsArticulaiton;
}

const HdDataSourceLocator &UsdPhysicsImagingArticulationSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
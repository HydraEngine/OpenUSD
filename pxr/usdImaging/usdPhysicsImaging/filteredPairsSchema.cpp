//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/filteredPairsSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingFilteredPairsSchema UsdPhysicsImagingFilteredPairsSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingFilteredPairsSchema(
            fromParentContainer
                    ? HdContainerDataSource::Cast(fromParentContainer->Get(HdPhysicsSchemaTokens->physicsFilteredPairs))
                    : nullptr);
}

const TfToken &UsdPhysicsImagingFilteredPairsSchema::GetSchemaToken() {
    return HdPhysicsSchemaTokens->physicsFilteredPairs;
}

const HdDataSourceLocator &UsdPhysicsImagingFilteredPairsSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
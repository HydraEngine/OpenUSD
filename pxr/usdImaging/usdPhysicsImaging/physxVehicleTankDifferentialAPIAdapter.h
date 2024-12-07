//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdImaging/apiSchemaAdapter.h"
#include "api.h"

PXR_NAMESPACE_OPEN_SCOPE

class UsdImagingPhysicsPhysXVehicleTankDifferentialAPIAdapter : public UsdImagingAPISchemaAdapter {
public:
    using BaseAdapter = UsdImagingAPISchemaAdapter;

    USDPHYSICSIMAGING_API
    HdContainerDataSourceHandle GetImagingSubprimData(UsdPrim const& prim,
                                                      TfToken const& subprim,
                                                      TfToken const& appliedInstanceName,
                                                      const UsdImagingDataSourceStageGlobals& stageGlobals) override;

    USDPHYSICSIMAGING_API
    HdDataSourceLocatorSet InvalidateImagingSubprim(UsdPrim const& prim,
                                                    TfToken const& subprim,
                                                    TfToken const& appliedInstanceName,
                                                    TfTokenVector const& properties,
                                                    UsdImagingPropertyInvalidationType invalidationType) override;
};

PXR_NAMESPACE_CLOSE_SCOPE

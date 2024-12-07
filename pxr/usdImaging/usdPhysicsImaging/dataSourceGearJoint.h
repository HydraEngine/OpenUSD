//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"

#include "pxr/usd/usdPhysX/physicsGearJoint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourceGearJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourceGearJoint final : public UsdImagingDataSourceJoint {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceGearJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceGearJoint(const SdfPath &sceneIndexPath,
                                  UsdPhysXPhysicsGearJoint usdJoint,
                                      const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    UsdPhysXPhysicsGearJoint _usdGearJoint;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceGearJoint);

/// \class UsdImagingDataSourceGearJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourceGearJointPrim final : public UsdImagingDataSourceJointPrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceGearJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceGearJointPrim(const SdfPath &sceneIndexPath,
                                          UsdPrim usdPrim,
                                          const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceGearJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

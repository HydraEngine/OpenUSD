//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"

#include "pxr/usd/usdPhysX/physicsRackAndPinionJoint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourceRackAndPinionJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourceRackAndPinionJoint final : public UsdImagingDataSourceJoint {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceRackAndPinionJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceRackAndPinionJoint(const SdfPath &sceneIndexPath,
                                  UsdPhysXPhysicsRackAndPinionJoint usdJoint,
                                      const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    UsdPhysXPhysicsRackAndPinionJoint _usdRackAndPinionJoint;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceRackAndPinionJoint);

/// \class UsdImagingDataSourceRackAndPinionJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourceRackAndPinionJointPrim final : public UsdImagingDataSourceJointPrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceRackAndPinionJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceRackAndPinionJointPrim(const SdfPath &sceneIndexPath,
                                          UsdPrim usdPrim,
                                          const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceRackAndPinionJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"

#include "pxr/usd/usdPhysics/sphericalJoint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourceSphericalJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourceSphericalJoint final : public UsdImagingDataSourceJoint {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceSphericalJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceSphericalJoint(const SdfPath &sceneIndexPath,
                                      UsdPhysicsSphericalJoint usdJoint,
                                      const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    UsdPhysicsSphericalJoint _usdSphericalJoint;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceSphericalJoint);

/// \class UsdImagingDataSourceSphericalJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourceSphericalJointPrim final : public UsdImagingDataSourceJointPrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceSphericalJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceSphericalJointPrim(const SdfPath &sceneIndexPath,
                                          UsdPrim usdPrim,
                                          const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceSphericalJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

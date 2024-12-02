//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"

#include "pxr/usd/usdPhysics/revoluteJoint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourceRevoluteJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourceRevoluteJoint final : public UsdImagingDataSourceJoint {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceRevoluteJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceRevoluteJoint(const SdfPath &sceneIndexPath,
                                      UsdPhysicsRevoluteJoint usdJoint,
                                      const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    UsdPhysicsRevoluteJoint _usdRevoluteJoint;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceRevoluteJoint);

/// \class UsdImagingDataSourceRevoluteJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourceRevoluteJointPrim final : public UsdImagingDataSourceJointPrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceRevoluteJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceRevoluteJointPrim(const SdfPath &sceneIndexPath,
                                          UsdPrim usdPrim,
                                          const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceRevoluteJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

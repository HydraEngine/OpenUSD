//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdImaging/dataSourcePrim.h"
#include "pxr/usdImaging/usdImaging/dataSourceStageGlobals.h"

#include "pxr/usd/usdPhysics/joint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourceJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourceJoint : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

protected:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceJoint(const SdfPath &sceneIndexPath,
                              UsdPhysicsJoint usdJoint,
                              const UsdImagingDataSourceStageGlobals &stageGlobals);

protected:
    const SdfPath _sceneIndexPath;
    UsdPhysicsJoint _usdJoint;
    const UsdImagingDataSourceStageGlobals &_stageGlobals;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceJoint);

/// \class UsdImagingDataSourceJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourceJointPrim : public UsdImagingDataSourcePrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourceJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

protected:
    // Private constructor, use static New() instead.
    UsdImagingDataSourceJointPrim(const SdfPath &sceneIndexPath,
                                  UsdPrim usdPrim,
                                  const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourceJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

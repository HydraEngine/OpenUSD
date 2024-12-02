//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"

#include "pxr/usd/usdPhysics/prismaticJoint.h"

#include "pxr/imaging/hd/dataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingDataSourcePrismaticJoint
///
/// A container data source representing camera info
///
class UsdImagingDataSourcePrismaticJoint final : public UsdImagingDataSourceJoint {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourcePrismaticJoint);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourcePrismaticJoint(const SdfPath &sceneIndexPath,
                                      UsdPhysicsPrismaticJoint usdJoint,
                                      const UsdImagingDataSourceStageGlobals &stageGlobals);

private:
    UsdPhysicsPrismaticJoint _usdPrismaticJoint;
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourcePrismaticJoint);

/// \class UsdImagingDataSourcePrismaticJointPrim
///
/// A prim data source representing UsdJoint.
///
class UsdImagingDataSourcePrismaticJointPrim final : public UsdImagingDataSourceJointPrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourcePrismaticJointPrim);

    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken &name) override;

    static HdDataSourceLocatorSet Invalidate(UsdPrim const &prim,
                                             const TfToken &subprim,
                                             const TfTokenVector &properties,
                                             UsdImagingPropertyInvalidationType invalidationType);

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourcePrismaticJointPrim(const SdfPath &sceneIndexPath,
                                          UsdPrim usdPrim,
                                          const UsdImagingDataSourceStageGlobals &stageGlobals);
};

HD_DECLARE_DATASOURCE_HANDLES(UsdImagingDataSourcePrismaticJointPrim);

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/dataSource.h>
#include <pxr/imaging/hd/dataSourceTypeDefs.h>
#include <pxr/imaging/hd/sceneIndex.h>

#include "api.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

/// \class HdPhysXDataSource
///
/// A datasource representing a wrapped view of an existing flattened
/// data source where the xform token is intercepted and a new geospatial
/// matrix dynamically calculated.
///
class HdPhysXDataSource : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(HdPhysXDataSource);

    HdPhysXDataSource(HdSceneIndexBaseRefPtr sceneIndex,
                      SdfPath primPath,
                      HdContainerDataSourceHandle wrappedDataSource);

    void UpdateWrappedDataSource(HdContainerDataSourceHandle wrappedDataSource);

    // data source overrides
    TfTokenVector GetNames() override;
    HdDataSourceBaseHandle Get(const TfToken& name) override;

private:
    HdSceneIndexBaseRefPtr _sceneIndex;
    SdfPath _primPath;
    HdContainerDataSourceHandle _wrappedDataSource;
};

HD_DECLARE_DATASOURCE_HANDLES(HdPhysXDataSource);

PXR_NAMESPACE_CLOSE_SCOPE
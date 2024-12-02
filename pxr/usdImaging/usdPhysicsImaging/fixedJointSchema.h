//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/imaging/hd/api.h"
#include "pxr/imaging/hd/schemaTypeDefs.h"

#include "pxr/usdImaging/usdPhysicsImaging/jointSchema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

class HdFixedJointSchema : public HdJointSchema {
public:
    /// \name Schema retrieval
    /// @{

    HdFixedJointSchema(HdContainerDataSourceHandle container) : HdJointSchema(container) {}

    /// Retrieves a container data source with the schema's default name token
    /// "camera" from the parent container and constructs a
    /// HdJointSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    HD_API
    static HdFixedJointSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

    /// @}


    /// \name Schema location
    /// @{

    /// Returns a token where the container representing this schema is found in
    /// a container by default.
    HD_API
    static const TfToken &GetSchemaToken();

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the container representing this schema is found by default.
    HD_API static const HdDataSourceLocator &GetDefaultLocator();
    /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE
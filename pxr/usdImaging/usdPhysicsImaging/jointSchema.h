//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/imaging/hd/api.h"
#include "pxr/imaging/hd/schemaTypeDefs.h"

#include "pxr/imaging/hd/schema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

class HdJointSchema : public HdSchema {
public:
    /// \name Schema retrieval
    /// @{

    HdJointSchema(HdContainerDataSourceHandle container) : HdSchema(container) {}

    /// Retrieves a container data source with the schema's default name token
    /// "camera" from the parent container and constructs a
    /// HdJointSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    HD_API
    static HdJointSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

    /// @}

    // --(BEGIN CUSTOM CODE: Schema Methods)--
    // --(END CUSTOM CODE: Schema Methods)--

    /// \name Member accessor
    /// @{

    HD_API [[nodiscard]] HdVec3fDataSourceHandle GetLocalPos0() const;
    HD_API [[nodiscard]] HdVec3fDataSourceHandle GetLocalRot0() const;
    HD_API [[nodiscard]] HdVec3fDataSourceHandle GetLocalPos1() const;
    HD_API [[nodiscard]] HdVec3fDataSourceHandle GetLocalRot1() const;
    HD_API [[nodiscard]] HdBoolDataSourceHandle GetJointEnabled() const;
    HD_API [[nodiscard]] HdBoolDataSourceHandle GetCollisionEnabled() const;
    HD_API [[nodiscard]] HdBoolDataSourceHandle GetExcludeFromArticulation() const;
    HD_API [[nodiscard]] HdFloatDataSourceHandle GetBreakForce() const;
    HD_API [[nodiscard]] HdFloatDataSourceHandle GetBreakTorque() const;
    HD_API [[nodiscard]] HdPathArrayDataSourceHandle GetBody0() const;
    HD_API [[nodiscard]] HdPathArrayDataSourceHandle GetBody1() const;

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

    HD_API static const HdDataSourceLocator &GetLocalPos0Locator();
    HD_API static const HdDataSourceLocator &GetLocalRot0Locator();
    HD_API static const HdDataSourceLocator &GetLocalPos1Locator();
    HD_API static const HdDataSourceLocator &GetLocalRot1Locator();
    HD_API static const HdDataSourceLocator &GetJointEnabledLocator();
    HD_API static const HdDataSourceLocator &GetCollisionEnabledLocator();
    HD_API static const HdDataSourceLocator &GetExcludeFromArticulationLocator();
    HD_API static const HdDataSourceLocator &GetBreakForceLocator();
    HD_API static const HdDataSourceLocator &GetBreakTorqueLocator();
    HD_API static const HdDataSourceLocator &GetBody0Locator();
    HD_API static const HdDataSourceLocator &GetBody1Locator();
    /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE
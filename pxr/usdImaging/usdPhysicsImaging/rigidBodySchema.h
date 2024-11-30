//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <utility>

#include "pxr/usdImaging/usdPhysicsImaging/api.h"

#include "pxr/imaging/hd/schema.h"

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

class UsdPhysicsImagingRigidBodySchema : public HdSchema {
public:
    /// \name Schema retrieval
    /// @{

    UsdPhysicsImagingRigidBodySchema(HdContainerDataSourceHandle container) : HdSchema(std::move(container)) {}

    [[nodiscard]] USDPHYSICSIMAGING_API HdBoolDataSourceHandle GetRigidBodyEnabled() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdBoolDataSourceHandle GetKinematicEnabled() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdBoolDataSourceHandle GetStartsAsleep() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdVec3fDataSourceHandle GetVelocity() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdVec3fDataSourceHandle GetAngularVelocity() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdPathArrayDataSourceHandle GetSimulationOwner() const;

    /// Retrieves a container data source with the schema's default name token
    /// "light" from the parent container and constructs a
    /// HdLightSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    USDPHYSICSIMAGING_API
    static UsdPhysicsImagingRigidBodySchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

    /// Returns a token where the container representing this schema is found in
    /// a container by default.
    USDPHYSICSIMAGING_API
    static const TfToken &GetSchemaToken();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDefaultLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetRigidBodyEnabledLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetKinematicEnabledLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetStartsAsleepLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetVelocityLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetAngularVelocityLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetSimulationOwnerLocator();
};

PXR_NAMESPACE_CLOSE_SCOPE
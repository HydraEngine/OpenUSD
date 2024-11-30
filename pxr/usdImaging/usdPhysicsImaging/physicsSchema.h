//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <utility>

#include "pxr/usdImaging/usdPhysicsImaging/api.h"

#include "pxr/imaging/hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--
// --(END CUSTOM CODE: Declares)--

#define HD_PHYSICS_SCHEMA_TOKENS \
    (physics)(density)(restitution)(dynamicFriction)(staticFriction)(gravityMagnitude)(gravityDirection)

TF_DECLARE_PUBLIC_TOKENS(HdPhysicsSchemaTokens, USDPHYSICSIMAGING_API, HD_PHYSICS_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class UsdImagingPhysicsSchema : public HdSchema {
public:
    /// \name Schema retrieval
    /// @{

    UsdImagingPhysicsSchema(HdContainerDataSourceHandle container) : HdSchema(std::move(container)) {}

    // ACCESSORS

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetDensity() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetRestitution() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetDynamicFriction() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetStaticFriction() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetGravityMagnitude() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdVec3fDataSourceHandle GetGravityDirection() const;

    /// Retrieves a container data source with the schema's default name token
    /// "light" from the parent container and constructs a
    /// HdLightSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    USDPHYSICSIMAGING_API
    static UsdImagingPhysicsSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

    /// Returns a token where the container representing this schema is found in
    /// a container by default.
    USDPHYSICSIMAGING_API
    static const TfToken &GetSchemaToken();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDefaultLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDensityLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetRestitutionLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDynamicFrictionLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetStaticFrictionLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetGravityMagnitudeLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetGravityDirectionLocator();
};

PXR_NAMESPACE_CLOSE_SCOPE
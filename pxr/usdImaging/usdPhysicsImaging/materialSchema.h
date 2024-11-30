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

//-----------------------------------------------------------------------------

class UsdPhysicsImagingMaterialSchema : public HdSchema {
public:
    /// \name Schema retrieval
    /// @{

    UsdPhysicsImagingMaterialSchema(HdContainerDataSourceHandle container) : HdSchema(std::move(container)) {}

    // ACCESSORS

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetDensity() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetRestitution() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetDynamicFriction() const;

    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetStaticFriction() const;

    /// Retrieves a container data source with the schema's default name token
    /// "light" from the parent container and constructs a
    /// HdLightSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    USDPHYSICSIMAGING_API
    static UsdPhysicsImagingMaterialSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

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
};

PXR_NAMESPACE_CLOSE_SCOPE
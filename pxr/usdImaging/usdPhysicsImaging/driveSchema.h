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

class UsdPhysicsImagingDriveSchema : public HdSchema {
public:
    /// \name Schema retrieval
    /// @{

    UsdPhysicsImagingDriveSchema(HdContainerDataSourceHandle container) : HdSchema(std::move(container)) {}

    [[nodiscard]] USDPHYSICSIMAGING_API HdTokenDataSourceHandle GetType() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetMaxForce() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetTargetPosition() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetTargetVelocity() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetDamping() const;
    [[nodiscard]] USDPHYSICSIMAGING_API HdFloatDataSourceHandle GetStiffness() const;

    /// Retrieves a container data source with the schema's default name token
    /// "light" from the parent container and constructs a
    /// HdLightSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    USDPHYSICSIMAGING_API
    static UsdPhysicsImagingDriveSchema GetFromParent(const HdContainerDataSourceHandle &fromParentContainer);

    /// Returns a token where the container representing this schema is found in
    /// a container by default.
    USDPHYSICSIMAGING_API
    static const TfToken &GetSchemaToken();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDefaultLocator();

    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetTypeLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetMaxForceLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetTargetPositionLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetTargetVelocityLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetDampingLocator();
    USDPHYSICSIMAGING_API
    static const HdDataSourceLocator &GetStiffnessLocator();
};

PXR_NAMESPACE_CLOSE_SCOPE
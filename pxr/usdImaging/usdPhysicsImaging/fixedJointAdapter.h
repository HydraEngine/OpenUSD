//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/pxr.h"
#include "pxr/usdImaging/usdPhysicsImaging/jointAdapter.h"

PXR_NAMESPACE_OPEN_SCOPE

/// \class UsdImagingPhysicsFixedJointAdapter
///
/// Adapter support for UsdPhysicsFixedJoint for *only* the scene index (2.0) API.
///
/// \note For the legacy (UsdImagingDelegate and associated prim adapter API)
///       scenario, UsdImagingRenderSettingsAdapter handles the flattening of
///       products and vars.
///
class  UsdImagingPhysicsFixedJointAdapter: public UsdImagingPhysicsJointAdapter {
public:
    using BaseAdapter = UsdImagingPrimAdapter;

    UsdImagingPhysicsFixedJointAdapter() : UsdImagingPhysicsJointAdapter() {}

    USDPHYSICSIMAGING_API
    ~UsdImagingPhysicsFixedJointAdapter() override;

    // ---------------------------------------------------------------------- //
    /// \name Scene Index Support
    // ---------------------------------------------------------------------- //

    USDPHYSICSIMAGING_API
    TfTokenVector GetImagingSubprims(UsdPrim const& prim) override;

    USDPHYSICSIMAGING_API
    TfToken GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) override;

    USDPHYSICSIMAGING_API
    HdContainerDataSourceHandle GetImagingSubprimData(UsdPrim const& prim,
                                                      TfToken const& subprim,
                                                      const UsdImagingDataSourceStageGlobals& stageGlobals) override;

    USDPHYSICSIMAGING_API
    HdDataSourceLocatorSet InvalidateImagingSubprim(UsdPrim const& prim,
                                                    TfToken const& subprim,
                                                    TfTokenVector const& properties,
                                                    UsdImagingPropertyInvalidationType invalidationType) override;

    // ---------------------------------------------------------------------- //
    /// \name Initialization
    // ---------------------------------------------------------------------- //

    USDPHYSICSIMAGING_API
    SdfPath Populate(UsdPrim const& prim,
                     UsdImagingIndexProxy* index,
                     UsdImagingInstancerContext const* instancerContext = nullptr) override;

    USDPHYSICSIMAGING_API
    bool IsSupported(UsdImagingIndexProxy const* index) const override;

    // ---------------------------------------------------------------------- //
    /// \name Parallel Setup and Resolve
    // ---------------------------------------------------------------------- //

    /// Thread Safe.
    USDPHYSICSIMAGING_API
    void TrackVariability(UsdPrim const& prim,
                          SdfPath const& cachePath,
                          HdDirtyBits* timeVaryingBits,
                          UsdImagingInstancerContext const* instancerContext = nullptr) const override;

    /// Thread Safe.
    USDPHYSICSIMAGING_API
    void UpdateForTime(UsdPrim const& prim,
                       SdfPath const& cachePath,
                       UsdTimeCode time,
                       HdDirtyBits requestedBits,
                       UsdImagingInstancerContext const* instancerContext = nullptr) const override;

    // ---------------------------------------------------------------------- //
    /// \name Change Processing
    // ---------------------------------------------------------------------- //

    /// Returns a bit mask of attributes to be udpated, or
    /// HdChangeTracker::AllDirty if the entire prim must be resynchronized.
    USDPHYSICSIMAGING_API
    HdDirtyBits ProcessPropertyChange(UsdPrim const& prim,
                                      SdfPath const& cachePath,
                                      TfToken const& propertyName) override;

    USDPHYSICSIMAGING_API
    void MarkDirty(UsdPrim const& prim,
                   SdfPath const& cachePath,
                   HdDirtyBits dirty,
                   UsdImagingIndexProxy* index) override;

    // ---------------------------------------------------------------------- //
    /// \name Data access
    // ---------------------------------------------------------------------- //

    USDPHYSICSIMAGING_API
    VtValue Get(UsdPrim const& prim,
                SdfPath const& cachePath,
                TfToken const& key,
                UsdTimeCode time,
                VtIntArray* outIndices) const override;

protected:
    USDPHYSICSIMAGING_API
    void _RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) override;
};

PXR_NAMESPACE_CLOSE_SCOPE
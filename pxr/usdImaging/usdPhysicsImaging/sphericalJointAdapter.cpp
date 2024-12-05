//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/sphericalJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourceSphericalJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/usdImaging/usdPhysicsImaging/sphericalJointSchema.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysics/sphericalJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsSphericalJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsSphericalJointAdapter::~UsdImagingPhysicsSphericalJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsSphericalJointAdapter::GetImagingSubprims(UsdPrim const& prim) {
    return UsdImagingPhysicsJointAdapter::GetImagingSubprims(prim);
}

TfToken UsdImagingPhysicsSphericalJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return UsdPhysicsImagingSphericalJointSchemaTokens->sphericalJoint;
    }
    return UsdImagingPhysicsJointAdapter::GetImagingSubprimType(prim, subprim);
}

HdContainerDataSourceHandle UsdImagingPhysicsSphericalJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceSphericalJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return UsdImagingPhysicsJointAdapter::GetImagingSubprimData(prim, subprim, stageGlobals);
}

HdDataSourceLocatorSet UsdImagingPhysicsSphericalJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceSphericalJointPrim::Invalidate(prim, subprim, properties, invalidationType);
    }

    return UsdImagingPhysicsJointAdapter::InvalidateImagingSubprim(prim, subprim, properties, invalidationType);
}

// -------------------------------------------------------------------------- //
// 1.0 Prim adapter API
//
// \note No hydra prims are added/managed for UsdPhysicsJoint prims.
//       UsdImagingRenderSettingsAdapter handles the flattening of
//       targeted products and vars.
// -------------------------------------------------------------------------- //

bool UsdImagingPhysicsSphericalJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsSphericalJointAdapter::Populate(UsdPrim const& prim,
                                                         UsdImagingIndexProxy* index,
                                                         UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsSphericalJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsSphericalJointAdapter::TrackVariability(
        UsdPrim const& prim,
        SdfPath const& cachePath,
        HdDirtyBits* timeVaryingBits,
        UsdImagingInstancerContext const* instancerContext) const {}

void UsdImagingPhysicsSphericalJointAdapter::UpdateForTime(UsdPrim const& prim,
                                                           SdfPath const& cachePath,
                                                           UsdTimeCode time,
                                                           HdDirtyBits requestedBits,
                                                           UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsSphericalJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                          SdfPath const& cachePath,
                                                                          TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsSphericalJointAdapter::MarkDirty(UsdPrim const& prim,
                                                       SdfPath const& cachePath,
                                                       HdDirtyBits dirty,
                                                       UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsSphericalJointAdapter::Get(UsdPrim const& prim,
                                                    SdfPath const& cachePath,
                                                    TfToken const& key,
                                                    UsdTimeCode time,
                                                    VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

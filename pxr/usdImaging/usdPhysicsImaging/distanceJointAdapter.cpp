//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/distanceJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourceDistanceJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/imaging/hd/distanceJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysics/distanceJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsDistanceJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsDistanceJointAdapter::~UsdImagingPhysicsDistanceJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsDistanceJointAdapter::GetImagingSubprims(UsdPrim const& prim) {
    return UsdImagingPhysicsJointAdapter::GetImagingSubprims(prim);
}

TfToken UsdImagingPhysicsDistanceJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdDistanceJointSchemaTokens->distanceJoint;
    }
    return UsdImagingPhysicsJointAdapter::GetImagingSubprimType(prim, subprim);
}

HdContainerDataSourceHandle UsdImagingPhysicsDistanceJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceDistanceJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return UsdImagingPhysicsJointAdapter::GetImagingSubprimData(prim, subprim, stageGlobals);
}

HdDataSourceLocatorSet UsdImagingPhysicsDistanceJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceDistanceJointPrim::Invalidate(prim, subprim, properties, invalidationType);
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

bool UsdImagingPhysicsDistanceJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsDistanceJointAdapter::Populate(UsdPrim const& prim,
                                                        UsdImagingIndexProxy* index,
                                                        UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsDistanceJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsDistanceJointAdapter::TrackVariability(UsdPrim const& prim,
                                                             SdfPath const& cachePath,
                                                             HdDirtyBits* timeVaryingBits,
                                                             UsdImagingInstancerContext const* instancerContext) const {
}

void UsdImagingPhysicsDistanceJointAdapter::UpdateForTime(UsdPrim const& prim,
                                                          SdfPath const& cachePath,
                                                          UsdTimeCode time,
                                                          HdDirtyBits requestedBits,
                                                          UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsDistanceJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                         SdfPath const& cachePath,
                                                                         TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsDistanceJointAdapter::MarkDirty(UsdPrim const& prim,
                                                      SdfPath const& cachePath,
                                                      HdDirtyBits dirty,
                                                      UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsDistanceJointAdapter::Get(UsdPrim const& prim,
                                                   SdfPath const& cachePath,
                                                   TfToken const& key,
                                                   UsdTimeCode time,
                                                   VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

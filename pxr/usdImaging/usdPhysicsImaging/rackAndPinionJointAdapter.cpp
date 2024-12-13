//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/rackAndPinionJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourceRackAndPinionJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/imaging/hd/physxPhysicsRackAndPinionJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysX/physicsRackAndPinionJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsRackAndPinionJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsRackAndPinionJointAdapter::~UsdImagingPhysicsRackAndPinionJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsRackAndPinionJointAdapter::GetImagingSubprims(UsdPrim const& prim) {
    return UsdImagingPhysicsJointAdapter::GetImagingSubprims(prim);
}

TfToken UsdImagingPhysicsRackAndPinionJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdPhysxPhysicsRackAndPinionJointSchemaTokens->physxPhysicsRackAndPinionJoint;
    }
    return UsdImagingPhysicsJointAdapter::GetImagingSubprimType(prim, subprim);
}

HdContainerDataSourceHandle UsdImagingPhysicsRackAndPinionJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceRackAndPinionJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return UsdImagingPhysicsJointAdapter::GetImagingSubprimData(prim, subprim, stageGlobals);
}

HdDataSourceLocatorSet UsdImagingPhysicsRackAndPinionJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceRackAndPinionJointPrim::Invalidate(prim, subprim, properties, invalidationType);
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

bool UsdImagingPhysicsRackAndPinionJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsRackAndPinionJointAdapter::Populate(UsdPrim const& prim,
                                                             UsdImagingIndexProxy* index,
                                                             UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsRackAndPinionJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsRackAndPinionJointAdapter::TrackVariability(
        UsdPrim const& prim,
        SdfPath const& cachePath,
        HdDirtyBits* timeVaryingBits,
        UsdImagingInstancerContext const* instancerContext) const {}

void UsdImagingPhysicsRackAndPinionJointAdapter::UpdateForTime(
        UsdPrim const& prim,
        SdfPath const& cachePath,
        UsdTimeCode time,
        HdDirtyBits requestedBits,
        UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsRackAndPinionJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                              SdfPath const& cachePath,
                                                                              TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsRackAndPinionJointAdapter::MarkDirty(UsdPrim const& prim,
                                                           SdfPath const& cachePath,
                                                           HdDirtyBits dirty,
                                                           UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsRackAndPinionJointAdapter::Get(UsdPrim const& prim,
                                                        SdfPath const& cachePath,
                                                        TfToken const& key,
                                                        UsdTimeCode time,
                                                        VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

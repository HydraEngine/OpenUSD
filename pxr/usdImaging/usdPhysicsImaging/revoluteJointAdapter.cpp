//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/revoluteJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourceRevoluteJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/imaging/hd/revoluteJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysics/revoluteJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsRevoluteJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsRevoluteJointAdapter::~UsdImagingPhysicsRevoluteJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsRevoluteJointAdapter::GetImagingSubprims(UsdPrim const& prim) {
    return UsdImagingPhysicsJointAdapter::GetImagingSubprims(prim);
}

TfToken UsdImagingPhysicsRevoluteJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdRevoluteJointSchemaTokens->revoluteJoint;
    }
    return UsdImagingPhysicsJointAdapter::GetImagingSubprimType(prim, subprim);
}

HdContainerDataSourceHandle UsdImagingPhysicsRevoluteJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceRevoluteJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return UsdImagingPhysicsJointAdapter::GetImagingSubprimData(prim, subprim, stageGlobals);
}

HdDataSourceLocatorSet UsdImagingPhysicsRevoluteJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceRevoluteJointPrim::Invalidate(prim, subprim, properties, invalidationType);
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

bool UsdImagingPhysicsRevoluteJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsRevoluteJointAdapter::Populate(UsdPrim const& prim,
                                                        UsdImagingIndexProxy* index,
                                                        UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsRevoluteJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsRevoluteJointAdapter::TrackVariability(UsdPrim const& prim,
                                                             SdfPath const& cachePath,
                                                             HdDirtyBits* timeVaryingBits,
                                                             UsdImagingInstancerContext const* instancerContext) const {
}

void UsdImagingPhysicsRevoluteJointAdapter::UpdateForTime(UsdPrim const& prim,
                                                          SdfPath const& cachePath,
                                                          UsdTimeCode time,
                                                          HdDirtyBits requestedBits,
                                                          UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsRevoluteJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                         SdfPath const& cachePath,
                                                                         TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsRevoluteJointAdapter::MarkDirty(UsdPrim const& prim,
                                                      SdfPath const& cachePath,
                                                      HdDirtyBits dirty,
                                                      UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsRevoluteJointAdapter::Get(UsdPrim const& prim,
                                                   SdfPath const& cachePath,
                                                   TfToken const& key,
                                                   UsdTimeCode time,
                                                   VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

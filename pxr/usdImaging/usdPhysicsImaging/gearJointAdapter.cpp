//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/gearJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourceGearJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/usdImaging/usdPhysicsImaging/physxPhysicsGearJointSchema.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysX/physicsGearJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsGearJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsGearJointAdapter::~UsdImagingPhysicsGearJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsGearJointAdapter::GetImagingSubprims(UsdPrim const& prim) {
    return UsdImagingPhysicsJointAdapter::GetImagingSubprims(prim);
}

TfToken UsdImagingPhysicsGearJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return UsdPhysicsImagingPhysxPhysicsGearJointSchemaTokens->physxPhysicsGearJoint;
    }
    return UsdImagingPhysicsJointAdapter::GetImagingSubprimType(prim, subprim);
}

HdContainerDataSourceHandle UsdImagingPhysicsGearJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceGearJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return UsdImagingPhysicsJointAdapter::GetImagingSubprimData(prim, subprim, stageGlobals);
}

HdDataSourceLocatorSet UsdImagingPhysicsGearJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourceGearJointPrim::Invalidate(prim, subprim, properties, invalidationType);
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

bool UsdImagingPhysicsGearJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsGearJointAdapter::Populate(UsdPrim const& prim,
                                                    UsdImagingIndexProxy* index,
                                                    UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsGearJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsGearJointAdapter::TrackVariability(UsdPrim const& prim,
                                                         SdfPath const& cachePath,
                                                         HdDirtyBits* timeVaryingBits,
                                                         UsdImagingInstancerContext const* instancerContext) const {}

void UsdImagingPhysicsGearJointAdapter::UpdateForTime(UsdPrim const& prim,
                                                      SdfPath const& cachePath,
                                                      UsdTimeCode time,
                                                      HdDirtyBits requestedBits,
                                                      UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsGearJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                     SdfPath const& cachePath,
                                                                     TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsGearJointAdapter::MarkDirty(UsdPrim const& prim,
                                                  SdfPath const& cachePath,
                                                  HdDirtyBits dirty,
                                                  UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsGearJointAdapter::Get(UsdPrim const& prim,
                                               SdfPath const& cachePath,
                                               TfToken const& key,
                                               UsdTimeCode time,
                                               VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

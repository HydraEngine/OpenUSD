//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/prismaticJointAdapter.h"
#include "pxr/usdImaging/usdPhysicsImaging/dataSourcePrismaticJoint.h"

#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/usdImaging/usdPhysicsImaging/prismaticJointSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysics/prismaticJoint.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsPrismaticJointAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

UsdImagingPhysicsPrismaticJointAdapter::~UsdImagingPhysicsPrismaticJointAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsPrismaticJointAdapter::GetImagingSubprims(UsdPrim const& prim) { return {TfToken()}; }

TfToken UsdImagingPhysicsPrismaticJointAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdPhysicsSchemaTokens->physicsPrismaticJoint;
    }
    return TfToken();
}

HdContainerDataSourceHandle UsdImagingPhysicsPrismaticJointAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePrismaticJointPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPrismaticJointAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePrismaticJointPrim::Invalidate(prim, subprim, properties, invalidationType);
    }

    return HdDataSourceLocatorSet();
}

// -------------------------------------------------------------------------- //
// 1.0 Prim adapter API
//
// \note No hydra prims are added/managed for UsdPhysicsJoint prims.
//       UsdImagingRenderSettingsAdapter handles the flattening of
//       targeted products and vars.
// -------------------------------------------------------------------------- //

bool UsdImagingPhysicsPrismaticJointAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsPrismaticJointAdapter::Populate(UsdPrim const& prim,
                                                        UsdImagingIndexProxy* index,
                                                        UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsPrismaticJointAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsPrismaticJointAdapter::TrackVariability(UsdPrim const& prim,
                                                             SdfPath const& cachePath,
                                                             HdDirtyBits* timeVaryingBits,
                                                             UsdImagingInstancerContext const* instancerContext) const {
}

void UsdImagingPhysicsPrismaticJointAdapter::UpdateForTime(UsdPrim const& prim,
                                                          SdfPath const& cachePath,
                                                          UsdTimeCode time,
                                                          HdDirtyBits requestedBits,
                                                          UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsPrismaticJointAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                         SdfPath const& cachePath,
                                                                         TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsPrismaticJointAdapter::MarkDirty(UsdPrim const& prim,
                                                      SdfPath const& cachePath,
                                                      HdDirtyBits dirty,
                                                      UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsPrismaticJointAdapter::Get(UsdPrim const& prim,
                                                   SdfPath const& cachePath,
                                                   TfToken const& key,
                                                   UsdTimeCode time,
                                                   VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

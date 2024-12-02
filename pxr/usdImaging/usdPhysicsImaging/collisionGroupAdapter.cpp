//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/collisionGroupAdapter.h"

#include "pxr/base/pegtl/pegtl/ascii.hpp"
#include "pxr/usdImaging/usdImaging/dataSourceRenderPrims.h"
#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/usdImaging/usdPhysicsImaging/collisionGroupSchema.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/usd/usdPhysics/collisionGroup.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsCollisionGroupAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

namespace {
///
/// A container data source representing render product info.
///
class _DataSourcePhysicsCollisionGroup : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_DataSourcePhysicsCollisionGroup);

    static const TfTokenVector& GetPropertyNames() {
        static const TfTokenVector names = {
                UsdPhysicsTokens->physicsGravityDirection,  //
                UsdPhysicsTokens->physicsGravityMagnitude   //
        };

        return names;
    }

    TfTokenVector GetNames() override { return GetPropertyNames(); }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsTokens->physicsMergeGroup) {
            if (UsdAttribute attr = _usdPhysicsCollisionGroup.GetMergeGroupNameAttr()) {
                std::string v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<std::string>::New(v);
                }
            }
        }

        if (name == UsdPhysicsTokens->physicsInvertFilteredGroups) {
            if (UsdAttribute attr = _usdPhysicsCollisionGroup.GetInvertFilteredGroupsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        }

        if (name == UsdPhysicsTokens->physicsFilteredGroups) {
            if (UsdRelationship rel = _usdPhysicsCollisionGroup.GetFilteredGroupsRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        }

        return nullptr;
    }

private:
    // Private constructor, use static New() instead.
    _DataSourcePhysicsCollisionGroup(const SdfPath& sceneIndexPath,
                                     UsdPhysicsCollisionGroup usdPhysicsCollisionGroup,
                                     const UsdImagingDataSourceStageGlobals& stageGlobals)
        : _sceneIndexPath(sceneIndexPath),
          _usdPhysicsCollisionGroup(usdPhysicsCollisionGroup),
          _stageGlobals(stageGlobals) {}

private:
    const SdfPath _sceneIndexPath;
    UsdPhysicsCollisionGroup _usdPhysicsCollisionGroup;
    const UsdImagingDataSourceStageGlobals& _stageGlobals;
};

HD_DECLARE_DATASOURCE_HANDLES(_DataSourcePhysicsCollisionGroup);

/// \class UsdImagingDataSourcePhysicsCollisionGroupPrim
///
/// A prim data source representing UsdPhysicsCollisionGroup.
///
class UsdImagingDataSourcePhysicsCollisionGroupPrim : public UsdImagingDataSourcePrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourcePhysicsCollisionGroupPrim);

    USDIMAGING_API
    TfTokenVector GetNames() override {
        // Note: Skip properties on UsdImagingDataSourcePrim.
        return {UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken()};
    }

    USDIMAGING_API
    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingCollisionGroupSchema::GetSchemaToken()) {
            return _DataSourcePhysicsCollisionGroup::New(_GetSceneIndexPath(), UsdPhysicsCollisionGroup(_GetUsdPrim()),
                                                         _GetStageGlobals());
        }

        // Note: Skip properties on UsdImagingDataSourcePrim.
        return nullptr;
    }

    USDIMAGING_API
    static HdDataSourceLocatorSet Invalidate(UsdPrim const& prim,
                                             const TfToken& subprim,
                                             const TfTokenVector& properties,
                                             UsdImagingPropertyInvalidationType invalidationType) {
        TRACE_FUNCTION();

        const TfTokenVector& names = _DataSourcePhysicsCollisionGroup::GetPropertyNames();
        static TfToken::HashSet tokensSet(names.begin(), names.end());

        HdDataSourceLocatorSet locators;

        for (const TfToken& propertyName : properties) {
            if (tokensSet.find(propertyName) != tokensSet.end()) {
                locators.insert(UsdPhysicsImagingCollisionGroupSchema::GetDefaultLocator().Append(propertyName));
            }
        }

        return locators;
    }

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourcePhysicsCollisionGroupPrim(const SdfPath& sceneIndexPath,
                                                  UsdPrim usdPrim,
                                                  const UsdImagingDataSourceStageGlobals& stageGlobals)
        : UsdImagingDataSourcePrim(sceneIndexPath, usdPrim, stageGlobals) {}
};
}  // namespace

UsdImagingPhysicsCollisionGroupAdapter::~UsdImagingPhysicsCollisionGroupAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsCollisionGroupAdapter::GetImagingSubprims(UsdPrim const& prim) { return {TfToken()}; }

TfToken UsdImagingPhysicsCollisionGroupAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdPhysicsSchemaTokens->physicsCollisionGroup;
    }
    return TfToken();
}

HdContainerDataSourceHandle UsdImagingPhysicsCollisionGroupAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePhysicsCollisionGroupPrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsCollisionGroupAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePhysicsCollisionGroupPrim::Invalidate(prim, subprim, properties, invalidationType);
    }

    return HdDataSourceLocatorSet();
}

// -------------------------------------------------------------------------- //
// 1.0 Prim adapter API
//
// \note No hydra prims are added/managed for UsdPhysicsCollisionGroup prims.
//       UsdImagingRenderSettingsAdapter handles the flattening of
//       targeted products and vars.
// -------------------------------------------------------------------------- //

bool UsdImagingPhysicsCollisionGroupAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsCollisionGroupAdapter::Populate(UsdPrim const& prim,
                                                         UsdImagingIndexProxy* index,
                                                         UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsCollisionGroupAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsCollisionGroupAdapter::TrackVariability(
        UsdPrim const& prim,
        SdfPath const& cachePath,
        HdDirtyBits* timeVaryingBits,
        UsdImagingInstancerContext const* instancerContext) const {}

void UsdImagingPhysicsCollisionGroupAdapter::UpdateForTime(UsdPrim const& prim,
                                                           SdfPath const& cachePath,
                                                           UsdTimeCode time,
                                                           HdDirtyBits requestedBits,
                                                           UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsCollisionGroupAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                          SdfPath const& cachePath,
                                                                          TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsCollisionGroupAdapter::MarkDirty(UsdPrim const& prim,
                                                       SdfPath const& cachePath,
                                                       HdDirtyBits dirty,
                                                       UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsCollisionGroupAdapter::Get(UsdPrim const& prim,
                                                    SdfPath const& cachePath,
                                                    TfToken const& key,
                                                    UsdTimeCode time,
                                                    VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

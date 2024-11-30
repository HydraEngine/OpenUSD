//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/sceneAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceRenderPrims.h"
#include "pxr/usdImaging/usdImaging/delegate.h"
#include "pxr/usdImaging/usdImaging/indexProxy.h"
#include "pxr/usdImaging/usdImaging/tokens.h"

#include "pxr/usd/usdRender/product.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    using Adapter = UsdImagingPhysicsSceneAdapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingPrimAdapterFactory<Adapter>>();
}

namespace {
inline TfTokenVector _Concat(const TfTokenVector& a, const TfTokenVector& b) {
    TfTokenVector result;
    result.reserve(a.size() + b.size());
    result.insert(result.end(), a.begin(), a.end());
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

///
/// A container data source representing render product info.
///
class _DataSourcePhysicsScene : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_DataSourcePhysicsScene);

    static const TfTokenVector& GetPropertyNames() {
        static TfTokenVector names = _Concat(
                UsdPhysicsScene::GetSchemaAttributeNames(
                        /* includeInherited = */ true),
                {UsdImagingUsdPhysicsSceneSchemaTokens->namespacedSettings,
                 // Relationships need to be explicitly specified.
                 UsdImagingUsdPhysicsSceneSchemaTokens->camera, UsdImagingUsdPhysicsSceneSchemaTokens->orderedVars});

        return names;
    }

    TfTokenVector GetNames() override { return GetPropertyNames(); }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdImagingUsdPhysicsSceneSchemaTokens->namespacedSettings) {
            VtDictionary settingsDict = _ComputeNamespacedSettings(_usdPhysicsScene.GetPrim());

            return _ToContainerDS(settingsDict);
        }

        if (name == UsdImagingUsdPhysicsSceneSchemaTokens->camera) {
            SdfPathVector targets;
            _usdPhysicsScene.GetCameraRel().GetForwardedTargets(&targets);
            if (!targets.empty()) {
                return HdRetainedTypedSampledDataSource<SdfPath>::New(targets[0]);
            }
            return nullptr;
        }

        if (name == UsdImagingUsdPhysicsSceneSchemaTokens->orderedVars) {
            SdfPathVector targets;
            _usdPhysicsScene.GetOrderedVarsRel().GetForwardedTargets(&targets);

            VtArray<SdfPath> vTargets(targets.begin(), targets.end());
            return HdRetainedTypedSampledDataSource<VtArray<SdfPath>>::New(vTargets);
        }

        if (UsdAttribute attr = _usdPhysicsScene.GetPrim().GetAttribute(name)) {
            // Only consider authored attributes in UsdRenderSettingsBase,
            // to allow the targeting render settings prim's opinion to be
            // inherited by the product via
            // UsdImagingRenderSettingsFlatteningSceneIndex.
            const TfTokenVector& settingsBaseTokens = UsdRenderSettingsBase::GetSchemaAttributeNames();
            static const TfToken::HashSet settingsBaseTokenSet(settingsBaseTokens.begin(), settingsBaseTokens.end());
            const bool attrInSettingsBase = settingsBaseTokenSet.find(name) != settingsBaseTokenSet.end();

            if (attrInSettingsBase && !attr.HasAuthoredValue()) {
                return nullptr;
            }

            return UsdImagingDataSourceAttributeNew(attr, _stageGlobals, _sceneIndexPath,
                                                    UsdImagingUsdPhysicsSceneSchema::GetDefaultLocator().Append(name));
        } else {
            TF_WARN("Unhandled attribute %s in _DataSourcePhysicsScene", name.GetText());
            return nullptr;
        }
    }

private:
    // Private constructor, use static New() instead.
    _DataSourcePhysicsScene(const SdfPath& sceneIndexPath,
                            UsdPhysicsScene usdPhysicsScene,
                            const UsdImagingDataSourceStageGlobals& stageGlobals)
        : _sceneIndexPath(sceneIndexPath), _usdPhysicsScene(usdPhysicsScene), _stageGlobals(stageGlobals) {}

private:
    const SdfPath _sceneIndexPath;
    UsdPhysicsScene _usdPhysicsScene;
    const UsdImagingDataSourceStageGlobals& _stageGlobals;
};

HD_DECLARE_DATASOURCE_HANDLES(_DataSourcePhysicsScene);

/// \class UsdImagingDataSourcePhysicsScenePrim
///
/// A prim data source representing UsdPhysicsScene.
///
class UsdImagingDataSourcePhysicsScenePrim : public UsdImagingDataSourcePrim {
public:
    HD_DECLARE_DATASOURCE(UsdImagingDataSourcePhysicsScenePrim);

    USDIMAGING_API
    TfTokenVector GetNames() override {
        // Note: Skip properties on UsdImagingDataSourcePrim.
        return {UsdImagingUsdPhysicsSceneSchema::GetSchemaToken()};
    }

    USDIMAGING_API
    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdImagingUsdPhysicsSceneSchema::GetSchemaToken()) {
            return _DataSourcePhysicsScene::New(_GetSceneIndexPath(), UsdPhysicsScene(_GetUsdPrim()),
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

        const TfTokenVector& names = _DataSourcePhysicsScene::GetPropertyNames();
        static TfToken::HashSet tokensSet(names.begin(), names.end());

        HdDataSourceLocatorSet locators;

        for (const TfToken& propertyName : properties) {
            if (tokensSet.find(propertyName) != tokensSet.end()) {
                locators.insert(UsdImagingUsdPhysicsSceneSchema::GetDefaultLocator().Append(propertyName));
            } else {
                // It is likely that the property is an attribute that's
                // aggregated under "namespaced settings". For performance, skip
                // validating whether that is the case.
                locators.insert(UsdImagingUsdPhysicsSceneSchema::GetNamespacedSettingsLocator());
            }
            // Note: Skip UsdImagingDataSourcePrim::Invalidate(...)
            // since none of the "base" set of properties are relevant here.
        }

        return locators;
    }

private:
    // Private constructor, use static New() instead.
    UsdImagingDataSourcePhysicsScenePrim(const SdfPath& sceneIndexPath,
                                         UsdPrim usdPrim,
                                         const UsdImagingDataSourceStageGlobals& stageGlobals)
        : UsdImagingDataSourcePrim(sceneIndexPath, usdPrim, stageGlobals) {}
};
}  // namespace

UsdImagingPhysicsSceneAdapter::~UsdImagingPhysicsSceneAdapter() = default;

// -------------------------------------------------------------------------- //
// 2.0 Prim adapter API
// -------------------------------------------------------------------------- //

TfTokenVector UsdImagingPhysicsSceneAdapter::GetImagingSubprims(UsdPrim const& prim) { return {TfToken()}; }

TfToken UsdImagingPhysicsSceneAdapter::GetImagingSubprimType(UsdPrim const& prim, TfToken const& subprim) {
    if (subprim.IsEmpty()) {
        return HdPhysicsSceneSchemaTokens->PhysicsScene;
    }
    return TfToken();
}

HdContainerDataSourceHandle UsdImagingPhysicsSceneAdapter::GetImagingSubprimData(
        UsdPrim const& prim, TfToken const& subprim, const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePhysicsScenePrim::New(prim.GetPath(), prim, stageGlobals);
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsSceneAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfTokenVector const& properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    if (subprim.IsEmpty()) {
        return UsdImagingDataSourcePhysicsScenePrim::Invalidate(prim, subprim, properties, invalidationType);
    }

    return HdDataSourceLocatorSet();
}

// -------------------------------------------------------------------------- //
// 1.0 Prim adapter API
//
// \note No hydra prims are added/managed for UsdPhysicsScene prims.
//       UsdImagingRenderSettingsAdapter handles the flattening of
//       targeted products and vars.
// -------------------------------------------------------------------------- //

bool UsdImagingPhysicsSceneAdapter::IsSupported(UsdImagingIndexProxy const* index) const {
    // Since we flatten products and vars into the targeting settings prim, 1.0
    // render delegates won't typically support render product prims as such.
    // Return true to supress warnings that the prim type isn't supported.
    return true;
}

SdfPath UsdImagingPhysicsSceneAdapter::Populate(UsdPrim const& prim,
                                                UsdImagingIndexProxy* index,
                                                UsdImagingInstancerContext const* instancerContext) {
    return SdfPath::EmptyPath();
}

void UsdImagingPhysicsSceneAdapter::_RemovePrim(SdfPath const& cachePath, UsdImagingIndexProxy* index) {}

void UsdImagingPhysicsSceneAdapter::TrackVariability(UsdPrim const& prim,
                                                     SdfPath const& cachePath,
                                                     HdDirtyBits* timeVaryingBits,
                                                     UsdImagingInstancerContext const* instancerContext) const {}

void UsdImagingPhysicsSceneAdapter::UpdateForTime(UsdPrim const& prim,
                                                  SdfPath const& cachePath,
                                                  UsdTimeCode time,
                                                  HdDirtyBits requestedBits,
                                                  UsdImagingInstancerContext const* instancerContext) const {}

HdDirtyBits UsdImagingPhysicsSceneAdapter::ProcessPropertyChange(UsdPrim const& prim,
                                                                 SdfPath const& cachePath,
                                                                 TfToken const& propertyName) {
    return HdChangeTracker::Clean;
}

void UsdImagingPhysicsSceneAdapter::MarkDirty(UsdPrim const& prim,
                                              SdfPath const& cachePath,
                                              HdDirtyBits dirty,
                                              UsdImagingIndexProxy* index) {}

VtValue UsdImagingPhysicsSceneAdapter::Get(UsdPrim const& prim,
                                           SdfPath const& cachePath,
                                           TfToken const& key,
                                           UsdTimeCode time,
                                           VtIntArray* outIndices) const {
    return VtValue();
}

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/filteredPairsAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/usdImaging/usdPhysicsImaging/filteredPairsSchema.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/usd/usdPhysics/filteredPairsAPI.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsFilteredPairsAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class _PhysicsFilteredPairsDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_PhysicsFilteredPairsDataSource);

    _PhysicsFilteredPairsDataSource(const UsdPrim& prim) : _api(prim) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                UsdPhysicsTokens->physicsFilteredPairs,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsTokens->physicsFilteredPairs) {
            if (UsdRelationship rel = _api.GetFilteredPairsRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        }
        return nullptr;
    }

private:
    UsdPhysicsFilteredPairsAPI _api;
};

}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsFilteredPairsAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsTokens->PhysicsFilteredPairsAPI,
                                                  _PhysicsFilteredPairsDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsFilteredPairsAPIAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        TfTokenVector const& properties,
        UsdImagingPropertyInvalidationType invalidationType) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return HdDataSourceLocatorSet();
    }

    HdDataSourceLocatorSet result;
    for (const TfToken& propertyName : properties) {
        if (TfStringStartsWith(propertyName.GetString(), "physics:")) {
            result.insert(UsdPhysicsImagingFilteredPairsSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
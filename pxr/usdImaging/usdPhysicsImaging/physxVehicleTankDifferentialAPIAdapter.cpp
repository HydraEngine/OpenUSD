//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleTankDifferentialAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleTankDifferentialSchema.h"
#include "pxr/usd/usdPhysX/vehicleTankDifferentialAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleTankDifferentialAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class PhysxDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(PhysxDataSource);

    explicit PhysxDataSource(const UsdPrim& prim) : _api(prim) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                HdPhysxVehicleTankDifferentialSchemaTokens->numberOfWheelsPerTrack,    //
                HdPhysxVehicleTankDifferentialSchemaTokens->thrustIndexPerTrack,       //
                HdPhysxVehicleTankDifferentialSchemaTokens->trackToWheelIndices,       //
                HdPhysxVehicleTankDifferentialSchemaTokens->wheelIndicesInTrackOrder,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleTankDifferentialSchemaTokens->numberOfWheelsPerTrack) {
            if (UsdAttribute attr = _api.GetNumberOfWheelsPerTrackAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleTankDifferentialSchemaTokens->thrustIndexPerTrack) {
            if (UsdAttribute attr = _api.GetThrustIndexPerTrackAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleTankDifferentialSchemaTokens->trackToWheelIndices) {
            if (UsdAttribute attr = _api.GetTrackToWheelIndicesAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleTankDifferentialSchemaTokens->wheelIndicesInTrackOrder) {
            if (UsdAttribute attr = _api.GetWheelIndicesInTrackOrderAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleTankDifferentialAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleTankDifferentialAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxVehicleTankDifferentialSchemaTokens->physxVehicleTankDifferential,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleTankDifferentialAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleTankDifferentialSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
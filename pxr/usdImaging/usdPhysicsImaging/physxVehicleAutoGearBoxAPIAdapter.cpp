//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAutoGearBoxAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAutoGearBoxSchema.h"
#include "pxr/usd/usdPhysX/vehicleAutoGearBoxAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleAutoGearBoxAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->downRatios,  //
                UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->latency,     //
                UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->upRatios,    //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->downRatios) {
            if (UsdAttribute attr = _api.GetDownRatiosAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->latency) {
            if (UsdAttribute attr = _api.GetLatencyAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->upRatios) {
            if (UsdAttribute attr = _api.GetUpRatiosAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleAutoGearBoxAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleAutoGearBoxAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxVehicleAutoGearBoxSchemaTokens->physxVehicleAutoGearBox,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleAutoGearBoxAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleAutoGearBoxSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
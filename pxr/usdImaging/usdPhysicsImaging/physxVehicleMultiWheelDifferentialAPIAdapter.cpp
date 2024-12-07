//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleMultiWheelDifferentialAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleMultiWheelDifferentialSchema.h"
#include "pxr/usd/usdPhysX/vehicleMultiWheelDifferentialAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleMultiWheelDifferentialAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->averageWheelSpeedRatios,  //
                UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->torqueRatios,             //
                UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->wheels,                   //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->averageWheelSpeedRatios) {
            if (UsdAttribute attr = _api.GetAverageWheelSpeedRatiosAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->torqueRatios) {
            if (UsdAttribute attr = _api.GetTorqueRatiosAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->wheels) {
            if (UsdAttribute attr = _api.GetWheelsAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleMultiWheelDifferentialAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleMultiWheelDifferentialAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchemaTokens->physxVehicleMultiWheelDifferential,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleMultiWheelDifferentialAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleMultiWheelDifferentialSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleBrakesAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleBrakesEntrySchema.h"
#include "pxr/usd/usdPhysX/vehicleBrakesAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleBrakesAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class PhysxDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(PhysxDataSource);

    explicit PhysxDataSource(const UsdPrim& prim, TfToken const& appliedInstanceName)
        : _api(prim, appliedInstanceName) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {HdPhysxVehicleBrakesSchemaTokens->maxBrakeTorque,     //
                                            HdPhysxVehicleBrakesSchemaTokens->torqueMultipliers,  //
                                            HdPhysxVehicleBrakesSchemaTokens->wheels,             //
                                            HdPhysxVehicleBrakesSchemaTokens->name};

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleBrakesSchemaTokens->maxBrakeTorque) {
            if (UsdAttribute attr = _api.GetMaxBrakeTorqueAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleBrakesSchemaTokens->torqueMultipliers) {
            if (UsdAttribute attr = _api.GetTorqueMultipliersAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleBrakesSchemaTokens->wheels) {
            if (UsdAttribute attr = _api.GetWheelsAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        }
        if (name == HdPhysxVehicleBrakesSchemaTokens->name) {
            return HdRetainedTypedSampledDataSource<TfToken>::New(_api.GetName());
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleBrakesAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleBrakesAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxVehicleBrakesEntrySchemaTokens->physxVehicleBrakesEntry,
                HdRetainedContainerDataSource::New(appliedInstanceName,
                                                   PhysxDataSource::New(prim, appliedInstanceName)));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleBrakesAPIAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        TfTokenVector const& properties,
        UsdImagingPropertyInvalidationType invalidationType) {
    if (appliedInstanceName.IsEmpty()) {
        return HdDataSourceLocatorSet();
    }

    HdDataSourceLocatorSet result;
    for (const TfToken& propertyName : properties) {
        if (TfStringStartsWith(propertyName.GetString(), "physics:")) {
            result.insert(HdPhysxVehicleBrakesSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleDriveBasicAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleDriveBasicSchema.h"
#include "pxr/usd/usdPhysX/vehicleDriveBasicAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleDriveBasicAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleDriveBasicSchemaTokens->peakTorque,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleDriveBasicSchemaTokens->peakTorque) {
            if (UsdAttribute attr = _api.GetPeakTorqueAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleDriveBasicAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleDriveBasicAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxVehicleDriveBasicSchemaTokens->physxVehicleDriveBasic,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleDriveBasicAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleDriveBasicSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAckermannSteeringAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAckermannSteeringSchema.h"
#include "pxr/usd/usdPhysX/vehicleAckermannSteeringAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleAckermannSteeringAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->maxSteerAngle,  //
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->strength,       //
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->trackWidth,     //
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheel0,         //
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheel1,         //
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheelBase,      //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->maxSteerAngle) {
            if (UsdAttribute attr = _api.GetMaxSteerAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->strength) {
            if (UsdAttribute attr = _api.GetStrengthAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->trackWidth) {
            if (UsdAttribute attr = _api.GetTrackWidthAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheel0) {
            if (UsdAttribute attr = _api.GetWheel0Attr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheel1) {
            if (UsdAttribute attr = _api.GetWheel1Attr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->wheelBase) {
            if (UsdAttribute attr = _api.GetWheelBaseAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleAckermannSteeringAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleAckermannSteeringAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxVehicleAckermannSteeringSchemaTokens->physxVehicleAckermannSteering,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleAckermannSteeringAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleAckermannSteeringSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
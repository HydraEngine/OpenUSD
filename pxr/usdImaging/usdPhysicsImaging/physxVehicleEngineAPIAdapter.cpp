//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleEngineAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleEngineSchema.h"
#include "pxr/usd/usdPhysX/vehicleEngineAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleEngineAPIAdapter Adapter;
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
                HdPhysxVehicleEngineSchemaTokens->dampingRateFullThrottle,                  //
                HdPhysxVehicleEngineSchemaTokens->dampingRateZeroThrottleClutchDisengaged,  //
                HdPhysxVehicleEngineSchemaTokens->dampingRateZeroThrottleClutchEngaged,     //
                HdPhysxVehicleEngineSchemaTokens->idleRotationSpeed,                        //
                HdPhysxVehicleEngineSchemaTokens->maxRotationSpeed,                         //
                HdPhysxVehicleEngineSchemaTokens->moi,                                      //
                HdPhysxVehicleEngineSchemaTokens->peakTorque,                               //
                HdPhysxVehicleEngineSchemaTokens->torqueCurve,                              //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleEngineSchemaTokens->dampingRateFullThrottle) {
            if (UsdAttribute attr = _api.GetDampingRateFullThrottleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->dampingRateZeroThrottleClutchDisengaged) {
            if (UsdAttribute attr = _api.GetDampingRateZeroThrottleClutchDisengagedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->dampingRateZeroThrottleClutchEngaged) {
            if (UsdAttribute attr = _api.GetDampingRateZeroThrottleClutchEngagedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->idleRotationSpeed) {
            if (UsdAttribute attr = _api.GetIdleRotationSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->maxRotationSpeed) {
            if (UsdAttribute attr = _api.GetMaxRotationSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->moi) {
            if (UsdAttribute attr = _api.GetMoiAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->peakTorque) {
            if (UsdAttribute attr = _api.GetPeakTorqueAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleEngineSchemaTokens->torqueCurve) {
            if (UsdAttribute attr = _api.GetTorqueCurveAttr()) {
                VtArray<GfVec2f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec2f>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleEngineAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleEngineAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdPhysxVehicleEngineSchemaTokens->physxVehicleEngine,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleEngineAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleEngineSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
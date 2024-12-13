//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleSchema.h"
#include "pxr/usd/usdPhysX/vehicleAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleAPIAdapter Adapter;
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
                HdPhysxVehicleSchemaTokens->highForwardSpeedSubStepCount,           //
                HdPhysxVehicleSchemaTokens->lateralStickyTireDamping,               //
                HdPhysxVehicleSchemaTokens->lateralStickyTireThresholdSpeed,        //
                HdPhysxVehicleSchemaTokens->lateralStickyTireThresholdTime,         //
                HdPhysxVehicleSchemaTokens->limitSuspensionExpansionVelocity,       //
                HdPhysxVehicleSchemaTokens->longitudinalStickyTireDamping,          //
                HdPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdSpeed,   //
                HdPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdTime,    //
                HdPhysxVehicleSchemaTokens->lowForwardSpeedSubStepCount,            //
                HdPhysxVehicleSchemaTokens->minActiveLongitudinalSlipDenominator,   //
                HdPhysxVehicleSchemaTokens->minLateralSlipDenominator,              //
                HdPhysxVehicleSchemaTokens->minPassiveLongitudinalSlipDenominator,  //
                HdPhysxVehicleSchemaTokens->subStepThresholdLongitudinalSpeed,      //
                HdPhysxVehicleSchemaTokens->suspensionLineQueryType,                //
                HdPhysxVehicleSchemaTokens->vehicleEnabled,                         //

        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleSchemaTokens->highForwardSpeedSubStepCount) {
            if (UsdAttribute attr = _api.GetHighForwardSpeedSubStepCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->lateralStickyTireDamping) {
            if (UsdAttribute attr = _api.GetLateralStickyTireDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->lateralStickyTireThresholdSpeed) {
            if (UsdAttribute attr = _api.GetLateralStickyTireThresholdSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->lateralStickyTireThresholdTime) {
            if (UsdAttribute attr = _api.GetLateralStickyTireThresholdTimeAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->limitSuspensionExpansionVelocity) {
            if (UsdAttribute attr = _api.GetLimitSuspensionExpansionVelocityAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->longitudinalStickyTireDamping) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdSpeed) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireThresholdSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdTime) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireThresholdTimeAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->lowForwardSpeedSubStepCount) {
            if (UsdAttribute attr = _api.GetLowForwardSpeedSubStepCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->minActiveLongitudinalSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinActiveLongitudinalSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->minLateralSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinLateralSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->minPassiveLongitudinalSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinPassiveLongitudinalSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->subStepThresholdLongitudinalSpeed) {
            if (UsdAttribute attr = _api.GetSubStepThresholdLongitudinalSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->suspensionLineQueryType) {
            if (UsdAttribute attr = _api.GetSuspensionLineQueryTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSchemaTokens->vehicleEnabled) {
            if (UsdAttribute attr = _api.GetVehicleEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdPhysxVehicleSchemaTokens->physxVehicle,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
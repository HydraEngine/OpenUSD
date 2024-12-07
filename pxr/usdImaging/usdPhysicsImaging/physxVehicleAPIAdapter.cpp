//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleSchema.h"
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
                UsdPhysicsImagingPhysxVehicleSchemaTokens->highForwardSpeedSubStepCount,           //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireDamping,               //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireThresholdSpeed,        //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireThresholdTime,         //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->limitSuspensionExpansionVelocity,       //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireDamping,          //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdSpeed,   //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdTime,    //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->lowForwardSpeedSubStepCount,            //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->minActiveLongitudinalSlipDenominator,   //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->minLateralSlipDenominator,              //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->minPassiveLongitudinalSlipDenominator,  //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->subStepThresholdLongitudinalSpeed,      //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->suspensionLineQueryType,                //
                UsdPhysicsImagingPhysxVehicleSchemaTokens->vehicleEnabled,                         //

        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->highForwardSpeedSubStepCount) {
            if (UsdAttribute attr = _api.GetHighForwardSpeedSubStepCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireDamping) {
            if (UsdAttribute attr = _api.GetLateralStickyTireDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireThresholdSpeed) {
            if (UsdAttribute attr = _api.GetLateralStickyTireThresholdSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->lateralStickyTireThresholdTime) {
            if (UsdAttribute attr = _api.GetLateralStickyTireThresholdTimeAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->limitSuspensionExpansionVelocity) {
            if (UsdAttribute attr = _api.GetLimitSuspensionExpansionVelocityAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireDamping) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdSpeed) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireThresholdSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->longitudinalStickyTireThresholdTime) {
            if (UsdAttribute attr = _api.GetLongitudinalStickyTireThresholdTimeAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->lowForwardSpeedSubStepCount) {
            if (UsdAttribute attr = _api.GetLowForwardSpeedSubStepCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->minActiveLongitudinalSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinActiveLongitudinalSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->minLateralSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinLateralSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->minPassiveLongitudinalSlipDenominator) {
            if (UsdAttribute attr = _api.GetMinPassiveLongitudinalSlipDenominatorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->subStepThresholdLongitudinalSpeed) {
            if (UsdAttribute attr = _api.GetSubStepThresholdLongitudinalSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->suspensionLineQueryType) {
            if (UsdAttribute attr = _api.GetSuspensionLineQueryTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleSchemaTokens->vehicleEnabled) {
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
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxVehicleSchemaTokens->physxVehicle,
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
            result.insert(UsdPhysicsImagingPhysxVehicleSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleSuspensionComplianceAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleSuspensionComplianceSchema.h"
#include "pxr/usd/usdPhysX/vehicleSuspensionComplianceAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleSuspensionComplianceAPIAdapter Adapter;
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
                HdPhysxVehicleSuspensionComplianceSchemaTokens->suspensionForceAppPoint,  //
                HdPhysxVehicleSuspensionComplianceSchemaTokens->tireForceAppPoint,        //
                HdPhysxVehicleSuspensionComplianceSchemaTokens->wheelCamberAngle,         //
                HdPhysxVehicleSuspensionComplianceSchemaTokens->wheelToeAngle,            //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleSuspensionComplianceSchemaTokens->suspensionForceAppPoint) {
            if (UsdAttribute attr = _api.GetSuspensionForceAppPointAttr()) {
                VtArray<GfVec4f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec4f>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSuspensionComplianceSchemaTokens->tireForceAppPoint) {
            if (UsdAttribute attr = _api.GetTireForceAppPointAttr()) {
                VtArray<GfVec4f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec4f>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSuspensionComplianceSchemaTokens->wheelCamberAngle) {
            if (UsdAttribute attr = _api.GetWheelCamberAngleAttr()) {
                VtArray<GfVec2f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec2f>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleSuspensionComplianceSchemaTokens->wheelToeAngle) {
            if (UsdAttribute attr = _api.GetWheelToeAngleAttr()) {
                VtArray<GfVec2f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec2f>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleSuspensionComplianceAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleSuspensionComplianceAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxVehicleSuspensionComplianceSchemaTokens->physxVehicleSuspensionCompliance,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleSuspensionComplianceAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleSuspensionComplianceSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
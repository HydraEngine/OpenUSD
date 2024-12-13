//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleNonlinearCommandResponseAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleNonlinearCommandResponseSchema.h"
#include "pxr/usd/usdPhysX/vehicleNonlinearCommandResponseAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleNonlinearCommandResponseAPIAdapter Adapter;
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
                HdPhysxVehicleNonlinearCommandResponseSchemaTokens->commandValues,                  //
                HdPhysxVehicleNonlinearCommandResponseSchemaTokens->speedResponses,                 //
                HdPhysxVehicleNonlinearCommandResponseSchemaTokens->speedResponsesPerCommandValue,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleNonlinearCommandResponseSchemaTokens->commandValues) {
            if (UsdAttribute attr = _api.GetCommandValuesAttr()) {
                VtArray<float> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<float>>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleNonlinearCommandResponseSchemaTokens->speedResponses) {
            if (UsdAttribute attr = _api.GetSpeedResponsesAttr()) {
                VtArray<GfVec2f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec2f>>::New(v);
                }
            }
        } else if (name ==
                   HdPhysxVehicleNonlinearCommandResponseSchemaTokens->speedResponsesPerCommandValue) {
            if (UsdAttribute attr = _api.GetSpeedResponsesPerCommandValueAttr()) {
                VtArray<int> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<int>>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleNonlinearCommandResponseAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleNonlinearCommandResponseAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxVehicleNonlinearCommandResponseSchemaTokens->physxVehicleNonlinearCommandResponse,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleNonlinearCommandResponseAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleNonlinearCommandResponseSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
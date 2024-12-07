//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleTireAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleTireSchema.h"
#include "pxr/usd/usdPhysX/vehicleTireAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleTireAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleTireSchemaTokens->camberStiffness,        //
                UsdPhysicsImagingPhysxVehicleTireSchemaTokens->frictionVsSlipGraph,    //
                UsdPhysicsImagingPhysxVehicleTireSchemaTokens->lateralStiffnessGraph,  //
                UsdPhysicsImagingPhysxVehicleTireSchemaTokens->longitudinalStiffness,  //
                UsdPhysicsImagingPhysxVehicleTireSchemaTokens->restLoad,               //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleTireSchemaTokens->camberStiffness) {
            if (UsdAttribute attr = _api.GetCamberStiffnessAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleTireSchemaTokens->frictionVsSlipGraph) {
            if (UsdAttribute attr = _api.GetFrictionVsSlipGraphAttr()) {
                VtArray<GfVec2f> v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<VtArray<GfVec2f>>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleTireSchemaTokens->lateralStiffnessGraph) {
            if (UsdAttribute attr = _api.GetLateralStiffnessGraphAttr()) {
                GfVec2f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec2f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleTireSchemaTokens->longitudinalStiffness) {
            if (UsdAttribute attr = _api.GetLongitudinalStiffnessAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleTireSchemaTokens->restLoad) {
            if (UsdAttribute attr = _api.GetRestLoadAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleTireAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleTireAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxVehicleTireSchemaTokens->physxVehicleTire,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleTireAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleTireSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
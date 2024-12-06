//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxForceAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxForceSchema.h"
#include "pxr/usd/usdPhysX/forceAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXForceAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxForceSchemaTokens->force,              //
                UsdPhysicsImagingPhysxForceSchemaTokens->forceEnabled,       //
                UsdPhysicsImagingPhysxForceSchemaTokens->mode,               //
                UsdPhysicsImagingPhysxForceSchemaTokens->torque,             //
                UsdPhysicsImagingPhysxForceSchemaTokens->worldFrameEnabled,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxForceSchemaTokens->force) {
            if (UsdAttribute attr = _api.GetForceAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxForceSchemaTokens->forceEnabled) {
            if (UsdAttribute attr = _api.GetForceEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxForceSchemaTokens->mode) {
            if (UsdAttribute attr = _api.GetModeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxForceSchemaTokens->torque) {
            if (UsdAttribute attr = _api.GetTorqueAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxForceSchemaTokens->worldFrameEnabled) {
            if (UsdAttribute attr = _api.GetWorldFrameEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXForceAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXForceAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxForceSchemaTokens->physxForce,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXForceAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxForceSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
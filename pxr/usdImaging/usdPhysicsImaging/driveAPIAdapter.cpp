//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/driveAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/driveSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/usd/usdPhysics/driveAPI.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsDriveAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class _PhysicsDriveDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_PhysicsDriveDataSource);

    explicit _PhysicsDriveDataSource(const UsdPrim& prim) : _api{prim} {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                HdDriveSchemaTokens->type,
                HdDriveSchemaTokens->maxForce,        //
                HdDriveSchemaTokens->targetPosition,  //
                HdDriveSchemaTokens->targetVelocity,  //
                HdDriveSchemaTokens->damping,         //
                HdDriveSchemaTokens->stiffness,       //
        };
        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdDriveSchemaTokens->type) {
            if (UsdAttribute attr = _api.GetTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        }
        if (name == HdDriveSchemaTokens->maxForce) {
            if (UsdAttribute attr = _api.GetMaxForceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        if (name == HdDriveSchemaTokens->targetPosition) {
            if (UsdAttribute attr = _api.GetTargetPositionAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        if (name == HdDriveSchemaTokens->targetVelocity) {
            if (UsdAttribute attr = _api.GetTargetVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        if (name == HdDriveSchemaTokens->damping) {
            if (UsdAttribute attr = _api.GetDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        if (name == HdDriveSchemaTokens->stiffness) {
            if (UsdAttribute attr = _api.GetStiffnessAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysicsDriveAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsDriveAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdDriveSchemaTokens->drive,
                                                  _PhysicsDriveDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsDriveAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdDriveSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
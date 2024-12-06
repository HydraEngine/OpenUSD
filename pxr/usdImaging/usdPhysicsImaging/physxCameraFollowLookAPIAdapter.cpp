//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraFollowLookAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraFollowLookSchema.h"
#include "pxr/usd/usdPhysX/cameraFollowLookAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysxCameraFollowLookAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->downHillGroundAngle,        //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->downHillGroundPitch,        //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->followReverseDistance,      //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->followReverseSpeed,         //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->upHillGroundAngle,          //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->upHillGroundPitch,          //
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->velocityBlendTimeConstant,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->downHillGroundAngle) {
            if (UsdAttribute attr = _api.GetDownHillGroundAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->downHillGroundPitch) {
            if (UsdAttribute attr = _api.GetDownHillGroundPitchAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->followReverseDistance) {
            if (UsdAttribute attr = _api.GetFollowReverseDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->followReverseSpeed) {
            if (UsdAttribute attr = _api.GetFollowReverseSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->upHillGroundAngle) {
            if (UsdAttribute attr = _api.GetUpHillGroundAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->upHillGroundPitch) {
            if (UsdAttribute attr = _api.GetUpHillGroundPitchAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->velocityBlendTimeConstant) {
            if (UsdAttribute attr = _api.GetVelocityBlendTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXCameraFollowLookAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysxCameraFollowLookAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxCameraFollowLookSchemaTokens->physxCameraFollowLook, PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysxCameraFollowLookAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxCameraFollowLookSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
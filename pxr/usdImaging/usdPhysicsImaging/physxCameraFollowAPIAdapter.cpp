//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraFollowAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraFollowSchema.h"
#include "pxr/usd/usdPhysX/cameraFollowAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXCameraFollowAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->cameraPositionTimeConstant,  //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMaxDistance,           //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMaxSpeed,              //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMinDistance,           //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMinSpeed,              //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followTurnRateGain,          //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMaxDistance,        //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMaxSpeed,           //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMinDistance,        //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMinSpeed,           //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadTurnRateGain,       //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookPositionHeight,          //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookPositionTimeConstant,    //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->pitchAngle,                  //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->pitchAngleTimeConstant,      //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->positionOffset,              //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->slowPitchAngleSpeed,         //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->slowSpeedPitchAngleScale,    //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->velocityNormalMinSpeed,      //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->yawAngle,                    //
                UsdPhysicsImagingPhysxCameraFollowSchemaTokens->yawRateTimeConstant          //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->cameraPositionTimeConstant) {
            if (UsdAttribute attr = _api.GetCameraPositionTimeConstantAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMaxDistance) {
            if (UsdAttribute attr = _api.GetFollowMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMaxSpeed) {
            if (UsdAttribute attr = _api.GetFollowMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMinDistance) {
            if (UsdAttribute attr = _api.GetFollowMinDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followMinSpeed) {
            if (UsdAttribute attr = _api.GetFollowMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->followTurnRateGain) {
            if (UsdAttribute attr = _api.GetFollowTurnRateGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMaxDistance) {
            if (UsdAttribute attr = _api.GetLookAheadMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMaxSpeed) {
            if (UsdAttribute attr = _api.GetLookAheadMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMinDistance) {
            if (UsdAttribute attr = _api.GetLookAheadMinDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadMinSpeed) {
            if (UsdAttribute attr = _api.GetLookAheadMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookAheadTurnRateGain) {
            if (UsdAttribute attr = _api.GetLookAheadTurnRateGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookPositionHeight) {
            if (UsdAttribute attr = _api.GetLookPositionHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->lookPositionTimeConstant) {
            if (UsdAttribute attr = _api.GetLookPositionTimeConstantAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->pitchAngle) {
            if (UsdAttribute attr = _api.GetPitchAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->pitchAngleTimeConstant) {
            if (UsdAttribute attr = _api.GetPitchAngleTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->positionOffset) {
            if (UsdAttribute attr = _api.GetPositionOffsetAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->slowPitchAngleSpeed) {
            if (UsdAttribute attr = _api.GetSlowPitchAngleSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->slowSpeedPitchAngleScale) {
            if (UsdAttribute attr = _api.GetSlowSpeedPitchAngleScaleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->velocityNormalMinSpeed) {
            if (UsdAttribute attr = _api.GetVelocityNormalMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->yawAngle) {
            if (UsdAttribute attr = _api.GetYawAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraFollowSchemaTokens->yawRateTimeConstant) {
            if (UsdAttribute attr = _api.GetYawRateTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXCameraFollowAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXCameraFollowAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxCameraFollowSchemaTokens->physxCameraFollow,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXCameraFollowAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxCameraFollowSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
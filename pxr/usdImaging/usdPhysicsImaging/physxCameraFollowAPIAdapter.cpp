//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraFollowAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxCameraFollowSchema.h"
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
                HdPhysxCameraFollowSchemaTokens->cameraPositionTimeConstant,  //
                HdPhysxCameraFollowSchemaTokens->followMaxDistance,           //
                HdPhysxCameraFollowSchemaTokens->followMaxSpeed,              //
                HdPhysxCameraFollowSchemaTokens->followMinDistance,           //
                HdPhysxCameraFollowSchemaTokens->followMinSpeed,              //
                HdPhysxCameraFollowSchemaTokens->followTurnRateGain,          //
                HdPhysxCameraFollowSchemaTokens->lookAheadMaxDistance,        //
                HdPhysxCameraFollowSchemaTokens->lookAheadMaxSpeed,           //
                HdPhysxCameraFollowSchemaTokens->lookAheadMinDistance,        //
                HdPhysxCameraFollowSchemaTokens->lookAheadMinSpeed,           //
                HdPhysxCameraFollowSchemaTokens->lookAheadTurnRateGain,       //
                HdPhysxCameraFollowSchemaTokens->lookPositionHeight,          //
                HdPhysxCameraFollowSchemaTokens->lookPositionTimeConstant,    //
                HdPhysxCameraFollowSchemaTokens->pitchAngle,                  //
                HdPhysxCameraFollowSchemaTokens->pitchAngleTimeConstant,      //
                HdPhysxCameraFollowSchemaTokens->positionOffset,              //
                HdPhysxCameraFollowSchemaTokens->slowPitchAngleSpeed,         //
                HdPhysxCameraFollowSchemaTokens->slowSpeedPitchAngleScale,    //
                HdPhysxCameraFollowSchemaTokens->velocityNormalMinSpeed,      //
                HdPhysxCameraFollowSchemaTokens->yawAngle,                    //
                HdPhysxCameraFollowSchemaTokens->yawRateTimeConstant          //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxCameraFollowSchemaTokens->cameraPositionTimeConstant) {
            if (UsdAttribute attr = _api.GetCameraPositionTimeConstantAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->followMaxDistance) {
            if (UsdAttribute attr = _api.GetFollowMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->followMaxSpeed) {
            if (UsdAttribute attr = _api.GetFollowMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->followMinDistance) {
            if (UsdAttribute attr = _api.GetFollowMinDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->followMinSpeed) {
            if (UsdAttribute attr = _api.GetFollowMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->followTurnRateGain) {
            if (UsdAttribute attr = _api.GetFollowTurnRateGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookAheadMaxDistance) {
            if (UsdAttribute attr = _api.GetLookAheadMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookAheadMaxSpeed) {
            if (UsdAttribute attr = _api.GetLookAheadMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookAheadMinDistance) {
            if (UsdAttribute attr = _api.GetLookAheadMinDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookAheadMinSpeed) {
            if (UsdAttribute attr = _api.GetLookAheadMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookAheadTurnRateGain) {
            if (UsdAttribute attr = _api.GetLookAheadTurnRateGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookPositionHeight) {
            if (UsdAttribute attr = _api.GetLookPositionHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->lookPositionTimeConstant) {
            if (UsdAttribute attr = _api.GetLookPositionTimeConstantAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->pitchAngle) {
            if (UsdAttribute attr = _api.GetPitchAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->pitchAngleTimeConstant) {
            if (UsdAttribute attr = _api.GetPitchAngleTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->positionOffset) {
            if (UsdAttribute attr = _api.GetPositionOffsetAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->slowPitchAngleSpeed) {
            if (UsdAttribute attr = _api.GetSlowPitchAngleSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->slowSpeedPitchAngleScale) {
            if (UsdAttribute attr = _api.GetSlowSpeedPitchAngleScaleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->velocityNormalMinSpeed) {
            if (UsdAttribute attr = _api.GetVelocityNormalMinSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->yawAngle) {
            if (UsdAttribute attr = _api.GetYawAngleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraFollowSchemaTokens->yawRateTimeConstant) {
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
        return HdRetainedContainerDataSource::New(HdPhysxCameraFollowSchemaTokens->physxCameraFollow,
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
            result.insert(HdPhysxCameraFollowSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraDroneAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxCameraDroneSchema.h"
#include "pxr/usd/usdPhysX/cameraDroneAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysxCameraDroneAPIAdapter Adapter;
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
                HdPhysxCameraDroneSchemaTokens->feedForwardVelocityGain,     //
                HdPhysxCameraDroneSchemaTokens->followDistance,              //
                HdPhysxCameraDroneSchemaTokens->followHeight,                //
                HdPhysxCameraDroneSchemaTokens->horizontalVelocityGain,      //
                HdPhysxCameraDroneSchemaTokens->maxDistance,                 //
                HdPhysxCameraDroneSchemaTokens->maxSpeed,                    //
                HdPhysxCameraDroneSchemaTokens->positionOffset,              //
                HdPhysxCameraDroneSchemaTokens->rotationFilterTimeConstant,  //
                HdPhysxCameraDroneSchemaTokens->velocityFilterTimeConstant,  //
                HdPhysxCameraDroneSchemaTokens->verticalVelocityGain,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxCameraDroneSchemaTokens->feedForwardVelocityGain) {
            if (UsdAttribute attr = _api.GetFeedForwardVelocityGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->followDistance) {
            if (UsdAttribute attr = _api.GetFollowDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->followHeight) {
            if (UsdAttribute attr = _api.GetFollowHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->horizontalVelocityGain) {
            if (UsdAttribute attr = _api.GetHorizontalVelocityGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->maxDistance) {
            if (UsdAttribute attr = _api.GetMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->maxSpeed) {
            if (UsdAttribute attr = _api.GetMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->positionOffset) {
            if (UsdAttribute attr = _api.GetPositionOffsetAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->rotationFilterTimeConstant) {
            if (UsdAttribute attr = _api.GetRotationFilterTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->velocityFilterTimeConstant) {
            if (UsdAttribute attr = _api.GetVelocityFilterTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxCameraDroneSchemaTokens->verticalVelocityGain) {
            if (UsdAttribute attr = _api.GetVerticalVelocityGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXCameraDroneAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysxCameraDroneAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdPhysxCameraDroneSchemaTokens->physxCameraDrone,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysxCameraDroneAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxCameraDroneSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
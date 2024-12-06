//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraDroneAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxCameraDroneSchema.h"
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
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->feedForwardVelocityGain,     //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->followDistance,              //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->followHeight,                //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->horizontalVelocityGain,      //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->maxDistance,                 //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->maxSpeed,                    //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->positionOffset,              //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->rotationFilterTimeConstant,  //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->velocityFilterTimeConstant,  //
                UsdPhysicsImagingPhysxCameraDroneSchemaTokens->verticalVelocityGain,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->feedForwardVelocityGain) {
            if (UsdAttribute attr = _api.GetFeedForwardVelocityGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->followDistance) {
            if (UsdAttribute attr = _api.GetFollowDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->followHeight) {
            if (UsdAttribute attr = _api.GetFollowHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->horizontalVelocityGain) {
            if (UsdAttribute attr = _api.GetHorizontalVelocityGainAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->maxDistance) {
            if (UsdAttribute attr = _api.GetMaxDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->maxSpeed) {
            if (UsdAttribute attr = _api.GetMaxSpeedAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->positionOffset) {
            if (UsdAttribute attr = _api.GetPositionOffsetAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->rotationFilterTimeConstant) {
            if (UsdAttribute attr = _api.GetRotationFilterTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->velocityFilterTimeConstant) {
            if (UsdAttribute attr = _api.GetVelocityFilterTimeConstantAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCameraDroneSchemaTokens->verticalVelocityGain) {
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
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxCameraDroneSchemaTokens->physxCameraDrone,
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
            result.insert(UsdPhysicsImagingPhysxCameraDroneSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
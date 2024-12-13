//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleWheelAttachmentAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxVehicleWheelAttachmentSchema.h"
#include "pxr/usd/usdPhysX/vehicleWheelAttachmentAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleWheelAttachmentAPIAdapter Adapter;
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
                HdPhysxVehicleWheelAttachmentSchemaTokens->index,                       //
                HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionFrameOrientation,  //
                HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionFramePosition,     //
                HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionTravelDirection,   //
                HdPhysxVehicleWheelAttachmentSchemaTokens->wheelFrameOrientation,       //
                HdPhysxVehicleWheelAttachmentSchemaTokens->wheelFramePosition,          //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->index) {
            if (UsdAttribute attr = _api.GetIndexAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionFrameOrientation) {
            if (UsdAttribute attr = _api.GetSuspensionFrameOrientationAttr()) {
                GfQuatf v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfQuatf>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionFramePosition) {
            if (UsdAttribute attr = _api.GetSuspensionFramePositionAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->suspensionTravelDirection) {
            if (UsdAttribute attr = _api.GetSuspensionTravelDirectionAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->wheelFrameOrientation) {
            if (UsdAttribute attr = _api.GetWheelFrameOrientationAttr()) {
                GfQuatf v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfQuatf>::New(v);
                }
            }
        } else if (name == HdPhysxVehicleWheelAttachmentSchemaTokens->wheelFramePosition) {
            if (UsdAttribute attr = _api.GetWheelFramePositionAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleWheelAttachmentAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleWheelAttachmentAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxVehicleWheelAttachmentSchemaTokens->physxVehicleWheelAttachment,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleWheelAttachmentAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxVehicleWheelAttachmentSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
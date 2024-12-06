//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxCharacterControllerAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxCharacterControllerSchema.h"
#include "pxr/usd/usdPhysX/characterControllerAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXCharacterControllerAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->climbingMode,         //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->contactOffset,        //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->invisibleWallHeight,  //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->maxJumpHeight,        //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->moveTarget,           //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->nonWalkableMode,      //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->scaleCoeff,           //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->slopeLimit,           //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->stepOffset,           //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->upAxis,               //
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->volumeGrowth,         //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->climbingMode) {
            if (UsdAttribute attr = _api.GetClimbingModeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->contactOffset) {
            if (UsdAttribute attr = _api.GetContactOffsetAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->invisibleWallHeight) {
            if (UsdAttribute attr = _api.GetInvisibleWallHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->maxJumpHeight) {
            if (UsdAttribute attr = _api.GetMaxJumpHeightAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->moveTarget) {
            if (UsdAttribute attr = _api.GetMoveTargetAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->nonWalkableMode) {
            if (UsdAttribute attr = _api.GetNonWalkableModeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->scaleCoeff) {
            if (UsdAttribute attr = _api.GetScaleCoeffAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->slopeLimit) {
            if (UsdAttribute attr = _api.GetSlopeLimitAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->stepOffset) {
            if (UsdAttribute attr = _api.GetStepOffsetAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->upAxis) {
            if (UsdAttribute attr = _api.GetUpAxisAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->volumeGrowth) {
            if (UsdAttribute attr = _api.GetVolumeGrowthAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXCharacterControllerAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXCharacterControllerAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxCharacterControllerSchemaTokens->physxCharacterController,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXCharacterControllerAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxCharacterControllerSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
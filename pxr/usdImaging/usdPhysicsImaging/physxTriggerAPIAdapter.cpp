//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxTriggerAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxTriggerSchema.h"
#include "pxr/usd/usdPhysX/triggerAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXTriggerAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxTriggerSchemaTokens->enterScriptType,  //
                UsdPhysicsImagingPhysxTriggerSchemaTokens->leaveScriptType,  //
                UsdPhysicsImagingPhysxTriggerSchemaTokens->onEnterScript,    //
                UsdPhysicsImagingPhysxTriggerSchemaTokens->onLeaveScript,    //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxTriggerSchemaTokens->enterScriptType) {
            if (UsdAttribute attr = _api.GetEnterScriptTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxTriggerSchemaTokens->leaveScriptType) {
            if (UsdAttribute attr = _api.GetLeaveScriptTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxTriggerSchemaTokens->onEnterScript) {
            if (UsdAttribute attr = _api.GetOnEnterScriptAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxTriggerSchemaTokens->onLeaveScript) {
            if (UsdAttribute attr = _api.GetOnLeaveScriptAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXTriggerAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXTriggerAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxTriggerSchemaTokens->physxTrigger,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXTriggerAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxTriggerSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
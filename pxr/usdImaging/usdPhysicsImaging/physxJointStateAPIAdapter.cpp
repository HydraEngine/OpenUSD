//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxJointStateAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxJointStateEntrySchema.h"
#include "pxr/usd/usdPhysX/jointStateAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXJointStateAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class PhysxDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(PhysxDataSource);

    explicit PhysxDataSource(const UsdPrim& prim, TfToken const& appliedInstanceName)
        : _api(prim, appliedInstanceName) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                HdPhysxJointStateSchemaTokens->position,  //
                HdPhysxJointStateSchemaTokens->velocity,  //
                HdPhysxJointStateSchemaTokens->name,
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxJointStateSchemaTokens->position) {
            if (UsdAttribute attr = _api.GetPositionAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxJointStateSchemaTokens->velocity) {
            if (UsdAttribute attr = _api.GetVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        if (name == HdPhysxJointStateSchemaTokens->name) {
            return HdRetainedTypedSampledDataSource<TfToken>::New(_api.GetName());
        }
        return nullptr;
    }

private:
    UsdPhysXJointStateAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXJointStateAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxJointStateEntrySchemaTokens->physxJointStateEntry,
                HdRetainedContainerDataSource::New(appliedInstanceName,
                                                   PhysxDataSource::New(prim, appliedInstanceName)));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXJointStateAPIAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        TfTokenVector const& properties,
        UsdImagingPropertyInvalidationType invalidationType) {
    if (appliedInstanceName.IsEmpty()) {
        return HdDataSourceLocatorSet();
    }

    HdDataSourceLocatorSet result;
    for (const TfToken& propertyName : properties) {
        if (TfStringStartsWith(propertyName.GetString(), "physics:")) {
            result.insert(HdPhysxJointStateSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
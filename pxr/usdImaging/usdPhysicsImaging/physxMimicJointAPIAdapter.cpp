//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxMimicJointAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxMimicJointEntrySchema.h"
#include "pxr/usd/usdPhysX/mimicJointAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXMimicJointAPIAdapter Adapter;
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
        static const TfTokenVector names = {HdPhysxMimicJointSchemaTokens->gearing,             //
                                            HdPhysxMimicJointSchemaTokens->offset,              //
                                            HdPhysxMimicJointSchemaTokens->referenceJointAxis,  //
                                            HdPhysxMimicJointSchemaTokens->name};

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxMimicJointSchemaTokens->gearing) {
            if (UsdAttribute attr = _api.GetGearingAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxMimicJointSchemaTokens->offset) {
            if (UsdAttribute attr = _api.GetOffsetAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxMimicJointSchemaTokens->referenceJointAxis) {
            if (UsdAttribute attr = _api.GetReferenceJointAxisAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        }
        if (name == HdPhysxMimicJointSchemaTokens->name) {
            return HdRetainedTypedSampledDataSource<TfToken>::New(_api.GetName());
        }
        return nullptr;
    }

private:
    UsdPhysXMimicJointAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXMimicJointAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxMimicJointEntrySchemaTokens->physxMimicJointEntry,
                HdRetainedContainerDataSource::New(appliedInstanceName,
                                                   PhysxDataSource::New(prim, appliedInstanceName)));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXMimicJointAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxMimicJointSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/materialAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usd/usdPhysics/materialAPI.h"
#include "pxr/usdImaging/usdPhysicsImaging/physicsSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsMaterialAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class _PhysicsMaterialDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_PhysicsMaterialDataSource);

    _PhysicsMaterialDataSource(const UsdPrim& prim, const UsdImagingDataSourceStageGlobals& stageGlobals)
        : _api(prim), _stageGlobals(stageGlobals) {
        std::cout<<"oooo"<<std::endl;
    }

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                HdPhysicsSchemaTokens->density,          //
                HdPhysicsSchemaTokens->restitution,      //
                HdPhysicsSchemaTokens->dynamicFriction,  //
                HdPhysicsSchemaTokens->staticFriction    //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        float v;
        if (name == HdPhysicsSchemaTokens->density) {
            if (UsdAttribute attr = _api.GetDensityAttr()) {
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysicsSchemaTokens->restitution) {
            if (UsdAttribute attr = _api.GetRestitutionAttr()) {
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysicsSchemaTokens->dynamicFriction) {
            if (UsdAttribute attr = _api.GetDynamicFrictionAttr()) {
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysicsSchemaTokens->staticFriction) {
            if (UsdAttribute attr = _api.GetStaticFrictionAttr()) {
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysicsMaterialAPI _api;
    const UsdImagingDataSourceStageGlobals& _stageGlobals;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsMaterialAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdPhysicsSchemaTokens->physics,
                                                  _PhysicsMaterialDataSource::New(prim, stageGlobals));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsMaterialAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdImagingPhysicsSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
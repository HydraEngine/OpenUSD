//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/massAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/massSchema.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/massAPI.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsMassAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class _PhysicsMassDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_PhysicsMassDataSource);

    explicit _PhysicsMassDataSource(const UsdPrim& prim) : _api(prim) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                UsdPhysicsTokens->physicsMass,             //
                UsdPhysicsTokens->physicsDensity,          //
                UsdPhysicsTokens->physicsCenterOfMass,     //
                UsdPhysicsTokens->physicsDiagonalInertia,  //
                UsdPhysicsTokens->physicsPrincipalAxes,    //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsTokens->physicsMass) {
            if (UsdAttribute attr = _api.GetMassAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsTokens->physicsDensity) {
            if (UsdAttribute attr = _api.GetDensityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsTokens->physicsCenterOfMass) {
            if (UsdAttribute attr = _api.GetCenterOfMassAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsTokens->physicsDiagonalInertia) {
            if (UsdAttribute attr = _api.GetDiagonalInertiaAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsTokens->physicsPrincipalAxes) {
            if (UsdAttribute attr = _api.GetPrincipalAxesAttr()) {
                GfQuatf v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfQuatf>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysicsMassAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsMassAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsTokens->PhysicsMassAPI,
                                                  _PhysicsMassDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsMassAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingMassSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
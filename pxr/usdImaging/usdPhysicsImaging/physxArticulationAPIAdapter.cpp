//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxArticulationAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxArticulationSchema.h"
#include "pxr/usd/usdPhysX/articulationAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXArticulationRootAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxArticulationSchemaTokens->articulationEnabled,           //
                UsdPhysicsImagingPhysxArticulationSchemaTokens->enabledSelfCollisions,         //
                UsdPhysicsImagingPhysxArticulationSchemaTokens->sleepThreshold,                //
                UsdPhysicsImagingPhysxArticulationSchemaTokens->solverPositionIterationCount,  //
                UsdPhysicsImagingPhysxArticulationSchemaTokens->solverVelocityIterationCount,  //
                UsdPhysicsImagingPhysxArticulationSchemaTokens->stabilizationThreshold,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->articulationEnabled) {
            if (UsdAttribute attr = _api.GetArticulationEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->enabledSelfCollisions) {
            if (UsdAttribute attr = _api.GetEnabledSelfCollisionsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->sleepThreshold) {
            if (UsdAttribute attr = _api.GetSleepThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->solverPositionIterationCount) {
            if (UsdAttribute attr = _api.GetSolverPositionIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->solverVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetSolverVelocityIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxArticulationSchemaTokens->stabilizationThreshold) {
            if (UsdAttribute attr = _api.GetStabilizationThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXArticulationAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXArticulationRootAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxArticulationSchemaTokens->physxArticulation,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXArticulationRootAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxArticulationSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
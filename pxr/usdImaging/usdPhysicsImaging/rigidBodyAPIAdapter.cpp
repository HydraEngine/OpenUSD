//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/rigidBodyAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/usdImaging/usdPhysicsImaging/rigidBodySchema.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/rigidBodyAPI.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsRigidBodyAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class _PhysicsRigidBodyDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(_PhysicsRigidBodyDataSource);

    explicit _PhysicsRigidBodyDataSource(const UsdPrim& prim) : _api(prim) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                UsdPhysicsImagingRigidBodySchemaTokens->rigidBodyEnabled,  //
                UsdPhysicsImagingRigidBodySchemaTokens->kinematicEnabled,  //
                UsdPhysicsImagingRigidBodySchemaTokens->startsAsleep,      //
                UsdPhysicsImagingRigidBodySchemaTokens->velocity,          //
                UsdPhysicsImagingRigidBodySchemaTokens->angularVelocity,   //
                UsdPhysicsImagingRigidBodySchemaTokens->simulationOwner,   //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingRigidBodySchemaTokens->rigidBodyEnabled) {
            if (UsdAttribute attr = _api.GetRigidBodyEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingRigidBodySchemaTokens->kinematicEnabled) {
            if (UsdAttribute attr = _api.GetKinematicEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingRigidBodySchemaTokens->startsAsleep) {
            if (UsdAttribute attr = _api.GetStartsAsleepAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingRigidBodySchemaTokens->velocity) {
            if (UsdAttribute attr = _api.GetVelocityAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingRigidBodySchemaTokens->angularVelocity) {
            if (UsdAttribute attr = _api.GetAngularVelocityAttr()) {
                GfVec3f v{};
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingRigidBodySchemaTokens->simulationOwner) {
            if (UsdRelationship rel = _api.GetSimulationOwnerRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        }
        return nullptr;
    }

private:
    UsdPhysicsRigidBodyAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsRigidBodyAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingRigidBodySchemaTokens->rigidBody,
                                                  _PhysicsRigidBodyDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsRigidBodyAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingRigidBodySchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
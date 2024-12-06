//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxRigidBodyAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxRigidBodySchema.h"
#include "pxr/usd/usdPhysX/rigidBodyAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXRigidBodyAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->angularDamping,                //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->cfmScale,                      //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->contactSlopCoefficient,        //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->disableGravity,                //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableCCD,                     //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableGyroscopicForces,        //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableSpeculativeCCD,          //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->linearDamping,                 //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->lockedPosAxis,                 //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->lockedRotAxis,                 //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxAngularVelocity,            //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxContactImpulse,             //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxDepenetrationVelocity,      //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxLinearVelocity,             //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->retainAccelerations,           //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->sleepThreshold,                //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->solveContact,                  //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->solverPositionIterationCount,  //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->solverVelocityIterationCount,  //
                UsdPhysicsImagingPhysxRigidBodySchemaTokens->stabilizationThreshold,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->angularDamping) {
            if (UsdAttribute attr = _api.GetAngularDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->cfmScale) {
            if (UsdAttribute attr = _api.GetCfmScaleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->contactSlopCoefficient) {
            if (UsdAttribute attr = _api.GetContactSlopCoefficientAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->disableGravity) {
            if (UsdAttribute attr = _api.GetDisableGravityAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableCCD) {
            if (UsdAttribute attr = _api.GetEnableCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableGyroscopicForces) {
            if (UsdAttribute attr = _api.GetEnableGyroscopicForcesAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->enableSpeculativeCCD) {
            if (UsdAttribute attr = _api.GetEnableSpeculativeCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->linearDamping) {
            if (UsdAttribute attr = _api.GetLinearDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->lockedPosAxis) {
            if (UsdAttribute attr = _api.GetLockedPosAxisAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->lockedRotAxis) {
            if (UsdAttribute attr = _api.GetLockedRotAxisAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxAngularVelocity) {
            if (UsdAttribute attr = _api.GetMaxAngularVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxContactImpulse) {
            if (UsdAttribute attr = _api.GetMaxContactImpulseAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxDepenetrationVelocity) {
            if (UsdAttribute attr = _api.GetMaxDepenetrationVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->maxLinearVelocity) {
            if (UsdAttribute attr = _api.GetMaxLinearVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->retainAccelerations) {
            if (UsdAttribute attr = _api.GetRetainAccelerationsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->sleepThreshold) {
            if (UsdAttribute attr = _api.GetSleepThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->solveContact) {
            if (UsdAttribute attr = _api.GetSolveContactAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->solverPositionIterationCount) {
            if (UsdAttribute attr = _api.GetSolverPositionIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->solverVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetSolverVelocityIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxRigidBodySchemaTokens->stabilizationThreshold) {
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
    UsdPhysXRigidBodyAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXRigidBodyAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxRigidBodySchemaTokens->physxRigidBody,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXRigidBodyAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxRigidBodySchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxRigidBodyAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxRigidBodySchema.h"
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
                HdPhysxRigidBodySchemaTokens->angularDamping,                //
                HdPhysxRigidBodySchemaTokens->cfmScale,                      //
                HdPhysxRigidBodySchemaTokens->contactSlopCoefficient,        //
                HdPhysxRigidBodySchemaTokens->disableGravity,                //
                HdPhysxRigidBodySchemaTokens->enableCCD,                     //
                HdPhysxRigidBodySchemaTokens->enableGyroscopicForces,        //
                HdPhysxRigidBodySchemaTokens->enableSpeculativeCCD,          //
                HdPhysxRigidBodySchemaTokens->linearDamping,                 //
                HdPhysxRigidBodySchemaTokens->lockedPosAxis,                 //
                HdPhysxRigidBodySchemaTokens->lockedRotAxis,                 //
                HdPhysxRigidBodySchemaTokens->maxAngularVelocity,            //
                HdPhysxRigidBodySchemaTokens->maxContactImpulse,             //
                HdPhysxRigidBodySchemaTokens->maxDepenetrationVelocity,      //
                HdPhysxRigidBodySchemaTokens->maxLinearVelocity,             //
                HdPhysxRigidBodySchemaTokens->retainAccelerations,           //
                HdPhysxRigidBodySchemaTokens->sleepThreshold,                //
                HdPhysxRigidBodySchemaTokens->solveContact,                  //
                HdPhysxRigidBodySchemaTokens->solverPositionIterationCount,  //
                HdPhysxRigidBodySchemaTokens->solverVelocityIterationCount,  //
                HdPhysxRigidBodySchemaTokens->stabilizationThreshold,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxRigidBodySchemaTokens->angularDamping) {
            if (UsdAttribute attr = _api.GetAngularDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->cfmScale) {
            if (UsdAttribute attr = _api.GetCfmScaleAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->contactSlopCoefficient) {
            if (UsdAttribute attr = _api.GetContactSlopCoefficientAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->disableGravity) {
            if (UsdAttribute attr = _api.GetDisableGravityAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->enableCCD) {
            if (UsdAttribute attr = _api.GetEnableCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->enableGyroscopicForces) {
            if (UsdAttribute attr = _api.GetEnableGyroscopicForcesAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->enableSpeculativeCCD) {
            if (UsdAttribute attr = _api.GetEnableSpeculativeCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->linearDamping) {
            if (UsdAttribute attr = _api.GetLinearDampingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->lockedPosAxis) {
            if (UsdAttribute attr = _api.GetLockedPosAxisAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->lockedRotAxis) {
            if (UsdAttribute attr = _api.GetLockedRotAxisAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->maxAngularVelocity) {
            if (UsdAttribute attr = _api.GetMaxAngularVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->maxContactImpulse) {
            if (UsdAttribute attr = _api.GetMaxContactImpulseAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->maxDepenetrationVelocity) {
            if (UsdAttribute attr = _api.GetMaxDepenetrationVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->maxLinearVelocity) {
            if (UsdAttribute attr = _api.GetMaxLinearVelocityAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->retainAccelerations) {
            if (UsdAttribute attr = _api.GetRetainAccelerationsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->sleepThreshold) {
            if (UsdAttribute attr = _api.GetSleepThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->solveContact) {
            if (UsdAttribute attr = _api.GetSolveContactAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->solverPositionIterationCount) {
            if (UsdAttribute attr = _api.GetSolverPositionIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->solverVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetSolverVelocityIterationCountAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxRigidBodySchemaTokens->stabilizationThreshold) {
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
        return HdRetainedContainerDataSource::New(HdPhysxRigidBodySchemaTokens->physxRigidBody,
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
            result.insert(HdPhysxRigidBodySchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
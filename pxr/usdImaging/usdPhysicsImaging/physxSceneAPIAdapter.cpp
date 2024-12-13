//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxSceneAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxSceneSchema.h"
#include "pxr/usd/usdPhysX/sceneAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXSceneAPIAdapter Adapter;
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
                HdPhysxSceneSchemaTokens->bounceThreshold,                     //
                HdPhysxSceneSchemaTokens->broadphaseType,                      //
                HdPhysxSceneSchemaTokens->collisionSystem,                     //
                HdPhysxSceneSchemaTokens->enableCCD,                           //
                HdPhysxSceneSchemaTokens->enableEnhancedDeterminism,           //
                HdPhysxSceneSchemaTokens->enableExternalForcesEveryIteration,  //
                HdPhysxSceneSchemaTokens->enableGPUDynamics,                   //
                HdPhysxSceneSchemaTokens->enableResidualReporting,             //
                HdPhysxSceneSchemaTokens->enableSceneQuerySupport,             //
                HdPhysxSceneSchemaTokens->enableStabilization,                 //
                HdPhysxSceneSchemaTokens->frictionCorrelationDistance,         //
                HdPhysxSceneSchemaTokens->frictionOffsetThreshold,             //
                HdPhysxSceneSchemaTokens->frictionType,                        //
                HdPhysxSceneSchemaTokens->gpuCollisionStackSize,               //
                HdPhysxSceneSchemaTokens->gpuFoundLostAggregatePairsCapacity,  //
                HdPhysxSceneSchemaTokens->gpuFoundLostPairsCapacity,           //
                HdPhysxSceneSchemaTokens->gpuHeapCapacity,                     //
                HdPhysxSceneSchemaTokens->gpuMaxDeformableSurfaceContacts,     //
                HdPhysxSceneSchemaTokens->gpuMaxHairContacts,                  //
                HdPhysxSceneSchemaTokens->gpuMaxNumPartitions,                 //
                HdPhysxSceneSchemaTokens->gpuMaxParticleContacts,              //
                HdPhysxSceneSchemaTokens->gpuMaxRigidContactCount,             //
                HdPhysxSceneSchemaTokens->gpuMaxRigidPatchCount,               //
                HdPhysxSceneSchemaTokens->gpuMaxSoftBodyContacts,              //
                HdPhysxSceneSchemaTokens->gpuTempBufferCapacity,               //
                HdPhysxSceneSchemaTokens->gpuTotalAggregatePairsCapacity,      //
                HdPhysxSceneSchemaTokens->invertCollisionGroupFilter,          //
                HdPhysxSceneSchemaTokens->maxBiasCoefficient,                  //
                HdPhysxSceneSchemaTokens->maxPositionIterationCount,           //
                HdPhysxSceneSchemaTokens->maxVelocityIterationCount,           //
                HdPhysxSceneSchemaTokens->minPositionIterationCount,           //
                HdPhysxSceneSchemaTokens->minVelocityIterationCount,           //
                HdPhysxSceneSchemaTokens->reportKinematicKinematicPairs,       //
                HdPhysxSceneSchemaTokens->reportKinematicStaticPairs,          //
                HdPhysxSceneSchemaTokens->solverType,                          //
                HdPhysxSceneSchemaTokens->timeStepsPerSecond,                  //
                HdPhysxSceneSchemaTokens->updateType,                          //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxSceneSchemaTokens->bounceThreshold) {
            if (UsdAttribute attr = _api.GetBounceThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->broadphaseType) {
            if (UsdAttribute attr = _api.GetBroadphaseTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->collisionSystem) {
            if (UsdAttribute attr = _api.GetCollisionSystemAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableCCD) {
            if (UsdAttribute attr = _api.GetEnableCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableEnhancedDeterminism) {
            if (UsdAttribute attr = _api.GetEnableEnhancedDeterminismAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableExternalForcesEveryIteration) {
            if (UsdAttribute attr = _api.GetEnableExternalForcesEveryIterationAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableGPUDynamics) {
            if (UsdAttribute attr = _api.GetEnableGPUDynamicsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableResidualReporting) {
            if (UsdAttribute attr = _api.GetEnableResidualReportingAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableSceneQuerySupport) {
            if (UsdAttribute attr = _api.GetEnableSceneQuerySupportAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->enableStabilization) {
            if (UsdAttribute attr = _api.GetEnableStabilizationAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->frictionCorrelationDistance) {
            if (UsdAttribute attr = _api.GetFrictionCorrelationDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->frictionOffsetThreshold) {
            if (UsdAttribute attr = _api.GetFrictionOffsetThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->frictionType) {
            if (UsdAttribute attr = _api.GetFrictionTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuCollisionStackSize) {
            if (UsdAttribute attr = _api.GetGpuCollisionStackSizeAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuFoundLostAggregatePairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuFoundLostAggregatePairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuFoundLostPairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuFoundLostPairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuHeapCapacity) {
            if (UsdAttribute attr = _api.GetGpuHeapCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxDeformableSurfaceContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxDeformableSurfaceContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxHairContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxHairContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxNumPartitions) {
            if (UsdAttribute attr = _api.GetGpuMaxNumPartitionsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxParticleContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxParticleContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxRigidContactCount) {
            if (UsdAttribute attr = _api.GetGpuMaxRigidContactCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxRigidPatchCount) {
            if (UsdAttribute attr = _api.GetGpuMaxRigidPatchCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuMaxSoftBodyContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxSoftBodyContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuTempBufferCapacity) {
            if (UsdAttribute attr = _api.GetGpuTempBufferCapacityAttr()) {
                uint64_t v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->gpuTotalAggregatePairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuTotalAggregatePairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->invertCollisionGroupFilter) {
            if (UsdAttribute attr = _api.GetInvertCollisionGroupFilterAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->maxBiasCoefficient) {
            if (UsdAttribute attr = _api.GetMaxBiasCoefficientAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->maxPositionIterationCount) {
            if (UsdAttribute attr = _api.GetMaxPositionIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->maxVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetMaxVelocityIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->minPositionIterationCount) {
            if (UsdAttribute attr = _api.GetMinPositionIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->minVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetMinVelocityIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->reportKinematicKinematicPairs) {
            if (UsdAttribute attr = _api.GetReportKinematicKinematicPairsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->reportKinematicStaticPairs) {
            if (UsdAttribute attr = _api.GetReportKinematicStaticPairsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->solverType) {
            if (UsdAttribute attr = _api.GetSolverTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->timeStepsPerSecond) {
            if (UsdAttribute attr = _api.GetTimeStepsPerSecondAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxSceneSchemaTokens->updateType) {
            if (UsdAttribute attr = _api.GetUpdateTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXSceneAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXSceneAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(HdPhysxSceneSchemaTokens->physxScene,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXSceneAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxSceneSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
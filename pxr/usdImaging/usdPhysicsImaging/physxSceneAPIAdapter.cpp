//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxSceneAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxSceneSchema.h"
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
                UsdPhysicsImagingPhysxSceneSchemaTokens->bounceThreshold,                     //
                UsdPhysicsImagingPhysxSceneSchemaTokens->broadphaseType,                      //
                UsdPhysicsImagingPhysxSceneSchemaTokens->collisionSystem,                     //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableCCD,                           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableEnhancedDeterminism,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableExternalForcesEveryIteration,  //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableGPUDynamics,                   //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableResidualReporting,             //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableSceneQuerySupport,             //
                UsdPhysicsImagingPhysxSceneSchemaTokens->enableStabilization,                 //
                UsdPhysicsImagingPhysxSceneSchemaTokens->frictionCorrelationDistance,         //
                UsdPhysicsImagingPhysxSceneSchemaTokens->frictionOffsetThreshold,             //
                UsdPhysicsImagingPhysxSceneSchemaTokens->frictionType,                        //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuCollisionStackSize,               //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuFoundLostAggregatePairsCapacity,  //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuFoundLostPairsCapacity,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuHeapCapacity,                     //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxDeformableSurfaceContacts,     //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxHairContacts,                  //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxNumPartitions,                 //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxParticleContacts,              //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxRigidContactCount,             //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxRigidPatchCount,               //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxSoftBodyContacts,              //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuTempBufferCapacity,               //
                UsdPhysicsImagingPhysxSceneSchemaTokens->gpuTotalAggregatePairsCapacity,      //
                UsdPhysicsImagingPhysxSceneSchemaTokens->invertCollisionGroupFilter,          //
                UsdPhysicsImagingPhysxSceneSchemaTokens->maxBiasCoefficient,                  //
                UsdPhysicsImagingPhysxSceneSchemaTokens->maxPositionIterationCount,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->maxVelocityIterationCount,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->minPositionIterationCount,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->minVelocityIterationCount,           //
                UsdPhysicsImagingPhysxSceneSchemaTokens->reportKinematicKinematicPairs,       //
                UsdPhysicsImagingPhysxSceneSchemaTokens->reportKinematicStaticPairs,          //
                UsdPhysicsImagingPhysxSceneSchemaTokens->solverType,                          //
                UsdPhysicsImagingPhysxSceneSchemaTokens->timeStepsPerSecond,                  //
                UsdPhysicsImagingPhysxSceneSchemaTokens->updateType,                          //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->bounceThreshold) {
            if (UsdAttribute attr = _api.GetBounceThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->broadphaseType) {
            if (UsdAttribute attr = _api.GetBroadphaseTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->collisionSystem) {
            if (UsdAttribute attr = _api.GetCollisionSystemAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableCCD) {
            if (UsdAttribute attr = _api.GetEnableCCDAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableEnhancedDeterminism) {
            if (UsdAttribute attr = _api.GetEnableEnhancedDeterminismAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableExternalForcesEveryIteration) {
            if (UsdAttribute attr = _api.GetEnableExternalForcesEveryIterationAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableGPUDynamics) {
            if (UsdAttribute attr = _api.GetEnableGPUDynamicsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableResidualReporting) {
            if (UsdAttribute attr = _api.GetEnableResidualReportingAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableSceneQuerySupport) {
            if (UsdAttribute attr = _api.GetEnableSceneQuerySupportAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->enableStabilization) {
            if (UsdAttribute attr = _api.GetEnableStabilizationAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->frictionCorrelationDistance) {
            if (UsdAttribute attr = _api.GetFrictionCorrelationDistanceAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->frictionOffsetThreshold) {
            if (UsdAttribute attr = _api.GetFrictionOffsetThresholdAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->frictionType) {
            if (UsdAttribute attr = _api.GetFrictionTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuCollisionStackSize) {
            if (UsdAttribute attr = _api.GetGpuCollisionStackSizeAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuFoundLostAggregatePairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuFoundLostAggregatePairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuFoundLostPairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuFoundLostPairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuHeapCapacity) {
            if (UsdAttribute attr = _api.GetGpuHeapCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxDeformableSurfaceContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxDeformableSurfaceContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxHairContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxHairContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxNumPartitions) {
            if (UsdAttribute attr = _api.GetGpuMaxNumPartitionsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxParticleContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxParticleContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxRigidContactCount) {
            if (UsdAttribute attr = _api.GetGpuMaxRigidContactCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxRigidPatchCount) {
            if (UsdAttribute attr = _api.GetGpuMaxRigidPatchCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuMaxSoftBodyContacts) {
            if (UsdAttribute attr = _api.GetGpuMaxSoftBodyContactsAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuTempBufferCapacity) {
            if (UsdAttribute attr = _api.GetGpuTempBufferCapacityAttr()) {
                uint64_t v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->gpuTotalAggregatePairsCapacity) {
            if (UsdAttribute attr = _api.GetGpuTotalAggregatePairsCapacityAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->invertCollisionGroupFilter) {
            if (UsdAttribute attr = _api.GetInvertCollisionGroupFilterAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->maxBiasCoefficient) {
            if (UsdAttribute attr = _api.GetMaxBiasCoefficientAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->maxPositionIterationCount) {
            if (UsdAttribute attr = _api.GetMaxPositionIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->maxVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetMaxVelocityIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->minPositionIterationCount) {
            if (UsdAttribute attr = _api.GetMinPositionIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->minVelocityIterationCount) {
            if (UsdAttribute attr = _api.GetMinVelocityIterationCountAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->reportKinematicKinematicPairs) {
            if (UsdAttribute attr = _api.GetReportKinematicKinematicPairsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->reportKinematicStaticPairs) {
            if (UsdAttribute attr = _api.GetReportKinematicStaticPairsAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->solverType) {
            if (UsdAttribute attr = _api.GetSolverTypeAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->timeStepsPerSecond) {
            if (UsdAttribute attr = _api.GetTimeStepsPerSecondAttr()) {
                uint v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSceneSchemaTokens->updateType) {
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
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxSceneSchemaTokens->physxScene,
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
            result.insert(UsdPhysicsImagingPhysxSceneSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
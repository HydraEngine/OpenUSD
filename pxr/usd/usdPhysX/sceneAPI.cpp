//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/sceneAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXSceneAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXSceneAPI::~UsdPhysXSceneAPI()
{
}

/* static */
UsdPhysXSceneAPI
UsdPhysXSceneAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXSceneAPI();
    }
    return UsdPhysXSceneAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXSceneAPI::_GetSchemaKind() const
{
    return UsdPhysXSceneAPI::schemaKind;
}

/* static */
bool
UsdPhysXSceneAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXSceneAPI>(whyNot);
}

/* static */
UsdPhysXSceneAPI
UsdPhysXSceneAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXSceneAPI>()) {
        return UsdPhysXSceneAPI(prim);
    }
    return UsdPhysXSceneAPI();
}

/* static */
const TfType &
UsdPhysXSceneAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXSceneAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXSceneAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXSceneAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXSceneAPI::GetBounceThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneBounceThreshold);
}

UsdAttribute
UsdPhysXSceneAPI::CreateBounceThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneBounceThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetBroadphaseTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneBroadphaseType);
}

UsdAttribute
UsdPhysXSceneAPI::CreateBroadphaseTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneBroadphaseType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetCollisionSystemAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneCollisionSystem);
}

UsdAttribute
UsdPhysXSceneAPI::CreateCollisionSystemAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneCollisionSystem,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableCCDAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableCCD);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableCCDAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableCCD,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableEnhancedDeterminismAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableEnhancedDeterminism);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableEnhancedDeterminismAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableEnhancedDeterminism,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableExternalForcesEveryIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableExternalForcesEveryIteration);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableExternalForcesEveryIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableExternalForcesEveryIteration,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableGPUDynamicsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableGPUDynamics);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableGPUDynamicsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableGPUDynamics,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableResidualReportingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableResidualReporting);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableResidualReportingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableResidualReporting,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableSceneQuerySupportAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableSceneQuerySupport);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableSceneQuerySupportAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableSceneQuerySupport,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetEnableStabilizationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneEnableStabilization);
}

UsdAttribute
UsdPhysXSceneAPI::CreateEnableStabilizationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneEnableStabilization,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetFrictionCorrelationDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneFrictionCorrelationDistance);
}

UsdAttribute
UsdPhysXSceneAPI::CreateFrictionCorrelationDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneFrictionCorrelationDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetFrictionOffsetThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneFrictionOffsetThreshold);
}

UsdAttribute
UsdPhysXSceneAPI::CreateFrictionOffsetThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneFrictionOffsetThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetFrictionTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneFrictionType);
}

UsdAttribute
UsdPhysXSceneAPI::CreateFrictionTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneFrictionType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuCollisionStackSizeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuCollisionStackSize);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuCollisionStackSizeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuCollisionStackSize,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuFoundLostAggregatePairsCapacityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuFoundLostAggregatePairsCapacity);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuFoundLostAggregatePairsCapacityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuFoundLostAggregatePairsCapacity,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuFoundLostPairsCapacityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuFoundLostPairsCapacity);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuFoundLostPairsCapacityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuFoundLostPairsCapacity,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuHeapCapacityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuHeapCapacity);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuHeapCapacityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuHeapCapacity,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxDeformableSurfaceContactsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxDeformableSurfaceContacts);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxDeformableSurfaceContactsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxDeformableSurfaceContacts,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxHairContactsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxHairContacts);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxHairContactsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxHairContacts,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxNumPartitionsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxNumPartitions);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxNumPartitionsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxNumPartitions,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxParticleContactsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxParticleContacts);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxParticleContactsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxParticleContacts,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxRigidContactCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxRigidContactCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxRigidContactCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxRigidContactCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxRigidPatchCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxRigidPatchCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxRigidPatchCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxRigidPatchCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuMaxSoftBodyContactsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuMaxSoftBodyContacts);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuMaxSoftBodyContactsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuMaxSoftBodyContacts,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuTempBufferCapacityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuTempBufferCapacity);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuTempBufferCapacityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuTempBufferCapacity,
                       SdfValueTypeNames->UInt64,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetGpuTotalAggregatePairsCapacityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneGpuTotalAggregatePairsCapacity);
}

UsdAttribute
UsdPhysXSceneAPI::CreateGpuTotalAggregatePairsCapacityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneGpuTotalAggregatePairsCapacity,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetInvertCollisionGroupFilterAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneInvertCollisionGroupFilter);
}

UsdAttribute
UsdPhysXSceneAPI::CreateInvertCollisionGroupFilterAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneInvertCollisionGroupFilter,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetMaxBiasCoefficientAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneMaxBiasCoefficient);
}

UsdAttribute
UsdPhysXSceneAPI::CreateMaxBiasCoefficientAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneMaxBiasCoefficient,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetMaxPositionIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneMaxPositionIterationCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateMaxPositionIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneMaxPositionIterationCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetMaxVelocityIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneMaxVelocityIterationCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateMaxVelocityIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneMaxVelocityIterationCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetMinPositionIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneMinPositionIterationCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateMinPositionIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneMinPositionIterationCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetMinVelocityIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneMinVelocityIterationCount);
}

UsdAttribute
UsdPhysXSceneAPI::CreateMinVelocityIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneMinVelocityIterationCount,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetReportKinematicKinematicPairsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneReportKinematicKinematicPairs);
}

UsdAttribute
UsdPhysXSceneAPI::CreateReportKinematicKinematicPairsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneReportKinematicKinematicPairs,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetReportKinematicStaticPairsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneReportKinematicStaticPairs);
}

UsdAttribute
UsdPhysXSceneAPI::CreateReportKinematicStaticPairsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneReportKinematicStaticPairs,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetSolverTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneSolverType);
}

UsdAttribute
UsdPhysXSceneAPI::CreateSolverTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneSolverType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetTimeStepsPerSecondAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneTimeStepsPerSecond);
}

UsdAttribute
UsdPhysXSceneAPI::CreateTimeStepsPerSecondAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneTimeStepsPerSecond,
                       SdfValueTypeNames->UInt,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSceneAPI::GetUpdateTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneUpdateType);
}

UsdAttribute
UsdPhysXSceneAPI::CreateUpdateTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneUpdateType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
UsdPhysXSceneAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxSceneBounceThreshold,
        UsdPhysXTokens->physxSceneBroadphaseType,
        UsdPhysXTokens->physxSceneCollisionSystem,
        UsdPhysXTokens->physxSceneEnableCCD,
        UsdPhysXTokens->physxSceneEnableEnhancedDeterminism,
        UsdPhysXTokens->physxSceneEnableExternalForcesEveryIteration,
        UsdPhysXTokens->physxSceneEnableGPUDynamics,
        UsdPhysXTokens->physxSceneEnableResidualReporting,
        UsdPhysXTokens->physxSceneEnableSceneQuerySupport,
        UsdPhysXTokens->physxSceneEnableStabilization,
        UsdPhysXTokens->physxSceneFrictionCorrelationDistance,
        UsdPhysXTokens->physxSceneFrictionOffsetThreshold,
        UsdPhysXTokens->physxSceneFrictionType,
        UsdPhysXTokens->physxSceneGpuCollisionStackSize,
        UsdPhysXTokens->physxSceneGpuFoundLostAggregatePairsCapacity,
        UsdPhysXTokens->physxSceneGpuFoundLostPairsCapacity,
        UsdPhysXTokens->physxSceneGpuHeapCapacity,
        UsdPhysXTokens->physxSceneGpuMaxDeformableSurfaceContacts,
        UsdPhysXTokens->physxSceneGpuMaxHairContacts,
        UsdPhysXTokens->physxSceneGpuMaxNumPartitions,
        UsdPhysXTokens->physxSceneGpuMaxParticleContacts,
        UsdPhysXTokens->physxSceneGpuMaxRigidContactCount,
        UsdPhysXTokens->physxSceneGpuMaxRigidPatchCount,
        UsdPhysXTokens->physxSceneGpuMaxSoftBodyContacts,
        UsdPhysXTokens->physxSceneGpuTempBufferCapacity,
        UsdPhysXTokens->physxSceneGpuTotalAggregatePairsCapacity,
        UsdPhysXTokens->physxSceneInvertCollisionGroupFilter,
        UsdPhysXTokens->physxSceneMaxBiasCoefficient,
        UsdPhysXTokens->physxSceneMaxPositionIterationCount,
        UsdPhysXTokens->physxSceneMaxVelocityIterationCount,
        UsdPhysXTokens->physxSceneMinPositionIterationCount,
        UsdPhysXTokens->physxSceneMinVelocityIterationCount,
        UsdPhysXTokens->physxSceneReportKinematicKinematicPairs,
        UsdPhysXTokens->physxSceneReportKinematicStaticPairs,
        UsdPhysXTokens->physxSceneSolverType,
        UsdPhysXTokens->physxSceneTimeStepsPerSecond,
        UsdPhysXTokens->physxSceneUpdateType,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdAPISchemaBase::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

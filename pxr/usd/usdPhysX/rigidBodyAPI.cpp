//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/rigidBodyAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXRigidBodyAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXRigidBodyAPI::~UsdPhysXRigidBodyAPI()
{
}

/* static */
UsdPhysXRigidBodyAPI
UsdPhysXRigidBodyAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXRigidBodyAPI();
    }
    return UsdPhysXRigidBodyAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXRigidBodyAPI::_GetSchemaKind() const
{
    return UsdPhysXRigidBodyAPI::schemaKind;
}

/* static */
bool
UsdPhysXRigidBodyAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXRigidBodyAPI>(whyNot);
}

/* static */
UsdPhysXRigidBodyAPI
UsdPhysXRigidBodyAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXRigidBodyAPI>()) {
        return UsdPhysXRigidBodyAPI(prim);
    }
    return UsdPhysXRigidBodyAPI();
}

/* static */
const TfType &
UsdPhysXRigidBodyAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXRigidBodyAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXRigidBodyAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXRigidBodyAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetAngularDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyAngularDamping);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateAngularDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyAngularDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetCfmScaleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyCfmScale);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateCfmScaleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyCfmScale,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetContactSlopCoefficientAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyContactSlopCoefficient);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateContactSlopCoefficientAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyContactSlopCoefficient,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetDisableGravityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyDisableGravity);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateDisableGravityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyDisableGravity,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetEnableCCDAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyEnableCCD);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateEnableCCDAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyEnableCCD,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetEnableGyroscopicForcesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyEnableGyroscopicForces);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateEnableGyroscopicForcesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyEnableGyroscopicForces,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetEnableSpeculativeCCDAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyEnableSpeculativeCCD);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateEnableSpeculativeCCDAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyEnableSpeculativeCCD,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetLinearDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyLinearDamping);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateLinearDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyLinearDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetLockedPosAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyLockedPosAxis);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateLockedPosAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyLockedPosAxis,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetLockedRotAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyLockedRotAxis);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateLockedRotAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyLockedRotAxis,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetMaxAngularVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyMaxAngularVelocity);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateMaxAngularVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyMaxAngularVelocity,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetMaxContactImpulseAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyMaxContactImpulse);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateMaxContactImpulseAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyMaxContactImpulse,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetMaxDepenetrationVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyMaxDepenetrationVelocity);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateMaxDepenetrationVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyMaxDepenetrationVelocity,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetMaxLinearVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyMaxLinearVelocity);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateMaxLinearVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyMaxLinearVelocity,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetRetainAccelerationsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyRetainAccelerations);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateRetainAccelerationsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyRetainAccelerations,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetSleepThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodySleepThreshold);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateSleepThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodySleepThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetSolveContactAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodySolveContact);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateSolveContactAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodySolveContact,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetSolverPositionIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodySolverPositionIterationCount);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateSolverPositionIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodySolverPositionIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetSolverVelocityIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodySolverVelocityIterationCount);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateSolverVelocityIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodySolverVelocityIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXRigidBodyAPI::GetStabilizationThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxRigidBodyStabilizationThreshold);
}

UsdAttribute
UsdPhysXRigidBodyAPI::CreateStabilizationThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxRigidBodyStabilizationThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
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
UsdPhysXRigidBodyAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxRigidBodyAngularDamping,
        UsdPhysXTokens->physxRigidBodyCfmScale,
        UsdPhysXTokens->physxRigidBodyContactSlopCoefficient,
        UsdPhysXTokens->physxRigidBodyDisableGravity,
        UsdPhysXTokens->physxRigidBodyEnableCCD,
        UsdPhysXTokens->physxRigidBodyEnableGyroscopicForces,
        UsdPhysXTokens->physxRigidBodyEnableSpeculativeCCD,
        UsdPhysXTokens->physxRigidBodyLinearDamping,
        UsdPhysXTokens->physxRigidBodyLockedPosAxis,
        UsdPhysXTokens->physxRigidBodyLockedRotAxis,
        UsdPhysXTokens->physxRigidBodyMaxAngularVelocity,
        UsdPhysXTokens->physxRigidBodyMaxContactImpulse,
        UsdPhysXTokens->physxRigidBodyMaxDepenetrationVelocity,
        UsdPhysXTokens->physxRigidBodyMaxLinearVelocity,
        UsdPhysXTokens->physxRigidBodyRetainAccelerations,
        UsdPhysXTokens->physxRigidBodySleepThreshold,
        UsdPhysXTokens->physxRigidBodySolveContact,
        UsdPhysXTokens->physxRigidBodySolverPositionIterationCount,
        UsdPhysXTokens->physxRigidBodySolverVelocityIterationCount,
        UsdPhysXTokens->physxRigidBodyStabilizationThreshold,
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

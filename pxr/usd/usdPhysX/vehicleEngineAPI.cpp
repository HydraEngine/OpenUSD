//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleEngineAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleEngineAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleEngineAPI::~UsdPhysXVehicleEngineAPI()
{
}

/* static */
UsdPhysXVehicleEngineAPI
UsdPhysXVehicleEngineAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleEngineAPI();
    }
    return UsdPhysXVehicleEngineAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleEngineAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleEngineAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleEngineAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleEngineAPI>(whyNot);
}

/* static */
UsdPhysXVehicleEngineAPI
UsdPhysXVehicleEngineAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleEngineAPI>()) {
        return UsdPhysXVehicleEngineAPI(prim);
    }
    return UsdPhysXVehicleEngineAPI();
}

/* static */
const TfType &
UsdPhysXVehicleEngineAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleEngineAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleEngineAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleEngineAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetDampingRateFullThrottleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineDampingRateFullThrottle);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateDampingRateFullThrottleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineDampingRateFullThrottle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetDampingRateZeroThrottleClutchDisengagedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchDisengaged);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateDampingRateZeroThrottleClutchDisengagedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchDisengaged,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetDampingRateZeroThrottleClutchEngagedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchEngaged);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateDampingRateZeroThrottleClutchEngagedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchEngaged,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetIdleRotationSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineIdleRotationSpeed);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateIdleRotationSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineIdleRotationSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetMaxRotationSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineMaxRotationSpeed);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateMaxRotationSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineMaxRotationSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetMoiAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineMoi);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateMoiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineMoi,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetPeakTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEnginePeakTorque);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreatePeakTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEnginePeakTorque,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::GetTorqueCurveAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleEngineTorqueCurve);
}

UsdAttribute
UsdPhysXVehicleEngineAPI::CreateTorqueCurveAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleEngineTorqueCurve,
                       SdfValueTypeNames->Float2Array,
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
UsdPhysXVehicleEngineAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleEngineDampingRateFullThrottle,
        UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchDisengaged,
        UsdPhysXTokens->physxVehicleEngineDampingRateZeroThrottleClutchEngaged,
        UsdPhysXTokens->physxVehicleEngineIdleRotationSpeed,
        UsdPhysXTokens->physxVehicleEngineMaxRotationSpeed,
        UsdPhysXTokens->physxVehicleEngineMoi,
        UsdPhysXTokens->physxVehicleEnginePeakTorque,
        UsdPhysXTokens->physxVehicleEngineTorqueCurve,
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

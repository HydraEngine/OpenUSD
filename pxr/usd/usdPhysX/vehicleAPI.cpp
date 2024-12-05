//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleAPI::~UsdPhysXVehicleAPI()
{
}

/* static */
UsdPhysXVehicleAPI
UsdPhysXVehicleAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleAPI();
    }
    return UsdPhysXVehicleAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleAPI>(whyNot);
}

/* static */
UsdPhysXVehicleAPI
UsdPhysXVehicleAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleAPI>()) {
        return UsdPhysXVehicleAPI(prim);
    }
    return UsdPhysXVehicleAPI();
}

/* static */
const TfType &
UsdPhysXVehicleAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleAPI::GetHighForwardSpeedSubStepCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleHighForwardSpeedSubStepCount);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateHighForwardSpeedSubStepCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleHighForwardSpeedSubStepCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLateralStickyTireDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLateralStickyTireDamping);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLateralStickyTireDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLateralStickyTireDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLateralStickyTireThresholdSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLateralStickyTireThresholdSpeed);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLateralStickyTireThresholdSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLateralStickyTireThresholdSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLateralStickyTireThresholdTimeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLateralStickyTireThresholdTime);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLateralStickyTireThresholdTimeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLateralStickyTireThresholdTime,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLimitSuspensionExpansionVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLimitSuspensionExpansionVelocity);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLimitSuspensionExpansionVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLimitSuspensionExpansionVelocity,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLongitudinalStickyTireDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLongitudinalStickyTireDamping);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLongitudinalStickyTireDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLongitudinalStickyTireDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLongitudinalStickyTireThresholdSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdSpeed);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLongitudinalStickyTireThresholdSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLongitudinalStickyTireThresholdTimeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdTime);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLongitudinalStickyTireThresholdTimeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdTime,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetLowForwardSpeedSubStepCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleLowForwardSpeedSubStepCount);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateLowForwardSpeedSubStepCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleLowForwardSpeedSubStepCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetMinActiveLongitudinalSlipDenominatorAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMinActiveLongitudinalSlipDenominator);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateMinActiveLongitudinalSlipDenominatorAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMinActiveLongitudinalSlipDenominator,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetMinLateralSlipDenominatorAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMinLateralSlipDenominator);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateMinLateralSlipDenominatorAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMinLateralSlipDenominator,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetMinPassiveLongitudinalSlipDenominatorAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMinPassiveLongitudinalSlipDenominator);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateMinPassiveLongitudinalSlipDenominatorAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMinPassiveLongitudinalSlipDenominator,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetSubStepThresholdLongitudinalSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSubStepThresholdLongitudinalSpeed);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateSubStepThresholdLongitudinalSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSubStepThresholdLongitudinalSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetSuspensionLineQueryTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionLineQueryType);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateSuspensionLineQueryTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionLineQueryType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAPI::GetVehicleEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleVehicleEnabled);
}

UsdAttribute
UsdPhysXVehicleAPI::CreateVehicleEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleVehicleEnabled,
                       SdfValueTypeNames->Bool,
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
UsdPhysXVehicleAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleHighForwardSpeedSubStepCount,
        UsdPhysXTokens->physxVehicleLateralStickyTireDamping,
        UsdPhysXTokens->physxVehicleLateralStickyTireThresholdSpeed,
        UsdPhysXTokens->physxVehicleLateralStickyTireThresholdTime,
        UsdPhysXTokens->physxVehicleLimitSuspensionExpansionVelocity,
        UsdPhysXTokens->physxVehicleLongitudinalStickyTireDamping,
        UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdSpeed,
        UsdPhysXTokens->physxVehicleLongitudinalStickyTireThresholdTime,
        UsdPhysXTokens->physxVehicleLowForwardSpeedSubStepCount,
        UsdPhysXTokens->physxVehicleMinActiveLongitudinalSlipDenominator,
        UsdPhysXTokens->physxVehicleMinLateralSlipDenominator,
        UsdPhysXTokens->physxVehicleMinPassiveLongitudinalSlipDenominator,
        UsdPhysXTokens->physxVehicleSubStepThresholdLongitudinalSpeed,
        UsdPhysXTokens->physxVehicleSuspensionLineQueryType,
        UsdPhysXTokens->physxVehicleVehicleEnabled,
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

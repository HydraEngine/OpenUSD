//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraFollowAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCameraFollowAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCameraFollowAPI::~UsdPhysXPhysxCameraFollowAPI()
{
}

/* static */
UsdPhysXPhysxCameraFollowAPI
UsdPhysXPhysxCameraFollowAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCameraFollowAPI();
    }
    return UsdPhysXPhysxCameraFollowAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCameraFollowAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCameraFollowAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCameraFollowAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCameraFollowAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCameraFollowAPI
UsdPhysXPhysxCameraFollowAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCameraFollowAPI>()) {
        return UsdPhysXPhysxCameraFollowAPI(prim);
    }
    return UsdPhysXPhysxCameraFollowAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCameraFollowAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCameraFollowAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCameraFollowAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCameraFollowAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetCameraPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateCameraPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetFollowMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxDistance);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateFollowMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetFollowMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateFollowMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetFollowMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinDistance);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateFollowMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetFollowMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateFollowMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetFollowTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateFollowTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookAheadMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookAheadMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookAheadMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookAheadMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookAheadMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookAheadMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookAheadMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookAheadMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookAheadTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookAheadTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookPositionHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionHeight);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookPositionHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetLookPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateLookPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetPitchAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngle);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreatePitchAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetPitchAngleTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreatePitchAngleTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPositionOffset);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetSlowPitchAngleSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateSlowPitchAngleSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetSlowSpeedPitchAngleScaleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateSlowSpeedPitchAngleScaleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetVelocityNormalMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateVelocityNormalMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetYawAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawAngle);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateYawAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraYawAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::GetYawRateTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawRateTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraFollowAPI::CreateYawRateTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraYawRateTimeConstant,
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
UsdPhysXPhysxCameraFollowAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant,
        UsdPhysXTokens->physxFollowCameraFollowMaxDistance,
        UsdPhysXTokens->physxFollowCameraFollowMaxSpeed,
        UsdPhysXTokens->physxFollowCameraFollowMinDistance,
        UsdPhysXTokens->physxFollowCameraFollowMinSpeed,
        UsdPhysXTokens->physxFollowCameraFollowTurnRateGain,
        UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance,
        UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed,
        UsdPhysXTokens->physxFollowCameraLookAheadMinDistance,
        UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed,
        UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain,
        UsdPhysXTokens->physxFollowCameraLookPositionHeight,
        UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant,
        UsdPhysXTokens->physxFollowCameraPitchAngle,
        UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant,
        UsdPhysXTokens->physxFollowCameraPositionOffset,
        UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed,
        UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale,
        UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed,
        UsdPhysXTokens->physxFollowCameraYawAngle,
        UsdPhysXTokens->physxFollowCameraYawRateTimeConstant,
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

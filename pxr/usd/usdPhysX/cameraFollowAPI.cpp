//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/cameraFollowAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXCameraFollowAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXCameraFollowAPI::~UsdPhysXCameraFollowAPI()
{
}

/* static */
UsdPhysXCameraFollowAPI
UsdPhysXCameraFollowAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXCameraFollowAPI();
    }
    return UsdPhysXCameraFollowAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXCameraFollowAPI::_GetSchemaKind() const
{
    return UsdPhysXCameraFollowAPI::schemaKind;
}

/* static */
bool
UsdPhysXCameraFollowAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXCameraFollowAPI>(whyNot);
}

/* static */
UsdPhysXCameraFollowAPI
UsdPhysXCameraFollowAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXCameraFollowAPI>()) {
        return UsdPhysXCameraFollowAPI(prim);
    }
    return UsdPhysXCameraFollowAPI();
}

/* static */
const TfType &
UsdPhysXCameraFollowAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXCameraFollowAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXCameraFollowAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXCameraFollowAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetCameraPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateCameraPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetFollowMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxDistance);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateFollowMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetFollowMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateFollowMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetFollowMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinDistance);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateFollowMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetFollowMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateFollowMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetFollowTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateFollowTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookAheadMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookAheadMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookAheadMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookAheadMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookAheadMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookAheadMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookAheadMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookAheadMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookAheadTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookAheadTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookPositionHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionHeight);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookPositionHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetLookPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateLookPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetPitchAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngle);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreatePitchAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetPitchAngleTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreatePitchAngleTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPositionOffset);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetSlowPitchAngleSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateSlowPitchAngleSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetSlowSpeedPitchAngleScaleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateSlowSpeedPitchAngleScaleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetVelocityNormalMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateVelocityNormalMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetYawAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawAngle);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateYawAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraYawAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowAPI::GetYawRateTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawRateTimeConstant);
}

UsdAttribute
UsdPhysXCameraFollowAPI::CreateYawRateTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXCameraFollowAPI::GetSchemaAttributeNames(bool includeInherited)
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

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
    TfType::Define<UsdPhysXphysxCameraFollowAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCameraFollowAPI::~UsdPhysXphysxCameraFollowAPI()
{
}

/* static */
UsdPhysXphysxCameraFollowAPI
UsdPhysXphysxCameraFollowAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCameraFollowAPI();
    }
    return UsdPhysXphysxCameraFollowAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCameraFollowAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCameraFollowAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCameraFollowAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCameraFollowAPI>(whyNot);
}

/* static */
UsdPhysXphysxCameraFollowAPI
UsdPhysXphysxCameraFollowAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCameraFollowAPI>()) {
        return UsdPhysXphysxCameraFollowAPI(prim);
    }
    return UsdPhysXphysxCameraFollowAPI();
}

/* static */
const TfType &
UsdPhysXphysxCameraFollowAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCameraFollowAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCameraFollowAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCameraFollowAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetCameraPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateCameraPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraCameraPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetFollowMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxDistance);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateFollowMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetFollowMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateFollowMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetFollowMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinDistance);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateFollowMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetFollowMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowMinSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateFollowMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetFollowTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateFollowTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraFollowTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookAheadMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookAheadMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowFollowCameraLookAheadMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookAheadMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookAheadMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookAheadMinDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookAheadMinDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookAheadMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookAheadMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookAheadTurnRateGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookAheadTurnRateGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookAheadTurnRateGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookPositionHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionHeight);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookPositionHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetLookPositionTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateLookPositionTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraLookPositionTimeConstant,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetPitchAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngle);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreatePitchAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetPitchAngleTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreatePitchAngleTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPitchAngleTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraPositionOffset);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetSlowPitchAngleSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateSlowPitchAngleSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowPitchAngleSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetSlowSpeedPitchAngleScaleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateSlowSpeedPitchAngleScaleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraSlowSpeedPitchAngleScale,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetVelocityNormalMinSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateVelocityNormalMinSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraVelocityNormalMinSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetYawAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawAngle);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateYawAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowCameraYawAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::GetYawRateTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowCameraYawRateTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraFollowAPI::CreateYawRateTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCameraFollowAPI::GetSchemaAttributeNames(bool includeInherited)
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

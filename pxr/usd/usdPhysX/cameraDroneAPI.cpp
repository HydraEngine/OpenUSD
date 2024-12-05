//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/cameraDroneAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXCameraDroneAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXCameraDroneAPI::~UsdPhysXCameraDroneAPI()
{
}

/* static */
UsdPhysXCameraDroneAPI
UsdPhysXCameraDroneAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXCameraDroneAPI();
    }
    return UsdPhysXCameraDroneAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXCameraDroneAPI::_GetSchemaKind() const
{
    return UsdPhysXCameraDroneAPI::schemaKind;
}

/* static */
bool
UsdPhysXCameraDroneAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXCameraDroneAPI>(whyNot);
}

/* static */
UsdPhysXCameraDroneAPI
UsdPhysXCameraDroneAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXCameraDroneAPI>()) {
        return UsdPhysXCameraDroneAPI(prim);
    }
    return UsdPhysXCameraDroneAPI();
}

/* static */
const TfType &
UsdPhysXCameraDroneAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXCameraDroneAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXCameraDroneAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXCameraDroneAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetFeedForwardVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateFeedForwardVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetFollowDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowDistance);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateFollowDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetFollowHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowHeight);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateFollowHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetHorizontalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateHorizontalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxDistance);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxSpeed);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraPositionOffset);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetRotationFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateRotationFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetVelocityFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateVelocityFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraDroneAPI::GetVerticalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVerticalVelocityGain);
}

UsdAttribute
UsdPhysXCameraDroneAPI::CreateVerticalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraVerticalVelocityGain,
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
UsdPhysXCameraDroneAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain,
        UsdPhysXTokens->physxDroneCameraFollowDistance,
        UsdPhysXTokens->physxDroneCameraFollowHeight,
        UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain,
        UsdPhysXTokens->physxDroneCameraMaxDistance,
        UsdPhysXTokens->physxDroneCameraMaxSpeed,
        UsdPhysXTokens->physxDroneCameraPositionOffset,
        UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant,
        UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant,
        UsdPhysXTokens->physxDroneCameraVerticalVelocityGain,
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

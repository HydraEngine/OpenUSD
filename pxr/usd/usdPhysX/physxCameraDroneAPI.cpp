//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraDroneAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCameraDroneAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCameraDroneAPI::~UsdPhysXPhysxCameraDroneAPI()
{
}

/* static */
UsdPhysXPhysxCameraDroneAPI
UsdPhysXPhysxCameraDroneAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCameraDroneAPI();
    }
    return UsdPhysXPhysxCameraDroneAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCameraDroneAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCameraDroneAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCameraDroneAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCameraDroneAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCameraDroneAPI
UsdPhysXPhysxCameraDroneAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCameraDroneAPI>()) {
        return UsdPhysXPhysxCameraDroneAPI(prim);
    }
    return UsdPhysXPhysxCameraDroneAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCameraDroneAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCameraDroneAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCameraDroneAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCameraDroneAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetFeedForwardVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateFeedForwardVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetFollowDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowDistance);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateFollowDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetFollowHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowHeight);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateFollowHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetHorizontalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateHorizontalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxDistance);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraPositionOffset);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetRotationFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateRotationFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetVelocityFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateVelocityFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::GetVerticalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVerticalVelocityGain);
}

UsdAttribute
UsdPhysXPhysxCameraDroneAPI::CreateVerticalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxCameraDroneAPI::GetSchemaAttributeNames(bool includeInherited)
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

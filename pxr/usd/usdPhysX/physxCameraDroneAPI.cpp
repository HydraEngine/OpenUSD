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
    TfType::Define<UsdPhysXphysxCameraDroneAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCameraDroneAPI::~UsdPhysXphysxCameraDroneAPI()
{
}

/* static */
UsdPhysXphysxCameraDroneAPI
UsdPhysXphysxCameraDroneAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCameraDroneAPI();
    }
    return UsdPhysXphysxCameraDroneAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCameraDroneAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCameraDroneAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCameraDroneAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCameraDroneAPI>(whyNot);
}

/* static */
UsdPhysXphysxCameraDroneAPI
UsdPhysXphysxCameraDroneAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCameraDroneAPI>()) {
        return UsdPhysXphysxCameraDroneAPI(prim);
    }
    return UsdPhysXphysxCameraDroneAPI();
}

/* static */
const TfType &
UsdPhysXphysxCameraDroneAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCameraDroneAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCameraDroneAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCameraDroneAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetFeedForwardVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateFeedForwardVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFeedForwardVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetFollowDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowDistance);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateFollowDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetFollowHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraFollowHeight);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateFollowHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraFollowHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetHorizontalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateHorizontalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraHorizontalVelocityGain,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetMaxDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxDistance);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateMaxDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetMaxSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraMaxSpeed);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateMaxSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraMaxSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetPositionOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraPositionOffset);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreatePositionOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraPositionOffset,
                       SdfValueTypeNames->Float3,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetRotationFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateRotationFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraRotationFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetVelocityFilterTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateVelocityFilterTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxDroneCameraVelocityFilterTimeConstant,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::GetVerticalVelocityGainAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxDroneCameraVerticalVelocityGain);
}

UsdAttribute
UsdPhysXphysxCameraDroneAPI::CreateVerticalVelocityGainAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCameraDroneAPI::GetSchemaAttributeNames(bool includeInherited)
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

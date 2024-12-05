//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/cameraFollowLookAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXCameraFollowLookAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXCameraFollowLookAPI::~UsdPhysXCameraFollowLookAPI()
{
}

/* static */
UsdPhysXCameraFollowLookAPI
UsdPhysXCameraFollowLookAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXCameraFollowLookAPI();
    }
    return UsdPhysXCameraFollowLookAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXCameraFollowLookAPI::_GetSchemaKind() const
{
    return UsdPhysXCameraFollowLookAPI::schemaKind;
}

/* static */
bool
UsdPhysXCameraFollowLookAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXCameraFollowLookAPI>(whyNot);
}

/* static */
UsdPhysXCameraFollowLookAPI
UsdPhysXCameraFollowLookAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXCameraFollowLookAPI>()) {
        return UsdPhysXCameraFollowLookAPI(prim);
    }
    return UsdPhysXCameraFollowLookAPI();
}

/* static */
const TfType &
UsdPhysXCameraFollowLookAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXCameraFollowLookAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXCameraFollowLookAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXCameraFollowLookAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetDownHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateDownHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetDownHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateDownHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetFollowReverseDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateFollowReverseDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetFollowReverseSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateFollowReverseSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetUpHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateUpHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetUpHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateUpHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::GetVelocityBlendTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraVelocityBlendTimeConstant);
}

UsdAttribute
UsdPhysXCameraFollowLookAPI::CreateVelocityBlendTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraVelocityBlendTimeConstant,
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
UsdPhysXCameraFollowLookAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle,
        UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch,
        UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance,
        UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed,
        UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle,
        UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch,
        UsdPhysXTokens->physxFollowLookCameraVelocityBlendTimeConstant,
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

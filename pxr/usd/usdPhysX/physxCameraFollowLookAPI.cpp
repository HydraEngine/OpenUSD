//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraFollowLookAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCameraFollowLookAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCameraFollowLookAPI::~UsdPhysXPhysxCameraFollowLookAPI()
{
}

/* static */
UsdPhysXPhysxCameraFollowLookAPI
UsdPhysXPhysxCameraFollowLookAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCameraFollowLookAPI();
    }
    return UsdPhysXPhysxCameraFollowLookAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCameraFollowLookAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCameraFollowLookAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCameraFollowLookAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCameraFollowLookAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCameraFollowLookAPI
UsdPhysXPhysxCameraFollowLookAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCameraFollowLookAPI>()) {
        return UsdPhysXPhysxCameraFollowLookAPI(prim);
    }
    return UsdPhysXPhysxCameraFollowLookAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCameraFollowLookAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCameraFollowLookAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCameraFollowLookAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCameraFollowLookAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetDownHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateDownHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetDownHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateDownHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetFollowReverseDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateFollowReverseDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetFollowReverseSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateFollowReverseSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetUpHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateUpHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetUpHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateUpHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::GetVelocityBlendTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraVelocityBlendTimeConstant);
}

UsdAttribute
UsdPhysXPhysxCameraFollowLookAPI::CreateVelocityBlendTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxCameraFollowLookAPI::GetSchemaAttributeNames(bool includeInherited)
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

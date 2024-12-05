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
    TfType::Define<UsdPhysXphysxCameraFollowLookAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCameraFollowLookAPI::~UsdPhysXphysxCameraFollowLookAPI()
{
}

/* static */
UsdPhysXphysxCameraFollowLookAPI
UsdPhysXphysxCameraFollowLookAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCameraFollowLookAPI();
    }
    return UsdPhysXphysxCameraFollowLookAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCameraFollowLookAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCameraFollowLookAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCameraFollowLookAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCameraFollowLookAPI>(whyNot);
}

/* static */
UsdPhysXphysxCameraFollowLookAPI
UsdPhysXphysxCameraFollowLookAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCameraFollowLookAPI>()) {
        return UsdPhysXphysxCameraFollowLookAPI(prim);
    }
    return UsdPhysXphysxCameraFollowLookAPI();
}

/* static */
const TfType &
UsdPhysXphysxCameraFollowLookAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCameraFollowLookAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCameraFollowLookAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCameraFollowLookAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetDownHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateDownHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetDownHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateDownHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraDownHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetFollowReverseDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateFollowReverseDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseDistance,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetFollowReverseSpeedAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateFollowReverseSpeedAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraFollowReverseSpeed,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetUpHillGroundAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateUpHillGroundAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetUpHillGroundPitchAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateUpHillGroundPitchAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxFollowLookCameraUpHillGroundPitch,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::GetVelocityBlendTimeConstantAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxFollowLookCameraVelocityBlendTimeConstant);
}

UsdAttribute
UsdPhysXphysxCameraFollowLookAPI::CreateVelocityBlendTimeConstantAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCameraFollowLookAPI::GetSchemaAttributeNames(bool includeInherited)
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

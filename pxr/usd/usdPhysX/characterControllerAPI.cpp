//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/characterControllerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXCharacterControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXCharacterControllerAPI::~UsdPhysXCharacterControllerAPI()
{
}

/* static */
UsdPhysXCharacterControllerAPI
UsdPhysXCharacterControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXCharacterControllerAPI();
    }
    return UsdPhysXCharacterControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXCharacterControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXCharacterControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXCharacterControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXCharacterControllerAPI>(whyNot);
}

/* static */
UsdPhysXCharacterControllerAPI
UsdPhysXCharacterControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXCharacterControllerAPI>()) {
        return UsdPhysXCharacterControllerAPI(prim);
    }
    return UsdPhysXCharacterControllerAPI();
}

/* static */
const TfType &
UsdPhysXCharacterControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXCharacterControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXCharacterControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXCharacterControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetClimbingModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerClimbingMode);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateClimbingModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerClimbingMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetContactOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerContactOffset);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateContactOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerContactOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetInvisibleWallHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateInvisibleWallHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetMaxJumpHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateMaxJumpHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetMoveTargetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMoveTarget);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateMoveTargetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMoveTarget,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetNonWalkableModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerNonWalkableMode);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateNonWalkableModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerNonWalkableMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetScaleCoeffAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerScaleCoeff);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateScaleCoeffAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerScaleCoeff,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetSlopeLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerSlopeLimit);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateSlopeLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerSlopeLimit,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetStepOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerStepOffset);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateStepOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerStepOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetUpAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerUpAxis);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateUpAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerUpAxis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::GetVolumeGrowthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerVolumeGrowth);
}

UsdAttribute
UsdPhysXCharacterControllerAPI::CreateVolumeGrowthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerVolumeGrowth,
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
UsdPhysXCharacterControllerAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxCharacterControllerClimbingMode,
        UsdPhysXTokens->physxCharacterControllerContactOffset,
        UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight,
        UsdPhysXTokens->physxCharacterControllerMaxJumpHeight,
        UsdPhysXTokens->physxCharacterControllerMoveTarget,
        UsdPhysXTokens->physxCharacterControllerNonWalkableMode,
        UsdPhysXTokens->physxCharacterControllerScaleCoeff,
        UsdPhysXTokens->physxCharacterControllerSlopeLimit,
        UsdPhysXTokens->physxCharacterControllerStepOffset,
        UsdPhysXTokens->physxCharacterControllerUpAxis,
        UsdPhysXTokens->physxCharacterControllerVolumeGrowth,
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

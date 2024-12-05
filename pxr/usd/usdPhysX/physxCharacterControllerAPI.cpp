//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCharacterControllerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCharacterControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCharacterControllerAPI::~UsdPhysXPhysxCharacterControllerAPI()
{
}

/* static */
UsdPhysXPhysxCharacterControllerAPI
UsdPhysXPhysxCharacterControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCharacterControllerAPI();
    }
    return UsdPhysXPhysxCharacterControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCharacterControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCharacterControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCharacterControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCharacterControllerAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCharacterControllerAPI
UsdPhysXPhysxCharacterControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCharacterControllerAPI>()) {
        return UsdPhysXPhysxCharacterControllerAPI(prim);
    }
    return UsdPhysXPhysxCharacterControllerAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCharacterControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCharacterControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCharacterControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCharacterControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetClimbingModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerClimbingMode);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateClimbingModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerClimbingMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetContactOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerContactOffset);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateContactOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerContactOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetInvisibleWallHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateInvisibleWallHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetMaxJumpHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateMaxJumpHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetMoveTargetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMoveTarget);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateMoveTargetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMoveTarget,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetNonWalkableModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerNonWalkableMode);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateNonWalkableModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerNonWalkableMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetScaleCoeffAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerScaleCoeff);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateScaleCoeffAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerScaleCoeff,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetSlopeLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerSlopeLimit);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateSlopeLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerSlopeLimit,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetStepOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerStepOffset);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateStepOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerStepOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetUpAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerUpAxis);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateUpAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerUpAxis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::GetVolumeGrowthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerVolumeGrowth);
}

UsdAttribute
UsdPhysXPhysxCharacterControllerAPI::CreateVolumeGrowthAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxCharacterControllerAPI::GetSchemaAttributeNames(bool includeInherited)
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

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
    TfType::Define<UsdPhysXphysxCharacterControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCharacterControllerAPI::~UsdPhysXphysxCharacterControllerAPI()
{
}

/* static */
UsdPhysXphysxCharacterControllerAPI
UsdPhysXphysxCharacterControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCharacterControllerAPI();
    }
    return UsdPhysXphysxCharacterControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCharacterControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCharacterControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCharacterControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCharacterControllerAPI>(whyNot);
}

/* static */
UsdPhysXphysxCharacterControllerAPI
UsdPhysXphysxCharacterControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCharacterControllerAPI>()) {
        return UsdPhysXphysxCharacterControllerAPI(prim);
    }
    return UsdPhysXphysxCharacterControllerAPI();
}

/* static */
const TfType &
UsdPhysXphysxCharacterControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCharacterControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCharacterControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCharacterControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetClimbingModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerClimbingMode);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateClimbingModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerClimbingMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetContactOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerContactOffset);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateContactOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerContactOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetInvisibleWallHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateInvisibleWallHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerInvisibleWallHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetMaxJumpHeightAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateMaxJumpHeightAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMaxJumpHeight,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetMoveTargetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerMoveTarget);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateMoveTargetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerMoveTarget,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetNonWalkableModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerNonWalkableMode);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateNonWalkableModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerNonWalkableMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetScaleCoeffAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerScaleCoeff);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateScaleCoeffAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerScaleCoeff,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetSlopeLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerSlopeLimit);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateSlopeLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerSlopeLimit,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetStepOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerStepOffset);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateStepOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerStepOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetUpAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerUpAxis);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateUpAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCharacterControllerUpAxis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::GetVolumeGrowthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCharacterControllerVolumeGrowth);
}

UsdAttribute
UsdPhysXphysxCharacterControllerAPI::CreateVolumeGrowthAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCharacterControllerAPI::GetSchemaAttributeNames(bool includeInherited)
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxMaterialAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXphysxMaterialAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxMaterialAPI::~UsdPhysXphysxMaterialAPI()
{
}

/* static */
UsdPhysXphysxMaterialAPI
UsdPhysXphysxMaterialAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxMaterialAPI();
    }
    return UsdPhysXphysxMaterialAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxMaterialAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxMaterialAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxMaterialAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxMaterialAPI>(whyNot);
}

/* static */
UsdPhysXphysxMaterialAPI
UsdPhysXphysxMaterialAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxMaterialAPI>()) {
        return UsdPhysXphysxMaterialAPI(prim);
    }
    return UsdPhysXphysxMaterialAPI();
}

/* static */
const TfType &
UsdPhysXphysxMaterialAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxMaterialAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxMaterialAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxMaterialAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetCompliantContactAccelerationSpringAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialCompliantContactAccelerationSpring);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateCompliantContactAccelerationSpringAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialCompliantContactAccelerationSpring,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetCompliantContactDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialCompliantContactDamping);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateCompliantContactDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialCompliantContactDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetCompliantContactStiffnessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialCompliantContactStiffness);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateCompliantContactStiffnessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialCompliantContactStiffness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetDampingCombineModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialDampingCombineMode);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateDampingCombineModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialDampingCombineMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetFrictionCombineModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialFrictionCombineMode);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateFrictionCombineModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialFrictionCombineMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::GetRestitutionCombineModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxMaterialRestitutionCombineMode);
}

UsdAttribute
UsdPhysXphysxMaterialAPI::CreateRestitutionCombineModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxMaterialRestitutionCombineMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
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
UsdPhysXphysxMaterialAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxMaterialCompliantContactAccelerationSpring,
        UsdPhysXTokens->physxMaterialCompliantContactDamping,
        UsdPhysXTokens->physxMaterialCompliantContactStiffness,
        UsdPhysXTokens->physxMaterialDampingCombineMode,
        UsdPhysXTokens->physxMaterialFrictionCombineMode,
        UsdPhysXTokens->physxMaterialRestitutionCombineMode,
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

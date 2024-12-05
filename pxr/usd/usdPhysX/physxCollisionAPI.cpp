//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCollisionAPI::~UsdPhysXPhysxCollisionAPI()
{
}

/* static */
UsdPhysXPhysxCollisionAPI
UsdPhysXPhysxCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCollisionAPI();
    }
    return UsdPhysXPhysxCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCollisionAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCollisionAPI
UsdPhysXPhysxCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCollisionAPI>()) {
        return UsdPhysXPhysxCollisionAPI(prim);
    }
    return UsdPhysXPhysxCollisionAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::GetContactOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionContactOffset);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::CreateContactOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionContactOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::GetMinTorsionalPatchRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionMinTorsionalPatchRadius);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::CreateMinTorsionalPatchRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionMinTorsionalPatchRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::GetRestOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionRestOffset);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::CreateRestOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionRestOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::GetTorsionalPatchRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionTorsionalPatchRadius);
}

UsdAttribute
UsdPhysXPhysxCollisionAPI::CreateTorsionalPatchRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionTorsionalPatchRadius,
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
UsdPhysXPhysxCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxCollisionContactOffset,
        UsdPhysXTokens->physxCollisionMinTorsionalPatchRadius,
        UsdPhysXTokens->physxCollisionRestOffset,
        UsdPhysXTokens->physxCollisionTorsionalPatchRadius,
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

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
    TfType::Define<UsdPhysXphysxCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCollisionAPI::~UsdPhysXphysxCollisionAPI()
{
}

/* static */
UsdPhysXphysxCollisionAPI
UsdPhysXphysxCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCollisionAPI();
    }
    return UsdPhysXphysxCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCollisionAPI>(whyNot);
}

/* static */
UsdPhysXphysxCollisionAPI
UsdPhysXphysxCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCollisionAPI>()) {
        return UsdPhysXphysxCollisionAPI(prim);
    }
    return UsdPhysXphysxCollisionAPI();
}

/* static */
const TfType &
UsdPhysXphysxCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxCollisionAPI::GetContactOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionContactOffset);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::CreateContactOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionContactOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::GetMinTorsionalPatchRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionMinTorsionalPatchRadius);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::CreateMinTorsionalPatchRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionMinTorsionalPatchRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::GetRestOffsetAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionRestOffset);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::CreateRestOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxCollisionRestOffset,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::GetTorsionalPatchRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxCollisionTorsionalPatchRadius);
}

UsdAttribute
UsdPhysXphysxCollisionAPI::CreateTorsionalPatchRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
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

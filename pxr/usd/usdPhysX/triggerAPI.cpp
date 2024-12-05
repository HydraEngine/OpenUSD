//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/triggerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXTriggerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXTriggerAPI::~UsdPhysXTriggerAPI()
{
}

/* static */
UsdPhysXTriggerAPI
UsdPhysXTriggerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXTriggerAPI();
    }
    return UsdPhysXTriggerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXTriggerAPI::_GetSchemaKind() const
{
    return UsdPhysXTriggerAPI::schemaKind;
}

/* static */
bool
UsdPhysXTriggerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXTriggerAPI>(whyNot);
}

/* static */
UsdPhysXTriggerAPI
UsdPhysXTriggerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXTriggerAPI>()) {
        return UsdPhysXTriggerAPI(prim);
    }
    return UsdPhysXTriggerAPI();
}

/* static */
const TfType &
UsdPhysXTriggerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXTriggerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXTriggerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXTriggerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXTriggerAPI::GetEnterScriptTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriggerEnterScriptType);
}

UsdAttribute
UsdPhysXTriggerAPI::CreateEnterScriptTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriggerEnterScriptType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXTriggerAPI::GetLeaveScriptTypeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriggerLeaveScriptType);
}

UsdAttribute
UsdPhysXTriggerAPI::CreateLeaveScriptTypeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriggerLeaveScriptType,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXTriggerAPI::GetOnEnterScriptAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriggerOnEnterScript);
}

UsdAttribute
UsdPhysXTriggerAPI::CreateOnEnterScriptAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriggerOnEnterScript,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXTriggerAPI::GetOnLeaveScriptAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriggerOnLeaveScript);
}

UsdAttribute
UsdPhysXTriggerAPI::CreateOnLeaveScriptAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriggerOnLeaveScript,
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
UsdPhysXTriggerAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxTriggerEnterScriptType,
        UsdPhysXTokens->physxTriggerLeaveScriptType,
        UsdPhysXTokens->physxTriggerOnEnterScript,
        UsdPhysXTokens->physxTriggerOnLeaveScript,
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

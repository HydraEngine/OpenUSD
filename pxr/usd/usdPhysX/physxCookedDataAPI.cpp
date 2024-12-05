//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCookedDataAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCookedDataAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCookedDataAPI::~UsdPhysXPhysxCookedDataAPI()
{
}

/* static */
UsdPhysXPhysxCookedDataAPI
UsdPhysXPhysxCookedDataAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCookedDataAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxCookedDataAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid physxCookedData path <%s>.", path.GetText());
        return UsdPhysXPhysxCookedDataAPI();
    }
    return UsdPhysXPhysxCookedDataAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXPhysxCookedDataAPI
UsdPhysXPhysxCookedDataAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXPhysxCookedDataAPI(prim, name);
}

/* static */
std::vector<UsdPhysXPhysxCookedDataAPI>
UsdPhysXPhysxCookedDataAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXPhysxCookedDataAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXPhysxCookedDataAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->physxCookedData_MultipleApplyTemplate_Buffer),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPhysXPhysxCookedDataAPI::IsPhysxSchemaPhysxCookedDataAPIPath(
    const SdfPath &path, TfToken *name)
{
    if (!path.IsPropertyPath()) {
        return false;
    }

    std::string propertyName = path.GetName();
    TfTokenVector tokens = SdfPath::TokenizeIdentifierAsTokens(propertyName);

    // The baseName of the  path can't be one of the 
    // schema properties. We should validate this in the creation (or apply)
    // API.
    TfToken baseName = *tokens.rbegin();
    if (IsSchemaPropertyBaseName(baseName)) {
        return false;
    }

    if (tokens.size() >= 2
        && tokens[0] == UsdPhysXTokens->physxCookedData) {
        *name = TfToken(propertyName.substr(
           UsdPhysXTokens->physxCookedData.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPhysXPhysxCookedDataAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCookedDataAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCookedDataAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCookedDataAPI>(name, whyNot);
}

/* static */
UsdPhysXPhysxCookedDataAPI
UsdPhysXPhysxCookedDataAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCookedDataAPI>(name)) {
        return UsdPhysXPhysxCookedDataAPI(prim, name);
    }
    return UsdPhysXPhysxCookedDataAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCookedDataAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCookedDataAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCookedDataAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCookedDataAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/// Returns the property name prefixed with the correct namespace prefix, which
/// is composed of the the API's propertyNamespacePrefix metadata and the
/// instance name of the API.
static inline
TfToken
_GetNamespacedPropertyName(const TfToken instanceName, const TfToken propName)
{
    return UsdSchemaRegistry::MakeMultipleApplyNameInstance(propName, instanceName);
}

UsdAttribute
UsdPhysXPhysxCookedDataAPI::GetBufferAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxCookedData_MultipleApplyTemplate_Buffer));
}

UsdAttribute
UsdPhysXPhysxCookedDataAPI::CreateBufferAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->physxCookedData_MultipleApplyTemplate_Buffer),
                       SdfValueTypeNames->UCharArray,
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
UsdPhysXPhysxCookedDataAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxCookedData_MultipleApplyTemplate_Buffer,
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

/*static*/
TfTokenVector
UsdPhysXPhysxCookedDataAPI::GetSchemaAttributeNames(
    bool includeInherited, const TfToken &instanceName)
{
    const TfTokenVector &attrNames = GetSchemaAttributeNames(includeInherited);
    if (instanceName.IsEmpty()) {
        return attrNames;
    }
    TfTokenVector result;
    result.reserve(attrNames.size());
    for (const TfToken &attrName : attrNames) {
        result.push_back(
            UsdSchemaRegistry::MakeMultipleApplyNameInstance(attrName, instanceName));
    }
    return result;
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

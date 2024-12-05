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
    TfType::Define<UsdPhysXphysxCookedDataAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCookedDataAPI::~UsdPhysXphysxCookedDataAPI()
{
}

/* static */
UsdPhysXphysxCookedDataAPI
UsdPhysXphysxCookedDataAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCookedDataAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxCookedDataAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid physxCookedData path <%s>.", path.GetText());
        return UsdPhysXphysxCookedDataAPI();
    }
    return UsdPhysXphysxCookedDataAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXphysxCookedDataAPI
UsdPhysXphysxCookedDataAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXphysxCookedDataAPI(prim, name);
}

/* static */
std::vector<UsdPhysXphysxCookedDataAPI>
UsdPhysXphysxCookedDataAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXphysxCookedDataAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXphysxCookedDataAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
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
UsdPhysXphysxCookedDataAPI::IsPhysxSchemaPhysxCookedDataAPIPath(
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
UsdSchemaKind UsdPhysXphysxCookedDataAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCookedDataAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCookedDataAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCookedDataAPI>(name, whyNot);
}

/* static */
UsdPhysXphysxCookedDataAPI
UsdPhysXphysxCookedDataAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXphysxCookedDataAPI>(name)) {
        return UsdPhysXphysxCookedDataAPI(prim, name);
    }
    return UsdPhysXphysxCookedDataAPI();
}

/* static */
const TfType &
UsdPhysXphysxCookedDataAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCookedDataAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCookedDataAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCookedDataAPI::_GetTfType() const
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
UsdPhysXphysxCookedDataAPI::GetBufferAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxCookedData_MultipleApplyTemplate_Buffer));
}

UsdAttribute
UsdPhysXphysxCookedDataAPI::CreateBufferAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxCookedDataAPI::GetSchemaAttributeNames(bool includeInherited)
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
UsdPhysXphysxCookedDataAPI::GetSchemaAttributeNames(
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/mimicJointAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXMimicJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXMimicJointAPI::~UsdPhysXMimicJointAPI()
{
}

/* static */
UsdPhysXMimicJointAPI
UsdPhysXMimicJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXMimicJointAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxMimicJointAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid physxMimicJoint path <%s>.", path.GetText());
        return UsdPhysXMimicJointAPI();
    }
    return UsdPhysXMimicJointAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXMimicJointAPI
UsdPhysXMimicJointAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXMimicJointAPI(prim, name);
}

/* static */
std::vector<UsdPhysXMimicJointAPI>
UsdPhysXMimicJointAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXMimicJointAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXMimicJointAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Gearing),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Offset),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPhysXMimicJointAPI::IsPhysxSchemaPhysxMimicJointAPIPath(
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
        && tokens[0] == UsdPhysXTokens->physxMimicJoint) {
        *name = TfToken(propertyName.substr(
           UsdPhysXTokens->physxMimicJoint.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPhysXMimicJointAPI::_GetSchemaKind() const
{
    return UsdPhysXMimicJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXMimicJointAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXMimicJointAPI>(name, whyNot);
}

/* static */
UsdPhysXMimicJointAPI
UsdPhysXMimicJointAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXMimicJointAPI>(name)) {
        return UsdPhysXMimicJointAPI(prim, name);
    }
    return UsdPhysXMimicJointAPI();
}

/* static */
const TfType &
UsdPhysXMimicJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXMimicJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXMimicJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXMimicJointAPI::_GetTfType() const
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
UsdPhysXMimicJointAPI::GetGearingAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Gearing));
}

UsdAttribute
UsdPhysXMimicJointAPI::CreateGearingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Gearing),
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXMimicJointAPI::GetOffsetAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Offset));
}

UsdAttribute
UsdPhysXMimicJointAPI::CreateOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Offset),
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXMimicJointAPI::GetReferenceJointAxisAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis));
}

UsdAttribute
UsdPhysXMimicJointAPI::CreateReferenceJointAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis),
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
UsdPhysXMimicJointAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Gearing,
        UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Offset,
        UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis,
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
UsdPhysXMimicJointAPI::GetSchemaAttributeNames(
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

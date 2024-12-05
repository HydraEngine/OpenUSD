//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxMimicJointAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxMimicJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxMimicJointAPI::~UsdPhysXPhysxMimicJointAPI()
{
}

/* static */
UsdPhysXPhysxMimicJointAPI
UsdPhysXPhysxMimicJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxMimicJointAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxMimicJointAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid physxMimicJoint path <%s>.", path.GetText());
        return UsdPhysXPhysxMimicJointAPI();
    }
    return UsdPhysXPhysxMimicJointAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXPhysxMimicJointAPI
UsdPhysXPhysxMimicJointAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXPhysxMimicJointAPI(prim, name);
}

/* static */
std::vector<UsdPhysXPhysxMimicJointAPI>
UsdPhysXPhysxMimicJointAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXPhysxMimicJointAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXPhysxMimicJointAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
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
UsdPhysXPhysxMimicJointAPI::IsPhysxSchemaPhysxMimicJointAPIPath(
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
UsdSchemaKind UsdPhysXPhysxMimicJointAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxMimicJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxMimicJointAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxMimicJointAPI>(name, whyNot);
}

/* static */
UsdPhysXPhysxMimicJointAPI
UsdPhysXPhysxMimicJointAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXPhysxMimicJointAPI>(name)) {
        return UsdPhysXPhysxMimicJointAPI(prim, name);
    }
    return UsdPhysXPhysxMimicJointAPI();
}

/* static */
const TfType &
UsdPhysXPhysxMimicJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxMimicJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxMimicJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxMimicJointAPI::_GetTfType() const
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
UsdPhysXPhysxMimicJointAPI::GetGearingAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Gearing));
}

UsdAttribute
UsdPhysXPhysxMimicJointAPI::CreateGearingAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxMimicJointAPI::GetOffsetAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_Offset));
}

UsdAttribute
UsdPhysXPhysxMimicJointAPI::CreateOffsetAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxMimicJointAPI::GetReferenceJointAxisAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis));
}

UsdAttribute
UsdPhysXPhysxMimicJointAPI::CreateReferenceJointAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxMimicJointAPI::GetSchemaAttributeNames(bool includeInherited)
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
UsdPhysXPhysxMimicJointAPI::GetSchemaAttributeNames(
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

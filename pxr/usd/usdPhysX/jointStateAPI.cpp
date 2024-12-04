//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/jointStateAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXJointStateAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXJointStateAPI::~UsdPhysXJointStateAPI()
{
}

/* static */
UsdPhysXJointStateAPI
UsdPhysXJointStateAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXJointStateAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaJointStateAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid jointState path <%s>.", path.GetText());
        return UsdPhysXJointStateAPI();
    }
    return UsdPhysXJointStateAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXJointStateAPI
UsdPhysXJointStateAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXJointStateAPI(prim, name);
}

/* static */
std::vector<UsdPhysXJointStateAPI>
UsdPhysXJointStateAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXJointStateAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXJointStateAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsPosition),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsVelocity),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPhysXJointStateAPI::IsPhysxSchemaJointStateAPIPath(
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
        && tokens[0] == UsdPhysXTokens->jointState) {
        *name = TfToken(propertyName.substr(
           UsdPhysXTokens->jointState.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPhysXJointStateAPI::_GetSchemaKind() const
{
    return UsdPhysXJointStateAPI::schemaKind;
}

/* static */
bool
UsdPhysXJointStateAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXJointStateAPI>(name, whyNot);
}

/* static */
UsdPhysXJointStateAPI
UsdPhysXJointStateAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXJointStateAPI>(name)) {
        return UsdPhysXJointStateAPI(prim, name);
    }
    return UsdPhysXJointStateAPI();
}

/* static */
const TfType &
UsdPhysXJointStateAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXJointStateAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXJointStateAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXJointStateAPI::_GetTfType() const
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
UsdPhysXJointStateAPI::GetPositionAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsPosition));
}

UsdAttribute
UsdPhysXJointStateAPI::CreatePositionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsPosition),
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXJointStateAPI::GetVelocityAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsVelocity));
}

UsdAttribute
UsdPhysXJointStateAPI::CreateVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsVelocity),
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
UsdPhysXJointStateAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsPosition,
        UsdPhysXTokens->jointState_MultipleApplyTemplate_PhysicsVelocity,
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
UsdPhysXJointStateAPI::GetSchemaAttributeNames(
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

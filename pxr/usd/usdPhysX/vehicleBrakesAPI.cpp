//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleBrakesAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleBrakesAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleBrakesAPI::~UsdPhysXVehicleBrakesAPI()
{
}

/* static */
UsdPhysXVehicleBrakesAPI
UsdPhysXVehicleBrakesAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleBrakesAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxVehicleBrakesAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid vehicleBrakes path <%s>.", path.GetText());
        return UsdPhysXVehicleBrakesAPI();
    }
    return UsdPhysXVehicleBrakesAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXVehicleBrakesAPI
UsdPhysXVehicleBrakesAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXVehicleBrakesAPI(prim, name);
}

/* static */
std::vector<UsdPhysXVehicleBrakesAPI>
UsdPhysXVehicleBrakesAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXVehicleBrakesAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXVehicleBrakesAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_MaxBrakeTorque),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_TorqueMultipliers),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_Wheels),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPhysXVehicleBrakesAPI::IsPhysxSchemaPhysxVehicleBrakesAPIPath(
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
        && tokens[0] == UsdPhysXTokens->vehicleBrakes) {
        *name = TfToken(propertyName.substr(
           UsdPhysXTokens->vehicleBrakes.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPhysXVehicleBrakesAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleBrakesAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleBrakesAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleBrakesAPI>(name, whyNot);
}

/* static */
UsdPhysXVehicleBrakesAPI
UsdPhysXVehicleBrakesAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXVehicleBrakesAPI>(name)) {
        return UsdPhysXVehicleBrakesAPI(prim, name);
    }
    return UsdPhysXVehicleBrakesAPI();
}

/* static */
const TfType &
UsdPhysXVehicleBrakesAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleBrakesAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleBrakesAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleBrakesAPI::_GetTfType() const
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
UsdPhysXVehicleBrakesAPI::GetMaxBrakeTorqueAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_MaxBrakeTorque));
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateMaxBrakeTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_MaxBrakeTorque),
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::GetTorqueMultipliersAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_TorqueMultipliers));
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateTorqueMultipliersAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_TorqueMultipliers),
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::GetWheelsAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_Wheels));
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateWheelsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_Wheels),
                       SdfValueTypeNames->IntArray,
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
UsdPhysXVehicleBrakesAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_MaxBrakeTorque,
        UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_TorqueMultipliers,
        UsdPhysXTokens->vehicleBrakes_MultipleApplyTemplate_Wheels,
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
UsdPhysXVehicleBrakesAPI::GetSchemaAttributeNames(
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

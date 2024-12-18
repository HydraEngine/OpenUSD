//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleNonlinearCommandResponseAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleNonlinearCommandResponseAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleNonlinearCommandResponseAPI::~UsdPhysXVehicleNonlinearCommandResponseAPI()
{
}

/* static */
UsdPhysXVehicleNonlinearCommandResponseAPI
UsdPhysXVehicleNonlinearCommandResponseAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleNonlinearCommandResponseAPI();
    }
    TfToken name;
    if (!IsPhysxSchemaPhysxVehicleNonlinearCommandResponseAPIPath(path, &name)) {
        TF_CODING_ERROR("Invalid vehicleNonlinearCommandResponse path <%s>.", path.GetText());
        return UsdPhysXVehicleNonlinearCommandResponseAPI();
    }
    return UsdPhysXVehicleNonlinearCommandResponseAPI(stage->GetPrimAtPath(path.GetPrimPath()), name);
}

UsdPhysXVehicleNonlinearCommandResponseAPI
UsdPhysXVehicleNonlinearCommandResponseAPI::Get(const UsdPrim &prim, const TfToken &name)
{
    return UsdPhysXVehicleNonlinearCommandResponseAPI(prim, name);
}

/* static */
std::vector<UsdPhysXVehicleNonlinearCommandResponseAPI>
UsdPhysXVehicleNonlinearCommandResponseAPI::GetAll(const UsdPrim &prim)
{
    std::vector<UsdPhysXVehicleNonlinearCommandResponseAPI> schemas;
    
    for (const auto &schemaName :
         UsdAPISchemaBase::_GetMultipleApplyInstanceNames(prim, _GetStaticTfType())) {
        schemas.emplace_back(prim, schemaName);
    }

    return schemas;
}


/* static */
bool 
UsdPhysXVehicleNonlinearCommandResponseAPI::IsSchemaPropertyBaseName(const TfToken &baseName)
{
    static TfTokenVector attrsAndRels = {
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_CommandValues),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponses),
        UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName(
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponsesPerCommandValue),
    };

    return find(attrsAndRels.begin(), attrsAndRels.end(), baseName)
            != attrsAndRels.end();
}

/* static */
bool
UsdPhysXVehicleNonlinearCommandResponseAPI::IsPhysxSchemaPhysxVehicleNonlinearCommandResponseAPIPath(
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
        && tokens[0] == UsdPhysXTokens->vehicleNonlinearCommandResponse) {
        *name = TfToken(propertyName.substr(
           UsdPhysXTokens->vehicleNonlinearCommandResponse.GetString().size() + 1));
        return true;
    }

    return false;
}

/* virtual */
UsdSchemaKind UsdPhysXVehicleNonlinearCommandResponseAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleNonlinearCommandResponseAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleNonlinearCommandResponseAPI::CanApply(
    const UsdPrim &prim, const TfToken &name, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleNonlinearCommandResponseAPI>(name, whyNot);
}

/* static */
UsdPhysXVehicleNonlinearCommandResponseAPI
UsdPhysXVehicleNonlinearCommandResponseAPI::Apply(const UsdPrim &prim, const TfToken &name)
{
    if (prim.ApplyAPI<UsdPhysXVehicleNonlinearCommandResponseAPI>(name)) {
        return UsdPhysXVehicleNonlinearCommandResponseAPI(prim, name);
    }
    return UsdPhysXVehicleNonlinearCommandResponseAPI();
}

/* static */
const TfType &
UsdPhysXVehicleNonlinearCommandResponseAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleNonlinearCommandResponseAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleNonlinearCommandResponseAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleNonlinearCommandResponseAPI::_GetTfType() const
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
UsdPhysXVehicleNonlinearCommandResponseAPI::GetCommandValuesAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_CommandValues));
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateCommandValuesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_CommandValues),
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSpeedResponsesAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponses));
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateSpeedResponsesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponses),
                       SdfValueTypeNames->Float2Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSpeedResponsesPerCommandValueAttr() const
{
    return GetPrim().GetAttribute(
        _GetNamespacedPropertyName(
            GetName(),
            UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponsesPerCommandValue));
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateSpeedResponsesPerCommandValueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(
                       _GetNamespacedPropertyName(
                            GetName(),
                           UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponsesPerCommandValue),
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
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_CommandValues,
        UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponses,
        UsdPhysXTokens->vehicleNonlinearCommandResponse_MultipleApplyTemplate_SpeedResponsesPerCommandValue,
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
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSchemaAttributeNames(
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

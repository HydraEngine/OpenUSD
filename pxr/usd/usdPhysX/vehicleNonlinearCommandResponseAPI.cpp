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
    return UsdPhysXVehicleNonlinearCommandResponseAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleNonlinearCommandResponseAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleNonlinearCommandResponseAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleNonlinearCommandResponseAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleNonlinearCommandResponseAPI>(whyNot);
}

/* static */
UsdPhysXVehicleNonlinearCommandResponseAPI
UsdPhysXVehicleNonlinearCommandResponseAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleNonlinearCommandResponseAPI>()) {
        return UsdPhysXVehicleNonlinearCommandResponseAPI(prim);
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

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::GetCommandValuesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->commandValues);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateCommandValuesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->commandValues,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSpeedResponsesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->speedResponses);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateSpeedResponsesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->speedResponses,
                       SdfValueTypeNames->Float2Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::GetSpeedResponsesPerCommandValueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->speedResponsesPerCommandValue);
}

UsdAttribute
UsdPhysXVehicleNonlinearCommandResponseAPI::CreateSpeedResponsesPerCommandValueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->speedResponsesPerCommandValue,
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
        UsdPhysXTokens->commandValues,
        UsdPhysXTokens->speedResponses,
        UsdPhysXTokens->speedResponsesPerCommandValue,
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

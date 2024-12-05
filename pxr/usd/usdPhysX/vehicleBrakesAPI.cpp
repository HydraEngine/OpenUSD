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
    return UsdPhysXVehicleBrakesAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleBrakesAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleBrakesAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleBrakesAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleBrakesAPI>(whyNot);
}

/* static */
UsdPhysXVehicleBrakesAPI
UsdPhysXVehicleBrakesAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleBrakesAPI>()) {
        return UsdPhysXVehicleBrakesAPI(prim);
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

UsdAttribute
UsdPhysXVehicleBrakesAPI::GetMaxBrakeTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->maxBrakeTorque);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateMaxBrakeTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->maxBrakeTorque,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::GetTorqueMultipliersAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->torqueMultipliers);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateTorqueMultipliersAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->torqueMultipliers,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::GetWheelsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->wheels);
}

UsdAttribute
UsdPhysXVehicleBrakesAPI::CreateWheelsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->wheels,
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
        UsdPhysXTokens->maxBrakeTorque,
        UsdPhysXTokens->torqueMultipliers,
        UsdPhysXTokens->wheels,
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleSteeringAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleSteeringAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleSteeringAPI::~UsdPhysXVehicleSteeringAPI()
{
}

/* static */
UsdPhysXVehicleSteeringAPI
UsdPhysXVehicleSteeringAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleSteeringAPI();
    }
    return UsdPhysXVehicleSteeringAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleSteeringAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleSteeringAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleSteeringAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleSteeringAPI>(whyNot);
}

/* static */
UsdPhysXVehicleSteeringAPI
UsdPhysXVehicleSteeringAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleSteeringAPI>()) {
        return UsdPhysXVehicleSteeringAPI(prim);
    }
    return UsdPhysXVehicleSteeringAPI();
}

/* static */
const TfType &
UsdPhysXVehicleSteeringAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleSteeringAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleSteeringAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleSteeringAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::GetAngleMultipliersAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSteeringAngleMultipliers);
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::CreateAngleMultipliersAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSteeringAngleMultipliers,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::GetMaxSteerAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSteeringMaxSteerAngle);
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::CreateMaxSteerAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSteeringMaxSteerAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::GetWheelsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSteeringWheels);
}

UsdAttribute
UsdPhysXVehicleSteeringAPI::CreateWheelsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSteeringWheels,
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
UsdPhysXVehicleSteeringAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleSteeringAngleMultipliers,
        UsdPhysXTokens->physxVehicleSteeringMaxSteerAngle,
        UsdPhysXTokens->physxVehicleSteeringWheels,
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

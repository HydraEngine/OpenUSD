//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleSuspensionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleSuspensionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleSuspensionAPI::~UsdPhysXVehicleSuspensionAPI()
{
}

/* static */
UsdPhysXVehicleSuspensionAPI
UsdPhysXVehicleSuspensionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleSuspensionAPI();
    }
    return UsdPhysXVehicleSuspensionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleSuspensionAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleSuspensionAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleSuspensionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleSuspensionAPI>(whyNot);
}

/* static */
UsdPhysXVehicleSuspensionAPI
UsdPhysXVehicleSuspensionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleSuspensionAPI>()) {
        return UsdPhysXVehicleSuspensionAPI(prim);
    }
    return UsdPhysXVehicleSuspensionAPI();
}

/* static */
const TfType &
UsdPhysXVehicleSuspensionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleSuspensionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleSuspensionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleSuspensionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::GetSpringDamperRateAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionSpringDamperRate);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::CreateSpringDamperRateAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionSpringDamperRate,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::GetSpringStrengthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionSpringStrength);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::CreateSpringStrengthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionSpringStrength,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::GetSprungMassAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionSprungMass);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::CreateSprungMassAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionSprungMass,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::GetTravelDistanceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionTravelDistance);
}

UsdAttribute
UsdPhysXVehicleSuspensionAPI::CreateTravelDistanceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionTravelDistance,
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
UsdPhysXVehicleSuspensionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleSuspensionSpringDamperRate,
        UsdPhysXTokens->physxVehicleSuspensionSpringStrength,
        UsdPhysXTokens->physxVehicleSuspensionSprungMass,
        UsdPhysXTokens->physxVehicleSuspensionTravelDistance,
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

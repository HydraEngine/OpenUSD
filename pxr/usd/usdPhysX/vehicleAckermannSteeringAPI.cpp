//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleAckermannSteeringAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleAckermannSteeringAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleAckermannSteeringAPI::~UsdPhysXVehicleAckermannSteeringAPI()
{
}

/* static */
UsdPhysXVehicleAckermannSteeringAPI
UsdPhysXVehicleAckermannSteeringAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleAckermannSteeringAPI();
    }
    return UsdPhysXVehicleAckermannSteeringAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleAckermannSteeringAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleAckermannSteeringAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleAckermannSteeringAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleAckermannSteeringAPI>(whyNot);
}

/* static */
UsdPhysXVehicleAckermannSteeringAPI
UsdPhysXVehicleAckermannSteeringAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleAckermannSteeringAPI>()) {
        return UsdPhysXVehicleAckermannSteeringAPI(prim);
    }
    return UsdPhysXVehicleAckermannSteeringAPI();
}

/* static */
const TfType &
UsdPhysXVehicleAckermannSteeringAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleAckermannSteeringAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleAckermannSteeringAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleAckermannSteeringAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetMaxSteerAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringMaxSteerAngle);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateMaxSteerAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringMaxSteerAngle,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetStrengthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringStrength);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateStrengthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringStrength,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetTrackWidthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringTrackWidth);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateTrackWidthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringTrackWidth,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetWheel0Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringWheel0);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateWheel0Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringWheel0,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetWheel1Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringWheel1);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateWheel1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringWheel1,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::GetWheelBaseAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAckermannSteeringWheelBase);
}

UsdAttribute
UsdPhysXVehicleAckermannSteeringAPI::CreateWheelBaseAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAckermannSteeringWheelBase,
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
UsdPhysXVehicleAckermannSteeringAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleAckermannSteeringMaxSteerAngle,
        UsdPhysXTokens->physxVehicleAckermannSteeringStrength,
        UsdPhysXTokens->physxVehicleAckermannSteeringTrackWidth,
        UsdPhysXTokens->physxVehicleAckermannSteeringWheel0,
        UsdPhysXTokens->physxVehicleAckermannSteeringWheel1,
        UsdPhysXTokens->physxVehicleAckermannSteeringWheelBase,
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

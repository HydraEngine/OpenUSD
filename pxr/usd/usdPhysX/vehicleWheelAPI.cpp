//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleWheelAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleWheelAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleWheelAPI::~UsdPhysXVehicleWheelAPI()
{
}

/* static */
UsdPhysXVehicleWheelAPI
UsdPhysXVehicleWheelAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleWheelAPI();
    }
    return UsdPhysXVehicleWheelAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleWheelAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleWheelAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleWheelAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleWheelAPI>(whyNot);
}

/* static */
UsdPhysXVehicleWheelAPI
UsdPhysXVehicleWheelAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleWheelAPI>()) {
        return UsdPhysXVehicleWheelAPI(prim);
    }
    return UsdPhysXVehicleWheelAPI();
}

/* static */
const TfType &
UsdPhysXVehicleWheelAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleWheelAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleWheelAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleWheelAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleWheelAPI::GetDampingRateAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelDampingRate);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::CreateDampingRateAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelDampingRate,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::GetMassAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelMass);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::CreateMassAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelMass,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::GetMoiAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelMoi);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::CreateMoiAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelMoi,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::GetRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelRadius);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::CreateRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::GetWidthAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelWidth);
}

UsdAttribute
UsdPhysXVehicleWheelAPI::CreateWidthAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelWidth,
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
UsdPhysXVehicleWheelAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleWheelDampingRate,
        UsdPhysXTokens->physxVehicleWheelMass,
        UsdPhysXTokens->physxVehicleWheelMoi,
        UsdPhysXTokens->physxVehicleWheelRadius,
        UsdPhysXTokens->physxVehicleWheelWidth,
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

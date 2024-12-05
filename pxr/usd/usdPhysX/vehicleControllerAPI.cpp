//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleControllerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleControllerAPI::~UsdPhysXVehicleControllerAPI()
{
}

/* static */
UsdPhysXVehicleControllerAPI
UsdPhysXVehicleControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleControllerAPI();
    }
    return UsdPhysXVehicleControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleControllerAPI>(whyNot);
}

/* static */
UsdPhysXVehicleControllerAPI
UsdPhysXVehicleControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleControllerAPI>()) {
        return UsdPhysXVehicleControllerAPI(prim);
    }
    return UsdPhysXVehicleControllerAPI();
}

/* static */
const TfType &
UsdPhysXVehicleControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleControllerAPI::GetAcceleratorAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleControllerAccelerator);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::CreateAcceleratorAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleControllerAccelerator,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::GetBrake0Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleControllerBrake0);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::CreateBrake0Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleControllerBrake0,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::GetBrake1Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleControllerBrake1);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::CreateBrake1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleControllerBrake1,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::GetSteerAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleControllerSteer);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::CreateSteerAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleControllerSteer,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::GetTargetGearAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleControllerTargetGear);
}

UsdAttribute
UsdPhysXVehicleControllerAPI::CreateTargetGearAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleControllerTargetGear,
                       SdfValueTypeNames->Int,
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
UsdPhysXVehicleControllerAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleControllerAccelerator,
        UsdPhysXTokens->physxVehicleControllerBrake0,
        UsdPhysXTokens->physxVehicleControllerBrake1,
        UsdPhysXTokens->physxVehicleControllerSteer,
        UsdPhysXTokens->physxVehicleControllerTargetGear,
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

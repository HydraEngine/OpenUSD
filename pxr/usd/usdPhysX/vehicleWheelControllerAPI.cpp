//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleWheelControllerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleWheelControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleWheelControllerAPI::~UsdPhysXVehicleWheelControllerAPI()
{
}

/* static */
UsdPhysXVehicleWheelControllerAPI
UsdPhysXVehicleWheelControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleWheelControllerAPI();
    }
    return UsdPhysXVehicleWheelControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleWheelControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleWheelControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleWheelControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleWheelControllerAPI>(whyNot);
}

/* static */
UsdPhysXVehicleWheelControllerAPI
UsdPhysXVehicleWheelControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleWheelControllerAPI>()) {
        return UsdPhysXVehicleWheelControllerAPI(prim);
    }
    return UsdPhysXVehicleWheelControllerAPI();
}

/* static */
const TfType &
UsdPhysXVehicleWheelControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleWheelControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleWheelControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleWheelControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::GetBrakeTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelControllerBrakeTorque);
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::CreateBrakeTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelControllerBrakeTorque,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::GetDriveTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelControllerDriveTorque);
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::CreateDriveTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelControllerDriveTorque,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::GetSteerAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelControllerSteerAngle);
}

UsdAttribute
UsdPhysXVehicleWheelControllerAPI::CreateSteerAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelControllerSteerAngle,
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
UsdPhysXVehicleWheelControllerAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleWheelControllerBrakeTorque,
        UsdPhysXTokens->physxVehicleWheelControllerDriveTorque,
        UsdPhysXTokens->physxVehicleWheelControllerSteerAngle,
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

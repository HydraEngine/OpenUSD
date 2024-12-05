//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleDriveBasicAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleDriveBasicAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleDriveBasicAPI::~UsdPhysXVehicleDriveBasicAPI()
{
}

/* static */
UsdPhysXVehicleDriveBasicAPI
UsdPhysXVehicleDriveBasicAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleDriveBasicAPI();
    }
    return UsdPhysXVehicleDriveBasicAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleDriveBasicAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleDriveBasicAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleDriveBasicAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleDriveBasicAPI>(whyNot);
}

/* static */
UsdPhysXVehicleDriveBasicAPI
UsdPhysXVehicleDriveBasicAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleDriveBasicAPI>()) {
        return UsdPhysXVehicleDriveBasicAPI(prim);
    }
    return UsdPhysXVehicleDriveBasicAPI();
}

/* static */
const TfType &
UsdPhysXVehicleDriveBasicAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleDriveBasicAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleDriveBasicAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleDriveBasicAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleDriveBasicAPI::GetPeakTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleDriveBasicPeakTorque);
}

UsdAttribute
UsdPhysXVehicleDriveBasicAPI::CreatePeakTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleDriveBasicPeakTorque,
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
UsdPhysXVehicleDriveBasicAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleDriveBasicPeakTorque,
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

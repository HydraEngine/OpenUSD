//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleSuspensionComplianceAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleSuspensionComplianceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleSuspensionComplianceAPI::~UsdPhysXVehicleSuspensionComplianceAPI()
{
}

/* static */
UsdPhysXVehicleSuspensionComplianceAPI
UsdPhysXVehicleSuspensionComplianceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleSuspensionComplianceAPI();
    }
    return UsdPhysXVehicleSuspensionComplianceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleSuspensionComplianceAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleSuspensionComplianceAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleSuspensionComplianceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleSuspensionComplianceAPI>(whyNot);
}

/* static */
UsdPhysXVehicleSuspensionComplianceAPI
UsdPhysXVehicleSuspensionComplianceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleSuspensionComplianceAPI>()) {
        return UsdPhysXVehicleSuspensionComplianceAPI(prim);
    }
    return UsdPhysXVehicleSuspensionComplianceAPI();
}

/* static */
const TfType &
UsdPhysXVehicleSuspensionComplianceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleSuspensionComplianceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleSuspensionComplianceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleSuspensionComplianceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::GetSuspensionForceAppPointAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionComplianceSuspensionForceAppPoint);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::CreateSuspensionForceAppPointAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionComplianceSuspensionForceAppPoint,
                       SdfValueTypeNames->Float4Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::GetTireForceAppPointAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionComplianceTireForceAppPoint);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::CreateTireForceAppPointAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionComplianceTireForceAppPoint,
                       SdfValueTypeNames->Float4Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::GetWheelCamberAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionComplianceWheelCamberAngle);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::CreateWheelCamberAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionComplianceWheelCamberAngle,
                       SdfValueTypeNames->Float2Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::GetWheelToeAngleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleSuspensionComplianceWheelToeAngle);
}

UsdAttribute
UsdPhysXVehicleSuspensionComplianceAPI::CreateWheelToeAngleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleSuspensionComplianceWheelToeAngle,
                       SdfValueTypeNames->Float2Array,
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
UsdPhysXVehicleSuspensionComplianceAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleSuspensionComplianceSuspensionForceAppPoint,
        UsdPhysXTokens->physxVehicleSuspensionComplianceTireForceAppPoint,
        UsdPhysXTokens->physxVehicleSuspensionComplianceWheelCamberAngle,
        UsdPhysXTokens->physxVehicleSuspensionComplianceWheelToeAngle,
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

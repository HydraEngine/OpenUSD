//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleMultiWheelDifferentialAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleMultiWheelDifferentialAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleMultiWheelDifferentialAPI::~UsdPhysXVehicleMultiWheelDifferentialAPI()
{
}

/* static */
UsdPhysXVehicleMultiWheelDifferentialAPI
UsdPhysXVehicleMultiWheelDifferentialAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleMultiWheelDifferentialAPI();
    }
    return UsdPhysXVehicleMultiWheelDifferentialAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleMultiWheelDifferentialAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleMultiWheelDifferentialAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleMultiWheelDifferentialAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleMultiWheelDifferentialAPI>(whyNot);
}

/* static */
UsdPhysXVehicleMultiWheelDifferentialAPI
UsdPhysXVehicleMultiWheelDifferentialAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleMultiWheelDifferentialAPI>()) {
        return UsdPhysXVehicleMultiWheelDifferentialAPI(prim);
    }
    return UsdPhysXVehicleMultiWheelDifferentialAPI();
}

/* static */
const TfType &
UsdPhysXVehicleMultiWheelDifferentialAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleMultiWheelDifferentialAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleMultiWheelDifferentialAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleMultiWheelDifferentialAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::GetAverageWheelSpeedRatiosAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMultiWheelDifferentialAverageWheelSpeedRatios);
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::CreateAverageWheelSpeedRatiosAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMultiWheelDifferentialAverageWheelSpeedRatios,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::GetTorqueRatiosAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMultiWheelDifferentialTorqueRatios);
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::CreateTorqueRatiosAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMultiWheelDifferentialTorqueRatios,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::GetWheelsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleMultiWheelDifferentialWheels);
}

UsdAttribute
UsdPhysXVehicleMultiWheelDifferentialAPI::CreateWheelsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleMultiWheelDifferentialWheels,
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
UsdPhysXVehicleMultiWheelDifferentialAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleMultiWheelDifferentialAverageWheelSpeedRatios,
        UsdPhysXTokens->physxVehicleMultiWheelDifferentialTorqueRatios,
        UsdPhysXTokens->physxVehicleMultiWheelDifferentialWheels,
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

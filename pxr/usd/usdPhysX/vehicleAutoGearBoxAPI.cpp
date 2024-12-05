//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleAutoGearBoxAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleAutoGearBoxAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleAutoGearBoxAPI::~UsdPhysXVehicleAutoGearBoxAPI()
{
}

/* static */
UsdPhysXVehicleAutoGearBoxAPI
UsdPhysXVehicleAutoGearBoxAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleAutoGearBoxAPI();
    }
    return UsdPhysXVehicleAutoGearBoxAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleAutoGearBoxAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleAutoGearBoxAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleAutoGearBoxAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleAutoGearBoxAPI>(whyNot);
}

/* static */
UsdPhysXVehicleAutoGearBoxAPI
UsdPhysXVehicleAutoGearBoxAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleAutoGearBoxAPI>()) {
        return UsdPhysXVehicleAutoGearBoxAPI(prim);
    }
    return UsdPhysXVehicleAutoGearBoxAPI();
}

/* static */
const TfType &
UsdPhysXVehicleAutoGearBoxAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleAutoGearBoxAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleAutoGearBoxAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleAutoGearBoxAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::GetDownRatiosAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAutoGearBoxDownRatios);
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::CreateDownRatiosAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAutoGearBoxDownRatios,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::GetLatencyAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAutoGearBoxLatency);
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::CreateLatencyAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAutoGearBoxLatency,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::GetUpRatiosAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleAutoGearBoxUpRatios);
}

UsdAttribute
UsdPhysXVehicleAutoGearBoxAPI::CreateUpRatiosAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleAutoGearBoxUpRatios,
                       SdfValueTypeNames->FloatArray,
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
UsdPhysXVehicleAutoGearBoxAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleAutoGearBoxDownRatios,
        UsdPhysXTokens->physxVehicleAutoGearBoxLatency,
        UsdPhysXTokens->physxVehicleAutoGearBoxUpRatios,
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

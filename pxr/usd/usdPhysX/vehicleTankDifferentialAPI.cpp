//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleTankDifferentialAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleTankDifferentialAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleTankDifferentialAPI::~UsdPhysXVehicleTankDifferentialAPI()
{
}

/* static */
UsdPhysXVehicleTankDifferentialAPI
UsdPhysXVehicleTankDifferentialAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleTankDifferentialAPI();
    }
    return UsdPhysXVehicleTankDifferentialAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleTankDifferentialAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleTankDifferentialAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleTankDifferentialAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleTankDifferentialAPI>(whyNot);
}

/* static */
UsdPhysXVehicleTankDifferentialAPI
UsdPhysXVehicleTankDifferentialAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleTankDifferentialAPI>()) {
        return UsdPhysXVehicleTankDifferentialAPI(prim);
    }
    return UsdPhysXVehicleTankDifferentialAPI();
}

/* static */
const TfType &
UsdPhysXVehicleTankDifferentialAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleTankDifferentialAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleTankDifferentialAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleTankDifferentialAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::GetNumberOfWheelsPerTrackAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankDifferentialNumberOfWheelsPerTrack);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::CreateNumberOfWheelsPerTrackAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankDifferentialNumberOfWheelsPerTrack,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::GetThrustIndexPerTrackAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankDifferentialThrustIndexPerTrack);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::CreateThrustIndexPerTrackAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankDifferentialThrustIndexPerTrack,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::GetTrackToWheelIndicesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankDifferentialTrackToWheelIndices);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::CreateTrackToWheelIndicesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankDifferentialTrackToWheelIndices,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::GetWheelIndicesInTrackOrderAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankDifferentialWheelIndicesInTrackOrder);
}

UsdAttribute
UsdPhysXVehicleTankDifferentialAPI::CreateWheelIndicesInTrackOrderAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankDifferentialWheelIndicesInTrackOrder,
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
UsdPhysXVehicleTankDifferentialAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleTankDifferentialNumberOfWheelsPerTrack,
        UsdPhysXTokens->physxVehicleTankDifferentialThrustIndexPerTrack,
        UsdPhysXTokens->physxVehicleTankDifferentialTrackToWheelIndices,
        UsdPhysXTokens->physxVehicleTankDifferentialWheelIndicesInTrackOrder,
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

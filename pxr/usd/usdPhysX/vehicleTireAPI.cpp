//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleTireAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleTireAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleTireAPI::~UsdPhysXVehicleTireAPI()
{
}

/* static */
UsdPhysXVehicleTireAPI
UsdPhysXVehicleTireAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleTireAPI();
    }
    return UsdPhysXVehicleTireAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleTireAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleTireAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleTireAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleTireAPI>(whyNot);
}

/* static */
UsdPhysXVehicleTireAPI
UsdPhysXVehicleTireAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleTireAPI>()) {
        return UsdPhysXVehicleTireAPI(prim);
    }
    return UsdPhysXVehicleTireAPI();
}

/* static */
const TfType &
UsdPhysXVehicleTireAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleTireAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleTireAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleTireAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleTireAPI::GetCamberStiffnessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTireCamberStiffness);
}

UsdAttribute
UsdPhysXVehicleTireAPI::CreateCamberStiffnessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTireCamberStiffness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTireAPI::GetFrictionVsSlipGraphAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTireFrictionVsSlipGraph);
}

UsdAttribute
UsdPhysXVehicleTireAPI::CreateFrictionVsSlipGraphAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTireFrictionVsSlipGraph,
                       SdfValueTypeNames->Float2Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTireAPI::GetLateralStiffnessGraphAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTireLateralStiffnessGraph);
}

UsdAttribute
UsdPhysXVehicleTireAPI::CreateLateralStiffnessGraphAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTireLateralStiffnessGraph,
                       SdfValueTypeNames->Float2,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTireAPI::GetLongitudinalStiffnessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTireLongitudinalStiffness);
}

UsdAttribute
UsdPhysXVehicleTireAPI::CreateLongitudinalStiffnessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTireLongitudinalStiffness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTireAPI::GetRestLoadAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTireRestLoad);
}

UsdAttribute
UsdPhysXVehicleTireAPI::CreateRestLoadAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTireRestLoad,
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
UsdPhysXVehicleTireAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleTireCamberStiffness,
        UsdPhysXTokens->physxVehicleTireFrictionVsSlipGraph,
        UsdPhysXTokens->physxVehicleTireLateralStiffnessGraph,
        UsdPhysXTokens->physxVehicleTireLongitudinalStiffness,
        UsdPhysXTokens->physxVehicleTireRestLoad,
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

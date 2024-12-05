//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleGearsAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleGearsAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleGearsAPI::~UsdPhysXVehicleGearsAPI()
{
}

/* static */
UsdPhysXVehicleGearsAPI
UsdPhysXVehicleGearsAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleGearsAPI();
    }
    return UsdPhysXVehicleGearsAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleGearsAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleGearsAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleGearsAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleGearsAPI>(whyNot);
}

/* static */
UsdPhysXVehicleGearsAPI
UsdPhysXVehicleGearsAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleGearsAPI>()) {
        return UsdPhysXVehicleGearsAPI(prim);
    }
    return UsdPhysXVehicleGearsAPI();
}

/* static */
const TfType &
UsdPhysXVehicleGearsAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleGearsAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleGearsAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleGearsAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleGearsAPI::GetRatiosAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleGearsRatios);
}

UsdAttribute
UsdPhysXVehicleGearsAPI::CreateRatiosAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleGearsRatios,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleGearsAPI::GetRatioScaleAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleGearsRatioScale);
}

UsdAttribute
UsdPhysXVehicleGearsAPI::CreateRatioScaleAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleGearsRatioScale,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleGearsAPI::GetSwitchTimeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleGearsSwitchTime);
}

UsdAttribute
UsdPhysXVehicleGearsAPI::CreateSwitchTimeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleGearsSwitchTime,
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
UsdPhysXVehicleGearsAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleGearsRatios,
        UsdPhysXTokens->physxVehicleGearsRatioScale,
        UsdPhysXTokens->physxVehicleGearsSwitchTime,
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

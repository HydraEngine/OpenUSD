//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleContextAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleContextAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleContextAPI::~UsdPhysXVehicleContextAPI()
{
}

/* static */
UsdPhysXVehicleContextAPI
UsdPhysXVehicleContextAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleContextAPI();
    }
    return UsdPhysXVehicleContextAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleContextAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleContextAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleContextAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleContextAPI>(whyNot);
}

/* static */
UsdPhysXVehicleContextAPI
UsdPhysXVehicleContextAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleContextAPI>()) {
        return UsdPhysXVehicleContextAPI(prim);
    }
    return UsdPhysXVehicleContextAPI();
}

/* static */
const TfType &
UsdPhysXVehicleContextAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleContextAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleContextAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleContextAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleContextAPI::GetLongitudinalAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleContextLongitudinalAxis);
}

UsdAttribute
UsdPhysXVehicleContextAPI::CreateLongitudinalAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleContextLongitudinalAxis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleContextAPI::GetUpdateModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleContextUpdateMode);
}

UsdAttribute
UsdPhysXVehicleContextAPI::CreateUpdateModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleContextUpdateMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleContextAPI::GetVerticalAxisAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleContextVerticalAxis);
}

UsdAttribute
UsdPhysXVehicleContextAPI::CreateVerticalAxisAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleContextVerticalAxis,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
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
UsdPhysXVehicleContextAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleContextLongitudinalAxis,
        UsdPhysXTokens->physxVehicleContextUpdateMode,
        UsdPhysXTokens->physxVehicleContextVerticalAxis,
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

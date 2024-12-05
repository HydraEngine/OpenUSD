//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleTankControllerAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleTankControllerAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleTankControllerAPI::~UsdPhysXVehicleTankControllerAPI()
{
}

/* static */
UsdPhysXVehicleTankControllerAPI
UsdPhysXVehicleTankControllerAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleTankControllerAPI();
    }
    return UsdPhysXVehicleTankControllerAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleTankControllerAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleTankControllerAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleTankControllerAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleTankControllerAPI>(whyNot);
}

/* static */
UsdPhysXVehicleTankControllerAPI
UsdPhysXVehicleTankControllerAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleTankControllerAPI>()) {
        return UsdPhysXVehicleTankControllerAPI(prim);
    }
    return UsdPhysXVehicleTankControllerAPI();
}

/* static */
const TfType &
UsdPhysXVehicleTankControllerAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleTankControllerAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleTankControllerAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleTankControllerAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleTankControllerAPI::GetThrust0Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankControllerThrust0);
}

UsdAttribute
UsdPhysXVehicleTankControllerAPI::CreateThrust0Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankControllerThrust0,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTankControllerAPI::GetThrust1Attr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleTankControllerThrust1);
}

UsdAttribute
UsdPhysXVehicleTankControllerAPI::CreateThrust1Attr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleTankControllerThrust1,
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
UsdPhysXVehicleTankControllerAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleTankControllerThrust0,
        UsdPhysXTokens->physxVehicleTankControllerThrust1,
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

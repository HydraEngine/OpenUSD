//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCameraAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCameraAPI::~UsdPhysXPhysxCameraAPI()
{
}

/* static */
UsdPhysXPhysxCameraAPI
UsdPhysXPhysxCameraAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCameraAPI();
    }
    return UsdPhysXPhysxCameraAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCameraAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCameraAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCameraAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCameraAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCameraAPI
UsdPhysXPhysxCameraAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCameraAPI>()) {
        return UsdPhysXPhysxCameraAPI(prim);
    }
    return UsdPhysXPhysxCameraAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCameraAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCameraAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCameraAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCameraAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxCameraAPI::GetAlwaysUpdateEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->alwaysUpdateEnabled);
}

UsdAttribute
UsdPhysXPhysxCameraAPI::CreateAlwaysUpdateEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->alwaysUpdateEnabled,
                       SdfValueTypeNames->Bool,
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
UsdPhysXPhysxCameraAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->alwaysUpdateEnabled,
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

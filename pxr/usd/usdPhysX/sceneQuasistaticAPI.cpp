//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/sceneQuasistaticAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXSceneQuasistaticAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXSceneQuasistaticAPI::~UsdPhysXSceneQuasistaticAPI()
{
}

/* static */
UsdPhysXSceneQuasistaticAPI
UsdPhysXSceneQuasistaticAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXSceneQuasistaticAPI();
    }
    return UsdPhysXSceneQuasistaticAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXSceneQuasistaticAPI::_GetSchemaKind() const
{
    return UsdPhysXSceneQuasistaticAPI::schemaKind;
}

/* static */
bool
UsdPhysXSceneQuasistaticAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXSceneQuasistaticAPI>(whyNot);
}

/* static */
UsdPhysXSceneQuasistaticAPI
UsdPhysXSceneQuasistaticAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXSceneQuasistaticAPI>()) {
        return UsdPhysXSceneQuasistaticAPI(prim);
    }
    return UsdPhysXSceneQuasistaticAPI();
}

/* static */
const TfType &
UsdPhysXSceneQuasistaticAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXSceneQuasistaticAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXSceneQuasistaticAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXSceneQuasistaticAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXSceneQuasistaticAPI::GetEnableQuasistaticAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSceneQuasistaticEnableQuasistatic);
}

UsdAttribute
UsdPhysXSceneQuasistaticAPI::CreateEnableQuasistaticAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSceneQuasistaticEnableQuasistatic,
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
UsdPhysXSceneQuasistaticAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxSceneQuasistaticEnableQuasistatic,
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/triangleMeshCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXTriangleMeshCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXTriangleMeshCollisionAPI::~UsdPhysXTriangleMeshCollisionAPI()
{
}

/* static */
UsdPhysXTriangleMeshCollisionAPI
UsdPhysXTriangleMeshCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXTriangleMeshCollisionAPI();
    }
    return UsdPhysXTriangleMeshCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXTriangleMeshCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXTriangleMeshCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXTriangleMeshCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXTriangleMeshCollisionAPI>(whyNot);
}

/* static */
UsdPhysXTriangleMeshCollisionAPI
UsdPhysXTriangleMeshCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXTriangleMeshCollisionAPI>()) {
        return UsdPhysXTriangleMeshCollisionAPI(prim);
    }
    return UsdPhysXTriangleMeshCollisionAPI();
}

/* static */
const TfType &
UsdPhysXTriangleMeshCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXTriangleMeshCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXTriangleMeshCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXTriangleMeshCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXTriangleMeshCollisionAPI::GetWeldToleranceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriangleMeshCollisionWeldTolerance);
}

UsdAttribute
UsdPhysXTriangleMeshCollisionAPI::CreateWeldToleranceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriangleMeshCollisionWeldTolerance,
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
UsdPhysXTriangleMeshCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxTriangleMeshCollisionWeldTolerance,
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

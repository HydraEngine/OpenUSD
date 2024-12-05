//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/triangleMeshSimplificationCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXTriangleMeshSimplificationCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXTriangleMeshSimplificationCollisionAPI::~UsdPhysXTriangleMeshSimplificationCollisionAPI()
{
}

/* static */
UsdPhysXTriangleMeshSimplificationCollisionAPI
UsdPhysXTriangleMeshSimplificationCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXTriangleMeshSimplificationCollisionAPI();
    }
    return UsdPhysXTriangleMeshSimplificationCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXTriangleMeshSimplificationCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXTriangleMeshSimplificationCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXTriangleMeshSimplificationCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXTriangleMeshSimplificationCollisionAPI>(whyNot);
}

/* static */
UsdPhysXTriangleMeshSimplificationCollisionAPI
UsdPhysXTriangleMeshSimplificationCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXTriangleMeshSimplificationCollisionAPI>()) {
        return UsdPhysXTriangleMeshSimplificationCollisionAPI(prim);
    }
    return UsdPhysXTriangleMeshSimplificationCollisionAPI();
}

/* static */
const TfType &
UsdPhysXTriangleMeshSimplificationCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXTriangleMeshSimplificationCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXTriangleMeshSimplificationCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXTriangleMeshSimplificationCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXTriangleMeshSimplificationCollisionAPI::GetMetricAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriangleMeshSimplificationCollisionMetric);
}

UsdAttribute
UsdPhysXTriangleMeshSimplificationCollisionAPI::CreateMetricAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriangleMeshSimplificationCollisionMetric,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXTriangleMeshSimplificationCollisionAPI::GetWeldToleranceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxTriangleMeshSimplificationCollisionWeldTolerance);
}

UsdAttribute
UsdPhysXTriangleMeshSimplificationCollisionAPI::CreateWeldToleranceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxTriangleMeshSimplificationCollisionWeldTolerance,
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
UsdPhysXTriangleMeshSimplificationCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxTriangleMeshSimplificationCollisionMetric,
        UsdPhysXTokens->physxTriangleMeshSimplificationCollisionWeldTolerance,
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

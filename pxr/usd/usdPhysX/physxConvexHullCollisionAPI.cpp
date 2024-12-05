//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxConvexHullCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxConvexHullCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxConvexHullCollisionAPI::~UsdPhysXPhysxConvexHullCollisionAPI()
{
}

/* static */
UsdPhysXPhysxConvexHullCollisionAPI
UsdPhysXPhysxConvexHullCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxConvexHullCollisionAPI();
    }
    return UsdPhysXPhysxConvexHullCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxConvexHullCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxConvexHullCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxConvexHullCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxConvexHullCollisionAPI>(whyNot);
}

/* static */
UsdPhysXPhysxConvexHullCollisionAPI
UsdPhysXPhysxConvexHullCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxConvexHullCollisionAPI>()) {
        return UsdPhysXPhysxConvexHullCollisionAPI(prim);
    }
    return UsdPhysXPhysxConvexHullCollisionAPI();
}

/* static */
const TfType &
UsdPhysXPhysxConvexHullCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxConvexHullCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxConvexHullCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxConvexHullCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxConvexHullCollisionAPI::GetHullVertexLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexHullCollisionHullVertexLimit);
}

UsdAttribute
UsdPhysXPhysxConvexHullCollisionAPI::CreateHullVertexLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexHullCollisionHullVertexLimit,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexHullCollisionAPI::GetMinThicknessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexHullCollisionMinThickness);
}

UsdAttribute
UsdPhysXPhysxConvexHullCollisionAPI::CreateMinThicknessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexHullCollisionMinThickness,
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
UsdPhysXPhysxConvexHullCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxConvexHullCollisionHullVertexLimit,
        UsdPhysXTokens->physxConvexHullCollisionMinThickness,
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

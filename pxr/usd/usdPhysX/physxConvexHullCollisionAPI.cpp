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
    TfType::Define<UsdPhysXphysxConvexHullCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxConvexHullCollisionAPI::~UsdPhysXphysxConvexHullCollisionAPI()
{
}

/* static */
UsdPhysXphysxConvexHullCollisionAPI
UsdPhysXphysxConvexHullCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxConvexHullCollisionAPI();
    }
    return UsdPhysXphysxConvexHullCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxConvexHullCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxConvexHullCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxConvexHullCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxConvexHullCollisionAPI>(whyNot);
}

/* static */
UsdPhysXphysxConvexHullCollisionAPI
UsdPhysXphysxConvexHullCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxConvexHullCollisionAPI>()) {
        return UsdPhysXphysxConvexHullCollisionAPI(prim);
    }
    return UsdPhysXphysxConvexHullCollisionAPI();
}

/* static */
const TfType &
UsdPhysXphysxConvexHullCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxConvexHullCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxConvexHullCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxConvexHullCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxConvexHullCollisionAPI::GetHullVertexLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexHullCollisionHullVertexLimit);
}

UsdAttribute
UsdPhysXphysxConvexHullCollisionAPI::CreateHullVertexLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexHullCollisionHullVertexLimit,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxConvexHullCollisionAPI::GetMinThicknessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexHullCollisionMinThickness);
}

UsdAttribute
UsdPhysXphysxConvexHullCollisionAPI::CreateMinThicknessAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxConvexHullCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/convexDecompositionCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXConvexDecompositionCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXConvexDecompositionCollisionAPI::~UsdPhysXConvexDecompositionCollisionAPI()
{
}

/* static */
UsdPhysXConvexDecompositionCollisionAPI
UsdPhysXConvexDecompositionCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXConvexDecompositionCollisionAPI();
    }
    return UsdPhysXConvexDecompositionCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXConvexDecompositionCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXConvexDecompositionCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXConvexDecompositionCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXConvexDecompositionCollisionAPI>(whyNot);
}

/* static */
UsdPhysXConvexDecompositionCollisionAPI
UsdPhysXConvexDecompositionCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXConvexDecompositionCollisionAPI>()) {
        return UsdPhysXConvexDecompositionCollisionAPI(prim);
    }
    return UsdPhysXConvexDecompositionCollisionAPI();
}

/* static */
const TfType &
UsdPhysXConvexDecompositionCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXConvexDecompositionCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXConvexDecompositionCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXConvexDecompositionCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetErrorPercentageAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionErrorPercentage);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateErrorPercentageAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionErrorPercentage,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetHullVertexLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionHullVertexLimit);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateHullVertexLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionHullVertexLimit,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetMaxConvexHullsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionMaxConvexHulls);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateMaxConvexHullsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionMaxConvexHulls,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetMinThicknessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionMinThickness);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateMinThicknessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionMinThickness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetShrinkWrapAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionShrinkWrap);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateShrinkWrapAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionShrinkWrap,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::GetVoxelResolutionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionVoxelResolution);
}

UsdAttribute
UsdPhysXConvexDecompositionCollisionAPI::CreateVoxelResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionVoxelResolution,
                       SdfValueTypeNames->Int,
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
UsdPhysXConvexDecompositionCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxConvexDecompositionCollisionErrorPercentage,
        UsdPhysXTokens->physxConvexDecompositionCollisionHullVertexLimit,
        UsdPhysXTokens->physxConvexDecompositionCollisionMaxConvexHulls,
        UsdPhysXTokens->physxConvexDecompositionCollisionMinThickness,
        UsdPhysXTokens->physxConvexDecompositionCollisionShrinkWrap,
        UsdPhysXTokens->physxConvexDecompositionCollisionVoxelResolution,
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

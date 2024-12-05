//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxConvexDecompositionCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxConvexDecompositionCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxConvexDecompositionCollisionAPI::~UsdPhysXPhysxConvexDecompositionCollisionAPI()
{
}

/* static */
UsdPhysXPhysxConvexDecompositionCollisionAPI
UsdPhysXPhysxConvexDecompositionCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxConvexDecompositionCollisionAPI();
    }
    return UsdPhysXPhysxConvexDecompositionCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxConvexDecompositionCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxConvexDecompositionCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxConvexDecompositionCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxConvexDecompositionCollisionAPI>(whyNot);
}

/* static */
UsdPhysXPhysxConvexDecompositionCollisionAPI
UsdPhysXPhysxConvexDecompositionCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxConvexDecompositionCollisionAPI>()) {
        return UsdPhysXPhysxConvexDecompositionCollisionAPI(prim);
    }
    return UsdPhysXPhysxConvexDecompositionCollisionAPI();
}

/* static */
const TfType &
UsdPhysXPhysxConvexDecompositionCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxConvexDecompositionCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxConvexDecompositionCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxConvexDecompositionCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetErrorPercentageAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionErrorPercentage);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateErrorPercentageAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionErrorPercentage,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetHullVertexLimitAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionHullVertexLimit);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateHullVertexLimitAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionHullVertexLimit,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetMaxConvexHullsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionMaxConvexHulls);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateMaxConvexHullsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionMaxConvexHulls,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetMinThicknessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionMinThickness);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateMinThicknessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionMinThickness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetShrinkWrapAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionShrinkWrap);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateShrinkWrapAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxConvexDecompositionCollisionShrinkWrap,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetVoxelResolutionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxConvexDecompositionCollisionVoxelResolution);
}

UsdAttribute
UsdPhysXPhysxConvexDecompositionCollisionAPI::CreateVoxelResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxConvexDecompositionCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/sDFMeshCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXSDFMeshCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXSDFMeshCollisionAPI::~UsdPhysXSDFMeshCollisionAPI()
{
}

/* static */
UsdPhysXSDFMeshCollisionAPI
UsdPhysXSDFMeshCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXSDFMeshCollisionAPI();
    }
    return UsdPhysXSDFMeshCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXSDFMeshCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXSDFMeshCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXSDFMeshCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXSDFMeshCollisionAPI>(whyNot);
}

/* static */
UsdPhysXSDFMeshCollisionAPI
UsdPhysXSDFMeshCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXSDFMeshCollisionAPI>()) {
        return UsdPhysXSDFMeshCollisionAPI(prim);
    }
    return UsdPhysXSDFMeshCollisionAPI();
}

/* static */
const TfType &
UsdPhysXSDFMeshCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXSDFMeshCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXSDFMeshCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXSDFMeshCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfBitsPerSubgridPixelAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfBitsPerSubgridPixel);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfBitsPerSubgridPixelAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfBitsPerSubgridPixel,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfEnableRemeshingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfEnableRemeshing);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfEnableRemeshingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfEnableRemeshing,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfMarginAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfMargin);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfMarginAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfMargin,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfNarrowBandThicknessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfNarrowBandThickness);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfNarrowBandThicknessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfNarrowBandThickness,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfResolutionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfResolution);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfResolution,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfSubgridResolutionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfSubgridResolution);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfSubgridResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfSubgridResolution,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::GetSdfTriangleCountReductionFactorAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSDFMeshCollisionSdfTriangleCountReductionFactor);
}

UsdAttribute
UsdPhysXSDFMeshCollisionAPI::CreateSdfTriangleCountReductionFactorAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSDFMeshCollisionSdfTriangleCountReductionFactor,
                       SdfValueTypeNames->Float,
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
UsdPhysXSDFMeshCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxSDFMeshCollisionSdfBitsPerSubgridPixel,
        UsdPhysXTokens->physxSDFMeshCollisionSdfEnableRemeshing,
        UsdPhysXTokens->physxSDFMeshCollisionSdfMargin,
        UsdPhysXTokens->physxSDFMeshCollisionSdfNarrowBandThickness,
        UsdPhysXTokens->physxSDFMeshCollisionSdfResolution,
        UsdPhysXTokens->physxSDFMeshCollisionSdfSubgridResolution,
        UsdPhysXTokens->physxSDFMeshCollisionSdfTriangleCountReductionFactor,
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

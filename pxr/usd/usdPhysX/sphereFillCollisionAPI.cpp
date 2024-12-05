//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/sphereFillCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXSphereFillCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXSphereFillCollisionAPI::~UsdPhysXSphereFillCollisionAPI()
{
}

/* static */
UsdPhysXSphereFillCollisionAPI
UsdPhysXSphereFillCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXSphereFillCollisionAPI();
    }
    return UsdPhysXSphereFillCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXSphereFillCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXSphereFillCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXSphereFillCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXSphereFillCollisionAPI>(whyNot);
}

/* static */
UsdPhysXSphereFillCollisionAPI
UsdPhysXSphereFillCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXSphereFillCollisionAPI>()) {
        return UsdPhysXSphereFillCollisionAPI(prim);
    }
    return UsdPhysXSphereFillCollisionAPI();
}

/* static */
const TfType &
UsdPhysXSphereFillCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXSphereFillCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXSphereFillCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXSphereFillCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::GetFillModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSphereFillCollisionFillMode);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::CreateFillModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSphereFillCollisionFillMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::GetMaxSpheresAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSphereFillCollisionMaxSpheres);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::CreateMaxSpheresAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSphereFillCollisionMaxSpheres,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::GetSeedCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSphereFillCollisionSeedCount);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::CreateSeedCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSphereFillCollisionSeedCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::GetVoxelResolutionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSphereFillCollisionVoxelResolution);
}

UsdAttribute
UsdPhysXSphereFillCollisionAPI::CreateVoxelResolutionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSphereFillCollisionVoxelResolution,
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
UsdPhysXSphereFillCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxSphereFillCollisionFillMode,
        UsdPhysXTokens->physxSphereFillCollisionMaxSpheres,
        UsdPhysXTokens->physxSphereFillCollisionSeedCount,
        UsdPhysXTokens->physxSphereFillCollisionVoxelResolution,
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

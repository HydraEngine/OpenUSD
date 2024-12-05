//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/surfaceVelocityAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXSurfaceVelocityAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXSurfaceVelocityAPI::~UsdPhysXSurfaceVelocityAPI()
{
}

/* static */
UsdPhysXSurfaceVelocityAPI
UsdPhysXSurfaceVelocityAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXSurfaceVelocityAPI();
    }
    return UsdPhysXSurfaceVelocityAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXSurfaceVelocityAPI::_GetSchemaKind() const
{
    return UsdPhysXSurfaceVelocityAPI::schemaKind;
}

/* static */
bool
UsdPhysXSurfaceVelocityAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXSurfaceVelocityAPI>(whyNot);
}

/* static */
UsdPhysXSurfaceVelocityAPI
UsdPhysXSurfaceVelocityAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXSurfaceVelocityAPI>()) {
        return UsdPhysXSurfaceVelocityAPI(prim);
    }
    return UsdPhysXSurfaceVelocityAPI();
}

/* static */
const TfType &
UsdPhysXSurfaceVelocityAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXSurfaceVelocityAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXSurfaceVelocityAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXSurfaceVelocityAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::GetSurfaceAngularVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSurfaceVelocitySurfaceAngularVelocity);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::CreateSurfaceAngularVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSurfaceVelocitySurfaceAngularVelocity,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::GetSurfaceVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocity);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::CreateSurfaceVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocity,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::GetSurfaceVelocityEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityEnabled);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::CreateSurfaceVelocityEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::GetSurfaceVelocityLocalSpaceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityLocalSpace);
}

UsdAttribute
UsdPhysXSurfaceVelocityAPI::CreateSurfaceVelocityLocalSpaceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityLocalSpace,
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
UsdPhysXSurfaceVelocityAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxSurfaceVelocitySurfaceAngularVelocity,
        UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocity,
        UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityEnabled,
        UsdPhysXTokens->physxSurfaceVelocitySurfaceVelocityLocalSpace,
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

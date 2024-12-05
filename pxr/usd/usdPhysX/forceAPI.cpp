//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/forceAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXForceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXForceAPI::~UsdPhysXForceAPI()
{
}

/* static */
UsdPhysXForceAPI
UsdPhysXForceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXForceAPI();
    }
    return UsdPhysXForceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXForceAPI::_GetSchemaKind() const
{
    return UsdPhysXForceAPI::schemaKind;
}

/* static */
bool
UsdPhysXForceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXForceAPI>(whyNot);
}

/* static */
UsdPhysXForceAPI
UsdPhysXForceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXForceAPI>()) {
        return UsdPhysXForceAPI(prim);
    }
    return UsdPhysXForceAPI();
}

/* static */
const TfType &
UsdPhysXForceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXForceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXForceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXForceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXForceAPI::GetForceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceForce);
}

UsdAttribute
UsdPhysXForceAPI::CreateForceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceForce,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXForceAPI::GetForceEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceForceEnabled);
}

UsdAttribute
UsdPhysXForceAPI::CreateForceEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceForceEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXForceAPI::GetModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceMode);
}

UsdAttribute
UsdPhysXForceAPI::CreateModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXForceAPI::GetTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceTorque);
}

UsdAttribute
UsdPhysXForceAPI::CreateTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceTorque,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXForceAPI::GetWorldFrameEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceWorldFrameEnabled);
}

UsdAttribute
UsdPhysXForceAPI::CreateWorldFrameEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceWorldFrameEnabled,
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
UsdPhysXForceAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxForceForce,
        UsdPhysXTokens->physxForceForceEnabled,
        UsdPhysXTokens->physxForceMode,
        UsdPhysXTokens->physxForceTorque,
        UsdPhysXTokens->physxForceWorldFrameEnabled,
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

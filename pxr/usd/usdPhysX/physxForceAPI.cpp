//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxForceAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXphysxForceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxForceAPI::~UsdPhysXphysxForceAPI()
{
}

/* static */
UsdPhysXphysxForceAPI
UsdPhysXphysxForceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxForceAPI();
    }
    return UsdPhysXphysxForceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxForceAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxForceAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxForceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxForceAPI>(whyNot);
}

/* static */
UsdPhysXphysxForceAPI
UsdPhysXphysxForceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxForceAPI>()) {
        return UsdPhysXphysxForceAPI(prim);
    }
    return UsdPhysXphysxForceAPI();
}

/* static */
const TfType &
UsdPhysXphysxForceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxForceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxForceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxForceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxForceAPI::GetForceAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceForce);
}

UsdAttribute
UsdPhysXphysxForceAPI::CreateForceAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceForce,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxForceAPI::GetForceEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceForceEnabled);
}

UsdAttribute
UsdPhysXphysxForceAPI::CreateForceEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceForceEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxForceAPI::GetModeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceMode);
}

UsdAttribute
UsdPhysXphysxForceAPI::CreateModeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceMode,
                       SdfValueTypeNames->Token,
                       /* custom = */ false,
                       SdfVariabilityUniform,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxForceAPI::GetTorqueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceTorque);
}

UsdAttribute
UsdPhysXphysxForceAPI::CreateTorqueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxForceTorque,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxForceAPI::GetWorldFrameEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxForceWorldFrameEnabled);
}

UsdAttribute
UsdPhysXphysxForceAPI::CreateWorldFrameEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxForceAPI::GetSchemaAttributeNames(bool includeInherited)
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

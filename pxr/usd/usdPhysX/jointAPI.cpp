//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/jointAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXJointAPI::~UsdPhysXJointAPI()
{
}

/* static */
UsdPhysXJointAPI
UsdPhysXJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXJointAPI();
    }
    return UsdPhysXJointAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXJointAPI::_GetSchemaKind() const
{
    return UsdPhysXJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXJointAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXJointAPI>(whyNot);
}

/* static */
UsdPhysXJointAPI
UsdPhysXJointAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXJointAPI>()) {
        return UsdPhysXJointAPI(prim);
    }
    return UsdPhysXJointAPI();
}

/* static */
const TfType &
UsdPhysXJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXJointAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXJointAPI::GetArmatureAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointArmature);
}

UsdAttribute
UsdPhysXJointAPI::CreateArmatureAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointArmature,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXJointAPI::GetEnableProjectionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointEnableProjection);
}

UsdAttribute
UsdPhysXJointAPI::CreateEnableProjectionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointEnableProjection,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXJointAPI::GetJointFrictionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointJointFriction);
}

UsdAttribute
UsdPhysXJointAPI::CreateJointFrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointJointFriction,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXJointAPI::GetMaxJointVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointMaxJointVelocity);
}

UsdAttribute
UsdPhysXJointAPI::CreateMaxJointVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointMaxJointVelocity,
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
UsdPhysXJointAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxJointArmature,
        UsdPhysXTokens->physxJointEnableProjection,
        UsdPhysXTokens->physxJointJointFriction,
        UsdPhysXTokens->physxJointMaxJointVelocity,
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

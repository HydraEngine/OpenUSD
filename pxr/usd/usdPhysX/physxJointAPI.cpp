//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxJointAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxJointAPI::~UsdPhysXPhysxJointAPI()
{
}

/* static */
UsdPhysXPhysxJointAPI
UsdPhysXPhysxJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxJointAPI();
    }
    return UsdPhysXPhysxJointAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxJointAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxJointAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxJointAPI>(whyNot);
}

/* static */
UsdPhysXPhysxJointAPI
UsdPhysXPhysxJointAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxJointAPI>()) {
        return UsdPhysXPhysxJointAPI(prim);
    }
    return UsdPhysXPhysxJointAPI();
}

/* static */
const TfType &
UsdPhysXPhysxJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxJointAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxJointAPI::GetArmatureAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointArmature);
}

UsdAttribute
UsdPhysXPhysxJointAPI::CreateArmatureAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointArmature,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxJointAPI::GetEnableProjectionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointEnableProjection);
}

UsdAttribute
UsdPhysXPhysxJointAPI::CreateEnableProjectionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointEnableProjection,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxJointAPI::GetJointFrictionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointJointFriction);
}

UsdAttribute
UsdPhysXPhysxJointAPI::CreateJointFrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointJointFriction,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxJointAPI::GetMaxJointVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointMaxJointVelocity);
}

UsdAttribute
UsdPhysXPhysxJointAPI::CreateMaxJointVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxJointAPI::GetSchemaAttributeNames(bool includeInherited)
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

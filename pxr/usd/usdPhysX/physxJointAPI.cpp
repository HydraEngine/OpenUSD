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
    TfType::Define<UsdPhysXphysxJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxJointAPI::~UsdPhysXphysxJointAPI()
{
}

/* static */
UsdPhysXphysxJointAPI
UsdPhysXphysxJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxJointAPI();
    }
    return UsdPhysXphysxJointAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxJointAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxJointAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxJointAPI>(whyNot);
}

/* static */
UsdPhysXphysxJointAPI
UsdPhysXphysxJointAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxJointAPI>()) {
        return UsdPhysXphysxJointAPI(prim);
    }
    return UsdPhysXphysxJointAPI();
}

/* static */
const TfType &
UsdPhysXphysxJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxJointAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxJointAPI::GetArmatureAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointArmature);
}

UsdAttribute
UsdPhysXphysxJointAPI::CreateArmatureAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointArmature,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxJointAPI::GetEnableProjectionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointEnableProjection);
}

UsdAttribute
UsdPhysXphysxJointAPI::CreateEnableProjectionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointEnableProjection,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxJointAPI::GetJointFrictionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointJointFriction);
}

UsdAttribute
UsdPhysXphysxJointAPI::CreateJointFrictionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxJointJointFriction,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxJointAPI::GetMaxJointVelocityAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxJointMaxJointVelocity);
}

UsdAttribute
UsdPhysXphysxJointAPI::CreateMaxJointVelocityAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxJointAPI::GetSchemaAttributeNames(bool includeInherited)
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

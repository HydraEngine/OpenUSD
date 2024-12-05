//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxPhysicsDistanceJointAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxPhysicsDistanceJointAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxPhysicsDistanceJointAPI::~UsdPhysXPhysxPhysicsDistanceJointAPI()
{
}

/* static */
UsdPhysXPhysxPhysicsDistanceJointAPI
UsdPhysXPhysxPhysicsDistanceJointAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxPhysicsDistanceJointAPI();
    }
    return UsdPhysXPhysxPhysicsDistanceJointAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxPhysicsDistanceJointAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxPhysicsDistanceJointAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxPhysicsDistanceJointAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxPhysicsDistanceJointAPI>(whyNot);
}

/* static */
UsdPhysXPhysxPhysicsDistanceJointAPI
UsdPhysXPhysxPhysicsDistanceJointAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxPhysicsDistanceJointAPI>()) {
        return UsdPhysXPhysxPhysicsDistanceJointAPI(prim);
    }
    return UsdPhysXPhysxPhysicsDistanceJointAPI();
}

/* static */
const TfType &
UsdPhysXPhysxPhysicsDistanceJointAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxPhysicsDistanceJointAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxPhysicsDistanceJointAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxPhysicsDistanceJointAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::GetSpringDampingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxPhysicsDistanceJointSpringDamping);
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::CreateSpringDampingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxPhysicsDistanceJointSpringDamping,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::GetSpringEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxPhysicsDistanceJointSpringEnabled);
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::CreateSpringEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxPhysicsDistanceJointSpringEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::GetSpringStiffnessAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxPhysicsDistanceJointSpringStiffness);
}

UsdAttribute
UsdPhysXPhysxPhysicsDistanceJointAPI::CreateSpringStiffnessAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxPhysicsDistanceJointSpringStiffness,
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
UsdPhysXPhysxPhysicsDistanceJointAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxPhysicsDistanceJointSpringDamping,
        UsdPhysXTokens->physxPhysicsDistanceJointSpringEnabled,
        UsdPhysXTokens->physxPhysicsDistanceJointSpringStiffness,
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

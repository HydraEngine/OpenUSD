//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physicsJointInstancer.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysicsJointInstancer,
        TfType::Bases< UsdPhysXPhysicsInstancer > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxPhysicsJointInstancer")
    // to find TfType<UsdPhysXPhysicsJointInstancer>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXPhysicsJointInstancer>("PhysxSchemaPhysxPhysicsJointInstancer");
}

/* virtual */
UsdPhysXPhysicsJointInstancer::~UsdPhysXPhysicsJointInstancer()
{
}

/* static */
UsdPhysXPhysicsJointInstancer
UsdPhysXPhysicsJointInstancer::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsJointInstancer();
    }
    return UsdPhysXPhysicsJointInstancer(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXPhysicsJointInstancer
UsdPhysXPhysicsJointInstancer::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxPhysicsJointInstancer");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsJointInstancer();
    }
    return UsdPhysXPhysicsJointInstancer(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXPhysicsJointInstancer::_GetSchemaKind() const
{
    return UsdPhysXPhysicsJointInstancer::schemaKind;
}

/* static */
const TfType &
UsdPhysXPhysicsJointInstancer::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysicsJointInstancer>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysicsJointInstancer::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysicsJointInstancer::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsBody0IndicesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsBody0Indices);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsBody0IndicesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsBody0Indices,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsBody1IndicesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsBody1Indices);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsBody1IndicesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsBody1Indices,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsLocalPos0sAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsLocalPos0s);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsLocalPos0sAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsLocalPos0s,
                       SdfValueTypeNames->Point3fArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsLocalPos1sAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsLocalPos1s);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsLocalPos1sAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsLocalPos1s,
                       SdfValueTypeNames->Point3fArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsLocalRot0sAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsLocalRot0s);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsLocalRot0sAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsLocalRot0s,
                       SdfValueTypeNames->QuathArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::GetPhysicsLocalRot1sAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsLocalRot1s);
}

UsdAttribute
UsdPhysXPhysicsJointInstancer::CreatePhysicsLocalRot1sAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsLocalRot1s,
                       SdfValueTypeNames->QuathArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
UsdPhysXPhysicsJointInstancer::GetPhysicsBody0sRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->physicsBody0s);
}

UsdRelationship
UsdPhysXPhysicsJointInstancer::CreatePhysicsBody0sRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->physicsBody0s,
                       /* custom = */ false);
}

UsdRelationship
UsdPhysXPhysicsJointInstancer::GetPhysicsBody1sRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->physicsBody1s);
}

UsdRelationship
UsdPhysXPhysicsJointInstancer::CreatePhysicsBody1sRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->physicsBody1s,
                       /* custom = */ false);
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
UsdPhysXPhysicsJointInstancer::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physicsBody0Indices,
        UsdPhysXTokens->physicsBody1Indices,
        UsdPhysXTokens->physicsLocalPos0s,
        UsdPhysXTokens->physicsLocalPos1s,
        UsdPhysXTokens->physicsLocalRot0s,
        UsdPhysXTokens->physicsLocalRot1s,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdPhysXPhysicsInstancer::GetSchemaAttributeNames(true),
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

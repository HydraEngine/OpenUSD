//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physicsRackAndPinionJoint.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysicsRackAndPinionJoint,
        TfType::Bases< UsdPhysicsJoint > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxPhysicsRackAndPinionJoint")
    // to find TfType<UsdPhysXPhysicsRackAndPinionJoint>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXPhysicsRackAndPinionJoint>("PhysxSchemaPhysxPhysicsRackAndPinionJoint");
}

/* virtual */
UsdPhysXPhysicsRackAndPinionJoint::~UsdPhysXPhysicsRackAndPinionJoint()
{
}

/* static */
UsdPhysXPhysicsRackAndPinionJoint
UsdPhysXPhysicsRackAndPinionJoint::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsRackAndPinionJoint();
    }
    return UsdPhysXPhysicsRackAndPinionJoint(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXPhysicsRackAndPinionJoint
UsdPhysXPhysicsRackAndPinionJoint::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxPhysicsRackAndPinionJoint");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsRackAndPinionJoint();
    }
    return UsdPhysXPhysicsRackAndPinionJoint(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXPhysicsRackAndPinionJoint::_GetSchemaKind() const
{
    return UsdPhysXPhysicsRackAndPinionJoint::schemaKind;
}

/* static */
const TfType &
UsdPhysXPhysicsRackAndPinionJoint::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysicsRackAndPinionJoint>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysicsRackAndPinionJoint::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysicsRackAndPinionJoint::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysicsRackAndPinionJoint::GetPhysicsRatioAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsRatio);
}

UsdAttribute
UsdPhysXPhysicsRackAndPinionJoint::CreatePhysicsRatioAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsRatio,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
UsdPhysXPhysicsRackAndPinionJoint::GetHingeRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->hinge);
}

UsdRelationship
UsdPhysXPhysicsRackAndPinionJoint::CreateHingeRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->hinge,
                       /* custom = */ false);
}

UsdRelationship
UsdPhysXPhysicsRackAndPinionJoint::GetPrismaticRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->prismatic);
}

UsdRelationship
UsdPhysXPhysicsRackAndPinionJoint::CreatePrismaticRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->prismatic,
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
UsdPhysXPhysicsRackAndPinionJoint::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physicsRatio,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdPhysicsJoint::GetSchemaAttributeNames(true),
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

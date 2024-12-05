//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physicsGearJoint.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysicsGearJoint,
        TfType::Bases< UsdPhysicsJoint > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxPhysicsGearJoint")
    // to find TfType<UsdPhysXPhysicsGearJoint>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXPhysicsGearJoint>("PhysxSchemaPhysxPhysicsGearJoint");
}

/* virtual */
UsdPhysXPhysicsGearJoint::~UsdPhysXPhysicsGearJoint()
{
}

/* static */
UsdPhysXPhysicsGearJoint
UsdPhysXPhysicsGearJoint::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsGearJoint();
    }
    return UsdPhysXPhysicsGearJoint(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXPhysicsGearJoint
UsdPhysXPhysicsGearJoint::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxPhysicsGearJoint");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysicsGearJoint();
    }
    return UsdPhysXPhysicsGearJoint(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXPhysicsGearJoint::_GetSchemaKind() const
{
    return UsdPhysXPhysicsGearJoint::schemaKind;
}

/* static */
const TfType &
UsdPhysXPhysicsGearJoint::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysicsGearJoint>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysicsGearJoint::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysicsGearJoint::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysicsGearJoint::GetPhysicsGearRatioAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsGearRatio);
}

UsdAttribute
UsdPhysXPhysicsGearJoint::CreatePhysicsGearRatioAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsGearRatio,
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
UsdPhysXPhysicsGearJoint::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physicsGearRatio,
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

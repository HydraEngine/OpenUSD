//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxPhysicsGearJoint.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxPhysicsGearJoint,
        TfType::Bases< UsdPhysicsJoint > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxPhysicsGearJoint")
    // to find TfType<UsdPhysXPhysxPhysicsGearJoint>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXPhysxPhysicsGearJoint>("PhysxSchemaPhysxPhysicsGearJoint");
}

/* virtual */
UsdPhysXPhysxPhysicsGearJoint::~UsdPhysXPhysxPhysicsGearJoint()
{
}

/* static */
UsdPhysXPhysxPhysicsGearJoint
UsdPhysXPhysxPhysicsGearJoint::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxPhysicsGearJoint();
    }
    return UsdPhysXPhysxPhysicsGearJoint(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXPhysxPhysicsGearJoint
UsdPhysXPhysxPhysicsGearJoint::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxPhysicsGearJoint");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxPhysicsGearJoint();
    }
    return UsdPhysXPhysxPhysicsGearJoint(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXPhysxPhysicsGearJoint::_GetSchemaKind() const
{
    return UsdPhysXPhysxPhysicsGearJoint::schemaKind;
}

/* static */
const TfType &
UsdPhysXPhysxPhysicsGearJoint::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxPhysicsGearJoint>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxPhysicsGearJoint::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxPhysicsGearJoint::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxPhysicsGearJoint::GetPhysicsGearRatioAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsGearRatio);
}

UsdAttribute
UsdPhysXPhysxPhysicsGearJoint::CreatePhysicsGearRatioAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXPhysxPhysicsGearJoint::GetSchemaAttributeNames(bool includeInherited)
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

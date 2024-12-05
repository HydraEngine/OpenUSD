//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxPhysicsInstancer.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxPhysicsInstancer,
        TfType::Bases< UsdGeomImageable > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxPhysicsInstancer")
    // to find TfType<UsdPhysXPhysxPhysicsInstancer>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXPhysxPhysicsInstancer>("PhysxSchemaPhysxPhysicsInstancer");
}

/* virtual */
UsdPhysXPhysxPhysicsInstancer::~UsdPhysXPhysxPhysicsInstancer()
{
}

/* static */
UsdPhysXPhysxPhysicsInstancer
UsdPhysXPhysxPhysicsInstancer::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxPhysicsInstancer();
    }
    return UsdPhysXPhysxPhysicsInstancer(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXPhysxPhysicsInstancer
UsdPhysXPhysxPhysicsInstancer::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxPhysicsInstancer");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxPhysicsInstancer();
    }
    return UsdPhysXPhysxPhysicsInstancer(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXPhysxPhysicsInstancer::_GetSchemaKind() const
{
    return UsdPhysXPhysxPhysicsInstancer::schemaKind;
}

/* static */
const TfType &
UsdPhysXPhysxPhysicsInstancer::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxPhysicsInstancer>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxPhysicsInstancer::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxPhysicsInstancer::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxPhysicsInstancer::GetPhysicsProtoIndicesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physicsProtoIndices);
}

UsdAttribute
UsdPhysXPhysxPhysicsInstancer::CreatePhysicsProtoIndicesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physicsProtoIndices,
                       SdfValueTypeNames->IntArray,
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
UsdPhysXPhysxPhysicsInstancer::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physicsProtoIndices,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdGeomImageable::GetSchemaAttributeNames(true),
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

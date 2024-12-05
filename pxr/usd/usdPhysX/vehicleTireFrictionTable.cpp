//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleTireFrictionTable.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleTireFrictionTable,
        TfType::Bases< UsdTyped > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysxSchemaPhysxVehicleTireFrictionTable")
    // to find TfType<UsdPhysXVehicleTireFrictionTable>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysXVehicleTireFrictionTable>("PhysxSchemaPhysxVehicleTireFrictionTable");
}

/* virtual */
UsdPhysXVehicleTireFrictionTable::~UsdPhysXVehicleTireFrictionTable()
{
}

/* static */
UsdPhysXVehicleTireFrictionTable
UsdPhysXVehicleTireFrictionTable::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleTireFrictionTable();
    }
    return UsdPhysXVehicleTireFrictionTable(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysXVehicleTireFrictionTable
UsdPhysXVehicleTireFrictionTable::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysxSchemaPhysxVehicleTireFrictionTable");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleTireFrictionTable();
    }
    return UsdPhysXVehicleTireFrictionTable(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysXVehicleTireFrictionTable::_GetSchemaKind() const
{
    return UsdPhysXVehicleTireFrictionTable::schemaKind;
}

/* static */
const TfType &
UsdPhysXVehicleTireFrictionTable::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleTireFrictionTable>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleTireFrictionTable::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleTireFrictionTable::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleTireFrictionTable::GetDefaultFrictionValueAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->defaultFrictionValue);
}

UsdAttribute
UsdPhysXVehicleTireFrictionTable::CreateDefaultFrictionValueAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->defaultFrictionValue,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleTireFrictionTable::GetFrictionValuesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->frictionValues);
}

UsdAttribute
UsdPhysXVehicleTireFrictionTable::CreateFrictionValuesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->frictionValues,
                       SdfValueTypeNames->FloatArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
UsdPhysXVehicleTireFrictionTable::GetGroundMaterialsRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->groundMaterials);
}

UsdRelationship
UsdPhysXVehicleTireFrictionTable::CreateGroundMaterialsRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->groundMaterials,
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
UsdPhysXVehicleTireFrictionTable::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->defaultFrictionValue,
        UsdPhysXTokens->frictionValues,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdTyped::GetSchemaAttributeNames(true),
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

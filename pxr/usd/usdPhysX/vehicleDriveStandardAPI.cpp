//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleDriveStandardAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleDriveStandardAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleDriveStandardAPI::~UsdPhysXVehicleDriveStandardAPI()
{
}

/* static */
UsdPhysXVehicleDriveStandardAPI
UsdPhysXVehicleDriveStandardAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleDriveStandardAPI();
    }
    return UsdPhysXVehicleDriveStandardAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleDriveStandardAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleDriveStandardAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleDriveStandardAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleDriveStandardAPI>(whyNot);
}

/* static */
UsdPhysXVehicleDriveStandardAPI
UsdPhysXVehicleDriveStandardAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleDriveStandardAPI>()) {
        return UsdPhysXVehicleDriveStandardAPI(prim);
    }
    return UsdPhysXVehicleDriveStandardAPI();
}

/* static */
const TfType &
UsdPhysXVehicleDriveStandardAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleDriveStandardAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleDriveStandardAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleDriveStandardAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::GetAutoGearBoxRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->autoGearBox);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::CreateAutoGearBoxRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->autoGearBox,
                       /* custom = */ false);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::GetClutchRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->clutch);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::CreateClutchRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->clutch,
                       /* custom = */ false);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::GetEngineRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->engine);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::CreateEngineRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->engine,
                       /* custom = */ false);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::GetGearsRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->gears);
}

UsdRelationship
UsdPhysXVehicleDriveStandardAPI::CreateGearsRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->gears,
                       /* custom = */ false);
}

/*static*/
const TfTokenVector&
UsdPhysXVehicleDriveStandardAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames;
    static TfTokenVector allNames =
        UsdAPISchemaBase::GetSchemaAttributeNames(true);

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

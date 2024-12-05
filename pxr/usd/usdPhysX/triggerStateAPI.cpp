//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/triggerStateAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXTriggerStateAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXTriggerStateAPI::~UsdPhysXTriggerStateAPI()
{
}

/* static */
UsdPhysXTriggerStateAPI
UsdPhysXTriggerStateAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXTriggerStateAPI();
    }
    return UsdPhysXTriggerStateAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXTriggerStateAPI::_GetSchemaKind() const
{
    return UsdPhysXTriggerStateAPI::schemaKind;
}

/* static */
bool
UsdPhysXTriggerStateAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXTriggerStateAPI>(whyNot);
}

/* static */
UsdPhysXTriggerStateAPI
UsdPhysXTriggerStateAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXTriggerStateAPI>()) {
        return UsdPhysXTriggerStateAPI(prim);
    }
    return UsdPhysXTriggerStateAPI();
}

/* static */
const TfType &
UsdPhysXTriggerStateAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXTriggerStateAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXTriggerStateAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXTriggerStateAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdRelationship
UsdPhysXTriggerStateAPI::GetTriggeredCollisionsRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->triggeredCollisions);
}

UsdRelationship
UsdPhysXTriggerStateAPI::CreateTriggeredCollisionsRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->triggeredCollisions,
                       /* custom = */ false);
}

/*static*/
const TfTokenVector&
UsdPhysXTriggerStateAPI::GetSchemaAttributeNames(bool includeInherited)
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

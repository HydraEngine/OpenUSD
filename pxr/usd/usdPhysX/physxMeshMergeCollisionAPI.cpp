//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxMeshMergeCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxMeshMergeCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxMeshMergeCollisionAPI::~UsdPhysXPhysxMeshMergeCollisionAPI()
{
}

/* static */
UsdPhysXPhysxMeshMergeCollisionAPI
UsdPhysXPhysxMeshMergeCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxMeshMergeCollisionAPI();
    }
    return UsdPhysXPhysxMeshMergeCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxMeshMergeCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxMeshMergeCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxMeshMergeCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxMeshMergeCollisionAPI>(whyNot);
}

/* static */
UsdPhysXPhysxMeshMergeCollisionAPI
UsdPhysXPhysxMeshMergeCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxMeshMergeCollisionAPI>()) {
        return UsdPhysXPhysxMeshMergeCollisionAPI(prim);
    }
    return UsdPhysXPhysxMeshMergeCollisionAPI();
}

/* static */
const TfType &
UsdPhysXPhysxMeshMergeCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxMeshMergeCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxMeshMergeCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxMeshMergeCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
UsdPhysXPhysxMeshMergeCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
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

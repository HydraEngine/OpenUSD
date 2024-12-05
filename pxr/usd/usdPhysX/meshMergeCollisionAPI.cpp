//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/meshMergeCollisionAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXMeshMergeCollisionAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXMeshMergeCollisionAPI::~UsdPhysXMeshMergeCollisionAPI()
{
}

/* static */
UsdPhysXMeshMergeCollisionAPI
UsdPhysXMeshMergeCollisionAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXMeshMergeCollisionAPI();
    }
    return UsdPhysXMeshMergeCollisionAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXMeshMergeCollisionAPI::_GetSchemaKind() const
{
    return UsdPhysXMeshMergeCollisionAPI::schemaKind;
}

/* static */
bool
UsdPhysXMeshMergeCollisionAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXMeshMergeCollisionAPI>(whyNot);
}

/* static */
UsdPhysXMeshMergeCollisionAPI
UsdPhysXMeshMergeCollisionAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXMeshMergeCollisionAPI>()) {
        return UsdPhysXMeshMergeCollisionAPI(prim);
    }
    return UsdPhysXMeshMergeCollisionAPI();
}

/* static */
const TfType &
UsdPhysXMeshMergeCollisionAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXMeshMergeCollisionAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXMeshMergeCollisionAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXMeshMergeCollisionAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
UsdPhysXMeshMergeCollisionAPI::GetSchemaAttributeNames(bool includeInherited)
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

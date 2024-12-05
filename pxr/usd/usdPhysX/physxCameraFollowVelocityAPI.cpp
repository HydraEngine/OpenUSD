//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraFollowVelocityAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxCameraFollowVelocityAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxCameraFollowVelocityAPI::~UsdPhysXPhysxCameraFollowVelocityAPI()
{
}

/* static */
UsdPhysXPhysxCameraFollowVelocityAPI
UsdPhysXPhysxCameraFollowVelocityAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxCameraFollowVelocityAPI();
    }
    return UsdPhysXPhysxCameraFollowVelocityAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxCameraFollowVelocityAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxCameraFollowVelocityAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxCameraFollowVelocityAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxCameraFollowVelocityAPI>(whyNot);
}

/* static */
UsdPhysXPhysxCameraFollowVelocityAPI
UsdPhysXPhysxCameraFollowVelocityAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxCameraFollowVelocityAPI>()) {
        return UsdPhysXPhysxCameraFollowVelocityAPI(prim);
    }
    return UsdPhysXPhysxCameraFollowVelocityAPI();
}

/* static */
const TfType &
UsdPhysXPhysxCameraFollowVelocityAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxCameraFollowVelocityAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxCameraFollowVelocityAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxCameraFollowVelocityAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
UsdPhysXPhysxCameraFollowVelocityAPI::GetSchemaAttributeNames(bool includeInherited)
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

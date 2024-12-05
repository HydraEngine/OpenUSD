//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/cameraFollowVelocityAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXCameraFollowVelocityAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXCameraFollowVelocityAPI::~UsdPhysXCameraFollowVelocityAPI()
{
}

/* static */
UsdPhysXCameraFollowVelocityAPI
UsdPhysXCameraFollowVelocityAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXCameraFollowVelocityAPI();
    }
    return UsdPhysXCameraFollowVelocityAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXCameraFollowVelocityAPI::_GetSchemaKind() const
{
    return UsdPhysXCameraFollowVelocityAPI::schemaKind;
}

/* static */
bool
UsdPhysXCameraFollowVelocityAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXCameraFollowVelocityAPI>(whyNot);
}

/* static */
UsdPhysXCameraFollowVelocityAPI
UsdPhysXCameraFollowVelocityAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXCameraFollowVelocityAPI>()) {
        return UsdPhysXCameraFollowVelocityAPI(prim);
    }
    return UsdPhysXCameraFollowVelocityAPI();
}

/* static */
const TfType &
UsdPhysXCameraFollowVelocityAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXCameraFollowVelocityAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXCameraFollowVelocityAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXCameraFollowVelocityAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
UsdPhysXCameraFollowVelocityAPI::GetSchemaAttributeNames(bool includeInherited)
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

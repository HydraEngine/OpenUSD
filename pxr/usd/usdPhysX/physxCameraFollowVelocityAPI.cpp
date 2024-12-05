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
    TfType::Define<UsdPhysXphysxCameraFollowVelocityAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxCameraFollowVelocityAPI::~UsdPhysXphysxCameraFollowVelocityAPI()
{
}

/* static */
UsdPhysXphysxCameraFollowVelocityAPI
UsdPhysXphysxCameraFollowVelocityAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxCameraFollowVelocityAPI();
    }
    return UsdPhysXphysxCameraFollowVelocityAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxCameraFollowVelocityAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxCameraFollowVelocityAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxCameraFollowVelocityAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxCameraFollowVelocityAPI>(whyNot);
}

/* static */
UsdPhysXphysxCameraFollowVelocityAPI
UsdPhysXphysxCameraFollowVelocityAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxCameraFollowVelocityAPI>()) {
        return UsdPhysXphysxCameraFollowVelocityAPI(prim);
    }
    return UsdPhysXphysxCameraFollowVelocityAPI();
}

/* static */
const TfType &
UsdPhysXphysxCameraFollowVelocityAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxCameraFollowVelocityAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxCameraFollowVelocityAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxCameraFollowVelocityAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
UsdPhysXphysxCameraFollowVelocityAPI::GetSchemaAttributeNames(bool includeInherited)
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

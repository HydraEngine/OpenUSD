//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleWheelAttachmentAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXVehicleWheelAttachmentAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXVehicleWheelAttachmentAPI::~UsdPhysXVehicleWheelAttachmentAPI()
{
}

/* static */
UsdPhysXVehicleWheelAttachmentAPI
UsdPhysXVehicleWheelAttachmentAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXVehicleWheelAttachmentAPI();
    }
    return UsdPhysXVehicleWheelAttachmentAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXVehicleWheelAttachmentAPI::_GetSchemaKind() const
{
    return UsdPhysXVehicleWheelAttachmentAPI::schemaKind;
}

/* static */
bool
UsdPhysXVehicleWheelAttachmentAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXVehicleWheelAttachmentAPI>(whyNot);
}

/* static */
UsdPhysXVehicleWheelAttachmentAPI
UsdPhysXVehicleWheelAttachmentAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXVehicleWheelAttachmentAPI>()) {
        return UsdPhysXVehicleWheelAttachmentAPI(prim);
    }
    return UsdPhysXVehicleWheelAttachmentAPI();
}

/* static */
const TfType &
UsdPhysXVehicleWheelAttachmentAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXVehicleWheelAttachmentAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXVehicleWheelAttachmentAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXVehicleWheelAttachmentAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetIndexAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentIndex);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateIndexAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentIndex,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetSuspensionFrameOrientationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFrameOrientation);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateSuspensionFrameOrientationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFrameOrientation,
                       SdfValueTypeNames->Quatf,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetSuspensionFramePositionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFramePosition);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateSuspensionFramePositionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFramePosition,
                       SdfValueTypeNames->Point3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetSuspensionTravelDirectionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionTravelDirection);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateSuspensionTravelDirectionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionTravelDirection,
                       SdfValueTypeNames->Vector3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetWheelFrameOrientationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentWheelFrameOrientation);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateWheelFrameOrientationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentWheelFrameOrientation,
                       SdfValueTypeNames->Quatf,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::GetWheelFramePositionAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxVehicleWheelAttachmentWheelFramePosition);
}

UsdAttribute
UsdPhysXVehicleWheelAttachmentAPI::CreateWheelFramePositionAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxVehicleWheelAttachmentWheelFramePosition,
                       SdfValueTypeNames->Point3f,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
UsdPhysXVehicleWheelAttachmentAPI::GetWheelRel() const
{
    return GetPrim().GetRelationship(UsdPhysXTokens->wheel);
}

UsdRelationship
UsdPhysXVehicleWheelAttachmentAPI::CreateWheelRel() const
{
    return GetPrim().CreateRelationship(UsdPhysXTokens->wheel,
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
UsdPhysXVehicleWheelAttachmentAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxVehicleWheelAttachmentIndex,
        UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFrameOrientation,
        UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionFramePosition,
        UsdPhysXTokens->physxVehicleWheelAttachmentSuspensionTravelDirection,
        UsdPhysXTokens->physxVehicleWheelAttachmentWheelFrameOrientation,
        UsdPhysXTokens->physxVehicleWheelAttachmentWheelFramePosition,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdAPISchemaBase::GetSchemaAttributeNames(true),
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

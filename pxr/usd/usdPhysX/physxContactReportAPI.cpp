//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxContactReportAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXphysxContactReportAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxContactReportAPI::~UsdPhysXphysxContactReportAPI()
{
}

/* static */
UsdPhysXphysxContactReportAPI
UsdPhysXphysxContactReportAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxContactReportAPI();
    }
    return UsdPhysXphysxContactReportAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxContactReportAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxContactReportAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxContactReportAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxContactReportAPI>(whyNot);
}

/* static */
UsdPhysXphysxContactReportAPI
UsdPhysXphysxContactReportAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxContactReportAPI>()) {
        return UsdPhysXphysxContactReportAPI(prim);
    }
    return UsdPhysXphysxContactReportAPI();
}

/* static */
const TfType &
UsdPhysXphysxContactReportAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxContactReportAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxContactReportAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxContactReportAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxContactReportAPI::GetThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxContactReportThreshold);
}

UsdAttribute
UsdPhysXphysxContactReportAPI::CreateThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxContactReportThreshold,
                       SdfValueTypeNames->Float,
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
UsdPhysXphysxContactReportAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxContactReportThreshold,
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

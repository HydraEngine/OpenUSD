//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/residualReportingAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXResidualReportingAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXResidualReportingAPI::~UsdPhysXResidualReportingAPI()
{
}

/* static */
UsdPhysXResidualReportingAPI
UsdPhysXResidualReportingAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXResidualReportingAPI();
    }
    return UsdPhysXResidualReportingAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXResidualReportingAPI::_GetSchemaKind() const
{
    return UsdPhysXResidualReportingAPI::schemaKind;
}

/* static */
bool
UsdPhysXResidualReportingAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXResidualReportingAPI>(whyNot);
}

/* static */
UsdPhysXResidualReportingAPI
UsdPhysXResidualReportingAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXResidualReportingAPI>()) {
        return UsdPhysXResidualReportingAPI(prim);
    }
    return UsdPhysXResidualReportingAPI();
}

/* static */
const TfType &
UsdPhysXResidualReportingAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXResidualReportingAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXResidualReportingAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXResidualReportingAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXResidualReportingAPI::GetMaxResidualPositionIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxResidualReportingMaxResidualPositionIteration);
}

UsdAttribute
UsdPhysXResidualReportingAPI::CreateMaxResidualPositionIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxResidualReportingMaxResidualPositionIteration,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXResidualReportingAPI::GetMaxResidualVelocityIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxResidualReportingMaxResidualVelocityIteration);
}

UsdAttribute
UsdPhysXResidualReportingAPI::CreateMaxResidualVelocityIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxResidualReportingMaxResidualVelocityIteration,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXResidualReportingAPI::GetRmsResidualPositionIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxResidualReportingRmsResidualPositionIteration);
}

UsdAttribute
UsdPhysXResidualReportingAPI::CreateRmsResidualPositionIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxResidualReportingRmsResidualPositionIteration,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXResidualReportingAPI::GetRmsResidualVelocityIterationAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxResidualReportingRmsResidualVelocityIteration);
}

UsdAttribute
UsdPhysXResidualReportingAPI::CreateRmsResidualVelocityIterationAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxResidualReportingRmsResidualVelocityIteration,
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
UsdPhysXResidualReportingAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxResidualReportingMaxResidualPositionIteration,
        UsdPhysXTokens->physxResidualReportingMaxResidualVelocityIteration,
        UsdPhysXTokens->physxResidualReportingRmsResidualPositionIteration,
        UsdPhysXTokens->physxResidualReportingRmsResidualVelocityIteration,
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

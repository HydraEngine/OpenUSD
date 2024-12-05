//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/articulationAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXArticulationAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXArticulationAPI::~UsdPhysXArticulationAPI()
{
}

/* static */
UsdPhysXArticulationAPI
UsdPhysXArticulationAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXArticulationAPI();
    }
    return UsdPhysXArticulationAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXArticulationAPI::_GetSchemaKind() const
{
    return UsdPhysXArticulationAPI::schemaKind;
}

/* static */
bool
UsdPhysXArticulationAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXArticulationAPI>(whyNot);
}

/* static */
UsdPhysXArticulationAPI
UsdPhysXArticulationAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXArticulationAPI>()) {
        return UsdPhysXArticulationAPI(prim);
    }
    return UsdPhysXArticulationAPI();
}

/* static */
const TfType &
UsdPhysXArticulationAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXArticulationAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXArticulationAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXArticulationAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXArticulationAPI::GetArticulationEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationArticulationEnabled);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateArticulationEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationArticulationEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXArticulationAPI::GetEnabledSelfCollisionsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationEnabledSelfCollisions);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateEnabledSelfCollisionsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationEnabledSelfCollisions,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXArticulationAPI::GetSleepThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSleepThreshold);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateSleepThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSleepThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXArticulationAPI::GetSolverPositionIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSolverPositionIterationCount);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateSolverPositionIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSolverPositionIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXArticulationAPI::GetSolverVelocityIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSolverVelocityIterationCount);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateSolverVelocityIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSolverVelocityIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXArticulationAPI::GetStabilizationThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationStabilizationThreshold);
}

UsdAttribute
UsdPhysXArticulationAPI::CreateStabilizationThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationStabilizationThreshold,
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
UsdPhysXArticulationAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxArticulationArticulationEnabled,
        UsdPhysXTokens->physxArticulationEnabledSelfCollisions,
        UsdPhysXTokens->physxArticulationSleepThreshold,
        UsdPhysXTokens->physxArticulationSolverPositionIterationCount,
        UsdPhysXTokens->physxArticulationSolverVelocityIterationCount,
        UsdPhysXTokens->physxArticulationStabilizationThreshold,
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

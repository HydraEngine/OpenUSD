//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxArticulationAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXphysxArticulationAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxArticulationAPI::~UsdPhysXphysxArticulationAPI()
{
}

/* static */
UsdPhysXphysxArticulationAPI
UsdPhysXphysxArticulationAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxArticulationAPI();
    }
    return UsdPhysXphysxArticulationAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxArticulationAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxArticulationAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxArticulationAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxArticulationAPI>(whyNot);
}

/* static */
UsdPhysXphysxArticulationAPI
UsdPhysXphysxArticulationAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxArticulationAPI>()) {
        return UsdPhysXphysxArticulationAPI(prim);
    }
    return UsdPhysXphysxArticulationAPI();
}

/* static */
const TfType &
UsdPhysXphysxArticulationAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxArticulationAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxArticulationAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxArticulationAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetArticulationEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationArticulationEnabled);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateArticulationEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationArticulationEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetEnabledSelfCollisionsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationEnabledSelfCollisions);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateEnabledSelfCollisionsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationEnabledSelfCollisions,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetSleepThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSleepThreshold);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateSleepThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSleepThreshold,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetSolverPositionIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSolverPositionIterationCount);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateSolverPositionIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSolverPositionIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetSolverVelocityIterationCountAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationSolverVelocityIterationCount);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateSolverVelocityIterationCountAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxArticulationSolverVelocityIterationCount,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::GetStabilizationThresholdAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxArticulationStabilizationThreshold);
}

UsdAttribute
UsdPhysXphysxArticulationAPI::CreateStabilizationThresholdAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxArticulationAPI::GetSchemaAttributeNames(bool includeInherited)
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

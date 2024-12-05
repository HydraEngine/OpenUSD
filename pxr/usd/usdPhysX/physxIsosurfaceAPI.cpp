//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxIsosurfaceAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXPhysxIsosurfaceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXPhysxIsosurfaceAPI::~UsdPhysXPhysxIsosurfaceAPI()
{
}

/* static */
UsdPhysXPhysxIsosurfaceAPI
UsdPhysXPhysxIsosurfaceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXPhysxIsosurfaceAPI();
    }
    return UsdPhysXPhysxIsosurfaceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXPhysxIsosurfaceAPI::_GetSchemaKind() const
{
    return UsdPhysXPhysxIsosurfaceAPI::schemaKind;
}

/* static */
bool
UsdPhysXPhysxIsosurfaceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXPhysxIsosurfaceAPI>(whyNot);
}

/* static */
UsdPhysXPhysxIsosurfaceAPI
UsdPhysXPhysxIsosurfaceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXPhysxIsosurfaceAPI>()) {
        return UsdPhysXPhysxIsosurfaceAPI(prim);
    }
    return UsdPhysXPhysxIsosurfaceAPI();
}

/* static */
const TfType &
UsdPhysXPhysxIsosurfaceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXPhysxIsosurfaceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXPhysxIsosurfaceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXPhysxIsosurfaceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetAnisotropyMaxAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMax);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateAnisotropyMaxAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMax,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetAnisotropyMinAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMin);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateAnisotropyMinAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMin,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetAnisotropyRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateAnisotropyRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetEnableAnisotropyAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateEnableAnisotropyAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetGridFilteringPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateGridFilteringPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetGridSmoothingRadiusRelativeToCellSizeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateGridSmoothingRadiusRelativeToCellSizeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetGridSpacingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSpacing);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateGridSpacingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSpacing,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetIsoSurfaceEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateIsoSurfaceEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetIsosurfaceLevelAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateIsosurfaceLevelAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetKernelRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceKernelRadius);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateKernelRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceKernelRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetMaxSubgridsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxSubgrids);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateMaxSubgridsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxSubgrids,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetMaxTrianglesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxTriangles);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateMaxTrianglesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxTriangles,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetMaxVerticesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxVertices);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateMaxVerticesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxVertices,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::GetNumMeshSmoothingPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceNumMeshSmoothingPasses);
}

UsdAttribute
UsdPhysXPhysxIsosurfaceAPI::CreateNumMeshSmoothingPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceNumMeshSmoothingPasses,
                       SdfValueTypeNames->Int,
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
UsdPhysXPhysxIsosurfaceAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        UsdPhysXTokens->physxIsosurfaceAnisotropyMax,
        UsdPhysXTokens->physxIsosurfaceAnisotropyMin,
        UsdPhysXTokens->physxIsosurfaceAnisotropyRadius,
        UsdPhysXTokens->physxIsosurfaceEnableAnisotropy,
        UsdPhysXTokens->physxIsosurfaceGridFilteringPasses,
        UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize,
        UsdPhysXTokens->physxIsosurfaceGridSpacing,
        UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled,
        UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel,
        UsdPhysXTokens->physxIsosurfaceKernelRadius,
        UsdPhysXTokens->physxIsosurfaceMaxSubgrids,
        UsdPhysXTokens->physxIsosurfaceMaxTriangles,
        UsdPhysXTokens->physxIsosurfaceMaxVertices,
        UsdPhysXTokens->physxIsosurfaceNumMeshSmoothingPasses,
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

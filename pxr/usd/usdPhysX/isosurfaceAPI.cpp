//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/isosurfaceAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<UsdPhysXIsosurfaceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXIsosurfaceAPI::~UsdPhysXIsosurfaceAPI()
{
}

/* static */
UsdPhysXIsosurfaceAPI
UsdPhysXIsosurfaceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXIsosurfaceAPI();
    }
    return UsdPhysXIsosurfaceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXIsosurfaceAPI::_GetSchemaKind() const
{
    return UsdPhysXIsosurfaceAPI::schemaKind;
}

/* static */
bool
UsdPhysXIsosurfaceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXIsosurfaceAPI>(whyNot);
}

/* static */
UsdPhysXIsosurfaceAPI
UsdPhysXIsosurfaceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXIsosurfaceAPI>()) {
        return UsdPhysXIsosurfaceAPI(prim);
    }
    return UsdPhysXIsosurfaceAPI();
}

/* static */
const TfType &
UsdPhysXIsosurfaceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXIsosurfaceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXIsosurfaceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXIsosurfaceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetAnisotropyMaxAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMax);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateAnisotropyMaxAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMax,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetAnisotropyMinAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMin);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateAnisotropyMinAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMin,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetAnisotropyRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateAnisotropyRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetEnableAnisotropyAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateEnableAnisotropyAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetGridFilteringPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateGridFilteringPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetGridSmoothingRadiusRelativeToCellSizeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateGridSmoothingRadiusRelativeToCellSizeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetGridSpacingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSpacing);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateGridSpacingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSpacing,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetIsoSurfaceEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateIsoSurfaceEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetIsosurfaceLevelAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateIsosurfaceLevelAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetKernelRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceKernelRadius);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateKernelRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceKernelRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetMaxSubgridsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxSubgrids);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateMaxSubgridsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxSubgrids,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetMaxTrianglesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxTriangles);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateMaxTrianglesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxTriangles,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetMaxVerticesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxVertices);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateMaxVerticesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxVertices,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::GetNumMeshSmoothingPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceNumMeshSmoothingPasses);
}

UsdAttribute
UsdPhysXIsosurfaceAPI::CreateNumMeshSmoothingPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXIsosurfaceAPI::GetSchemaAttributeNames(bool includeInherited)
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

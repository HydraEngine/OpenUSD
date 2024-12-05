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
    TfType::Define<UsdPhysXphysxIsosurfaceAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
UsdPhysXphysxIsosurfaceAPI::~UsdPhysXphysxIsosurfaceAPI()
{
}

/* static */
UsdPhysXphysxIsosurfaceAPI
UsdPhysXphysxIsosurfaceAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysXphysxIsosurfaceAPI();
    }
    return UsdPhysXphysxIsosurfaceAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysXphysxIsosurfaceAPI::_GetSchemaKind() const
{
    return UsdPhysXphysxIsosurfaceAPI::schemaKind;
}

/* static */
bool
UsdPhysXphysxIsosurfaceAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysXphysxIsosurfaceAPI>(whyNot);
}

/* static */
UsdPhysXphysxIsosurfaceAPI
UsdPhysXphysxIsosurfaceAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysXphysxIsosurfaceAPI>()) {
        return UsdPhysXphysxIsosurfaceAPI(prim);
    }
    return UsdPhysXphysxIsosurfaceAPI();
}

/* static */
const TfType &
UsdPhysXphysxIsosurfaceAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysXphysxIsosurfaceAPI>();
    return tfType;
}

/* static */
bool 
UsdPhysXphysxIsosurfaceAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
UsdPhysXphysxIsosurfaceAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetAnisotropyMaxAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMax);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateAnisotropyMaxAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMax,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetAnisotropyMinAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyMin);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateAnisotropyMinAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyMin,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetAnisotropyRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateAnisotropyRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceAnisotropyRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetEnableAnisotropyAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateEnableAnisotropyAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceEnableAnisotropy,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetGridFilteringPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateGridFilteringPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridFilteringPasses,
                       SdfValueTypeNames->String,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetGridSmoothingRadiusRelativeToCellSizeAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateGridSmoothingRadiusRelativeToCellSizeAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSmoothingRadiusRelativeToCellSize,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetGridSpacingAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceGridSpacing);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateGridSpacingAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceGridSpacing,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetIsoSurfaceEnabledAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateIsoSurfaceEnabledAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsoSurfaceEnabled,
                       SdfValueTypeNames->Bool,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetIsosurfaceLevelAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateIsosurfaceLevelAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceIsosurfaceLevel,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetKernelRadiusAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceKernelRadius);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateKernelRadiusAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceKernelRadius,
                       SdfValueTypeNames->Float,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetMaxSubgridsAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxSubgrids);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateMaxSubgridsAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxSubgrids,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetMaxTrianglesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxTriangles);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateMaxTrianglesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxTriangles,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetMaxVerticesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceMaxVertices);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateMaxVerticesAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(UsdPhysXTokens->physxIsosurfaceMaxVertices,
                       SdfValueTypeNames->Int,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::GetNumMeshSmoothingPassesAttr() const
{
    return GetPrim().GetAttribute(UsdPhysXTokens->physxIsosurfaceNumMeshSmoothingPasses);
}

UsdAttribute
UsdPhysXphysxIsosurfaceAPI::CreateNumMeshSmoothingPassesAttr(VtValue const &defaultValue, bool writeSparsely) const
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
UsdPhysXphysxIsosurfaceAPI::GetSchemaAttributeNames(bool includeInherited)
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

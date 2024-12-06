//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxIsosurfaceAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxIsosurfaceSchema.h"
#include "pxr/usd/usdPhysX/isosurfaceAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXIsosurfaceAPIAdapter Adapter;
    TfType t = TfType::Define<Adapter, TfType::Bases<Adapter::BaseAdapter>>();
    t.SetFactory<UsdImagingAPISchemaAdapterFactory<Adapter>>();
}

namespace {
class PhysxDataSource final : public HdContainerDataSource {
public:
    HD_DECLARE_DATASOURCE(PhysxDataSource);

    explicit PhysxDataSource(const UsdPrim& prim) : _api(prim) {}

    TfTokenVector GetNames() override {
        static const TfTokenVector names = {
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyMax,                          //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyMin,                          //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyRadius,                       //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->enableAnisotropy,                       //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridFilteringPasses,                    //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridSmoothingRadiusRelativeToCellSize,  //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridSpacing,                            //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->isoSurfaceEnabled,                      //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->isosurfaceLevel,                        //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->kernelRadius,                           //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxSubgrids,                            //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxTriangles,                           //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxVertices,                            //
                UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->numMeshSmoothingPasses,                 //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyMax) {
            if (UsdAttribute attr = _api.GetAnisotropyMaxAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyMin) {
            if (UsdAttribute attr = _api.GetAnisotropyMinAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->anisotropyRadius) {
            if (UsdAttribute attr = _api.GetAnisotropyRadiusAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->enableAnisotropy) {
            if (UsdAttribute attr = _api.GetEnableAnisotropyAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridFilteringPasses) {
            if (UsdAttribute attr = _api.GetGridFilteringPassesAttr()) {
                std::string v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<std::string>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridSmoothingRadiusRelativeToCellSize) {
            if (UsdAttribute attr = _api.GetGridSmoothingRadiusRelativeToCellSizeAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->gridSpacing) {
            if (UsdAttribute attr = _api.GetGridSpacingAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->isoSurfaceEnabled) {
            if (UsdAttribute attr = _api.GetIsoSurfaceEnabledAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->isosurfaceLevel) {
            if (UsdAttribute attr = _api.GetIsosurfaceLevelAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->kernelRadius) {
            if (UsdAttribute attr = _api.GetKernelRadiusAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxSubgrids) {
            if (UsdAttribute attr = _api.GetMaxSubgridsAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxTriangles) {
            if (UsdAttribute attr = _api.GetMaxTrianglesAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->maxVertices) {
            if (UsdAttribute attr = _api.GetMaxVerticesAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->numMeshSmoothingPasses) {
            if (UsdAttribute attr = _api.GetNumMeshSmoothingPassesAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXIsosurfaceAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXIsosurfaceAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(UsdPhysicsImagingPhysxIsosurfaceSchemaTokens->physxIsosurface,
                                                  PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXIsosurfaceAPIAdapter::InvalidateImagingSubprim(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        TfTokenVector const& properties,
        UsdImagingPropertyInvalidationType invalidationType) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return HdDataSourceLocatorSet();
    }

    HdDataSourceLocatorSet result;
    for (const TfToken& propertyName : properties) {
        if (TfStringStartsWith(propertyName.GetString(), "physics:")) {
            result.insert(UsdPhysicsImagingPhysxIsosurfaceSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
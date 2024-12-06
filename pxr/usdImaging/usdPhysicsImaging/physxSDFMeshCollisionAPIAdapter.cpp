//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxSDFMeshCollisionAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/physxSDFMeshCollisionSchema.h"
#include "pxr/usd/usdPhysX/sDFMeshCollisionAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXSDFMeshCollisionAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfBitsPerSubgridPixel,           //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfEnableRemeshing,               //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfMargin,                        //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfNarrowBandThickness,           //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfResolution,                    //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfSubgridResolution,             //
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfTriangleCountReductionFactor,  //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfBitsPerSubgridPixel) {
            if (UsdAttribute attr = _api.GetSdfBitsPerSubgridPixelAttr()) {
                TfToken v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<TfToken>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfEnableRemeshing) {
            if (UsdAttribute attr = _api.GetSdfEnableRemeshingAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfMargin) {
            if (UsdAttribute attr = _api.GetSdfMarginAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfNarrowBandThickness) {
            if (UsdAttribute attr = _api.GetSdfNarrowBandThicknessAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfResolution) {
            if (UsdAttribute attr = _api.GetSdfResolutionAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfSubgridResolution) {
            if (UsdAttribute attr = _api.GetSdfSubgridResolutionAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->sdfTriangleCountReductionFactor) {
            if (UsdAttribute attr = _api.GetSdfTriangleCountReductionFactorAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXSDFMeshCollisionAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXSDFMeshCollisionAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxSDFMeshCollisionSchemaTokens->physxSDFMeshCollision, PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXSDFMeshCollisionAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxSDFMeshCollisionSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
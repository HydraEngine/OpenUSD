//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxConvexDecompositionCollisionAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/physxConvexDecompositionCollisionSchema.h"
#include "pxr/usd/usdPhysX/convexDecompositionCollisionAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXConvexDecompositionCollisionAPIAdapter Adapter;
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
                HdPhysxConvexDecompositionCollisionSchemaTokens->errorPercentage,           //
                HdPhysxConvexDecompositionCollisionSchemaTokens->hullVertexLimit,         //
                HdPhysxConvexDecompositionCollisionSchemaTokens->maxConvexHulls,                //
                HdPhysxConvexDecompositionCollisionSchemaTokens->minThickness,  //
                HdPhysxConvexDecompositionCollisionSchemaTokens->shrinkWrap,  //
                HdPhysxConvexDecompositionCollisionSchemaTokens->voxelResolution,        //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->errorPercentage) {
            if (UsdAttribute attr = _api.GetErrorPercentageAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->hullVertexLimit) {
            if (UsdAttribute attr = _api.GetHullVertexLimitAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->maxConvexHulls) {
            if (UsdAttribute attr = _api.GetMaxConvexHullsAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        } else if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->minThickness) {
            if (UsdAttribute attr = _api.GetMinThicknessAttr()) {
                float v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<float>::New(v);
                }
            }
        } else if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->shrinkWrap) {
            if (UsdAttribute attr = _api.GetShrinkWrapAttr()) {
                bool v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<bool>::New(v);
                }
            }
        } else if (name == HdPhysxConvexDecompositionCollisionSchemaTokens->voxelResolution) {
            if (UsdAttribute attr = _api.GetVoxelResolutionAttr()) {
                int v;
                if (attr.Get(&v)) {
                    return HdRetainedTypedSampledDataSource<int>::New(v);
                }
            }
        }
        return nullptr;
    }

private:
    UsdPhysXConvexDecompositionCollisionAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXConvexDecompositionCollisionAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                HdPhysxConvexDecompositionCollisionSchemaTokens->physxConvexDecompositionCollision,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXConvexDecompositionCollisionAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(HdPhysxConvexDecompositionCollisionSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
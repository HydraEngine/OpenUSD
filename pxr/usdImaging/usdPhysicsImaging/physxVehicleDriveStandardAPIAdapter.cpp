//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleDriveStandardAPIAdapter.h"
#include "pxr/usdImaging/usdImaging/primAdapter.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/usdImaging/usdPhysicsImaging/physxVehicleDriveStandardSchema.h"
#include "pxr/usd/usdPhysX/vehicleDriveStandardAPI.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include <iostream>

PXR_NAMESPACE_OPEN_SCOPE

TF_REGISTRY_FUNCTION(TfType) {
    typedef UsdImagingPhysicsPhysXVehicleDriveStandardAPIAdapter Adapter;
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
                UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->gears,        //
                UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->engine,       //
                UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->autoGearBox,  //
                UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->clutch,       //
        };

        return names;
    }

    HdDataSourceBaseHandle Get(const TfToken& name) override {
        if (name == UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->gears) {
            if (UsdRelationship rel = _api.GetGearsRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->engine) {
            if (UsdRelationship rel = _api.GetEngineRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->autoGearBox) {
            if (UsdRelationship rel = _api.GetAutoGearBoxRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        } else if (name == UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->clutch) {
            if (UsdRelationship rel = _api.GetClutchRel()) {
                return DependentPrimsDataSource::New(rel);
            }
        }
        return nullptr;
    }

private:
    UsdPhysXVehicleDriveStandardAPI _api;
};
}  // namespace

HdContainerDataSourceHandle UsdImagingPhysicsPhysXVehicleDriveStandardAPIAdapter::GetImagingSubprimData(
        UsdPrim const& prim,
        TfToken const& subprim,
        TfToken const& appliedInstanceName,
        const UsdImagingDataSourceStageGlobals& stageGlobals) {
    if (!subprim.IsEmpty() || !appliedInstanceName.IsEmpty()) {
        return nullptr;
    }

    if (subprim.IsEmpty()) {
        return HdRetainedContainerDataSource::New(
                UsdPhysicsImagingPhysxVehicleDriveStandardSchemaTokens->physxVehicleDriveStandard,
                PhysxDataSource::New(prim));
    }

    return nullptr;
}

HdDataSourceLocatorSet UsdImagingPhysicsPhysXVehicleDriveStandardAPIAdapter::InvalidateImagingSubprim(
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
            result.insert(UsdPhysicsImagingPhysxVehicleDriveStandardSchema::GetDefaultLocator());
        }
    }

    return result;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceGearJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/usdImaging/usdPhysicsImaging/physxPhysicsGearJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourceGearJoint::UsdImagingDataSourceGearJoint(const SdfPath &sceneIndexPath,
                                                             UsdPhysXPhysicsGearJoint usdJoint,
                                                             const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdGearJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourceGearJoint::GetNames() {
    return UsdPhysXPhysicsGearJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceGearJoint::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingPhysxPhysicsGearJointSchemaTokens->gearRatio) {
        if (UsdAttribute attr = _usdGearJoint.GetPhysicsGearRatioAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == UsdPhysicsImagingPhysxPhysicsGearJointSchemaTokens->hinge0) {
        if (UsdRelationship rel = _usdGearJoint.GetHinge0Rel()) {
            return DependentPrimsDataSource::New(rel);
        }
    } else if (name == UsdPhysicsImagingPhysxPhysicsGearJointSchemaTokens->hinge1) {
        if (UsdRelationship rel = _usdGearJoint.GetHinge1Rel()) {
            return DependentPrimsDataSource::New(rel);
        }
    }
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceGearJointPrim::UsdImagingDataSourceGearJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceGearJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(UsdPhysicsImagingPhysxPhysicsGearJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceGearJointPrim::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingPhysxPhysicsGearJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceGearJoint::New(_GetSceneIndexPath(), UsdPhysXPhysicsGearJoint(_GetUsdPrim()),
                                                  _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceGearJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators =
            UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysXPhysicsGearJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(UsdPhysicsImagingPhysxPhysicsGearJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceRackAndPinionJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"
#include "pxr/usdImaging/usdPhysicsImaging/physxPhysicsRackAndPinionJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourceRackAndPinionJoint::UsdImagingDataSourceRackAndPinionJoint(
        const SdfPath &sceneIndexPath,
        UsdPhysXPhysicsRackAndPinionJoint usdJoint,
        const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdRackAndPinionJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourceRackAndPinionJoint::GetNames() {
    return UsdPhysXPhysicsRackAndPinionJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceRackAndPinionJoint::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchemaTokens->ratio) {
        if (UsdAttribute attr = _usdRackAndPinionJoint.GetPhysicsRatioAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchemaTokens->hinge) {
        if (UsdRelationship rel = _usdRackAndPinionJoint.GetHingeRel()) {
            return DependentPrimsDataSource::New(rel);
        }
    } else if (name == UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchemaTokens->prismatic) {
        if (UsdRelationship rel = _usdRackAndPinionJoint.GetPrismaticRel()) {
            return DependentPrimsDataSource::New(rel);
        }
    }
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceRackAndPinionJointPrim::UsdImagingDataSourceRackAndPinionJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceRackAndPinionJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceRackAndPinionJointPrim::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceRackAndPinionJoint::New(
                _GetSceneIndexPath(), UsdPhysXPhysicsRackAndPinionJoint(_GetUsdPrim()), _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceRackAndPinionJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators =
            UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames =
            UsdPhysXPhysicsRackAndPinionJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(UsdPhysicsImagingPhysxPhysicsRackAndPinionJointSchema::GetDefaultLocator().Append(
                        propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

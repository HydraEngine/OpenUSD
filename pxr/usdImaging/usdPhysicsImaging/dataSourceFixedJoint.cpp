//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceFixedJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/fixedJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourceFixedJoint::UsdImagingDataSourceFixedJoint(
        const SdfPath &sceneIndexPath,
        UsdPhysicsFixedJoint usdJoint,
        const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdFixedJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourceFixedJoint::GetNames() {
    return UsdPhysicsFixedJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceFixedJoint::Get(const TfToken &name) {
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceFixedJointPrim::UsdImagingDataSourceFixedJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceFixedJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(HdFixedJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceFixedJointPrim::Get(const TfToken &name) {
    if (name == HdFixedJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceFixedJoint::New(_GetSceneIndexPath(), UsdPhysicsFixedJoint(_GetUsdPrim()),
                                                      _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceFixedJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators = UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysicsFixedJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(HdFixedJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

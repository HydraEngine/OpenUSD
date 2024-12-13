//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceRevoluteJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/revoluteJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourceRevoluteJoint::UsdImagingDataSourceRevoluteJoint(
        const SdfPath &sceneIndexPath,
        UsdPhysicsRevoluteJoint usdJoint,
        const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdRevoluteJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourceRevoluteJoint::GetNames() {
    return UsdPhysicsRevoluteJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceRevoluteJoint::Get(const TfToken &name) {
    if (name == HdRevoluteJointSchemaTokens->axis) {
        if (UsdAttribute attr = _usdRevoluteJoint.GetAxisAttr()) {
            TfToken v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<TfToken>::New(v);
            }
        }
    } else if (name == HdRevoluteJointSchemaTokens->lowerLimit) {
        if (UsdAttribute attr = _usdRevoluteJoint.GetLowerLimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == HdRevoluteJointSchemaTokens->upperLimit) {
        if (UsdAttribute attr = _usdRevoluteJoint.GetUpperLimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    }
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceRevoluteJointPrim::UsdImagingDataSourceRevoluteJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceRevoluteJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(HdRevoluteJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceRevoluteJointPrim::Get(const TfToken &name) {
    if (name == HdRevoluteJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceRevoluteJoint::New(_GetSceneIndexPath(), UsdPhysicsRevoluteJoint(_GetUsdPrim()),
                                                      _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceRevoluteJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators =
            UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysicsRevoluteJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(HdRevoluteJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

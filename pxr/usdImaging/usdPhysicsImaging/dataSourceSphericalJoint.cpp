//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceSphericalJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/sphericalJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourceSphericalJoint::UsdImagingDataSourceSphericalJoint(
        const SdfPath &sceneIndexPath,
        UsdPhysicsSphericalJoint usdJoint,
        const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdSphericalJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourceSphericalJoint::GetNames() {
    return UsdPhysicsSphericalJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceSphericalJoint::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingSphericalJointSchemaTokens->axis) {
        if (UsdAttribute attr = _usdSphericalJoint.GetAxisAttr()) {
            TfToken v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<TfToken>::New(v);
            }
        }
    } else if (name == UsdPhysicsImagingSphericalJointSchemaTokens->coneAngle0Limit) {
        if (UsdAttribute attr = _usdSphericalJoint.GetConeAngle0LimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == UsdPhysicsImagingSphericalJointSchemaTokens->coneAngle1Limit) {
        if (UsdAttribute attr = _usdSphericalJoint.GetConeAngle1LimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    }
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceSphericalJointPrim::UsdImagingDataSourceSphericalJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceSphericalJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(UsdPhysicsImagingSphericalJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceSphericalJointPrim::Get(const TfToken &name) {
    if (name == UsdPhysicsImagingSphericalJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceSphericalJoint::New(_GetSceneIndexPath(), UsdPhysicsSphericalJoint(_GetUsdPrim()),
                                                       _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceSphericalJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators =
            UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysicsSphericalJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(UsdPhysicsImagingSphericalJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

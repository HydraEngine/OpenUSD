//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourcePrismaticJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/imaging/hd/prismaticJointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdImagingDataSourcePrismaticJoint::UsdImagingDataSourcePrismaticJoint(
        const SdfPath &sceneIndexPath,
        UsdPhysicsPrismaticJoint usdJoint,
        const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJoint(sceneIndexPath, usdJoint, stageGlobals), _usdPrismaticJoint(usdJoint) {}

TfTokenVector UsdImagingDataSourcePrismaticJoint::GetNames() {
    return UsdPhysicsPrismaticJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourcePrismaticJoint::Get(const TfToken &name) {
    if (name == HdPrismaticJointSchemaTokens->axis) {
        if (UsdAttribute attr = _usdPrismaticJoint.GetAxisAttr()) {
            TfToken v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<TfToken>::New(v);
            }
        }
    } else if (name == HdPrismaticJointSchemaTokens->lowerLimit) {
        if (UsdAttribute attr = _usdPrismaticJoint.GetLowerLimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == HdPrismaticJointSchemaTokens->upperLimit) {
        if (UsdAttribute attr = _usdPrismaticJoint.GetUpperLimitAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    }
    return UsdImagingDataSourceJoint::Get(name);
}

// ----------------------------------------------------------------------------

UsdImagingDataSourcePrismaticJointPrim::UsdImagingDataSourcePrismaticJointPrim(
        const SdfPath &sceneIndexPath, UsdPrim usdPrim, const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourceJointPrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourcePrismaticJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourceJointPrim::GetNames();
    result.push_back(HdPrismaticJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourcePrismaticJointPrim::Get(const TfToken &name) {
    if (name == HdPrismaticJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourcePrismaticJoint::New(_GetSceneIndexPath(), UsdPhysicsPrismaticJoint(_GetUsdPrim()),
                                                       _GetStageGlobals());
    }

    return UsdImagingDataSourceJointPrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourcePrismaticJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators =
            UsdImagingDataSourceJointPrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysicsPrismaticJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(HdPrismaticJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

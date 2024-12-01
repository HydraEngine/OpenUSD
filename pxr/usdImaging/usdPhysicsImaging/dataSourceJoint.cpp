//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dataSourceJoint.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"

#include "pxr/usdImaging/usdPhysicsImaging/jointSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

namespace {
class DependentPrimsDataSource : public HdPathArrayDataSource {
public:
    HD_DECLARE_DATASOURCE(DependentPrimsDataSource);

    DependentPrimsDataSource(const UsdRelationship &rel) : _usdRel(rel) {}

    VtValue GetValue(HdSampledDataSource::Time shutterOffset) override { return VtValue(GetTypedValue(shutterOffset)); }

    VtArray<SdfPath> GetTypedValue(HdSampledDataSource::Time shutterOffset) override {
        SdfPathVector paths;
        _usdRel.GetForwardedTargets(&paths);
        VtArray<SdfPath> vtPaths(paths.begin(), paths.end());
        return vtPaths;
    }

    bool GetContributingSampleTimesForInterval(HdSampledDataSource::Time startTime,
                                               HdSampledDataSource::Time endTime,
                                               std::vector<HdSampledDataSource::Time> *outSampleTimes) override {
        return false;
    }

private:
    UsdRelationship _usdRel;
};
}  // namespace

UsdImagingDataSourceJoint::UsdImagingDataSourceJoint(const SdfPath &sceneIndexPath,
                                                     UsdPhysicsJoint usdJoint,
                                                     const UsdImagingDataSourceStageGlobals &stageGlobals)
    : _sceneIndexPath(sceneIndexPath), _usdJoint(usdJoint), _stageGlobals(stageGlobals) {}

TfTokenVector UsdImagingDataSourceJoint::GetNames() {
    return UsdPhysicsJoint::GetSchemaAttributeNames(/* includeInherited = */ false);
}

HdDataSourceBaseHandle UsdImagingDataSourceJoint::Get(const TfToken &name) {
    if (name == UsdPhysicsTokens->physicsLocalPos0) {
        if (UsdAttribute attr = _usdJoint.GetLocalPos0Attr()) {
            GfVec3f v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsLocalPos1) {
        if (UsdAttribute attr = _usdJoint.GetLocalPos1Attr()) {
            GfVec3f v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsLocalRot0) {
        if (UsdAttribute attr = _usdJoint.GetLocalRot0Attr()) {
            GfVec3f v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsLocalRot1) {
        if (UsdAttribute attr = _usdJoint.GetLocalRot1Attr()) {
            GfVec3f v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<GfVec3f>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsJointEnabled) {
        if (UsdAttribute attr = _usdJoint.GetJointEnabledAttr()) {
            bool v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<bool>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsCollisionEnabled) {
        if (UsdAttribute attr = _usdJoint.GetCollisionEnabledAttr()) {
            bool v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<bool>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsExcludeFromArticulation) {
        if (UsdAttribute attr = _usdJoint.GetExcludeFromArticulationAttr()) {
            bool v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<bool>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsBreakForce) {
        if (UsdAttribute attr = _usdJoint.GetBreakForceAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsBreakTorque) {
        if (UsdAttribute attr = _usdJoint.GetBreakTorqueAttr()) {
            float v{};
            if (attr.Get(&v)) {
                return HdRetainedTypedSampledDataSource<float>::New(v);
            }
        }
    } else if (name == UsdPhysicsTokens->physicsBody0) {
        if (UsdRelationship rel = _usdJoint.GetBody0Rel()) {
            return DependentPrimsDataSource::New(rel);
        }
    } else if (name == UsdPhysicsTokens->physicsBody1) {
        if (UsdRelationship rel = _usdJoint.GetBody1Rel()) {
            return DependentPrimsDataSource::New(rel);
        }
    }
    return nullptr;
}

// ----------------------------------------------------------------------------

UsdImagingDataSourceJointPrim::UsdImagingDataSourceJointPrim(const SdfPath &sceneIndexPath,
                                                             UsdPrim usdPrim,
                                                             const UsdImagingDataSourceStageGlobals &stageGlobals)
    : UsdImagingDataSourcePrim(sceneIndexPath, usdPrim, stageGlobals) {}

TfTokenVector UsdImagingDataSourceJointPrim::GetNames() {
    TfTokenVector result = UsdImagingDataSourcePrim::GetNames();
    result.push_back(HdJointSchema::GetSchemaToken());
    return result;
}

HdDataSourceBaseHandle UsdImagingDataSourceJointPrim::Get(const TfToken &name) {
    if (name == HdJointSchema::GetSchemaToken()) {
        return UsdImagingDataSourceJoint::New(_GetSceneIndexPath(), UsdPhysicsJoint(_GetUsdPrim()), _GetStageGlobals());
    }

    return UsdImagingDataSourcePrim::Get(name);
}

HdDataSourceLocatorSet UsdImagingDataSourceJointPrim::Invalidate(
        UsdPrim const &prim,
        const TfToken &subprim,
        const TfTokenVector &properties,
        const UsdImagingPropertyInvalidationType invalidationType) {
    TRACE_FUNCTION();

    HdDataSourceLocatorSet locators = UsdImagingDataSourcePrim::Invalidate(prim, subprim, properties, invalidationType);

    static TfTokenVector usdNames = UsdPhysicsJoint::GetSchemaAttributeNames(/* includeInherited = */ false);

    for (const TfToken &propertyName : properties) {
        for (const TfToken &usdName : usdNames) {
            if (propertyName == usdName) {
                locators.insert(HdJointSchema::GetDefaultLocator().Append(propertyName));
            }
        }
    }

    return locators;
}

PXR_NAMESPACE_CLOSE_SCOPE

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/dependentPrimsDataSource.h"

PXR_NAMESPACE_OPEN_SCOPE

DependentPrimsDataSource::DependentPrimsDataSource(const UsdRelationship& rel) : _usdRel(rel) {}

VtValue DependentPrimsDataSource::GetValue(HdSampledDataSource::Time shutterOffset) {
    return VtValue(GetTypedValue(shutterOffset));
}

VtArray<SdfPath> DependentPrimsDataSource::GetTypedValue(HdSampledDataSource::Time shutterOffset) {
    SdfPathVector paths;
    _usdRel.GetForwardedTargets(&paths);
    VtArray<SdfPath> vtPaths(paths.begin(), paths.end());
    return vtPaths;
}

bool DependentPrimsDataSource::GetContributingSampleTimesForInterval(
        HdSampledDataSource::Time startTime,
        HdSampledDataSource::Time endTime,
        std::vector<HdSampledDataSource::Time>* outSampleTimes) {
    return false;
}

PXR_NAMESPACE_CLOSE_SCOPE
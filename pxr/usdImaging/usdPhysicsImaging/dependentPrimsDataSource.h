//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/usdImaging/usdImaging/dataSourceAttribute.h"
#include "pxr/usd/usd/relationship.h"

PXR_NAMESPACE_OPEN_SCOPE

class DependentPrimsDataSource : public HdPathArrayDataSource {
public:
    HD_DECLARE_DATASOURCE(DependentPrimsDataSource);

    DependentPrimsDataSource(const UsdRelationship& rel);

    VtValue GetValue(HdSampledDataSource::Time shutterOffset);

    VtArray<SdfPath> GetTypedValue(HdSampledDataSource::Time shutterOffset);

    bool GetContributingSampleTimesForInterval(HdSampledDataSource::Time startTime,
                                               HdSampledDataSource::Time endTime,
                                               std::vector<HdSampledDataSource::Time>* outSampleTimes);

private:
    UsdRelationship _usdRel;
};

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/distanceJointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdFloatDataSourceHandle HdDistanceJointSchema::GetMinDistance() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsMinDistance);
}
HdFloatDataSourceHandle HdDistanceJointSchema::GetMaxDistance() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsMaxDistance);
}

/*static*/
HdDistanceJointSchema HdDistanceJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdDistanceJointSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                               HdPhysicsSchemaTokens->physicsDistanceJoint))
                                                     : nullptr);
}

/*static*/
const TfToken &HdDistanceJointSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsDistanceJoint; }

/*static*/
const HdDataSourceLocator &HdDistanceJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &HdDistanceJointSchema::GetMinDistanceLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsMinDistance);
    return locator;
}
const HdDataSourceLocator &HdDistanceJointSchema::GetMaxDistanceLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsMaxDistance);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
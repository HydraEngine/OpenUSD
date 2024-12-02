//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/revoluteJointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE
HdTokenDataSourceHandle HdRevoluteJointSchema::GetAxis() const {
    return _GetTypedDataSource<HdTokenDataSource>(UsdPhysicsTokens->physicsAxis);
}
HdFloatDataSourceHandle HdRevoluteJointSchema::GetLowerLimit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsLowerLimit);
}
HdFloatDataSourceHandle HdRevoluteJointSchema::GetUpperLimit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsUpperLimit);
}

/*static*/
HdRevoluteJointSchema HdRevoluteJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdRevoluteJointSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                               HdPhysicsSchemaTokens->physicsRevoluteJoint))
                                                     : nullptr);
}

/*static*/
const TfToken &HdRevoluteJointSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsRevoluteJoint; }

/*static*/
const HdDataSourceLocator &HdRevoluteJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}
const HdDataSourceLocator &HdRevoluteJointSchema::GetAxisLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsAxis);
    return locator;
}
const HdDataSourceLocator &HdRevoluteJointSchema::GetLowerLimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLowerLimit);
    return locator;
}
const HdDataSourceLocator &HdRevoluteJointSchema::GetUpperLimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsUpperLimit);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/prismaticJointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE
HdTokenDataSourceHandle HdPrismaticJointSchema::GetAxis() const {
    return _GetTypedDataSource<HdTokenDataSource>(UsdPhysicsTokens->physicsAxis);
}
HdFloatDataSourceHandle HdPrismaticJointSchema::GetLowerLimit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsLowerLimit);
}
HdFloatDataSourceHandle HdPrismaticJointSchema::GetUpperLimit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsUpperLimit);
}

/*static*/
HdPrismaticJointSchema HdPrismaticJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdPrismaticJointSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                               UsdPhysicsTokens->PhysicsPrismaticJoint))
                                                     : nullptr);
}

/*static*/
const TfToken &HdPrismaticJointSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsPrismaticJoint; }

/*static*/
const HdDataSourceLocator &HdPrismaticJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}
const HdDataSourceLocator &HdPrismaticJointSchema::GetAxisLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsAxis);
    return locator;
}
const HdDataSourceLocator &HdPrismaticJointSchema::GetLowerLimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLowerLimit);
    return locator;
}
const HdDataSourceLocator &HdPrismaticJointSchema::GetUpperLimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsUpperLimit);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
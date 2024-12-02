//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/sphericalJointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE
HdTokenDataSourceHandle HdSphericalJointSchema::GetAxis() const {
    return _GetTypedDataSource<HdTokenDataSource>(UsdPhysicsTokens->physicsAxis);
}
HdFloatDataSourceHandle HdSphericalJointSchema::GetConeAngle0Limit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsConeAngle0Limit);
}
HdFloatDataSourceHandle HdSphericalJointSchema::GetConeAngle1Limit() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsConeAngle1Limit);
}

/*static*/
HdSphericalJointSchema HdSphericalJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdSphericalJointSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                UsdPhysicsTokens->PhysicsSphericalJoint))
                                                      : nullptr);
}

/*static*/
const TfToken &HdSphericalJointSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsSphericalJoint; }

/*static*/
const HdDataSourceLocator &HdSphericalJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}
const HdDataSourceLocator &HdSphericalJointSchema::GetAxisLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsAxis);
    return locator;
}
const HdDataSourceLocator &HdSphericalJointSchema::GetConeAngle0LimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsConeAngle0Limit);
    return locator;
}
const HdDataSourceLocator &HdSphericalJointSchema::GetConeAngle1LimitLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsConeAngle1Limit);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
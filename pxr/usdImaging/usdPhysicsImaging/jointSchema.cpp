//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/jointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

HdVec3fDataSourceHandle HdJointSchema::GetLocalPos0() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsLocalPos0);
}
HdVec3fDataSourceHandle HdJointSchema::GetLocalRot0() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsLocalRot0);
}
HdVec3fDataSourceHandle HdJointSchema::GetLocalPos1() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsLocalPos1);
}
HdVec3fDataSourceHandle HdJointSchema::GetLocalRot1() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsLocalRot1);
}
HdBoolDataSourceHandle HdJointSchema::GetJointEnabled() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsJointEnabled);
}
HdBoolDataSourceHandle HdJointSchema::GetCollisionEnabled() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsCollisionEnabled);
}
HdBoolDataSourceHandle HdJointSchema::GetExcludeFromArticulation() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsExcludeFromArticulation);
}
HdFloatDataSourceHandle HdJointSchema::GetBreakForce() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsBreakForce);
}
HdFloatDataSourceHandle HdJointSchema::GetBreakTorque() const {
    return _GetTypedDataSource<HdFloatDataSource>(UsdPhysicsTokens->physicsBreakTorque);
}
HdPathArrayDataSourceHandle HdJointSchema::GetBody0() const {
    return _GetTypedDataSource<HdPathArrayDataSource>(UsdPhysicsTokens->physicsBody0);
}
HdPathArrayDataSourceHandle HdJointSchema::GetBody1() const {
    return _GetTypedDataSource<HdPathArrayDataSource>(UsdPhysicsTokens->physicsBody1);
}

/*static*/
HdJointSchema HdJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdJointSchema(fromParentContainer ? HdContainerDataSource::Cast(
                                                       fromParentContainer->Get(HdPhysicsSchemaTokens->physicsJoint))
                                             : nullptr);
}

/*static*/
const TfToken &HdJointSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsJoint; }

/*static*/
const HdDataSourceLocator &HdJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &HdJointSchema::GetLocalPos0Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLocalPos0);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetLocalRot0Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLocalRot0);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetLocalPos1Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLocalPos1);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetLocalRot1Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsLocalRot1);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetJointEnabledLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsJointEnabled);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetCollisionEnabledLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsCollisionEnabled);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetExcludeFromArticulationLocator() {
    static const HdDataSourceLocator locator =
            GetDefaultLocator().Append(UsdPhysicsTokens->physicsExcludeFromArticulation);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetBreakForceLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsBreakForce);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetBreakTorqueLocator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsBreakTorque);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetBody0Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsBody0);
    return locator;
}
const HdDataSourceLocator &HdJointSchema::GetBody1Locator() {
    static const HdDataSourceLocator locator = GetDefaultLocator().Append(UsdPhysicsTokens->physicsBody1);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/rigidBodySchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"
#include "pxr/usdImaging/usdPhysicsImaging/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysicsImagingRigidBodySchema UsdPhysicsImagingRigidBodySchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer) {
    return UsdPhysicsImagingRigidBodySchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                                          HdPhysicsSchemaTokens->physicsRigidBody))
                                                                : nullptr);
}

HdBoolDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetRigidBodyEnabled() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsRigidBodyEnabled);
}
HdBoolDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetKinematicEnabled() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsKinematicEnabled);
}
HdBoolDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetStartsAsleep() const {
    return _GetTypedDataSource<HdBoolDataSource>(UsdPhysicsTokens->physicsStartsAsleep);
}
HdVec3fDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetVelocity() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsVelocity);
}
HdVec3fDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetAngularVelocity() const {
    return _GetTypedDataSource<HdVec3fDataSource>(UsdPhysicsTokens->physicsAngularVelocity);
}
HdPathArrayDataSourceHandle UsdPhysicsImagingRigidBodySchema::GetSimulationOwner() const {
    return _GetTypedDataSource<HdPathArrayDataSource>(UsdPhysicsTokens->physicsSimulationOwner);
}

const TfToken &UsdPhysicsImagingRigidBodySchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physicsLimit; }

const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetRigidBodyEnabledLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsRigidBodyEnabled);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetKinematicEnabledLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsKinematicEnabled);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetStartsAsleepLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsStartsAsleep);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetVelocityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsVelocity);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetAngularVelocityLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsAngularVelocity);
    return locator;
}
const HdDataSourceLocator &UsdPhysicsImagingRigidBodySchema::GetSimulationOwnerLocator() {
    static const HdDataSourceLocator locator(UsdPhysicsImagingRigidBodySchema::GetSchemaToken(),
                                             UsdPhysicsTokens->physicsSimulationOwner);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
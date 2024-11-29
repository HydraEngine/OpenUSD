//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hd/physicsSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/trace/trace.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPhysicsSchemaTokens, HD_PHYSICS_SCHEMA_TOKENS);

HdFloatDataSourceHandle HdPhysicsSchema::GetDensity() const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->density);
}

HdFloatDataSourceHandle HdPhysicsSchema::GetRestitution()const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->restitution);
}

HdFloatDataSourceHandle HdPhysicsSchema::GetDynamicFriction()const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->dynamicFriction);
}

HdFloatDataSourceHandle HdPhysicsSchema::GetStaticFriction()const {
    return _GetTypedDataSource<HdFloatDataSource>(HdPhysicsSchemaTokens->staticFriction);
}

HdPhysicsSchema HdPhysicsSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdPhysicsSchema(
            fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(HdPhysicsSchemaTokens->physics))
                                : nullptr);
}

const TfToken &HdPhysicsSchema::GetSchemaToken() { return HdPhysicsSchemaTokens->physics; }

const HdDataSourceLocator &HdPhysicsSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

const HdDataSourceLocator &HdPhysicsSchema::GetDensityLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->density);
    return locator;
}

const HdDataSourceLocator &HdPhysicsSchema::GetRestitutionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->restitution);
    return locator;
}

const HdDataSourceLocator &HdPhysicsSchema::GetDynamicFrictionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->dynamicFriction);
    return locator;
}

const HdDataSourceLocator &HdPhysicsSchema::GetStaticFrictionLocator() {
    static const HdDataSourceLocator locator(HdPhysicsSchemaTokens->physics, HdPhysicsSchemaTokens->staticFriction);
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdPhysXTokensType::UsdPhysXTokensType() :
    jointState("jointState", TfToken::Immortal),
    jointState_MultipleApplyTemplate_PhysicsPosition("jointState:__INSTANCE_NAME__:physics:position", TfToken::Immortal),
    jointState_MultipleApplyTemplate_PhysicsVelocity("jointState:__INSTANCE_NAME__:physics:velocity", TfToken::Immortal),
    PhysxSchemaJointStateAPI("PhysxSchemaJointStateAPI", TfToken::Immortal),
    allTokens({
        jointState,
        jointState_MultipleApplyTemplate_PhysicsPosition,
        jointState_MultipleApplyTemplate_PhysicsVelocity,
        PhysxSchemaJointStateAPI
    })
{
}

TfStaticData<UsdPhysXTokensType> UsdPhysXTokens;

PXR_NAMESPACE_CLOSE_SCOPE

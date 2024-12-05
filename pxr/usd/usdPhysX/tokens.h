//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_TOKENS_H
#define USDPHYSX_TOKENS_H

/// \file usdPhysX/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include "pxr/usd/usdPhysX/api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


/// \class UsdPhysXTokensType
///
/// \link UsdPhysXTokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// UsdPhysXTokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use UsdPhysXTokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(UsdPhysXTokens->alwaysUpdateEnabled);
/// \endcode
struct UsdPhysXTokensType {
    USDPHYSX_API UsdPhysXTokensType();
    /// \brief "alwaysUpdateEnabled"
    /// 
    /// UsdPhysXphysxCameraAPI
    const TfToken alwaysUpdateEnabled;
    /// \brief "jointState"
    /// 
    /// Property namespace prefix for the UsdPhysXJointStateAPI schema.
    const TfToken jointState;
    /// \brief "jointState:__INSTANCE_NAME__:physics:position"
    /// 
    /// UsdPhysXJointStateAPI
    const TfToken jointState_MultipleApplyTemplate_PhysicsPosition;
    /// \brief "jointState:__INSTANCE_NAME__:physics:velocity"
    /// 
    /// UsdPhysXJointStateAPI
    const TfToken jointState_MultipleApplyTemplate_PhysicsVelocity;
    /// \brief "physxArticulation:articulationEnabled"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationArticulationEnabled;
    /// \brief "physxArticulation:enabledSelfCollisions"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationEnabledSelfCollisions;
    /// \brief "physxArticulation:sleepThreshold"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationSleepThreshold;
    /// \brief "physxArticulation:solverPositionIterationCount"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationSolverPositionIterationCount;
    /// \brief "physxArticulation:solverVelocityIterationCount"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationSolverVelocityIterationCount;
    /// \brief "physxArticulation:stabilizationThreshold"
    /// 
    /// UsdPhysXphysxArticulationAPI
    const TfToken physxArticulationStabilizationThreshold;
    /// \brief "physxDroneCamera:feedForwardVelocityGain"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraFeedForwardVelocityGain;
    /// \brief "physxDroneCamera:followDistance"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraFollowDistance;
    /// \brief "physxDroneCamera:followHeight"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraFollowHeight;
    /// \brief "physxDroneCamera:horizontalVelocityGain"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraHorizontalVelocityGain;
    /// \brief "physxDroneCamera:maxDistance"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraMaxDistance;
    /// \brief "physxDroneCamera:maxSpeed"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraMaxSpeed;
    /// \brief "physxDroneCamera:positionOffset"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraPositionOffset;
    /// \brief "physxDroneCamera:rotationFilterTimeConstant"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraRotationFilterTimeConstant;
    /// \brief "physxDroneCamera:velocityFilterTimeConstant"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraVelocityFilterTimeConstant;
    /// \brief "physxDroneCamera:verticalVelocityGain"
    /// 
    /// UsdPhysXphysxCameraDroneAPI
    const TfToken physxDroneCameraVerticalVelocityGain;
    /// \brief "physxFollowCamera:cameraPositionTimeConstant"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraCameraPositionTimeConstant;
    /// \brief "physxFollowCamera:followMaxDistance"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraFollowMaxDistance;
    /// \brief "physxFollowCamera:followMaxSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraFollowMaxSpeed;
    /// \brief "physxFollowCamera:followMinDistance"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraFollowMinDistance;
    /// \brief "physxFollowCamera:followMinSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraFollowMinSpeed;
    /// \brief "physxFollowCamera:followTurnRateGain"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraFollowTurnRateGain;
    /// \brief "physxFollowCamera:lookAheadMaxSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMaxSpeed;
    /// \brief "physxFollowCamera:lookAheadMinDistance"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMinDistance;
    /// \brief "physxFollowCamera:lookAheadMinSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMinSpeed;
    /// \brief "physxFollowCamera:lookAheadTurnRateGain"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookAheadTurnRateGain;
    /// \brief "physxFollowCamera:lookPositionHeight"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookPositionHeight;
    /// \brief "physxFollowCamera:lookPositionTimeConstant"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraLookPositionTimeConstant;
    /// \brief "physxFollowCamera:pitchAngle"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraPitchAngle;
    /// \brief "physxFollowCamera:pitchAngleTimeConstant"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraPitchAngleTimeConstant;
    /// \brief "physxFollowCamera:positionOffset"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraPositionOffset;
    /// \brief "physxFollowCamera:slowPitchAngleSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraSlowPitchAngleSpeed;
    /// \brief "physxFollowCamera:slowSpeedPitchAngleScale"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraSlowSpeedPitchAngleScale;
    /// \brief "physxFollowCamera:velocityNormalMinSpeed"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraVelocityNormalMinSpeed;
    /// \brief "physxFollowCamera:yawAngle"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraYawAngle;
    /// \brief "physxFollowCamera:yawRateTimeConstant"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowCameraYawRateTimeConstant;
    /// \brief "physxFollowFollowCamera:lookAheadMaxDistance"
    /// 
    /// UsdPhysXphysxCameraFollowAPI
    const TfToken physxFollowFollowCameraLookAheadMaxDistance;
    /// \brief "PhysxSchemaJointStateAPI"
    /// 
    /// Schema identifer and family for UsdPhysXJointStateAPI
    const TfToken PhysxSchemaJointStateAPI;
    /// \brief "PhysxSchemaPhysxArticulationAPI"
    /// 
    /// Schema identifer and family for UsdPhysXphysxArticulationAPI
    const TfToken PhysxSchemaPhysxArticulationAPI;
    /// \brief "PhysxSchemaPhysxCameraAPI"
    /// 
    /// Schema identifer and family for UsdPhysXphysxCameraAPI
    const TfToken PhysxSchemaPhysxCameraAPI;
    /// \brief "PhysxSchemaPhysxCameraDroneAPI"
    /// 
    /// Schema identifer and family for UsdPhysXphysxCameraDroneAPI
    const TfToken PhysxSchemaPhysxCameraDroneAPI;
    /// \brief "PhysxSchemaPhysxCameraFollowAPI"
    /// 
    /// Schema identifer and family for UsdPhysXphysxCameraFollowAPI
    const TfToken PhysxSchemaPhysxCameraFollowAPI;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var UsdPhysXTokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa UsdPhysXTokensType
extern USDPHYSX_API TfStaticData<UsdPhysXTokensType> UsdPhysXTokens;

PXR_NAMESPACE_CLOSE_SCOPE

#endif

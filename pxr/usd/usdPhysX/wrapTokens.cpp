//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// GENERATED FILE.  DO NOT EDIT.
#include "pxr/external/boost/python/class.hpp"
#include "pxr/usd/usdPhysX/tokens.h"

PXR_NAMESPACE_USING_DIRECTIVE

#define _ADD_TOKEN(cls, name) \
    cls.add_static_property(#name, +[]() { return UsdPhysXTokens->name.GetString(); });

void wrapUsdPhysXTokens()
{
    pxr_boost::python::class_<UsdPhysXTokensType, pxr_boost::python::noncopyable>
        cls("Tokens", pxr_boost::python::no_init);
    _ADD_TOKEN(cls, alwaysUpdateEnabled);
    _ADD_TOKEN(cls, jointState);
    _ADD_TOKEN(cls, jointState_MultipleApplyTemplate_PhysicsPosition);
    _ADD_TOKEN(cls, jointState_MultipleApplyTemplate_PhysicsVelocity);
    _ADD_TOKEN(cls, physxArticulationArticulationEnabled);
    _ADD_TOKEN(cls, physxArticulationEnabledSelfCollisions);
    _ADD_TOKEN(cls, physxArticulationSleepThreshold);
    _ADD_TOKEN(cls, physxArticulationSolverPositionIterationCount);
    _ADD_TOKEN(cls, physxArticulationSolverVelocityIterationCount);
    _ADD_TOKEN(cls, physxArticulationStabilizationThreshold);
    _ADD_TOKEN(cls, physxDroneCameraFeedForwardVelocityGain);
    _ADD_TOKEN(cls, physxDroneCameraFollowDistance);
    _ADD_TOKEN(cls, physxDroneCameraFollowHeight);
    _ADD_TOKEN(cls, physxDroneCameraHorizontalVelocityGain);
    _ADD_TOKEN(cls, physxDroneCameraMaxDistance);
    _ADD_TOKEN(cls, physxDroneCameraMaxSpeed);
    _ADD_TOKEN(cls, physxDroneCameraPositionOffset);
    _ADD_TOKEN(cls, physxDroneCameraRotationFilterTimeConstant);
    _ADD_TOKEN(cls, physxDroneCameraVelocityFilterTimeConstant);
    _ADD_TOKEN(cls, physxDroneCameraVerticalVelocityGain);
    _ADD_TOKEN(cls, physxFollowCameraCameraPositionTimeConstant);
    _ADD_TOKEN(cls, physxFollowCameraFollowMaxDistance);
    _ADD_TOKEN(cls, physxFollowCameraFollowMaxSpeed);
    _ADD_TOKEN(cls, physxFollowCameraFollowMinDistance);
    _ADD_TOKEN(cls, physxFollowCameraFollowMinSpeed);
    _ADD_TOKEN(cls, physxFollowCameraFollowTurnRateGain);
    _ADD_TOKEN(cls, physxFollowCameraLookAheadMaxSpeed);
    _ADD_TOKEN(cls, physxFollowCameraLookAheadMinDistance);
    _ADD_TOKEN(cls, physxFollowCameraLookAheadMinSpeed);
    _ADD_TOKEN(cls, physxFollowCameraLookAheadTurnRateGain);
    _ADD_TOKEN(cls, physxFollowCameraLookPositionHeight);
    _ADD_TOKEN(cls, physxFollowCameraLookPositionTimeConstant);
    _ADD_TOKEN(cls, physxFollowCameraPitchAngle);
    _ADD_TOKEN(cls, physxFollowCameraPitchAngleTimeConstant);
    _ADD_TOKEN(cls, physxFollowCameraPositionOffset);
    _ADD_TOKEN(cls, physxFollowCameraSlowPitchAngleSpeed);
    _ADD_TOKEN(cls, physxFollowCameraSlowSpeedPitchAngleScale);
    _ADD_TOKEN(cls, physxFollowCameraVelocityNormalMinSpeed);
    _ADD_TOKEN(cls, physxFollowCameraYawAngle);
    _ADD_TOKEN(cls, physxFollowCameraYawRateTimeConstant);
    _ADD_TOKEN(cls, physxFollowFollowCameraLookAheadMaxDistance);
    _ADD_TOKEN(cls, physxFollowLookCameraDownHillGroundAngle);
    _ADD_TOKEN(cls, physxFollowLookCameraDownHillGroundPitch);
    _ADD_TOKEN(cls, physxFollowLookCameraFollowReverseDistance);
    _ADD_TOKEN(cls, physxFollowLookCameraFollowReverseSpeed);
    _ADD_TOKEN(cls, physxFollowLookCameraUpHillGroundAngle);
    _ADD_TOKEN(cls, physxFollowLookCameraUpHillGroundPitch);
    _ADD_TOKEN(cls, physxFollowLookCameraVelocityBlendTimeConstant);
    _ADD_TOKEN(cls, PhysxSchemaJointStateAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxArticulationAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxCameraAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxCameraDroneAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxCameraFollowAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxCameraFollowLookAPI);
    _ADD_TOKEN(cls, PhysxSchemaPhysxCameraFollowVelocityAPI);
}

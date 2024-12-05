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
///     gprim.GetMyTokenValuedAttr().Set(UsdPhysXTokens->acceleration);
/// \endcode
struct UsdPhysXTokensType {
    USDPHYSX_API UsdPhysXTokensType();
    /// \brief "acceleration"
    /// 
    /// Fallback value for UsdPhysXForceAPI::GetModeAttr()
    const TfToken acceleration;
    /// \brief "alwaysUpdateEnabled"
    /// 
    /// UsdPhysXCameraAPI
    const TfToken alwaysUpdateEnabled;
    /// \brief "Asynchronous"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetUpdateTypeAttr()
    const TfToken Asynchronous;
    /// \brief "average"
    /// 
    /// Fallback value for UsdPhysXMaterialAPI::GetDampingCombineModeAttr(), Fallback value for UsdPhysXMaterialAPI::GetFrictionCombineModeAttr(), Fallback value for UsdPhysXMaterialAPI::GetRestitutionCombineModeAttr()
    const TfToken average;
    /// \brief "BitsPerPixel16"
    /// 
    /// Fallback value for UsdPhysXSDFMeshCollisionAPI::GetSdfBitsPerSubgridPixelAttr()
    const TfToken BitsPerPixel16;
    /// \brief "BitsPerPixel32"
    /// 
    /// Possible value for UsdPhysXSDFMeshCollisionAPI::GetSdfBitsPerSubgridPixelAttr()
    const TfToken BitsPerPixel32;
    /// \brief "BitsPerPixel8"
    /// 
    /// Possible value for UsdPhysXSDFMeshCollisionAPI::GetSdfBitsPerSubgridPixelAttr()
    const TfToken BitsPerPixel8;
    /// \brief "constrained"
    /// 
    /// Possible value for UsdPhysXCharacterControllerAPI::GetClimbingModeAttr()
    const TfToken constrained;
    /// \brief "Disabled"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetUpdateTypeAttr()
    const TfToken Disabled;
    /// \brief "easy"
    /// 
    /// Fallback value for UsdPhysXCharacterControllerAPI::GetClimbingModeAttr()
    const TfToken easy;
    /// \brief "flood"
    /// 
    /// Fallback value for UsdPhysXSphereFillCollisionAPI::GetFillModeAttr()
    const TfToken flood;
    /// \brief "force"
    /// 
    /// Possible value for UsdPhysXForceAPI::GetModeAttr()
    const TfToken force;
    /// \brief "GPU"
    /// 
    /// Fallback value for UsdPhysXSceneAPI::GetBroadphaseTypeAttr()
    const TfToken GPU;
    /// \brief "hinge"
    /// 
    /// UsdPhysXPhysicsRackAndPinionJoint
    const TfToken hinge;
    /// \brief "hinge0"
    /// 
    /// UsdPhysXPhysicsGearJoint
    const TfToken hinge0;
    /// \brief "hinge1"
    /// 
    /// UsdPhysXPhysicsGearJoint
    const TfToken hinge1;
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
    /// \brief "max"
    /// 
    /// Possible value for UsdPhysXMaterialAPI::GetDampingCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetFrictionCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetRestitutionCombineModeAttr()
    const TfToken max;
    /// \brief "MBP"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetBroadphaseTypeAttr()
    const TfToken MBP;
    /// \brief "min"
    /// 
    /// Possible value for UsdPhysXMaterialAPI::GetDampingCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetFrictionCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetRestitutionCombineModeAttr()
    const TfToken min;
    /// \brief "multiply"
    /// 
    /// Possible value for UsdPhysXMaterialAPI::GetDampingCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetFrictionCombineModeAttr(), Possible value for UsdPhysXMaterialAPI::GetRestitutionCombineModeAttr()
    const TfToken multiply;
    /// \brief "patch"
    /// 
    /// Fallback value for UsdPhysXSceneAPI::GetFrictionTypeAttr()
    const TfToken patch;
    /// \brief "PCM"
    /// 
    /// Fallback value for UsdPhysXSceneAPI::GetCollisionSystemAttr()
    const TfToken PCM;
    /// \brief "PGS"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetSolverTypeAttr()
    const TfToken PGS;
    /// \brief "physics:body0Indices"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsBody0Indices;
    /// \brief "physicsBody0s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsBody0s;
    /// \brief "physics:body1Indices"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsBody1Indices;
    /// \brief "physicsBody1s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsBody1s;
    /// \brief "physics:gearRatio"
    /// 
    /// UsdPhysXPhysicsGearJoint
    const TfToken physicsGearRatio;
    /// \brief "physics:localPos0s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsLocalPos0s;
    /// \brief "physics:localPos1s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsLocalPos1s;
    /// \brief "physics:localRot0s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsLocalRot0s;
    /// \brief "physics:localRot1s"
    /// 
    /// UsdPhysXPhysicsJointInstancer
    const TfToken physicsLocalRot1s;
    /// \brief "physics:protoIndices"
    /// 
    /// UsdPhysXPhysicsInstancer
    const TfToken physicsProtoIndices;
    /// \brief "physics:ratio"
    /// 
    /// UsdPhysXPhysicsRackAndPinionJoint
    const TfToken physicsRatio;
    /// \brief "physxArticulation:articulationEnabled"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationArticulationEnabled;
    /// \brief "physxArticulation:enabledSelfCollisions"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationEnabledSelfCollisions;
    /// \brief "physxArticulation:sleepThreshold"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationSleepThreshold;
    /// \brief "physxArticulation:solverPositionIterationCount"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationSolverPositionIterationCount;
    /// \brief "physxArticulation:solverVelocityIterationCount"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationSolverVelocityIterationCount;
    /// \brief "physxArticulation:stabilizationThreshold"
    /// 
    /// UsdPhysXArticulationAPI
    const TfToken physxArticulationStabilizationThreshold;
    /// \brief "physxCharacterController:climbingMode"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerClimbingMode;
    /// \brief "physxCharacterController:contactOffset"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerContactOffset;
    /// \brief "physxCharacterController:invisibleWallHeight"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerInvisibleWallHeight;
    /// \brief "physxCharacterController:maxJumpHeight"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerMaxJumpHeight;
    /// \brief "physxCharacterController:moveTarget"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerMoveTarget;
    /// \brief "physxCharacterController:nonWalkableMode"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerNonWalkableMode;
    /// \brief "physxCharacterController:scaleCoeff"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerScaleCoeff;
    /// \brief "physxCharacterController:slopeLimit"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerSlopeLimit;
    /// \brief "physxCharacterController:stepOffset"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerStepOffset;
    /// \brief "physxCharacterController:upAxis"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerUpAxis;
    /// \brief "physxCharacterController:volumeGrowth"
    /// 
    /// UsdPhysXCharacterControllerAPI
    const TfToken physxCharacterControllerVolumeGrowth;
    /// \brief "physxCollision:contactOffset"
    /// 
    /// UsdPhysXCollisionAPI
    const TfToken physxCollisionContactOffset;
    /// \brief "physxCollision:minTorsionalPatchRadius"
    /// 
    /// UsdPhysXCollisionAPI
    const TfToken physxCollisionMinTorsionalPatchRadius;
    /// \brief "physxCollision:restOffset"
    /// 
    /// UsdPhysXCollisionAPI
    const TfToken physxCollisionRestOffset;
    /// \brief "physxCollision:torsionalPatchRadius"
    /// 
    /// UsdPhysXCollisionAPI
    const TfToken physxCollisionTorsionalPatchRadius;
    /// \brief "physxContactReport:threshold"
    /// 
    /// UsdPhysXContactReportAPI
    const TfToken physxContactReportThreshold;
    /// \brief "physxConvexDecompositionCollision:errorPercentage"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionErrorPercentage;
    /// \brief "physxConvexDecompositionCollision:hullVertexLimit"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionHullVertexLimit;
    /// \brief "physxConvexDecompositionCollision:maxConvexHulls"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionMaxConvexHulls;
    /// \brief "physxConvexDecompositionCollision:minThickness"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionMinThickness;
    /// \brief "physxConvexDecompositionCollision:shrinkWrap"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionShrinkWrap;
    /// \brief "physxConvexDecompositionCollision:voxelResolution"
    /// 
    /// UsdPhysXConvexDecompositionCollisionAPI
    const TfToken physxConvexDecompositionCollisionVoxelResolution;
    /// \brief "physxConvexHullCollision:hullVertexLimit"
    /// 
    /// UsdPhysXConvexHullCollisionAPI
    const TfToken physxConvexHullCollisionHullVertexLimit;
    /// \brief "physxConvexHullCollision:minThickness"
    /// 
    /// UsdPhysXConvexHullCollisionAPI
    const TfToken physxConvexHullCollisionMinThickness;
    /// \brief "physxCookedData"
    /// 
    /// Property namespace prefix for the UsdPhysXCookedDataAPI schema.
    const TfToken physxCookedData;
    /// \brief "physxCookedData:__INSTANCE_NAME__:buffer"
    /// 
    /// UsdPhysXCookedDataAPI
    const TfToken physxCookedData_MultipleApplyTemplate_Buffer;
    /// \brief "physxDroneCamera:feedForwardVelocityGain"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraFeedForwardVelocityGain;
    /// \brief "physxDroneCamera:followDistance"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraFollowDistance;
    /// \brief "physxDroneCamera:followHeight"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraFollowHeight;
    /// \brief "physxDroneCamera:horizontalVelocityGain"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraHorizontalVelocityGain;
    /// \brief "physxDroneCamera:maxDistance"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraMaxDistance;
    /// \brief "physxDroneCamera:maxSpeed"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraMaxSpeed;
    /// \brief "physxDroneCamera:positionOffset"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraPositionOffset;
    /// \brief "physxDroneCamera:rotationFilterTimeConstant"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraRotationFilterTimeConstant;
    /// \brief "physxDroneCamera:velocityFilterTimeConstant"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraVelocityFilterTimeConstant;
    /// \brief "physxDroneCamera:verticalVelocityGain"
    /// 
    /// UsdPhysXCameraDroneAPI
    const TfToken physxDroneCameraVerticalVelocityGain;
    /// \brief "physxFollowCamera:cameraPositionTimeConstant"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraCameraPositionTimeConstant;
    /// \brief "physxFollowCamera:followMaxDistance"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraFollowMaxDistance;
    /// \brief "physxFollowCamera:followMaxSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraFollowMaxSpeed;
    /// \brief "physxFollowCamera:followMinDistance"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraFollowMinDistance;
    /// \brief "physxFollowCamera:followMinSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraFollowMinSpeed;
    /// \brief "physxFollowCamera:followTurnRateGain"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraFollowTurnRateGain;
    /// \brief "physxFollowCamera:lookAheadMaxSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMaxSpeed;
    /// \brief "physxFollowCamera:lookAheadMinDistance"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMinDistance;
    /// \brief "physxFollowCamera:lookAheadMinSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookAheadMinSpeed;
    /// \brief "physxFollowCamera:lookAheadTurnRateGain"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookAheadTurnRateGain;
    /// \brief "physxFollowCamera:lookPositionHeight"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookPositionHeight;
    /// \brief "physxFollowCamera:lookPositionTimeConstant"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraLookPositionTimeConstant;
    /// \brief "physxFollowCamera:pitchAngle"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraPitchAngle;
    /// \brief "physxFollowCamera:pitchAngleTimeConstant"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraPitchAngleTimeConstant;
    /// \brief "physxFollowCamera:positionOffset"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraPositionOffset;
    /// \brief "physxFollowCamera:slowPitchAngleSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraSlowPitchAngleSpeed;
    /// \brief "physxFollowCamera:slowSpeedPitchAngleScale"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraSlowSpeedPitchAngleScale;
    /// \brief "physxFollowCamera:velocityNormalMinSpeed"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraVelocityNormalMinSpeed;
    /// \brief "physxFollowCamera:yawAngle"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraYawAngle;
    /// \brief "physxFollowCamera:yawRateTimeConstant"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowCameraYawRateTimeConstant;
    /// \brief "physxFollowFollowCamera:lookAheadMaxDistance"
    /// 
    /// UsdPhysXCameraFollowAPI
    const TfToken physxFollowFollowCameraLookAheadMaxDistance;
    /// \brief "physxFollowLookCamera:downHillGroundAngle"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraDownHillGroundAngle;
    /// \brief "physxFollowLookCamera:downHillGroundPitch"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraDownHillGroundPitch;
    /// \brief "physxFollowLookCamera:followReverseDistance"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraFollowReverseDistance;
    /// \brief "physxFollowLookCamera:followReverseSpeed"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraFollowReverseSpeed;
    /// \brief "physxFollowLookCamera:upHillGroundAngle"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraUpHillGroundAngle;
    /// \brief "physxFollowLookCamera:upHillGroundPitch"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraUpHillGroundPitch;
    /// \brief "physxFollowLookCamera:velocityBlendTimeConstant"
    /// 
    /// UsdPhysXCameraFollowLookAPI
    const TfToken physxFollowLookCameraVelocityBlendTimeConstant;
    /// \brief "physxForce:force"
    /// 
    /// UsdPhysXForceAPI
    const TfToken physxForceForce;
    /// \brief "physxForce:forceEnabled"
    /// 
    /// UsdPhysXForceAPI
    const TfToken physxForceForceEnabled;
    /// \brief "physxForce:mode"
    /// 
    /// UsdPhysXForceAPI
    const TfToken physxForceMode;
    /// \brief "physxForce:torque"
    /// 
    /// UsdPhysXForceAPI
    const TfToken physxForceTorque;
    /// \brief "physxForce:worldFrameEnabled"
    /// 
    /// UsdPhysXForceAPI
    const TfToken physxForceWorldFrameEnabled;
    /// \brief "physxIsosurface:anisotropyMax"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceAnisotropyMax;
    /// \brief "physxIsosurface:anisotropyMin"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceAnisotropyMin;
    /// \brief "physxIsosurface:anisotropyRadius"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceAnisotropyRadius;
    /// \brief "physxIsosurface:enableAnisotropy"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceEnableAnisotropy;
    /// \brief "physxIsosurface:gridFilteringPasses"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceGridFilteringPasses;
    /// \brief "physxIsosurface:gridSmoothingRadiusRelativeToCellSize"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceGridSmoothingRadiusRelativeToCellSize;
    /// \brief "physxIsosurface:gridSpacing"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceGridSpacing;
    /// \brief "physxIsosurface:isoSurfaceEnabled"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceIsoSurfaceEnabled;
    /// \brief "physxIsosurface:isosurfaceLevel"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceIsosurfaceLevel;
    /// \brief "physxIsosurface:kernelRadius"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceKernelRadius;
    /// \brief "physxIsosurface:maxSubgrids"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceMaxSubgrids;
    /// \brief "physxIsosurface:maxTriangles"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceMaxTriangles;
    /// \brief "physxIsosurface:maxVertices"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceMaxVertices;
    /// \brief "physxIsosurface:numMeshSmoothingPasses"
    /// 
    /// UsdPhysXIsosurfaceAPI
    const TfToken physxIsosurfaceNumMeshSmoothingPasses;
    /// \brief "physxJoint:armature"
    /// 
    /// UsdPhysXJointAPI
    const TfToken physxJointArmature;
    /// \brief "physxJoint:enableProjection"
    /// 
    /// UsdPhysXJointAPI
    const TfToken physxJointEnableProjection;
    /// \brief "physxJoint:jointFriction"
    /// 
    /// UsdPhysXJointAPI
    const TfToken physxJointJointFriction;
    /// \brief "physxJoint:maxJointVelocity"
    /// 
    /// UsdPhysXJointAPI
    const TfToken physxJointMaxJointVelocity;
    /// \brief "physxMaterial:compliantContactAccelerationSpring"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialCompliantContactAccelerationSpring;
    /// \brief "physxMaterial:compliantContactDamping"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialCompliantContactDamping;
    /// \brief "physxMaterial:compliantContactStiffness"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialCompliantContactStiffness;
    /// \brief "physxMaterial:dampingCombineMode"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialDampingCombineMode;
    /// \brief "physxMaterial:frictionCombineMode"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialFrictionCombineMode;
    /// \brief "physxMaterial:restitutionCombineMode"
    /// 
    /// UsdPhysXMaterialAPI
    const TfToken physxMaterialRestitutionCombineMode;
    /// \brief "physxMimicJoint"
    /// 
    /// Property namespace prefix for the UsdPhysXMimicJointAPI schema.
    const TfToken physxMimicJoint;
    /// \brief "physxMimicJoint:__INSTANCE_NAME__:gearing"
    /// 
    /// UsdPhysXMimicJointAPI
    const TfToken physxMimicJoint_MultipleApplyTemplate_Gearing;
    /// \brief "physxMimicJoint:__INSTANCE_NAME__:offset"
    /// 
    /// UsdPhysXMimicJointAPI
    const TfToken physxMimicJoint_MultipleApplyTemplate_Offset;
    /// \brief "physxMimicJoint:__INSTANCE_NAME__:referenceJointAxis"
    /// 
    /// UsdPhysXMimicJointAPI
    const TfToken physxMimicJoint_MultipleApplyTemplate_ReferenceJointAxis;
    /// \brief "physxPhysicsDistanceJoint:springDamping"
    /// 
    /// UsdPhysXPhysicsDistanceJointAPI
    const TfToken physxPhysicsDistanceJointSpringDamping;
    /// \brief "physxPhysicsDistanceJoint:springEnabled"
    /// 
    /// UsdPhysXPhysicsDistanceJointAPI
    const TfToken physxPhysicsDistanceJointSpringEnabled;
    /// \brief "physxPhysicsDistanceJoint:springStiffness"
    /// 
    /// UsdPhysXPhysicsDistanceJointAPI
    const TfToken physxPhysicsDistanceJointSpringStiffness;
    /// \brief "physxResidualReporting:maxResidualPositionIteration"
    /// 
    /// UsdPhysXResidualReportingAPI
    const TfToken physxResidualReportingMaxResidualPositionIteration;
    /// \brief "physxResidualReporting:maxResidualVelocityIteration"
    /// 
    /// UsdPhysXResidualReportingAPI
    const TfToken physxResidualReportingMaxResidualVelocityIteration;
    /// \brief "physxResidualReporting:rmsResidualPositionIteration"
    /// 
    /// UsdPhysXResidualReportingAPI
    const TfToken physxResidualReportingRmsResidualPositionIteration;
    /// \brief "physxResidualReporting:rmsResidualVelocityIteration"
    /// 
    /// UsdPhysXResidualReportingAPI
    const TfToken physxResidualReportingRmsResidualVelocityIteration;
    /// \brief "physxRigidBody:angularDamping"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyAngularDamping;
    /// \brief "physxRigidBody:cfmScale"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyCfmScale;
    /// \brief "physxRigidBody:contactSlopCoefficient"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyContactSlopCoefficient;
    /// \brief "physxRigidBody:disableGravity"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyDisableGravity;
    /// \brief "physxRigidBody:enableCCD"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyEnableCCD;
    /// \brief "physxRigidBody:enableGyroscopicForces"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyEnableGyroscopicForces;
    /// \brief "physxRigidBody:enableSpeculativeCCD"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyEnableSpeculativeCCD;
    /// \brief "physxRigidBody:linearDamping"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyLinearDamping;
    /// \brief "physxRigidBody:lockedPosAxis"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyLockedPosAxis;
    /// \brief "physxRigidBody:lockedRotAxis"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyLockedRotAxis;
    /// \brief "physxRigidBody:maxAngularVelocity"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyMaxAngularVelocity;
    /// \brief "physxRigidBody:maxContactImpulse"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyMaxContactImpulse;
    /// \brief "physxRigidBody:maxDepenetrationVelocity"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyMaxDepenetrationVelocity;
    /// \brief "physxRigidBody:maxLinearVelocity"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyMaxLinearVelocity;
    /// \brief "physxRigidBody:retainAccelerations"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyRetainAccelerations;
    /// \brief "physxRigidBody:sleepThreshold"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodySleepThreshold;
    /// \brief "physxRigidBody:solveContact"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodySolveContact;
    /// \brief "physxRigidBody:solverPositionIterationCount"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodySolverPositionIterationCount;
    /// \brief "physxRigidBody:solverVelocityIterationCount"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodySolverVelocityIterationCount;
    /// \brief "physxRigidBody:stabilizationThreshold"
    /// 
    /// UsdPhysXRigidBodyAPI
    const TfToken physxRigidBodyStabilizationThreshold;
    /// \brief "physxScene:bounceThreshold"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneBounceThreshold;
    /// \brief "physxScene:broadphaseType"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneBroadphaseType;
    /// \brief "physxScene:collisionSystem"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneCollisionSystem;
    /// \brief "physxScene:enableCCD"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableCCD;
    /// \brief "physxScene:enableEnhancedDeterminism"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableEnhancedDeterminism;
    /// \brief "physxScene:enableExternalForcesEveryIteration"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableExternalForcesEveryIteration;
    /// \brief "physxScene:enableGPUDynamics"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableGPUDynamics;
    /// \brief "physxScene:enableResidualReporting"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableResidualReporting;
    /// \brief "physxScene:enableSceneQuerySupport"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableSceneQuerySupport;
    /// \brief "physxScene:enableStabilization"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneEnableStabilization;
    /// \brief "physxScene:frictionCorrelationDistance"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneFrictionCorrelationDistance;
    /// \brief "physxScene:frictionOffsetThreshold"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneFrictionOffsetThreshold;
    /// \brief "physxScene:frictionType"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneFrictionType;
    /// \brief "physxScene:gpuCollisionStackSize"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuCollisionStackSize;
    /// \brief "physxScene:gpuFoundLostAggregatePairsCapacity"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuFoundLostAggregatePairsCapacity;
    /// \brief "physxScene:gpuFoundLostPairsCapacity"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuFoundLostPairsCapacity;
    /// \brief "physxScene:gpuHeapCapacity"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuHeapCapacity;
    /// \brief "physxScene:gpuMaxDeformableSurfaceContacts"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxDeformableSurfaceContacts;
    /// \brief "physxScene:gpuMaxHairContacts"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxHairContacts;
    /// \brief "physxScene:gpuMaxNumPartitions"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxNumPartitions;
    /// \brief "physxScene:gpuMaxParticleContacts"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxParticleContacts;
    /// \brief "physxScene:gpuMaxRigidContactCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxRigidContactCount;
    /// \brief "physxScene:gpuMaxRigidPatchCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxRigidPatchCount;
    /// \brief "physxScene:gpuMaxSoftBodyContacts"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuMaxSoftBodyContacts;
    /// \brief "physxScene:gpuTempBufferCapacity"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuTempBufferCapacity;
    /// \brief "physxScene:gpuTotalAggregatePairsCapacity"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneGpuTotalAggregatePairsCapacity;
    /// \brief "physxScene:invertCollisionGroupFilter"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneInvertCollisionGroupFilter;
    /// \brief "physxScene:maxBiasCoefficient"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneMaxBiasCoefficient;
    /// \brief "physxScene:maxPositionIterationCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneMaxPositionIterationCount;
    /// \brief "physxScene:maxVelocityIterationCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneMaxVelocityIterationCount;
    /// \brief "physxScene:minPositionIterationCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneMinPositionIterationCount;
    /// \brief "physxScene:minVelocityIterationCount"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneMinVelocityIterationCount;
    /// \brief "physxSceneQuasistatic:enableQuasistatic"
    /// 
    /// UsdPhysXSceneQuasistaticAPI
    const TfToken physxSceneQuasistaticEnableQuasistatic;
    /// \brief "physxScene:reportKinematicKinematicPairs"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneReportKinematicKinematicPairs;
    /// \brief "physxScene:reportKinematicStaticPairs"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneReportKinematicStaticPairs;
    /// \brief "physxScene:solverType"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneSolverType;
    /// \brief "physxScene:timeStepsPerSecond"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneTimeStepsPerSecond;
    /// \brief "physxScene:updateType"
    /// 
    /// UsdPhysXSceneAPI
    const TfToken physxSceneUpdateType;
    /// \brief "physxSDFMeshCollision:sdfBitsPerSubgridPixel"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfBitsPerSubgridPixel;
    /// \brief "physxSDFMeshCollision:sdfEnableRemeshing"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfEnableRemeshing;
    /// \brief "physxSDFMeshCollision:sdfMargin"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfMargin;
    /// \brief "physxSDFMeshCollision:sdfNarrowBandThickness"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfNarrowBandThickness;
    /// \brief "physxSDFMeshCollision:sdfResolution"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfResolution;
    /// \brief "physxSDFMeshCollision:sdfSubgridResolution"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfSubgridResolution;
    /// \brief "physxSDFMeshCollision:sdfTriangleCountReductionFactor"
    /// 
    /// UsdPhysXSDFMeshCollisionAPI
    const TfToken physxSDFMeshCollisionSdfTriangleCountReductionFactor;
    /// \brief "physxSphereFillCollision:fillMode"
    /// 
    /// UsdPhysXSphereFillCollisionAPI
    const TfToken physxSphereFillCollisionFillMode;
    /// \brief "physxSphereFillCollision:maxSpheres"
    /// 
    /// UsdPhysXSphereFillCollisionAPI
    const TfToken physxSphereFillCollisionMaxSpheres;
    /// \brief "physxSphereFillCollision:seedCount"
    /// 
    /// UsdPhysXSphereFillCollisionAPI
    const TfToken physxSphereFillCollisionSeedCount;
    /// \brief "physxSphereFillCollision:voxelResolution"
    /// 
    /// UsdPhysXSphereFillCollisionAPI
    const TfToken physxSphereFillCollisionVoxelResolution;
    /// \brief "physxSurfaceVelocity:surfaceAngularVelocity"
    /// 
    /// UsdPhysXSurfaceVelocityAPI
    const TfToken physxSurfaceVelocitySurfaceAngularVelocity;
    /// \brief "physxSurfaceVelocity:surfaceVelocity"
    /// 
    /// UsdPhysXSurfaceVelocityAPI
    const TfToken physxSurfaceVelocitySurfaceVelocity;
    /// \brief "physxSurfaceVelocity:surfaceVelocityEnabled"
    /// 
    /// UsdPhysXSurfaceVelocityAPI
    const TfToken physxSurfaceVelocitySurfaceVelocityEnabled;
    /// \brief "physxSurfaceVelocity:surfaceVelocityLocalSpace"
    /// 
    /// UsdPhysXSurfaceVelocityAPI
    const TfToken physxSurfaceVelocitySurfaceVelocityLocalSpace;
    /// \brief "preventClimbing"
    /// 
    /// Fallback value for UsdPhysXCharacterControllerAPI::GetNonWalkableModeAttr()
    const TfToken preventClimbing;
    /// \brief "preventClimbingForceSliding"
    /// 
    /// Possible value for UsdPhysXCharacterControllerAPI::GetNonWalkableModeAttr()
    const TfToken preventClimbingForceSliding;
    /// \brief "prismatic"
    /// 
    /// UsdPhysXPhysicsRackAndPinionJoint
    const TfToken prismatic;
    /// \brief "raycast"
    /// 
    /// Possible value for UsdPhysXSphereFillCollisionAPI::GetFillModeAttr()
    const TfToken raycast;
    /// \brief "rotX"
    /// 
    /// Fallback value for UsdPhysXMimicJointAPI::GetReferenceJointAxisAttr()
    const TfToken rotX;
    /// \brief "rotY"
    /// 
    /// Possible value for UsdPhysXMimicJointAPI::GetReferenceJointAxisAttr()
    const TfToken rotY;
    /// \brief "rotZ"
    /// 
    /// Possible value for UsdPhysXMimicJointAPI::GetReferenceJointAxisAttr()
    const TfToken rotZ;
    /// \brief "SAP"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetBroadphaseTypeAttr()
    const TfToken SAP;
    /// \brief "SAT"
    /// 
    /// Possible value for UsdPhysXSceneAPI::GetCollisionSystemAttr()
    const TfToken SAT;
    /// \brief "surface"
    /// 
    /// Possible value for UsdPhysXSphereFillCollisionAPI::GetFillModeAttr()
    const TfToken surface;
    /// \brief "Synchronous"
    /// 
    /// Fallback value for UsdPhysXSceneAPI::GetUpdateTypeAttr()
    const TfToken Synchronous;
    /// \brief "TGS"
    /// 
    /// Fallback value for UsdPhysXSceneAPI::GetSolverTypeAttr()
    const TfToken TGS;
    /// \brief "X"
    /// 
    /// Possible value for UsdPhysXCharacterControllerAPI::GetUpAxisAttr()
    const TfToken X;
    /// \brief "Y"
    /// 
    /// Possible value for UsdPhysXCharacterControllerAPI::GetUpAxisAttr()
    const TfToken Y;
    /// \brief "Z"
    /// 
    /// Fallback value for UsdPhysXCharacterControllerAPI::GetUpAxisAttr()
    const TfToken Z;
    /// \brief "PhysxSchemaJointStateAPI"
    /// 
    /// Schema identifer and family for UsdPhysXJointStateAPI
    const TfToken PhysxSchemaJointStateAPI;
    /// \brief "PhysxSchemaPhysxArticulationAPI"
    /// 
    /// Schema identifer and family for UsdPhysXArticulationAPI
    const TfToken PhysxSchemaPhysxArticulationAPI;
    /// \brief "PhysxSchemaPhysxCameraAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCameraAPI
    const TfToken PhysxSchemaPhysxCameraAPI;
    /// \brief "PhysxSchemaPhysxCameraDroneAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCameraDroneAPI
    const TfToken PhysxSchemaPhysxCameraDroneAPI;
    /// \brief "PhysxSchemaPhysxCameraFollowAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCameraFollowAPI
    const TfToken PhysxSchemaPhysxCameraFollowAPI;
    /// \brief "PhysxSchemaPhysxCameraFollowLookAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCameraFollowLookAPI
    const TfToken PhysxSchemaPhysxCameraFollowLookAPI;
    /// \brief "PhysxSchemaPhysxCameraFollowVelocityAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCameraFollowVelocityAPI
    const TfToken PhysxSchemaPhysxCameraFollowVelocityAPI;
    /// \brief "PhysxSchemaPhysxCharacterControllerAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCharacterControllerAPI
    const TfToken PhysxSchemaPhysxCharacterControllerAPI;
    /// \brief "PhysxSchemaPhysxCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCollisionAPI
    const TfToken PhysxSchemaPhysxCollisionAPI;
    /// \brief "PhysxSchemaPhysxContactReportAPI"
    /// 
    /// Schema identifer and family for UsdPhysXContactReportAPI
    const TfToken PhysxSchemaPhysxContactReportAPI;
    /// \brief "PhysxSchemaPhysxConvexDecompositionCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXConvexDecompositionCollisionAPI
    const TfToken PhysxSchemaPhysxConvexDecompositionCollisionAPI;
    /// \brief "PhysxSchemaPhysxConvexHullCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXConvexHullCollisionAPI
    const TfToken PhysxSchemaPhysxConvexHullCollisionAPI;
    /// \brief "PhysxSchemaPhysxCookedDataAPI"
    /// 
    /// Schema identifer and family for UsdPhysXCookedDataAPI
    const TfToken PhysxSchemaPhysxCookedDataAPI;
    /// \brief "PhysxSchemaPhysxForceAPI"
    /// 
    /// Schema identifer and family for UsdPhysXForceAPI
    const TfToken PhysxSchemaPhysxForceAPI;
    /// \brief "PhysxSchemaPhysxIsosurfaceAPI"
    /// 
    /// Schema identifer and family for UsdPhysXIsosurfaceAPI
    const TfToken PhysxSchemaPhysxIsosurfaceAPI;
    /// \brief "PhysxSchemaPhysxJointAPI"
    /// 
    /// Schema identifer and family for UsdPhysXJointAPI
    const TfToken PhysxSchemaPhysxJointAPI;
    /// \brief "PhysxSchemaPhysxMaterialAPI"
    /// 
    /// Schema identifer and family for UsdPhysXMaterialAPI
    const TfToken PhysxSchemaPhysxMaterialAPI;
    /// \brief "PhysxSchemaPhysxMeshMergeCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXMeshMergeCollisionAPI
    const TfToken PhysxSchemaPhysxMeshMergeCollisionAPI;
    /// \brief "PhysxSchemaPhysxMimicJointAPI"
    /// 
    /// Schema identifer and family for UsdPhysXMimicJointAPI
    const TfToken PhysxSchemaPhysxMimicJointAPI;
    /// \brief "PhysxSchemaPhysxPhysicsDistanceJointAPI"
    /// 
    /// Schema identifer and family for UsdPhysXPhysicsDistanceJointAPI
    const TfToken PhysxSchemaPhysxPhysicsDistanceJointAPI;
    /// \brief "PhysxSchemaPhysxPhysicsGearJoint"
    /// 
    /// Schema identifer and family for UsdPhysXPhysicsGearJoint
    const TfToken PhysxSchemaPhysxPhysicsGearJoint;
    /// \brief "PhysxSchemaPhysxPhysicsInstancer"
    /// 
    /// Schema identifer and family for UsdPhysXPhysicsInstancer
    const TfToken PhysxSchemaPhysxPhysicsInstancer;
    /// \brief "PhysxSchemaPhysxPhysicsJointInstancer"
    /// 
    /// Schema identifer and family for UsdPhysXPhysicsJointInstancer
    const TfToken PhysxSchemaPhysxPhysicsJointInstancer;
    /// \brief "PhysxSchemaPhysxPhysicsRackAndPinionJoint"
    /// 
    /// Schema identifer and family for UsdPhysXPhysicsRackAndPinionJoint
    const TfToken PhysxSchemaPhysxPhysicsRackAndPinionJoint;
    /// \brief "PhysxSchemaPhysxResidualReportingAPI"
    /// 
    /// Schema identifer and family for UsdPhysXResidualReportingAPI
    const TfToken PhysxSchemaPhysxResidualReportingAPI;
    /// \brief "PhysxSchemaPhysxRigidBodyAPI"
    /// 
    /// Schema identifer and family for UsdPhysXRigidBodyAPI
    const TfToken PhysxSchemaPhysxRigidBodyAPI;
    /// \brief "PhysxSchemaPhysxSceneAPI"
    /// 
    /// Schema identifer and family for UsdPhysXSceneAPI
    const TfToken PhysxSchemaPhysxSceneAPI;
    /// \brief "PhysxSchemaPhysxSceneQuasistaticAPI"
    /// 
    /// Schema identifer and family for UsdPhysXSceneQuasistaticAPI
    const TfToken PhysxSchemaPhysxSceneQuasistaticAPI;
    /// \brief "PhysxSchemaPhysxSDFMeshCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXSDFMeshCollisionAPI
    const TfToken PhysxSchemaPhysxSDFMeshCollisionAPI;
    /// \brief "PhysxSchemaPhysxSphereFillCollisionAPI"
    /// 
    /// Schema identifer and family for UsdPhysXSphereFillCollisionAPI
    const TfToken PhysxSchemaPhysxSphereFillCollisionAPI;
    /// \brief "PhysxSchemaPhysxSurfaceVelocityAPI"
    /// 
    /// Schema identifer and family for UsdPhysXSurfaceVelocityAPI
    const TfToken PhysxSchemaPhysxSurfaceVelocityAPI;
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

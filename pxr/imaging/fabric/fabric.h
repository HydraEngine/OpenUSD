//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usd/sdf/pathTable.h>

PXR_NAMESPACE_OPEN_SCOPE

class FabricArticulationRootSchema;
class FabricCollisionGroupSchema;
class FabricCollisionSchema;
class FabricDistanceJointSchema;
class FabricDriveSchema;
class FabricFilteredPairsSchema;
class FabricFixedJointSchema;
class FabricJointSchema;
class FabricLimitSchema;
class FabricMassSchema;
class FabricMaterialSchema;
class FabricMeshCollisionSchema;
class FabricPhysxArticulationSchema;
class FabricPhysxCameraDroneSchema;
class FabricPhysxCameraFollowLookSchema;
class FabricPhysxCameraFollowSchema;
class FabricPhysxCameraFollowVelocitySchema;
class FabricPhysxCameraSchema;
class FabricPhysxCharacterControllerSchema;
class FabricPhysxCollisionSchema;
class FabricPhysxContactReportSchema;
class FabricPhysxConvexDecompositionCollisionSchema;
class FabricPhysxConvexHullCollisionSchema;
class FabricPhysxCookedDataSchema;
class FabricPhysxForceSchema;
class FabricPhysxIsosurfaceSchema;
class FabricPhysxJointSchema;
class FabricPhysxJointStateSchema;
class FabricPhysxMaterialSchema;
class FabricPhysxMeshMergeCollisionSchema;
class FabricPhysxMimicJointSchema;
class FabricPhysxPhysicsDistanceJointSchema;
class FabricPhysxPhysicsGearJointSchema;
class FabricPhysxPhysicsInstancerSchema;
class FabricPhysxPhysicsJointInstancerSchema;
class FabricPhysxPhysicsRackAndPinionJointSchema;
class FabricPhysxResidualReportingSchema;
class FabricPhysxRigidBodySchema;
class FabricPhysxSceneQuasistaticSchema;
class FabricPhysxSceneSchema;
class FabricPhysxSDFMeshCollisionSchema;
class FabricPhysxSphereFillCollisionSchema;
class FabricPhysxSurfaceVelocitySchema;
class FabricPhysxTriangleMeshCollisionSchema;
class FabricPhysxTriangleMeshSimplificationCollisionSchema;
class FabricPhysxTriggerSchema;
class FabricPhysxTriggerStateSchema;
class FabricPhysxVehicleAckermannSteeringSchema;
class FabricPhysxVehicleAutoGearBoxSchema;
class FabricPhysxVehicleBrakesSchema;
class FabricPhysxVehicleClutchSchema;
class FabricPhysxVehicleContextSchema;
class FabricPhysxVehicleControllerSchema;
class FabricPhysxVehicleDriveBasicSchema;
class FabricPhysxVehicleDriveStandardSchema;
class FabricPhysxVehicleEngineSchema;
class FabricPhysxVehicleGearsSchema;
class FabricPhysxVehicleMultiWheelDifferentialSchema;
class FabricPhysxVehicleNonlinearCommandResponseSchema;
class FabricPhysxVehicleSchema;
class FabricPhysxVehicleSteeringSchema;
class FabricPhysxVehicleSuspensionComplianceSchema;
class FabricPhysxVehicleSuspensionSchema;
class FabricPhysxVehicleTankControllerSchema;
class FabricPhysxVehicleTankDifferentialSchema;
class FabricPhysxVehicleTireFrictionTableSchema;
class FabricPhysxVehicleTireSchema;
class FabricPhysxVehicleWheelAttachmentSchema;
class FabricPhysxVehicleWheelControllerSchema;
class FabricPhysxVehicleWheelSchema;
class FabricPrismaticJointSchema;
class FabricRevoluteJointSchema;
class FabricRigidBodySchema;
class FabricSceneSchema;
class FabricSphericalJointSchema;

class Fabric {
public:
    void PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry& entry);

    void PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry& entry);

    void PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry& entry);

private:
    std::map<SdfPath, FabricArticulationRootSchema> _articulationRoots;
    std::map<SdfPath, FabricCollisionGroupSchema> _collisionGroups;
    std::map<SdfPath, FabricCollisionSchema> _collisions;
    std::map<SdfPath, FabricDistanceJointSchema> _distanceJoints;
    std::map<SdfPath, FabricDriveSchema> _drives;
    std::map<SdfPath, FabricFilteredPairsSchema> _filteredPairs;
    std::map<SdfPath, FabricFixedJointSchema> _fixedJoints;
    std::map<SdfPath, FabricJointSchema> _joints;
    std::map<SdfPath, FabricLimitSchema> _limits;
    std::map<SdfPath, FabricMassSchema> _masses;
    std::map<SdfPath, FabricMaterialSchema> _materials;
    std::map<SdfPath, FabricMeshCollisionSchema> _meshCollisions;
    std::map<SdfPath, FabricPhysxArticulationSchema> _physxArticulations;
    std::map<SdfPath, FabricPhysxCameraDroneSchema> _physxCameraDrones;
    std::map<SdfPath, FabricPhysxCameraFollowLookSchema> _physxCameraFollowLooks;
    std::map<SdfPath, FabricPhysxCameraFollowSchema> _physxCameraFollows;
    std::map<SdfPath, FabricPhysxCameraFollowVelocitySchema> _physxCameraFollowVelocities;
    std::map<SdfPath, FabricPhysxCameraSchema> _physxCameras;
    std::map<SdfPath, FabricPhysxCharacterControllerSchema> _physxCharacterControllers;
    std::map<SdfPath, FabricPhysxCollisionSchema> _physxCollisions;
    std::map<SdfPath, FabricPhysxContactReportSchema> _physxContactReports;
    std::map<SdfPath, FabricPhysxConvexDecompositionCollisionSchema> _physxConvexDecompositionCollisions;
    std::map<SdfPath, FabricPhysxConvexHullCollisionSchema> _physxConvexHullCollisions;
    std::map<SdfPath, FabricPhysxCookedDataSchema> _physxCookedDatas;
    std::map<SdfPath, FabricPhysxForceSchema> _physxForces;
    std::map<SdfPath, FabricPhysxIsosurfaceSchema> _physxIsosurfaces;
    std::map<SdfPath, FabricPhysxJointSchema> _physxJoints;
    std::map<SdfPath, FabricPhysxJointStateSchema> _physxJointStates;
    std::map<SdfPath, FabricPhysxMaterialSchema> _physxMaterials;
    std::map<SdfPath, FabricPhysxMeshMergeCollisionSchema> _physxMeshMergeCollisions;
    std::map<SdfPath, FabricPhysxMimicJointSchema> _physxMimicJoints;
    std::map<SdfPath, FabricPhysxPhysicsDistanceJointSchema> _physxPhysicsDistanceJoints;
    std::map<SdfPath, FabricPhysxPhysicsGearJointSchema> _physxPhysicsGearJoints;
    std::map<SdfPath, FabricPhysxPhysicsInstancerSchema> _physxPhysicsInstancers;
    std::map<SdfPath, FabricPhysxPhysicsJointInstancerSchema> _physxPhysicsJointInstancers;
    std::map<SdfPath, FabricPhysxPhysicsRackAndPinionJointSchema> _physxPhysicsRackAndPinionJoints;
    std::map<SdfPath, FabricPhysxResidualReportingSchema> _physxResidualReportings;
    std::map<SdfPath, FabricPhysxRigidBodySchema> _physxRigidBodies;
    std::map<SdfPath, FabricPhysxSceneQuasistaticSchema> _physxSceneQuasistatics;
    std::map<SdfPath, FabricPhysxSceneSchema> _physxScenes;
    std::map<SdfPath, FabricPhysxSDFMeshCollisionSchema> _physxSDFMeshCollisions;
    std::map<SdfPath, FabricPhysxSphereFillCollisionSchema> _physxSphereFillCollisions;
    std::map<SdfPath, FabricPhysxSurfaceVelocitySchema> _physxSurfaceVelocities;
    std::map<SdfPath, FabricPhysxTriangleMeshCollisionSchema> _physxTriangleMeshCollisions;
    std::map<SdfPath, FabricPhysxTriangleMeshSimplificationCollisionSchema> _physxTriangleMeshSimplificationCollisions;
    std::map<SdfPath, FabricPhysxTriggerSchema> _physxTriggers;
    std::map<SdfPath, FabricPhysxTriggerStateSchema> _physxTriggerStates;
    std::map<SdfPath, FabricPhysxVehicleAckermannSteeringSchema> _physxVehicleAckermannSteerings;
    std::map<SdfPath, FabricPhysxVehicleAutoGearBoxSchema> _physxVehicleAutoGearBoxs;
    std::map<SdfPath, FabricPhysxVehicleBrakesSchema> _physxVehicleBrakes;
    std::map<SdfPath, FabricPhysxVehicleClutchSchema> _physxVehicleClutches;
    std::map<SdfPath, FabricPhysxVehicleContextSchema> _physxVehicleContexts;
    std::map<SdfPath, FabricPhysxVehicleControllerSchema> _physxVehicleControllers;
    std::map<SdfPath, FabricPhysxVehicleDriveBasicSchema> _physxVehicleDriveBasics;
    std::map<SdfPath, FabricPhysxVehicleDriveStandardSchema> _physxVehicleDriveStandards;
    std::map<SdfPath, FabricPhysxVehicleEngineSchema> _physxVehicleEngines;
    std::map<SdfPath, FabricPhysxVehicleGearsSchema> _physxVehicleGears;
    std::map<SdfPath, FabricPhysxVehicleMultiWheelDifferentialSchema> _physxVehicleMultiWheelDifferentials;
    std::map<SdfPath, FabricPhysxVehicleNonlinearCommandResponseSchema> _physxVehicleNonlinearCommandResponseSchemas;
    std::map<SdfPath, FabricPhysxVehicleSchema> _physxVehicles;
    std::map<SdfPath, FabricPhysxVehicleSteeringSchema> _physxVehicleSteerings;
    std::map<SdfPath, FabricPhysxVehicleSuspensionComplianceSchema> _physxVehicleSuspensionCompliances;
    std::map<SdfPath, FabricPhysxVehicleSuspensionSchema> _physxVehicleSuspensions;
    std::map<SdfPath, FabricPhysxVehicleTankControllerSchema> _physxVehicleTankControllers;
    std::map<SdfPath, FabricPhysxVehicleTankDifferentialSchema> _physxVehicleTankDifferentials;
    std::map<SdfPath, FabricPhysxVehicleTireFrictionTableSchema> _physxVehicleTireFrictionTables;
    std::map<SdfPath, FabricPhysxVehicleTireSchema> _physxVehicleTires;
    std::map<SdfPath, FabricPhysxVehicleWheelAttachmentSchema> _physxVehicleWheelAttachments;
    std::map<SdfPath, FabricPhysxVehicleWheelControllerSchema> _physxVehicleWheelControllers;
    std::map<SdfPath, FabricPhysxVehicleWheelSchema> _physxVehicleWheels;
    std::map<SdfPath, FabricPrismaticJointSchema> _prismaticJoints;
    std::map<SdfPath, FabricRevoluteJointSchema> _revoluteJoints;
    std::map<SdfPath, FabricRigidBodySchema> _rigidBodies;
    std::map<SdfPath, FabricSceneSchema> _scenes;
    std::map<SdfPath, FabricSphericalJointSchema> _sphericalJoints;
};

PXR_NAMESPACE_CLOSE_SCOPE
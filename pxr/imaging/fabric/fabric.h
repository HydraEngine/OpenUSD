//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usd/sdf/pathTable.h>
#include <pxr/imaging/fabric/materialSchema.h>
#include <pxr/imaging/fabric/articulationRootSchema.h>
#include <pxr/imaging/fabric/collisionGroupSchema.h>
#include <pxr/imaging/fabric/collisionSchema.h>
#include <pxr/imaging/fabric/distanceJointSchema.h>
#include <pxr/imaging/fabric/driveSchema.h>
#include <pxr/imaging/fabric/filteredPairsSchema.h>
#include <pxr/imaging/fabric/fixedJointSchema.h>
#include <pxr/imaging/fabric/jointSchema.h>
#include <pxr/imaging/fabric/limitSchema.h>
#include <pxr/imaging/fabric/massSchema.h>
#include <pxr/imaging/fabric/materialSchema.h>
#include <pxr/imaging/fabric/meshCollisionSchema.h>
#include <pxr/imaging/fabric/physxArticulationSchema.h>
#include <pxr/imaging/fabric/physxCameraDroneSchema.h>
#include <pxr/imaging/fabric/physxCameraFollowLookSchema.h>
#include <pxr/imaging/fabric/physxCameraFollowSchema.h>
#include <pxr/imaging/fabric/physxCameraFollowVelocitySchema.h>
#include <pxr/imaging/fabric/physxCameraSchema.h>
#include <pxr/imaging/fabric/physxCharacterControllerSchema.h>
#include <pxr/imaging/fabric/physxCollisionSchema.h>
#include <pxr/imaging/fabric/physxContactReportSchema.h>
#include <pxr/imaging/fabric/physxConvexDecompositionCollisionSchema.h>
#include <pxr/imaging/fabric/physxConvexHullCollisionSchema.h>
#include <pxr/imaging/fabric/physxCookedDataSchema.h>
#include <pxr/imaging/fabric/physxForceSchema.h>
#include <pxr/imaging/fabric/physxIsosurfaceSchema.h>
#include <pxr/imaging/fabric/physxJointSchema.h>
#include <pxr/imaging/fabric/physxJointStateSchema.h>
#include <pxr/imaging/fabric/physxMaterialSchema.h>
#include <pxr/imaging/fabric/physxMeshMergeCollisionSchema.h>
#include <pxr/imaging/fabric/physxMimicJointSchema.h>
#include <pxr/imaging/fabric/physxPhysicsDistanceJointSchema.h>
#include <pxr/imaging/fabric/physxPhysicsGearJointSchema.h>
#include <pxr/imaging/fabric/physxPhysicsInstancerSchema.h>
#include <pxr/imaging/fabric/physxPhysicsJointInstancerSchema.h>
#include <pxr/imaging/fabric/physxPhysicsRackAndPinionJointSchema.h>
#include <pxr/imaging/fabric/physxResidualReportingSchema.h>
#include <pxr/imaging/fabric/physxRigidBodySchema.h>
#include <pxr/imaging/fabric/physxSceneQuasistaticSchema.h>
#include <pxr/imaging/fabric/physxSceneSchema.h>
#include <pxr/imaging/fabric/physxSDFMeshCollisionSchema.h>
#include <pxr/imaging/fabric/physxSphereFillCollisionSchema.h>
#include <pxr/imaging/fabric/physxSurfaceVelocitySchema.h>
#include <pxr/imaging/fabric/physxTriangleMeshCollisionSchema.h>
#include <pxr/imaging/fabric/physxTriangleMeshSimplificationCollisionSchema.h>
#include <pxr/imaging/fabric/physxTriggerSchema.h>
#include <pxr/imaging/fabric/physxTriggerStateSchema.h>
#include <pxr/imaging/fabric/physxVehicleAckermannSteeringSchema.h>
#include <pxr/imaging/fabric/physxVehicleAutoGearBoxSchema.h>
#include <pxr/imaging/fabric/physxVehicleBrakesSchema.h>
#include <pxr/imaging/fabric/physxVehicleClutchSchema.h>
#include <pxr/imaging/fabric/physxVehicleContextSchema.h>
#include <pxr/imaging/fabric/physxVehicleControllerSchema.h>
#include <pxr/imaging/fabric/physxVehicleDriveBasicSchema.h>
#include <pxr/imaging/fabric/physxVehicleDriveStandardSchema.h>
#include <pxr/imaging/fabric/physxVehicleEngineSchema.h>
#include <pxr/imaging/fabric/physxVehicleGearsSchema.h>
#include <pxr/imaging/fabric/physxVehicleMultiWheelDifferentialSchema.h>
#include <pxr/imaging/fabric/physxVehicleNonlinearCommandResponseSchema.h>
#include <pxr/imaging/fabric/physxVehicleSchema.h>
#include <pxr/imaging/fabric/physxVehicleSteeringSchema.h>
#include <pxr/imaging/fabric/physxVehicleSuspensionComplianceSchema.h>
#include <pxr/imaging/fabric/physxVehicleSuspensionSchema.h>
#include <pxr/imaging/fabric/physxVehicleTankControllerSchema.h>
#include <pxr/imaging/fabric/physxVehicleTankDifferentialSchema.h>
#include <pxr/imaging/fabric/physxVehicleTireFrictionTableSchema.h>
#include <pxr/imaging/fabric/physxVehicleTireSchema.h>
#include <pxr/imaging/fabric/physxVehicleWheelAttachmentSchema.h>
#include <pxr/imaging/fabric/physxVehicleWheelControllerSchema.h>
#include <pxr/imaging/fabric/physxVehicleWheelSchema.h>
#include <pxr/imaging/fabric/prismaticJointSchema.h>
#include <pxr/imaging/fabric/revoluteJointSchema.h>
#include <pxr/imaging/fabric/rigidBodySchema.h>
#include <pxr/imaging/fabric/sceneSchema.h>
#include <pxr/imaging/fabric/sphericalJointSchema.h>

#include <pxr/imaging/hd/xformSchema.h>
#include <pxr/imaging/hd/cubeSchema.h>
#include <pxr/imaging/hd/capsuleSchema.h>
#include <pxr/imaging/hd/sphereSchema.h>
#include <pxr/imaging/hd/coneSchema.h>
#include <pxr/imaging/hd/cylinderSchema.h>
#include <pxr/imaging/hd/planeSchema.h>
#include <pxr/imaging/hd/primvarsSchema.h>

PXR_NAMESPACE_OPEN_SCOPE

class Fabric {
public:
    void PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry& entry);

    void PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry& entry);

    void PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry& entry);

    HdSceneIndexObserver::DirtiedPrimEntries& dirtyEntries() { return _dirtyEntries; }



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

    std::map<SdfPath, HdCubeSchema> _cubes;
    std::map<SdfPath, HdCapsuleSchema> _capsules;
    std::map<SdfPath, HdSphereSchema> _spheres;
    std::map<SdfPath, HdConeSchema> _cones;
    std::map<SdfPath, HdCylinderSchema> _cylinders;
    std::map<SdfPath, HdPlaneSchema> _planes;
    std::map<SdfPath, HdPrimvarsSchema> _meshes;

    SdfPathTable<GfMatrix4d> _globalXforms;
    HdSceneIndexObserver::DirtiedPrimEntries _dirtyEntries;
};

PXR_NAMESPACE_CLOSE_SCOPE
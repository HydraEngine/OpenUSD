//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <pxr/imaging/hd/filteringSceneIndex.h>
#include <pxr/usd/sdf/pathTable.h>
#include <pxr/imaging/hd/articulationRootSchema.h>
#include <pxr/imaging/hd/collisionGroupSchema.h>
#include <pxr/imaging/hd/collisionSchema.h>
#include <pxr/imaging/hd/distanceJointSchema.h>
#include <pxr/imaging/hd/driveSchema.h>
#include <pxr/imaging/hd/filteredPairsSchema.h>
#include <pxr/imaging/hd/fixedJointSchema.h>
#include <pxr/imaging/hd/jointSchema.h>
#include <pxr/imaging/hd/limitSchema.h>
#include <pxr/imaging/hd/massSchema.h>
#include <pxr/imaging/hd/physicsMaterialSchema.h>
#include <pxr/imaging/hd/meshCollisionSchema.h>
#include <pxr/imaging/hd/physxArticulationSchema.h>
#include <pxr/imaging/hd/physxCameraDroneSchema.h>
#include <pxr/imaging/hd/physxCameraFollowLookSchema.h>
#include <pxr/imaging/hd/physxCameraFollowSchema.h>
#include <pxr/imaging/hd/physxCameraFollowVelocitySchema.h>
#include <pxr/imaging/hd/physxCameraSchema.h>
#include <pxr/imaging/hd/physxCharacterControllerSchema.h>
#include <pxr/imaging/hd/physxCollisionSchema.h>
#include <pxr/imaging/hd/physxContactReportSchema.h>
#include <pxr/imaging/hd/physxConvexDecompositionCollisionSchema.h>
#include <pxr/imaging/hd/physxConvexHullCollisionSchema.h>
#include <pxr/imaging/hd/physxCookedDataSchema.h>
#include <pxr/imaging/hd/physxForceSchema.h>
#include <pxr/imaging/hd/physxIsosurfaceSchema.h>
#include <pxr/imaging/hd/physxJointSchema.h>
#include <pxr/imaging/hd/physxJointStateSchema.h>
#include <pxr/imaging/hd/physxMaterialSchema.h>
#include <pxr/imaging/hd/physxMeshMergeCollisionSchema.h>
#include <pxr/imaging/hd/physxMimicJointSchema.h>
#include <pxr/imaging/hd/physxPhysicsDistanceJointSchema.h>
#include <pxr/imaging/hd/physxPhysicsGearJointSchema.h>
#include <pxr/imaging/hd/physxPhysicsInstancerSchema.h>
#include <pxr/imaging/hd/physxPhysicsJointInstancerSchema.h>
#include <pxr/imaging/hd/physxPhysicsRackAndPinionJointSchema.h>
#include <pxr/imaging/hd/physxResidualReportingSchema.h>
#include <pxr/imaging/hd/physxRigidBodySchema.h>
#include <pxr/imaging/hd/physxSceneQuasistaticSchema.h>
#include <pxr/imaging/hd/physxSceneSchema.h>
#include <pxr/imaging/hd/physxSDFMeshCollisionSchema.h>
#include <pxr/imaging/hd/physxSphereFillCollisionSchema.h>
#include <pxr/imaging/hd/physxSurfaceVelocitySchema.h>
#include <pxr/imaging/hd/physxTriangleMeshCollisionSchema.h>
#include <pxr/imaging/hd/physxTriangleMeshSimplificationCollisionSchema.h>
#include <pxr/imaging/hd/physxTriggerSchema.h>
#include <pxr/imaging/hd/physxTriggerStateSchema.h>
#include <pxr/imaging/hd/physxVehicleAckermannSteeringSchema.h>
#include <pxr/imaging/hd/physxVehicleAutoGearBoxSchema.h>
#include <pxr/imaging/hd/physxVehicleBrakesSchema.h>
#include <pxr/imaging/hd/physxVehicleClutchSchema.h>
#include <pxr/imaging/hd/physxVehicleContextSchema.h>
#include <pxr/imaging/hd/physxVehicleControllerSchema.h>
#include <pxr/imaging/hd/physxVehicleDriveBasicSchema.h>
#include <pxr/imaging/hd/physxVehicleDriveStandardSchema.h>
#include <pxr/imaging/hd/physxVehicleEngineSchema.h>
#include <pxr/imaging/hd/physxVehicleGearsSchema.h>
#include <pxr/imaging/hd/physxVehicleMultiWheelDifferentialSchema.h>
#include <pxr/imaging/hd/physxVehicleNonlinearCommandResponseSchema.h>
#include <pxr/imaging/hd/physxVehicleSchema.h>
#include <pxr/imaging/hd/physxVehicleSteeringSchema.h>
#include <pxr/imaging/hd/physxVehicleSuspensionComplianceSchema.h>
#include <pxr/imaging/hd/physxVehicleSuspensionSchema.h>
#include <pxr/imaging/hd/physxVehicleTankControllerSchema.h>
#include <pxr/imaging/hd/physxVehicleTankDifferentialSchema.h>
#include <pxr/imaging/hd/physxVehicleTireFrictionTableSchema.h>
#include <pxr/imaging/hd/physxVehicleTireSchema.h>
#include <pxr/imaging/hd/physxVehicleWheelAttachmentSchema.h>
#include <pxr/imaging/hd/physxVehicleWheelControllerSchema.h>
#include <pxr/imaging/hd/physxVehicleWheelSchema.h>
#include <pxr/imaging/hd/prismaticJointSchema.h>
#include <pxr/imaging/hd/revoluteJointSchema.h>
#include <pxr/imaging/hd/rigidBodySchema.h>
#include <pxr/imaging/hd/sceneSchema.h>
#include <pxr/imaging/hd/sphericalJointSchema.h>

#include <pxr/imaging/hd/xformSchema.h>
#include <pxr/imaging/hd/cubeSchema.h>
#include <pxr/imaging/hd/capsuleSchema.h>
#include <pxr/imaging/hd/sphereSchema.h>
#include <pxr/imaging/hd/coneSchema.h>
#include <pxr/imaging/hd/cylinderSchema.h>
#include <pxr/imaging/hd/planeSchema.h>
#include <pxr/imaging/hd/primvarsSchema.h>
#include <pxr/imaging/hd/directMaterialBindingsSchema.h>

PXR_NAMESPACE_OPEN_SCOPE

class Fabric {
public:
    void PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry& entry);

    void PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry& entry);

    void PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry& entry);

    HdSceneIndexObserver::DirtiedPrimEntries& dirtyEntries() { return _dirtyEntries; }

    std::optional<GfMatrix4d> findXform(const SdfPath& path);

    std::map<SdfPath, HdArticulationRootSchema> _articulationRoots;
    std::map<SdfPath, HdCollisionGroupSchema> _collisionGroups;
    std::map<SdfPath, HdCollisionSchema> _collisions;
    std::map<SdfPath, HdDistanceJointSchema> _distanceJoints;
    std::map<SdfPath, HdDriveSchema> _drives;
    std::map<SdfPath, HdFilteredPairsSchema> _filteredPairs;
    std::map<SdfPath, HdFixedJointSchema> _fixedJoints;
    std::map<SdfPath, HdJointSchema> _joints;
    std::map<SdfPath, HdLimitSchema> _limits;
    std::map<SdfPath, HdMassSchema> _masses;
    std::map<SdfPath, HdPhysicsMaterialSchema> _materials;
    std::map<SdfPath, HdMeshCollisionSchema> _meshCollisions;
    std::map<SdfPath, HdPhysxArticulationSchema> _physxArticulations;
    std::map<SdfPath, HdPhysxCameraDroneSchema> _physxCameraDrones;
    std::map<SdfPath, HdPhysxCameraFollowLookSchema> _physxCameraFollowLooks;
    std::map<SdfPath, HdPhysxCameraFollowSchema> _physxCameraFollows;
    std::map<SdfPath, HdPhysxCameraFollowVelocitySchema> _physxCameraFollowVelocities;
    std::map<SdfPath, HdPhysxCameraSchema> _physxCameras;
    std::map<SdfPath, HdPhysxCharacterControllerSchema> _physxCharacterControllers;
    std::map<SdfPath, HdPhysxCollisionSchema> _physxCollisions;
    std::map<SdfPath, HdPhysxContactReportSchema> _physxContactReports;
    std::map<SdfPath, HdPhysxConvexDecompositionCollisionSchema> _physxConvexDecompositionCollisions;
    std::map<SdfPath, HdPhysxConvexHullCollisionSchema> _physxConvexHullCollisions;
    std::map<SdfPath, HdPhysxCookedDataSchema> _physxCookedDatas;
    std::map<SdfPath, HdPhysxForceSchema> _physxForces;
    std::map<SdfPath, HdPhysxIsosurfaceSchema> _physxIsosurfaces;
    std::map<SdfPath, HdPhysxJointSchema> _physxJoints;
    std::map<SdfPath, HdPhysxJointStateSchema> _physxJointStates;
    std::map<SdfPath, HdPhysxMaterialSchema> _physxMaterials;
    std::map<SdfPath, HdPhysxMeshMergeCollisionSchema> _physxMeshMergeCollisions;
    std::map<SdfPath, HdPhysxMimicJointSchema> _physxMimicJoints;
    std::map<SdfPath, HdPhysxPhysicsDistanceJointSchema> _physxPhysicsDistanceJoints;
    std::map<SdfPath, HdPhysxPhysicsGearJointSchema> _physxPhysicsGearJoints;
    std::map<SdfPath, HdPhysxPhysicsInstancerSchema> _physxPhysicsInstancers;
    std::map<SdfPath, HdPhysxPhysicsJointInstancerSchema> _physxPhysicsJointInstancers;
    std::map<SdfPath, HdPhysxPhysicsRackAndPinionJointSchema> _physxPhysicsRackAndPinionJoints;
    std::map<SdfPath, HdPhysxResidualReportingSchema> _physxResidualReportings;
    std::map<SdfPath, HdPhysxRigidBodySchema> _physxRigidBodies;
    std::map<SdfPath, HdPhysxSceneQuasistaticSchema> _physxSceneQuasistatics;
    std::map<SdfPath, HdPhysxSceneSchema> _physxScenes;
    std::map<SdfPath, HdPhysxSDFMeshCollisionSchema> _physxSDFMeshCollisions;
    std::map<SdfPath, HdPhysxSphereFillCollisionSchema> _physxSphereFillCollisions;
    std::map<SdfPath, HdPhysxSurfaceVelocitySchema> _physxSurfaceVelocities;
    std::map<SdfPath, HdPhysxTriangleMeshCollisionSchema> _physxTriangleMeshCollisions;
    std::map<SdfPath, HdPhysxTriangleMeshSimplificationCollisionSchema> _physxTriangleMeshSimplificationCollisions;
    std::map<SdfPath, HdPhysxTriggerSchema> _physxTriggers;
    std::map<SdfPath, HdPhysxTriggerStateSchema> _physxTriggerStates;
    std::map<SdfPath, HdPhysxVehicleAckermannSteeringSchema> _physxVehicleAckermannSteerings;
    std::map<SdfPath, HdPhysxVehicleAutoGearBoxSchema> _physxVehicleAutoGearBoxs;
    std::map<SdfPath, HdPhysxVehicleBrakesSchema> _physxVehicleBrakes;
    std::map<SdfPath, HdPhysxVehicleClutchSchema> _physxVehicleClutches;
    std::map<SdfPath, HdPhysxVehicleContextSchema> _physxVehicleContexts;
    std::map<SdfPath, HdPhysxVehicleControllerSchema> _physxVehicleControllers;
    std::map<SdfPath, HdPhysxVehicleDriveBasicSchema> _physxVehicleDriveBasics;
    std::map<SdfPath, HdPhysxVehicleDriveStandardSchema> _physxVehicleDriveStandards;
    std::map<SdfPath, HdPhysxVehicleEngineSchema> _physxVehicleEngines;
    std::map<SdfPath, HdPhysxVehicleGearsSchema> _physxVehicleGears;
    std::map<SdfPath, HdPhysxVehicleMultiWheelDifferentialSchema> _physxVehicleMultiWheelDifferentials;
    std::map<SdfPath, HdPhysxVehicleNonlinearCommandResponseSchema> _physxVehicleNonlinearCommandResponseSchemas;
    std::map<SdfPath, HdPhysxVehicleSchema> _physxVehicles;
    std::map<SdfPath, HdPhysxVehicleSteeringSchema> _physxVehicleSteerings;
    std::map<SdfPath, HdPhysxVehicleSuspensionComplianceSchema> _physxVehicleSuspensionCompliances;
    std::map<SdfPath, HdPhysxVehicleSuspensionSchema> _physxVehicleSuspensions;
    std::map<SdfPath, HdPhysxVehicleTankControllerSchema> _physxVehicleTankControllers;
    std::map<SdfPath, HdPhysxVehicleTankDifferentialSchema> _physxVehicleTankDifferentials;
    std::map<SdfPath, HdPhysxVehicleTireFrictionTableSchema> _physxVehicleTireFrictionTables;
    std::map<SdfPath, HdPhysxVehicleTireSchema> _physxVehicleTires;
    std::map<SdfPath, HdPhysxVehicleWheelAttachmentSchema> _physxVehicleWheelAttachments;
    std::map<SdfPath, HdPhysxVehicleWheelControllerSchema> _physxVehicleWheelControllers;
    std::map<SdfPath, HdPhysxVehicleWheelSchema> _physxVehicleWheels;
    std::map<SdfPath, HdPrismaticJointSchema> _prismaticJoints;
    std::map<SdfPath, HdRevoluteJointSchema> _revoluteJoints;
    std::map<SdfPath, HdRigidBodySchema> _rigidBodies;
    std::map<SdfPath, HdSceneSchema> _scenes;
    std::map<SdfPath, HdSphericalJointSchema> _sphericalJoints;

    std::map<SdfPath, HdCubeSchema> _cubes;
    std::map<SdfPath, HdCapsuleSchema> _capsules;
    std::map<SdfPath, HdSphereSchema> _spheres;
    std::map<SdfPath, HdConeSchema> _cones;
    std::map<SdfPath, HdCylinderSchema> _cylinders;
    std::map<SdfPath, HdPlaneSchema> _planes;
    std::map<SdfPath, HdPrimvarsSchema> _meshes;
    std::map<SdfPath, HdDirectMaterialBindingsSchema> _materialBindings;

    SdfPathTable<GfMatrix4d> _globalXforms;
    SdfPathTable<GfMatrix4d> _resultXforms;
    HdSceneIndexObserver::DirtiedPrimEntries _dirtyEntries;
};

PXR_NAMESPACE_CLOSE_SCOPE
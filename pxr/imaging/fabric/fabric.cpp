//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/fabric/fabric.h"
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

void Fabric::PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry& entry) {
    if (auto schema = FabricArticulationRootSchema::GetFromParent(prim.dataSource)) {
        _articulationRoots.insert({entry.primPath, schema});
    }
    if (auto schema = FabricCollisionGroupSchema::GetFromParent(prim.dataSource)) {
        _collisionGroups.insert({entry.primPath, schema});
    }
    if (auto schema = FabricCollisionSchema::GetFromParent(prim.dataSource)) {
        if (auto geom = HdCubeSchema::GetFromParent(prim.dataSource)) {
            _cubes.insert({entry.primPath, geom});
        }
        if (auto geom = HdCapsuleSchema::GetFromParent(prim.dataSource)) {
            _capsules.insert({entry.primPath, geom});
        }
        if (auto geom = HdSphereSchema::GetFromParent(prim.dataSource)) {
            _spheres.insert({entry.primPath, geom});
        }
        if (auto geom = HdConeSchema::GetFromParent(prim.dataSource)) {
            _cones.insert({entry.primPath, geom});
        }
        if (auto geom = HdCylinderSchema::GetFromParent(prim.dataSource)) {
            _cylinders.insert({entry.primPath, geom});
        }
        if (auto geom = HdPlaneSchema::GetFromParent(prim.dataSource)) {
            _planes.insert({entry.primPath, geom});
        }
        if (auto geom = HdPrimvarsSchema::GetFromParent(prim.dataSource)) {
            _meshes.insert({entry.primPath, geom});
        }
        _collisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricDistanceJointSchema::GetFromParent(prim.dataSource)) {
        _distanceJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricDriveSchema::GetFromParent(prim.dataSource)) {
        _drives.insert({entry.primPath, schema});
    }
    if (auto schema = FabricFilteredPairsSchema::GetFromParent(prim.dataSource)) {
        _filteredPairs.insert({entry.primPath, schema});
    }
    if (auto schema = FabricFixedJointSchema::GetFromParent(prim.dataSource)) {
        _fixedJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricJointSchema::GetFromParent(prim.dataSource)) {
        _joints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricLimitSchema::GetFromParent(prim.dataSource)) {
        _limits.insert({entry.primPath, schema});
    }
    if (auto schema = FabricMassSchema::GetFromParent(prim.dataSource)) {
        _masses.insert({entry.primPath, schema});
    }
    if (auto schema = FabricMaterialSchema::GetFromParent(prim.dataSource)) {
        _materials.insert({entry.primPath, schema});
    }
    if (auto schema = FabricMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _meshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxArticulationSchema::GetFromParent(prim.dataSource)) {
        _physxArticulations.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCameraDroneSchema::GetFromParent(prim.dataSource)) {
        _physxCameraDrones.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCameraFollowLookSchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollowLooks.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCameraFollowSchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollows.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCameraFollowVelocitySchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollowVelocities.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCameraSchema::GetFromParent(prim.dataSource)) {
        _physxCameras.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCharacterControllerSchema::GetFromParent(prim.dataSource)) {
        _physxCharacterControllers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxContactReportSchema::GetFromParent(prim.dataSource)) {
        _physxContactReports.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxConvexDecompositionCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxConvexDecompositionCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxConvexHullCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxConvexHullCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxCookedDataSchema::GetFromParent(prim.dataSource)) {
        _physxCookedDatas.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxForceSchema::GetFromParent(prim.dataSource)) {
        _physxForces.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxIsosurfaceSchema::GetFromParent(prim.dataSource)) {
        _physxIsosurfaces.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxJointSchema::GetFromParent(prim.dataSource)) {
        _physxJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxJointStateSchema::GetFromParent(prim.dataSource)) {
        _physxJointStates.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxMaterialSchema::GetFromParent(prim.dataSource)) {
        _physxMaterials.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxMeshMergeCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxMeshMergeCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxMimicJointSchema::GetFromParent(prim.dataSource)) {
        _physxMimicJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxPhysicsDistanceJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsDistanceJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxPhysicsGearJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsGearJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxPhysicsInstancerSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsInstancers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxPhysicsJointInstancerSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsJointInstancers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxPhysicsRackAndPinionJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsRackAndPinionJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxResidualReportingSchema::GetFromParent(prim.dataSource)) {
        _physxResidualReportings.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxRigidBodySchema::GetFromParent(prim.dataSource)) {
        _physxRigidBodies.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxSceneQuasistaticSchema::GetFromParent(prim.dataSource)) {
        _physxSceneQuasistatics.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxSceneSchema::GetFromParent(prim.dataSource)) {
        _physxScenes.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxSDFMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxSDFMeshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxSphereFillCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxSphereFillCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxSurfaceVelocitySchema::GetFromParent(prim.dataSource)) {
        _physxSurfaceVelocities.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxTriangleMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxTriangleMeshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxTriangleMeshSimplificationCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxTriangleMeshSimplificationCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxTriggerSchema::GetFromParent(prim.dataSource)) {
        _physxTriggers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxTriggerStateSchema::GetFromParent(prim.dataSource)) {
        _physxTriggerStates.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleAckermannSteeringSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleAckermannSteerings.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleAutoGearBoxSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleAutoGearBoxs.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleBrakesSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleBrakes.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleClutchSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleClutches.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleContextSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleContexts.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleControllers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleDriveBasicSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleDriveBasics.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleDriveStandardSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleDriveStandards.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleEngineSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleEngines.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleGearsSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleGears.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleMultiWheelDifferentialSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleMultiWheelDifferentials.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleNonlinearCommandResponseSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleNonlinearCommandResponseSchemas.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleSchema::GetFromParent(prim.dataSource)) {
        _physxVehicles.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleSteeringSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSteerings.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleSuspensionComplianceSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSuspensionCompliances.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleSuspensionSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSuspensions.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleTankControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTankControllers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleTankDifferentialSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTankDifferentials.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleTireFrictionTableSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTireFrictionTables.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleTireSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTires.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleWheelAttachmentSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheelAttachments.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleWheelControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheelControllers.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPhysxVehicleWheelSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheels.insert({entry.primPath, schema});
    }
    if (auto schema = FabricPrismaticJointSchema::GetFromParent(prim.dataSource)) {
        _prismaticJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricRevoluteJointSchema::GetFromParent(prim.dataSource)) {
        _revoluteJoints.insert({entry.primPath, schema});
    }
    if (auto schema = FabricRigidBodySchema::GetFromParent(prim.dataSource)) {
        _rigidBodies.insert({entry.primPath, schema});
    }
    if (auto schema = FabricSceneSchema::GetFromParent(prim.dataSource)) {
        _scenes.insert({entry.primPath, schema});
    }
    if (auto schema = FabricSphericalJointSchema::GetFromParent(prim.dataSource)) {
        _sphericalJoints.insert({entry.primPath, schema});
    }
}

void Fabric::PrimsRemoved(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::RemovedPrimEntry& entry) {
    _articulationRoots.erase(entry.primPath);
    _collisionGroups.erase(entry.primPath);
    if (_collisions.erase(entry.primPath)) {
        _cubes.erase(entry.primPath);
        _capsules.erase(entry.primPath);
        _spheres.erase(entry.primPath);
        _cones.erase(entry.primPath);
        _cylinders.erase(entry.primPath);
        _planes.erase(entry.primPath);
        _meshes.erase(entry.primPath);
    }
    _distanceJoints.erase(entry.primPath);
    _drives.erase(entry.primPath);
    _filteredPairs.erase(entry.primPath);
    _fixedJoints.erase(entry.primPath);
    _joints.erase(entry.primPath);
    _limits.erase(entry.primPath);
    _masses.erase(entry.primPath);
    _materials.erase(entry.primPath);
    _meshCollisions.erase(entry.primPath);
    _physxArticulations.erase(entry.primPath);
    _physxCameraDrones.erase(entry.primPath);
    _physxCameraFollowLooks.erase(entry.primPath);
    _physxCameraFollows.erase(entry.primPath);
    _physxCameraFollowVelocities.erase(entry.primPath);
    _physxCameras.erase(entry.primPath);
    _physxCharacterControllers.erase(entry.primPath);
    _physxCollisions.erase(entry.primPath);
    _physxContactReports.erase(entry.primPath);
    _physxConvexDecompositionCollisions.erase(entry.primPath);
    _physxConvexHullCollisions.erase(entry.primPath);
    _physxCookedDatas.erase(entry.primPath);
    _physxForces.erase(entry.primPath);
    _physxIsosurfaces.erase(entry.primPath);
    _physxJoints.erase(entry.primPath);
    _physxJointStates.erase(entry.primPath);
    _physxMaterials.erase(entry.primPath);
    _physxMeshMergeCollisions.erase(entry.primPath);
    _physxMimicJoints.erase(entry.primPath);
    _physxPhysicsDistanceJoints.erase(entry.primPath);
    _physxPhysicsGearJoints.erase(entry.primPath);
    _physxPhysicsInstancers.erase(entry.primPath);
    _physxPhysicsJointInstancers.erase(entry.primPath);
    _physxPhysicsRackAndPinionJoints.erase(entry.primPath);
    _physxResidualReportings.erase(entry.primPath);
    _physxRigidBodies.erase(entry.primPath);
    _physxSceneQuasistatics.erase(entry.primPath);
    _physxScenes.erase(entry.primPath);
    _physxSDFMeshCollisions.erase(entry.primPath);
    _physxSphereFillCollisions.erase(entry.primPath);
    _physxSurfaceVelocities.erase(entry.primPath);
    _physxTriangleMeshCollisions.erase(entry.primPath);
    _physxTriangleMeshSimplificationCollisions.erase(entry.primPath);
    _physxTriggers.erase(entry.primPath);
    _physxTriggerStates.erase(entry.primPath);
    _physxVehicleAckermannSteerings.erase(entry.primPath);
    _physxVehicleAutoGearBoxs.erase(entry.primPath);
    _physxVehicleBrakes.erase(entry.primPath);
    _physxVehicleClutches.erase(entry.primPath);
    _physxVehicleContexts.erase(entry.primPath);
    _physxVehicleControllers.erase(entry.primPath);
    _physxVehicleDriveBasics.erase(entry.primPath);
    _physxVehicleDriveStandards.erase(entry.primPath);
    _physxVehicleEngines.erase(entry.primPath);
    _physxVehicleGears.erase(entry.primPath);
    _physxVehicleMultiWheelDifferentials.erase(entry.primPath);
    _physxVehicleNonlinearCommandResponseSchemas.erase(entry.primPath);
    _physxVehicles.erase(entry.primPath);
    _physxVehicleSteerings.erase(entry.primPath);
    _physxVehicleSuspensionCompliances.erase(entry.primPath);
    _physxVehicleSuspensions.erase(entry.primPath);
    _physxVehicleTankControllers.erase(entry.primPath);
    _physxVehicleTankDifferentials.erase(entry.primPath);
    _physxVehicleTireFrictionTables.erase(entry.primPath);
    _physxVehicleTires.erase(entry.primPath);
    _physxVehicleWheelAttachments.erase(entry.primPath);
    _physxVehicleWheelControllers.erase(entry.primPath);
    _physxVehicleWheels.erase(entry.primPath);
    _prismaticJoints.erase(entry.primPath);
    _revoluteJoints.erase(entry.primPath);
    _rigidBodies.erase(entry.primPath);
    _scenes.erase(entry.primPath);
    _sphericalJoints.erase(entry.primPath);
}

void Fabric::PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry& entry) {}

PXR_NAMESPACE_CLOSE_SCOPE
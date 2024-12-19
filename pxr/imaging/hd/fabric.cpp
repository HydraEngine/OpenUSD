//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hd/fabric.h"

PXR_NAMESPACE_OPEN_SCOPE

void Fabric::PrimsAdded(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::AddedPrimEntry& entry) {
    if (auto schema = HdArticulationRootSchema::GetFromParent(prim.dataSource)) {
        _articulationRoots.insert({entry.primPath, schema});
    }
    if (auto schema = HdCollisionGroupSchema::GetFromParent(prim.dataSource)) {
        _collisionGroups.insert({entry.primPath, schema});
    }
    if (auto schema = HdCollisionSchema::GetFromParent(prim.dataSource)) {
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
    if (auto schema = HdDistanceJointSchema::GetFromParent(prim.dataSource)) {
        _distanceJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdDriveEntrySchema::GetFromParent(prim.dataSource)) {
        _drives.insert({entry.primPath, schema});
    }
    if (auto schema = HdFilteredPairsSchema::GetFromParent(prim.dataSource)) {
        _filteredPairs.insert({entry.primPath, schema});
    }
    if (auto schema = HdFixedJointSchema::GetFromParent(prim.dataSource)) {
        _fixedJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdJointSchema::GetFromParent(prim.dataSource)) {
        _joints.insert({entry.primPath, schema});
    }
    if (auto schema = HdLimitEntrySchema::GetFromParent(prim.dataSource)) {
        _limits.insert({entry.primPath, schema});
    }
    if (auto schema = HdMassSchema::GetFromParent(prim.dataSource)) {
        _masses.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysicsMaterialSchema::GetFromParent(prim.dataSource)) {
        _materials.insert({entry.primPath, schema});
    }
    if (auto schema = HdDirectMaterialBindingsSchema::GetFromParent(prim.dataSource)) {
        _materialBindings.insert({entry.primPath, schema});
    }
    if (auto schema = HdMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _meshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxArticulationSchema::GetFromParent(prim.dataSource)) {
        _physxArticulations.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCameraDroneSchema::GetFromParent(prim.dataSource)) {
        _physxCameraDrones.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCameraFollowLookSchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollowLooks.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCameraFollowSchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollows.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCameraFollowVelocitySchema::GetFromParent(prim.dataSource)) {
        _physxCameraFollowVelocities.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCameraSchema::GetFromParent(prim.dataSource)) {
        _physxCameras.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCharacterControllerSchema::GetFromParent(prim.dataSource)) {
        _physxCharacterControllers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxContactReportSchema::GetFromParent(prim.dataSource)) {
        _physxContactReports.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxConvexDecompositionCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxConvexDecompositionCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxConvexHullCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxConvexHullCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxCookedDataSchema::GetFromParent(prim.dataSource)) {
        _physxCookedDatas.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxForceSchema::GetFromParent(prim.dataSource)) {
        _physxForces.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxIsosurfaceSchema::GetFromParent(prim.dataSource)) {
        _physxIsosurfaces.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxJointSchema::GetFromParent(prim.dataSource)) {
        _physxJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxJointStateEntrySchema::GetFromParent(prim.dataSource)) {
        _physxJointStates.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxMaterialSchema::GetFromParent(prim.dataSource)) {
        _physxMaterials.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxMeshMergeCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxMeshMergeCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxMimicJointEntrySchema::GetFromParent(prim.dataSource)) {
        _physxMimicJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxPhysicsDistanceJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsDistanceJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxPhysicsGearJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsGearJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxPhysicsInstancerSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsInstancers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxPhysicsJointInstancerSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsJointInstancers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxPhysicsRackAndPinionJointSchema::GetFromParent(prim.dataSource)) {
        _physxPhysicsRackAndPinionJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxResidualReportingSchema::GetFromParent(prim.dataSource)) {
        _physxResidualReportings.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxRigidBodySchema::GetFromParent(prim.dataSource)) {
        _physxRigidBodies.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxSceneQuasistaticSchema::GetFromParent(prim.dataSource)) {
        _physxSceneQuasistatics.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxSceneSchema::GetFromParent(prim.dataSource)) {
        _physxScenes.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxSDFMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxSDFMeshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxSphereFillCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxSphereFillCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxSurfaceVelocitySchema::GetFromParent(prim.dataSource)) {
        _physxSurfaceVelocities.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxTriangleMeshCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxTriangleMeshCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxTriangleMeshSimplificationCollisionSchema::GetFromParent(prim.dataSource)) {
        _physxTriangleMeshSimplificationCollisions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxTriggerSchema::GetFromParent(prim.dataSource)) {
        _physxTriggers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxTriggerStateSchema::GetFromParent(prim.dataSource)) {
        _physxTriggerStates.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleAckermannSteeringSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleAckermannSteerings.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleAutoGearBoxSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleAutoGearBoxs.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleBrakesEntrySchema::GetFromParent(prim.dataSource)) {
        _physxVehicleBrakes.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleClutchSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleClutches.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleContextSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleContexts.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleControllers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleDriveBasicSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleDriveBasics.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleDriveStandardSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleDriveStandards.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleEngineSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleEngines.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleGearsSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleGears.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleMultiWheelDifferentialSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleMultiWheelDifferentials.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleNonlinearCommandResponseEntrySchema::GetFromParent(prim.dataSource)) {
        _physxVehicleNonlinearCommandResponseSchemas.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleSchema::GetFromParent(prim.dataSource)) {
        _physxVehicles.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleSteeringSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSteerings.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleSuspensionComplianceSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSuspensionCompliances.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleSuspensionSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleSuspensions.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleTankControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTankControllers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleTankDifferentialSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTankDifferentials.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleTireFrictionTableSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTireFrictionTables.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleTireSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleTires.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleWheelAttachmentSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheelAttachments.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleWheelControllerSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheelControllers.insert({entry.primPath, schema});
    }
    if (auto schema = HdPhysxVehicleWheelSchema::GetFromParent(prim.dataSource)) {
        _physxVehicleWheels.insert({entry.primPath, schema});
    }
    if (auto schema = HdPrismaticJointSchema::GetFromParent(prim.dataSource)) {
        _prismaticJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdRevoluteJointSchema::GetFromParent(prim.dataSource)) {
        _revoluteJoints.insert({entry.primPath, schema});
    }
    if (auto schema = HdRigidBodySchema::GetFromParent(prim.dataSource)) {
        _rigidBodies.insert({entry.primPath, schema});
    }
    if (auto schema = HdSceneSchema::GetFromParent(prim.dataSource)) {
        _scenes.insert({entry.primPath, schema});
    }
    if (auto schema = HdSphericalJointSchema::GetFromParent(prim.dataSource)) {
        _sphericalJoints.insert({entry.primPath, schema});
    }

    if (auto schema = HdXformSchema::GetFromParent(prim.dataSource)) {
        if (auto matrixSource = schema.GetMatrix()) {
            auto m = matrixSource->GetTypedValue(0.0f);
            const auto it = _globalXforms.find(entry.primPath);
            if (it != _globalXforms.end()) {
                it->second = m;
            } else {
                _globalXforms.insert({entry.primPath, m});
            }
        }
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
    _materialBindings.erase(entry.primPath);
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
    if (_rigidBodies.erase(entry.primPath)) {
        _globalXforms.erase(entry.primPath);
    }
    _scenes.erase(entry.primPath);
    _sphericalJoints.erase(entry.primPath);
}

void Fabric::PrimsDirtied(const HdSceneIndexPrim& prim, const HdSceneIndexObserver::DirtiedPrimEntry& entry) {}

std::optional<GfMatrix4d> Fabric::FindXform(const SdfPath& path) {
    auto iter = _resultXforms.find(path);
    if (iter != _resultXforms.end()) {
        return iter->second;
    }
    return std::nullopt;
}

void Fabric::InsertDirtyEntry(const SdfPath& path) {
    static HdDataSourceLocatorSet locators = {pxr::HdXformSchema::GetDefaultLocator()};
    _dirtyEntries.emplace_back(path, locators);
}

PXR_NAMESPACE_CLOSE_SCOPE
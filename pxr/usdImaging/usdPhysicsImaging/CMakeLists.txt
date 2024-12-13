set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdPhysicsImaging)

pxr_library(usdPhysicsImaging
        LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics
        usdPhysX

        PUBLIC_CLASSES
        dependentPrimsDataSource

        materialAPIAdapter
        collisionAPIAdapter
        meshCollisionAPIAdapter
        massAPIAdapter
        rigidBodyAPIAdapter

        articulationRootAPIAdapter
        driveAPIAdapter
        limitAPIAdapter

        dataSourceJoint
        dataSourceDistanceJoint
        dataSourceFixedJoint
        dataSourcePrismaticJoint
        dataSourceRevoluteJoint
        dataSourceSphericalJoint
        dataSourceGearJoint
        dataSourceRackAndPinionJoint

        jointAdapter
        distanceJointAdapter
        fixedJointAdapter
        prismaticJointAdapter
        revoluteJointAdapter
        sphericalJointAdapter
        gearJointAdapter
        rackAndPinionJointAdapter

        sceneAdapter
        filteredPairsAPIAdapter
        collisionGroupAdapter

        physxArticulationAPIAdapter
        physxCameraDroneAPIAdapter
        physxCameraFollowLookAPIAdapter
        physxCameraFollowAPIAdapter
        physxCameraFollowVelocityAPIAdapter
        physxCameraAPIAdapter
        physxCharacterControllerAPIAdapter
        physxCollisionAPIAdapter
        physxContactReportAPIAdapter
        physxConvexDecompositionCollisionAPIAdapter
        physxConvexHullCollisionAPIAdapter
        physxCookedDataAPIAdapter
        physxForceAPIAdapter
        physxIsosurfaceAPIAdapter
        physxJointAPIAdapter
        physxJointStateAPIAdapter
        physxMaterialAPIAdapter
        physxMeshMergeCollisionAPIAdapter
        physxMimicJointAPIAdapter
        physxPhysicsDistanceJointAPIAdapter
        physxResidualReportingAPIAdapter
        physxRigidBodyAPIAdapter
        physxSceneQuasistaticAPIAdapter
        physxSceneAPIAdapter
        physxSDFMeshCollisionAPIAdapter
        physxSphereFillCollisionAPIAdapter
        physxSurfaceVelocityAPIAdapter
        physxTriangleMeshCollisionAPIAdapter
        physxTriangleMeshSimplificationCollisionAPIAdapter
        physxTriggerAPIAdapter
        physxTriggerStateAPIAdapter
        physxVehicleAckermannSteeringAPIAdapter
        physxVehicleAutoGearBoxAPIAdapter
        physxVehicleBrakesAPIAdapter
        physxVehicleClutchAPIAdapter
        physxVehicleContextAPIAdapter
        physxVehicleControllerAPIAdapter
        physxVehicleDriveBasicAPIAdapter
        physxVehicleDriveStandardAPIAdapter
        physxVehicleEngineAPIAdapter
        physxVehicleGearsAPIAdapter
        physxVehicleMultiWheelDifferentialAPIAdapter
        physxVehicleNonlinearCommandResponseAPIAdapter
        physxVehicleAPIAdapter
        physxVehicleSteeringAPIAdapter
        physxVehicleSuspensionComplianceAPIAdapter
        physxVehicleSuspensionAPIAdapter
        physxVehicleTankControllerAPIAdapter
        physxVehicleTankDifferentialAPIAdapter
        physxVehicleTireAPIAdapter
        physxVehicleWheelAttachmentAPIAdapter
        physxVehicleWheelControllerAPIAdapter
        physxVehicleWheelAPIAdapter

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json
)

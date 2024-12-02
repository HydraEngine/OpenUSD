set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdPhysicsImaging)

pxr_library(usdPhysicsImaging
        LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics

        PUBLIC_CLASSES
        dependentPrimsDataSource

        materialSchema
        materialAPIAdapter
        collisionSchema
        collisionAPIAdapter
        meshCollisionSchema
        meshCollisionAPIAdapter
        massSchema
        massAPIAdapter
        rigidBodySchema
        rigidBodyAPIAdapter

        articulationRootSchema
        articulationRootAPIAdapter
        driveSchema
        driveAPIAdapter
        limitSchema
        limitAPIAdapter

        jointSchema
        distanceJointSchema
        fixedJointSchema
        prismaticJointSchema
        revoluteJointSchema
        sphericalJointSchema

        dataSourceJoint
        dataSourceDistanceJoint
        dataSourceFixedJoint
        dataSourcePrismaticJoint
        dataSourceRevoluteJoint
        dataSourceSphericalJoint

        jointAdapter
        distanceJointAdapter
        fixedJointAdapter
        prismaticJointAdapter
        revoluteJointAdapter
        sphericalJointAdapter

        sceneSchema
        sceneAdapter
        filteredPairsSchema
        filteredPairsAPIAdapter
        collisionGroupSchema
        collisionGroupAdapter

        physicsSceneIndex

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json
)

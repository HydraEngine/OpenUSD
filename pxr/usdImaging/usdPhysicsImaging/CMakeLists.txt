set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdPhysicsImaging)

pxr_library(usdPhysicsImaging
        LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics

        PUBLIC_CLASSES
        tokens
        sceneSchema
        sceneAdapter

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

        dataSourceJoint
        dataSourceDistanceJoint
        dataSourceFixedJoint
        dataSourcePrismaticJoint
        dataSourceRevoluteJoint

        jointAdapter
        distanceJointAdapter
        fixedJointAdapter
        prismaticJointAdapter
        revoluteJointAdapter

        filteredPairsSchema
        filteredPairsAPIAdapter

        physicsSceneIndex

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json
)

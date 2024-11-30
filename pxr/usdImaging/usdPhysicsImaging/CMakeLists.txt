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

        articulationRootSchema
        articulationRootAPIAdapter
        driveSchema
        driveAPIAdapter
        limitSchema
        limitAPIAdapter

        filteredPairsSchema
        filteredPairsAPIAdapter

        physicsSceneIndex

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json
)

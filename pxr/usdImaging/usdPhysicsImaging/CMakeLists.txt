set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdPhysicsImaging)

pxr_library(usdPhysicsImaging
    LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics

    PUBLIC_CLASSES
        materialAPIAdapter
        sceneAdapter

        physicsSchema
        physicsSceneIndex

    PUBLIC_HEADERS
        api.h

    RESOURCE_FILES
        plugInfo.json
)

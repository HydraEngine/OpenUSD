set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdPhysicsImaging)

pxr_library(usdSimImaging
        LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics
        usdPhysicsImaging

        PUBLIC_CLASSES
        physicsSceneIndex

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json
)

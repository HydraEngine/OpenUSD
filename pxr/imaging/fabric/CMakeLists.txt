set(PXR_PREFIX pxr/imaging)
set(PXR_PACKAGE fabric)

pxr_library(fabric
    LIBRARIES
        plug
        tf
        trace
        vt
        work
        sdf
        cameraUtil
        geomUtil
        hf
        hd
        pxOsd

    PUBLIC_CLASSES
        fabricSceneIndex

    PUBLIC_HEADERS
        api.h
        version.h
)
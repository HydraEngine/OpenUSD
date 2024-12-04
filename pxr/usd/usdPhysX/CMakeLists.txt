set(PXR_PREFIX pxr/usd)
set(PXR_PACKAGE usdPhysX)

pxr_library(usdPhysX
    INCLUDE_SCHEMA_FILES

    LIBRARIES
        tf
        plug
        vt
        sdf
        trace
        usd
        usdGeom
        usdShade
        work
        ${TBB_tbb_LIBRARY}

    INCLUDE_DIRS
        ${TBB_INCLUDE_DIRS}

    PUBLIC_CLASSES
        jointStateAPI
        
    PUBLIC_HEADERS
        api.h
        jointStateAPI.h

    PYTHON_CPPFILES
        moduleDeps.cpp

    PYMODULE_CPPFILES
        wrapJointStateAPI.cpp

    PYMODULE_FILES
        __init__.py
)

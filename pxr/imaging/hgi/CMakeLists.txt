set(PXR_PREFIX pxr/imaging)
set(PXR_PACKAGE hgi)

find_package(CUDAToolkit)
set(LINK_LIBRARIES
        gf
        plug
        tf
        hio
)
if (CUDAToolkit_FOUND)
    list(APPEND LINK_LIBRARIES CUDA::cudart)
endif ()

pxr_library(hgi
    LIBRARIES
        ${LINK_LIBRARIES}

    PUBLIC_CLASSES
        attachmentDesc
        blitCmds
        buffer
        capabilities
        cmds
        computeCmds
        computeCmdsDesc
        computePipeline
        debugCodes
        graphicsCmds
        graphicsCmdsDesc
        graphicsPipeline
        hgi
        indirectCommandEncoder
        resourceBindings
        sampler
        shaderFunction
        shaderFunctionDesc
        shaderGenerator
        shaderProgram
        shaderSection
        texture
        tokens
        types
        unitTestHelper

    PUBLIC_HEADERS
        api.h
        blitCmdsOps.h
        enums.h
        handle.h
)

if (CUDAToolkit_FOUND)
    target_compile_definitions(hgi PUBLIC WITH_CUDA)
endif ()

if (${PXR_HEADLESS_TEST_MODE})
    message(STATUS "Skipping ${PXR_PACKAGE} tests because PXR_HEADLESS_TEST_MODE is ON")
    return()
endif()

if (APPLE)
    message(STATUS "Skipping ${PXR_PACKAGE} tests because they are currently unsupported on macOS")
    return()
endif()

if (WIN32)
    message(STATUS "Skipping ${PXR_PACKAGE} tests because they are currently unsupported on Windows")
    return()
endif()

pxr_build_test(testHgiCommand
    LIBRARIES
        hgi
        garch
        tf
    CPPFILES
        testenv/testHgiCommand.cpp
)

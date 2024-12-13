set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdSimImaging)

if (APPLE)
    set(physx5_SOURCE_DIR $ENV{HOME}/Desktop/PhysX-Mac/physx)
else ()
    find_package(CUDAToolkit REQUIRED)
    set(physx5_SOURCE_DIR $$ENV{HOME}/Desktop/PhysX/physx)
endif ()

set(physx5_link_libraries)
set(physx5_include_directories)
if (physx5_SOURCE_DIR)
    if (APPLE)
        set(physx5_link_directories ${physx5_SOURCE_DIR}/bin/mac.x86_64/release)
    else ()
        set(physx5_link_directories ${physx5_SOURCE_DIR}/bin/linux.clang/release)
    endif ()

    set(physx5_link_libraries
            ${physx5_link_directories}/libPhysXCharacterKinematic_static_64.a
            ${physx5_link_directories}/libPhysXExtensions_static_64.a
            ${physx5_link_directories}/libPhysXPvdSDK_static_64.a
            ${physx5_link_directories}/libPhysXVehicle2_static_64.a
            ${physx5_link_directories}/libPhysXVehicle_static_64.a
    )
    if (APPLE)
        list(APPEND physx5_link_libraries
                ${physx5_link_directories}/libPhysX_64.dylib
                ${physx5_link_directories}/libPhysXCommon_64.dylib
                ${physx5_link_directories}/libPhysXCooking_64.dylib
                ${physx5_link_directories}/libPhysXFoundation_64.dylib
        )
    else ()
        list(APPEND physx5_link_libraries
                ${physx5_link_directories}/libPhysX_64.so
                ${physx5_link_directories}/libPhysXCommon_64.so
                ${physx5_link_directories}/libPhysXCooking_64.so
                ${physx5_link_directories}/libPhysXFoundation_64.so
                ${physx5_link_directories}/libPhysXGpu_64.so
                CUDA::cuda_driver
        )
    endif ()

    set(physx5_include_directories
            ${physx5_SOURCE_DIR}/include
            ${physx5_SOURCE_DIR}/source
    )
endif ()

pxr_library(usdSimImaging
        LIBRARIES
        hio
        hd
        usdImaging
        usdPhysics
        usdPhysicsImaging
        ${physx5_link_libraries}

        PUBLIC_CLASSES
        physxEngine
        physxScene
        filterShader
        utils

        PUBLIC_HEADERS
        api.h

        RESOURCE_FILES
        plugInfo.json

        INCLUDE_DIRS
        ${physx5_include_directories}
)

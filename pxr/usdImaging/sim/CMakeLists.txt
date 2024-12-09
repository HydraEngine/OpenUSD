set(PXR_PREFIX pxr/usdImaging)
set(PXR_PACKAGE usdSimImaging)

find_package(CUDAToolkit REQUIRED)

set(physx5_SOURCE_DIR /home/yangfengzzz/Desktop/PhysX/physx)

set(physx5_link_libraries)
set(physx5_include_directories)
if (physx5_SOURCE_DIR)
    set(physx5_link_directories ${physx5_SOURCE_DIR}/bin/linux.clang/release)
    set(physx5_link_libraries
            ${physx5_link_directories}/libPhysX_64.so
            ${physx5_link_directories}/libPhysXCommon_64.so
            ${physx5_link_directories}/libPhysXCooking_64.so
            ${physx5_link_directories}/libPhysXFoundation_64.so
            ${physx5_link_directories}/libPhysXGpu_64.so

            ${physx5_link_directories}/libPhysXCharacterKinematic_static_64.a
            ${physx5_link_directories}/libPhysXExtensions_static_64.a
            ${physx5_link_directories}/libPhysXPvdSDK_static_64.a
            ${physx5_link_directories}/libPhysXVehicle2_static_64.a
            ${physx5_link_directories}/libPhysXVehicle_static_64.a
            CUDA::cuda_driver
    )
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
        physicsSceneIndex
        physxDataSource
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

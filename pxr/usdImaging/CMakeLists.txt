set(DIRS
        usdImaging
        usdImagingGL
        usdProcImaging
        usdRiPxrImaging
        usdSkelImaging
        usdPhysicsImaging
        usdVolImaging
        usdAppUtils
        usdviewq
        sim
        bin
        plugin
)

foreach (d ${DIRS})
    add_subdirectory(${d})
endforeach ()

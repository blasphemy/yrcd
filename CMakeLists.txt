project (yrcd)
cmake_minimum_required (VERSION 2.6)
list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set (DATADIR "${CMAKE_INSTALL_PREFIX}/share")
set (PKGDATADIR "${DATADIR}/yrcd")
set (YRCD_NAME "yrcd")
set (RELEASE_NAME "prealpha")
set (VERSION "0.1")
set (VERSION_INFO "prealpha")
find_package(PkgConfig)
pkg_check_modules(GEE REQUIRED gee-1.0)
pkg_check_modules(GIO REQUIRED gio-2.0)
set( CFLAGS
    ${GEE_CFLAGS}
    ${GIO_CFLAGS}
)
add_definitions(${CFLAGS})
set( LIBS
    ${GEE_LIBRARIES}    
    ${GIO_LIBRARIES}
)
link_libraries(${LIBS})
set ( LIB_PATHS
    ${GEE_LIBRARY_DIRS}    
    ${GIO_LIBRARY_DIRS}
)
link_directories(${LIB_PATHS})
find_package(Vala REQUIRED)
include(ValaVersion)
ensure_vala_version("0.16" MINIMUM)
include(ValaPrecompile)
vala_precompile(YRCD_C ${YRCD_NAME}
    src/main.vala
    src/server.vala
    src/user.vala
    src/router.vala    
    src/constants.vala
    src/numeric.vala
    src/numeric_wrapper.vala
PACKAGES
    gio-2.0
    gee-1.0
)
add_executable(${YRCD_NAME} ${YRCD_C})
install (TARGETS ${YRCD_NAME} RUNTIME DESTINATION bin)

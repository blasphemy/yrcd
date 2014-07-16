project (yrcd)
cmake_minimum_required (VERSION 2.6)
list (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# where we install data directory (if we have any)
set (DATADIR "${CMAKE_INSTALL_PREFIX}/share")
# what to call that directory where we install data too
set (PKGDATADIR "${DATADIR}/yrcd")

set (YRCD_NAME "yrcd")

set (RELEASE_NAME "prealpha")
set (VERSION "0.1")
set (VERSION_INFO "prealpha")


# we're about to use pkgconfig to make sure dependencies are installed so let's find pkgconfig first
find_package(PkgConfig)
# now let's actually check for the required dependencies
pkg_check_modules(DEPS REQUIRED gio-2.0)
add_definitions(${DEPS_CFLAGS})
link_libraries(${DEPS_LIBRARIES})
link_directories(${DEPS_LIBRARY_DIRS})
# make sure we have vala
find_package(Vala REQUIRED)
# make sure we use vala
include(ValaVersion)
# make sure it's the desired version of vala
ensure_vala_version("0.16" MINIMUM)
# files we want to compile
include(ValaPrecompile)
vala_precompile(YRCD_C ${YRCD_NAME}
    src/main.vala
    src/server.vala
    src/user.vala
    src/router.vala    
PACKAGES
    gio-2.0
)
# tell cmake what to call the executable we just made
add_executable(${YRCD_NAME} ${YRCD_C})
# install the binaries we just made
install (TARGETS ${YRCD_NAME} RUNTIME DESTINATION bin)

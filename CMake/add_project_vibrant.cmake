# vibrant External Project
#
# Required symbols are:
#   VIAME_BUILD_PREFIX - where packages are built
#   VIAME_BUILD_INSTALL_PREFIX - directory install target
#   VIAME_PACKAGES_DIR - location of git submodule packages
#   VIAME_ARGS_COMMON -
##

set( VIAME_PROJECT_LIST ${VIAME_PROJECT_LIST} vibrant )

set( VIBRANT_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )

ExternalProject_Add(vibrant
  DEPENDS fletch
  PREFIX ${VIAME_BUILD_PREFIX}
  SOURCE_DIR ${VIAME_PACKAGES_DIR}/vibrant
  CMAKE_GENERATOR ${gen}
  CMAKE_ARGS
    ${VIAME_ARGS_COMMON}
    ${VIAME_ARGS_fletch}

    -DBUILD_SHARED_LIBS:BOOL=ON
    -DBUILD_TESTING:BOOL=OFF
    -DVIDTK_BUILD_TESTS:BOOL=OFF

    -DBOOST_ROOT:PATH=${VIAME_BUILD_INSTALL_PREFIX}
    -DBoost_DIR:PATH=${VIAME_BUILD_INSTALL_PREFIX}
    -DBoost_INCLUDE_DIRS:PATH=${VIAME_BUILD_INSTALL_PREFIX}/include
    -DBoost_INCLUDE_DIR:PATH=${VIAME_BUILD_INSTALL_PREFIX}/include
    -DBoost_LIBRARY_DIR:PATH=${VIAME_BUILD_INSTALL_PREFIX}/lib
    -DBoost_LIBRARY_DIR_DEBUG:PATH=${VIAME_BUILD_INSTALL_PREFIX}/lib
    -DBoost_LIBRARY_DIR_RELEASE:PATH=${VIAME_BUILD_INSTALL_PREFIX}/lib

    -DCMAKE_CXX_FLAGS:STRING=${VIBRANT_CXX_FLAGS}

  INSTALL_DIR ${VIAME_BUILD_INSTALL_PREFIX}
  )

ExternalProject_Add_Step(vibrant forcebuild
  COMMAND ${CMAKE_COMMAND}
    -E remove ${VIAME_BUILD_PREFIX}/src/vibrant-stamp/vibrant-build
  COMMENT "Removing build stamp file for build update (forcebuild)."
  DEPENDEES configure
  DEPENDERS build
  ALWAYS 1
  )

set(VIAME_ARGS_vibrant
  -Dvibrant_DIR:PATH=${VIAME_BUILD_PREFIX}/src/vibrant-build
  -Dvidtk_DIR:PATH=${VIAME_BUILD_PREFIX}/src/vibrant-build
  )

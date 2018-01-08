cmake_minimum_required(VERSION 3.0)
project(daydream CXX)

enable_language(C)

set(DAYDREAM_MAJOR_VERSION 0)
set(DAYDREAM_MINOR_VERSION 0)
set(DAYDREAM_PATCH_VERSION 1)
set(DAYDREAM_VERSION ${DAYDREAM_MAJOR_VERSION}.${DAYDREAM_MINOR_VERSION}.${DAYDREAM_PATCH_VERSION})

set(DAYDREAM_OUTPUT_DIR ${CMAKE_BINARY_DIR}/build CACHE PATH "Ouput directory for built files")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DAYDREAM_OUTPUT_DIR})

foreach(CONFIG_TYPE ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${CONFIG_TYPE} CONFIG_TYPE_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_TYPE_UPPER} ${DAYDREAM_OUTPUT_DIR})
endforeach()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
enable_testing()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/cmake)
add_subdirectory(${PROJECT_SOURCE_DIR}/external/catch)

add_subdirectory(${PROJECT_SOURCE_DIR}/source/modules/client)

add_subdirectory(${PROJECT_SOURCE_DIR}/source/modules/scene)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/tests/scenetests)

add_subdirectory(${PROJECT_SOURCE_DIR}/source/modules/game)
add_subdirectory(${PROJECT_SOURCE_DIR}/source/tests/gametests)


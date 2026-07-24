cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Находим Geode SDK
find_path(GEODE_SDK_PATH "cmake/geode.cmake"
    PATHS
        "$ENV{GEODE_SDK}"
        "${CMAKE_CURRENT_SOURCE_DIR}/../geode-sdk"
        "${CMAKE_CURRENT_SOURCE_DIR}/../sdk"
)

if(NOT GEODE_SDK_PATH)
    message(FATAL_ERROR "Could not find Geode SDK!")
endif()

list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES src/BetterEditorUnlock.cpp
)

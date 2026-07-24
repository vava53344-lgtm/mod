cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

if(NOT GEODE_SDK)
    set(GEODE_SDK "$ENV{GEODE_SDK}")
endif()

if(NOT GEODE_SDK)
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES src/BetterEditorUnlock.cpp
)

cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Официальный способ найти geode.cmake
if(NOT GEODE_SDK)
    set(GEODE_SDK "$ENV{GEODE_SDK}")
endif()

if(NOT GEODE_SDK)
    message(FATAL_ERROR "GEODE_SDK environment variable not set!")
endif()

list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES src/BetterEditorUnlock.cpp
)

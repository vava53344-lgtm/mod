cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(geode)

# Явно указываем файл
file(GLOB SOURCES "src/*.cpp")

if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src/")
endif()

add_geode_mod(
    NAME better-editor-unlock
    SOURCES ${SOURCES}
)

cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(geode)

# Указываем полный путь к файлу
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/BetterEditorUnlock.cpp
)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES ${SOURCES}
)

cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Подключаем локальный geode.cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES src/BetterEditorUnlock.cpp
)

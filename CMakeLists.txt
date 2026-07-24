cmake_minimum_required(VERSION 3.10)
project(better-editor-unlock)

set(GEODE_SDK_DIR "$ENV{GEODE_SDK}" CACHE PATH "Geode SDK path")
include(${GEODE_SDK_DIR}/cmake/geode.cmake)

add_geode_mod(
  NAME better-editor-unlock
  SOURCES src/BetterEditorUnlock.cpp
)

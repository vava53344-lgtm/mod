cmake_minimum_required(VERSION 3.20)
project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

# Это все, что нужно! Action сам подставит нужные пути к SDK.
include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG main
)
FetchContent_MakeAvailable(Geode)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
setup_geode_mod(better-editor-unlock)
package_geode_mod(better-editor-unlock ${SRC_FILES})

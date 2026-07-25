cmake_minimum_required(VERSION 3.20)

project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v5.3.0
)

FetchContent_MakeAvailable(Geode)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

setup_geode_mod(better-editor-unlock)

target_sources(${PROJECT_NAME} PRIVATE
    ${SRC_FILES}
)

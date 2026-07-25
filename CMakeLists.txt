cmake_minimum_required(VERSION 3.25)

project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

# Указываем платформу
if(NOT GEODE_PLATFORM)
    set(GEODE_PLATFORM "Android64" CACHE STRING "Target platform" FORCE)
endif()

# Если передан путь к SDK через переменную окружения
if(DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK_PATH $ENV{GEODE_SDK} CACHE PATH "Path to Geode SDK")
endif()

include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG v5.3.0
)
FetchContent_MakeAvailable(Geode)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
setup_geode_mod(better-editor-unlock)
package_geode_mod(better-editor-unlock ${SRC_FILES})

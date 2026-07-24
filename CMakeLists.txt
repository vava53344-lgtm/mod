cmake_minimum_required(VERSION 3.25)

project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

# Проверяем, установлен ли Geode CLI
find_program(GEODE_EXECUTABLE geode)
if(NOT GEODE_EXECUTABLE)
    message(FATAL_ERROR "Geode CLI not found! Install it with: pip install geode-cli")
endif()

# Подключаем Geode SDK
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

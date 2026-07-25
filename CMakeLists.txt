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

# 1. Указываем платформу
set(GEODE_PLATFORM "Android64")

# 2. Скачиваем бинарники для Android (ЭТО ГЛАВНОЕ)
execute_process(
    COMMAND geode sdk install-binaries -p android64
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

setup_geode_mod(better-editor-unlock)
package_geode_mod(better-editor-unlock ${SRC_FILES})

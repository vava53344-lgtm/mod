cmake_minimum_required(VERSION 3.25)

project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

# Устанавливаем платформу Android
if(NOT GEODE_PLATFORM)
    set(GEODE_PLATFORM "Android64" CACHE STRING "Target platform" FORCE)
endif()

# Подключаем Geode SDK
include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com/geode-sdk/geode.git
    GIT_TAG main
)
FetchContent_MakeAvailable(Geode)

# Ищем исходные файлы
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Регистрируем мод
setup_geode_mod(better-editor-unlock)

# Создаем пакет
package_geode_mod(better-editor-unlock ${SRC_FILES})

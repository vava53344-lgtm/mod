cmake_minimum_required(VERSION 3.25)

# Подключаем Geode CLI инструменты
find_package(GeodeCLI REQUIRED)

project(better-editor-unlock VERSION 1.0.0 LANGUAGES CXX)

# Подключаем само SDK
include(FetchContent)
FetchContent_Declare(
    Geode
    GIT_REPOSITORY https://github.com
    GIT_TAG main
)
FetchContent_MakeAvailable(Geode)

# Ищем твои исходные файлы
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Регистрируем мод в системе Geode
setup_geode_mod(better-editor-unlock)

# Создаем финальный рабочий .geode пакет
package_geode_mod(better-editor-unlock ${SRC_FILES})

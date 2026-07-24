cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Жестко указываем ТОЛЬКО папку src
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Ищем файлы ТОЛЬКО в src/
file(GLOB SRC_FILES "${SOURCE_DIR}/*.cpp")

# Проверяем, есть ли хоть один файл
if(NOT SRC_FILES)
    message(FATAL_ERROR "No .cpp files found in ${SOURCE_DIR}")
endif()

message(STATUS "Found source files in src/:")
foreach(FILE ${SRC_FILES})
    message(STATUS "  ${FILE}")
endforeach()

# Подключаем Geode
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES ${SRC_FILES}
)

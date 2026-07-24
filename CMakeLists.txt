cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Ищем main.cpp во всём проекте
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Проверяем, что нашли хоть что-то
if(NOT SRC_FILES)
    message(FATAL_ERROR "No .cpp files found anywhere!")
endif()

# Выводим найденные файлы для отладки
message(STATUS "Found source files:")
foreach(FILE ${SRC_FILES})
    message(STATUS "  ${FILE}")
endforeach()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(geode)

add_geode_mod(
    NAME better-editor-unlock
    SOURCES ${SRC_FILES}
)

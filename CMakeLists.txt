cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Проверяем, что переменная окружения GEODE_SDK установлена
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK environment variable is not set!")
endif()

set(GEODE_SDK_PATH "$ENV{GEODE_SDK}")

# Подключаем официальный модуль Geode
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")
include(geode)

# Объявляем мод
add_geode_mod(
    NAME better-editor-unlock
    SOURCES src/main.cpp
)

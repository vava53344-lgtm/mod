cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Проверяем SDK
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

set(GEODE_SDK "$ENV{GEODE_SDK}")
message(STATUS "GEODE_SDK: ${GEODE_SDK}")

# Добавляем include пути
include_directories(${GEODE_SDK}/include)

# Добавляем библиотеки Geode
link_directories(${GEODE_SDK}/lib/android64)

# Создаём библиотеку
add_library(better-editor-unlock SHARED src/main.cpp)

# Линкуем Geode
target_link_libraries(better-editor-unlock 
    geode
    cocos2d
)

# Устанавливаем свойства
set_target_properties(better-editor-unlock PROPERTIES
    PREFIX ""
    SUFFIX ".geode"
    OUTPUT_NAME "better-editor-unlock"
)

# Копируем mod.json
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/mod.json
    ${CMAKE_CURRENT_BINARY_DIR}/mod.json
    COPYONLY
)

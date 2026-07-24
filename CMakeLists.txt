cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Правильный способ подключения Geode для Android
find_path(GEODE_SDK_INCLUDE_DIR "Geode/Geode.hpp"
    PATHS
        "$ENV{GEODE_SDK}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/../geode-sdk/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/include"
)

if(NOT GEODE_SDK_INCLUDE_DIR)
    message(FATAL_ERROR "Could not find Geode SDK!")
endif()

# Ручная настройка
add_library(geode INTERFACE)
target_include_directories(geode INTERFACE ${GEODE_SDK_INCLUDE_DIR})
target_compile_features(geode INTERFACE cxx_std_17)

# Создаём мод
add_library(better-editor-unlock SHARED src/main.cpp)

target_link_libraries(better-editor-unlock geode)

set_target_properties(better-editor-unlock PROPERTIES
    PREFIX ""
    SUFFIX ".geode"
    OUTPUT_NAME "better-editor-unlock"
)

# Копируем mod.json
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/mod.json")
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/mod.json"
        "${CMAKE_CURRENT_BINARY_DIR}/mod.json"
        COPYONLY
    )
endif()

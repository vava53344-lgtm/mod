cmake_minimum_required(VERSION 3.15)
project(better-editor-unlock)

# Проверяем SDK
if(NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

set(GEODE_SDK "$ENV{GEODE_SDK}")
message(STATUS "GEODE_SDK: ${GEODE_SDK}")

# Проверяем, какие библиотеки есть
execute_process(COMMAND find ${GEODE_SDK} -name "*.so" -type f
    OUTPUT_VARIABLE SO_FILES
)
message(STATUS "Found .so files: ${SO_FILES}")

# Ищем cpp файлы
file(GLOB SRC_FILES "src/*.cpp")
if(NOT SRC_FILES)
    file(GLOB SRC_FILES "*.cpp")
endif()

if(NOT SRC_FILES)
    message(FATAL_ERROR "No source files found!")
endif()

# Добавляем include пути
include_directories(${GEODE_SDK}/include)

# Создаём библиотеку
add_library(better-editor-unlock SHARED ${SRC_FILES})

# Просто добавляем все .so файлы из SDK
file(GLOB SO_LIBS "${GEODE_SDK}/lib/android64/*.so")
if(SO_LIBS)
    target_link_libraries(better-editor-unlock ${SO_LIBS})
endif()

# Стандартные библиотеки Android
target_link_libraries(better-editor-unlock
    log
    android
    z
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

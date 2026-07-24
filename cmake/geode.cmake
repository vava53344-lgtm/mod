# Geode CMake module

# Check if GEODE_SDK is set
if(NOT GEODE_SDK)
    set(GEODE_SDK "$ENV{GEODE_SDK}")
endif()

if(NOT GEODE_SDK)
    message(FATAL_ERROR "GEODE_SDK not set!")
endif()

# Add Geode include directory
include_directories(${GEODE_SDK}/include)

# Add Geode as a library
add_library(geode INTERFACE)
target_include_directories(geode INTERFACE ${GEODE_SDK}/include)

# Helper function to create a Geode mod
function(add_geode_mod)
    set(options)
    set(oneValueArgs NAME)
    set(multiValueArgs SOURCES)
    cmake_parse_arguments(GEODE_MOD "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT GEODE_MOD_NAME)
        message(FATAL_ERROR "NAME is required")
    endif()

    # Create shared library
    add_library(${GEODE_MOD_NAME} SHARED ${GEODE_MOD_SOURCES})

    # Link Geode
    target_link_libraries(${GEODE_MOD_NAME} geode)

    # Set output name
    set_target_properties(${GEODE_MOD_NAME} PROPERTIES
        PREFIX ""
        SUFFIX ".geode"
        OUTPUT_NAME "${GEODE_MOD_NAME}"
    )

    # Copy mod.json to build directory
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/mod.json")
        configure_file(
            "${CMAKE_CURRENT_SOURCE_DIR}/mod.json"
            "${CMAKE_CURRENT_BINARY_DIR}/mod.json"
            COPYONLY
        )
    endif()

    # Set C++ standard
    target_compile_features(${GEODE_MOD_NAME} PRIVATE cxx_std_17)
endfunction()

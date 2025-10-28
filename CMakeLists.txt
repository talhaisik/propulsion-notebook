cmake_minimum_required(VERSION 3.15)

project(PropulsionNotebook
    VERSION 0.1.0
    DESCRIPTION "Aerospace propulsion and flight systems simulation library"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

# Options
option(BUILD_TESTS "Build unit tests" ON)
option(BUILD_EXAMPLES "Build example programs" ON)

# Add subdirectories
add_subdirectory(lib)

# Add examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Optionally add simulations
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/sims/CMakeLists.txt)
    add_subdirectory(sims)
endif()

# Print summary
message(STATUS "")
message(STATUS "Propulsion Notebook Configuration Summary")
message(STATUS "=========================================")
message(STATUS "  Version:      ${PROJECT_VERSION}")
message(STATUS "  Build type:   ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build tests:  ${BUILD_TESTS}")
message(STATUS "  Build examples: ${BUILD_EXAMPLES}")
message(STATUS "")


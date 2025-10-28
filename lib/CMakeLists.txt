# Propulsion library
add_library(propulsion_lib INTERFACE)

# Set include directories
target_include_directories(propulsion_lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Require C++17
target_compile_features(propulsion_lib INTERFACE cxx_std_17)

# Create alias for consistent usage
add_library(Propulsion::Library ALIAS propulsion_lib)

# Add source files when they exist
# Uncomment and populate as you add implementation files
# set(PROPULSION_SOURCES
#     src/orbital.cpp
#     src/rocket.cpp
# )
# 
# add_library(propulsion_impl STATIC ${PROPULSION_SOURCES})
# target_link_libraries(propulsion_impl PUBLIC propulsion_lib)

# Tests
if(BUILD_TESTS)
    # Uncomment when you add test framework
    # add_subdirectory(tests)
endif()

message(STATUS "Configured propulsion library (header-only for now)")


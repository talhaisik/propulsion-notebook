# Example programs demonstrating library usage

add_executable(basic_calculations basic_calculations.cpp)
target_link_libraries(basic_calculations PRIVATE Propulsion::Library)

# Copy to build directory for easy running
set_target_properties(basic_calculations
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples
)

message(STATUS "Configured example: basic_calculations")


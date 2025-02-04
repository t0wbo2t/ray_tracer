add_executable(r_tracer_demo)

target_sources(r_tracer_demo
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src/ray_tracer_demo.cpp
)

target_compile_options(r_tracer_demo PRIVATE
    -Wall               # Enable all warnings
    -Wextra             # Enable extra warnings
    -O2                 # Optimization level 2
    -march=native        # Optimize for the current architecture
    -ftree-vectorize     # Enable automatic vectorization
)

set_target_properties(r_tracer_demo
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/example"
)

target_link_libraries(r_tracer_demo
    PRIVATE
    RayTracer::rtracer
)

target_include_directories(r_tracer_demo
    PRIVATE
    SDL3::SDL3
)

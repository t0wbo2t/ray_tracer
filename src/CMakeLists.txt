set(SOURCES
    image_handler.cpp
    scene_handler.cpp
    ray_handler.cpp
    camera_handler.cpp
    ray_tracer.cpp
    shapes.cpp
    sphere.cpp
    light_sources.cpp
    point_light.cpp
)

add_library(rtracer
    STATIC
    ${SOURCES}
)

add_library(RayTracer::rtracer
    ALIAS
    rtracer
)

target_include_directories(rtracer
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(rtracer
    PRIVATE
    glm::glm
    SDL3::SDL3
)

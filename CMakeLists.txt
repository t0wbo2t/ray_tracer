cmake_minimum_required(VERSION 3.30)

project(RayTracer
    VERSION 1.0.0
    DESCRIPTION "A Modern C++ Ray Tracer implementation"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

option(SDL_VENDORED "Use Vendored SDL3 Library" OFF)

if(SDL_VENDORED)
    add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

find_package(glm CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(example)

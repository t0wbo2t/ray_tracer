# Ray Tracer

This is a simple ray tracer built using **C++**, **SDL3**, and **GLM**. The project demonstrates how to render a scene with various objects (spheres, cones, etc), handle rays, trace them through a scene, and apply **lighting and shading** for realistic visuals.


## Description

This ray tracer project implements fundamental ray tracing techniques, including:
- **Ray-object intersection**.
- **Lighting models** to simulate realism.
- **Shading techniques** for better surface visualization.
- **Scene handling and camera movement.**
- **Image generation and display using SDL3.**

The rendering engine applies **Phong shading** to enhance the realism of objects in the scene.

## Features

- **Ray Tracing Algorithm**
- **Support for Spheres** (Intersection, Reflection, etc.)
- **Scene Management**
- **Camera Handling**
- **Lighting & Shading:**
- Ambient, Diffuse, and Specular Lighting (**Phong Model**)
- Soft Shadows
- Basic Reflection
- **SDL3 Integration for Display**

## Requirements

To build and run this project, you will need:
- **C++17** or later
- **CMake** (for building)
- **SDL3** (for rendering)
- **GLM** (for mathematical operations)

### Installing Dependencies
- Install **SDL3** from [SDL3 official website](https://github.com/libsdl-org/SDL).
- Install **GLM** from [GLM's GitHub](https://github.com/g-truc/glm).

## Installation

1. Clone the repository:
```bash
git clone https://github.com/t0wbo2t/ray_tracer.git
cd Ray.Tracer
```
2. Install the necessary dependencies (**SDL3** and **GLM**).
3. Create a build directory:
```bash
mkdir build
cd build
```
4. Configure the project using **CMake**:
```bash
cmake ..
```

## Building

Once you have CMake configured, build the project:

1. On Linux/macOS:
```bash
make
```
2. On Windows (using Visual Studio or other tools):
- Open the generated `Ray.Tracer.sln` and build the solution.

## Usage

Once built, run the application with:
```bash
./RayTracer
```

This will load the default scene and display it using SDL3. You can modify the scene configuration in `scene_handler.cpp` or change camera settings in `camera_handler.cpp`.

### Example Demo
To test the demo program with basic lighting and shading:
```bash
./RayTracerDemo
```
This will load a sample scene with **Phong shading, reflections, and soft shadows**.

## License

This project is licensed under the GNU General Public License - see the [LICENSE](LICENSE) file for details.

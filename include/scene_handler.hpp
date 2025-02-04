#ifndef SCENE_HANDLER_HPP
#define SCENE_HANDLER_HPP

#include <vector>
#include <SDL3/SDL.h>
#include "../include/image_handler.hpp"
#include "../include/camera_handler.hpp"
#include "../include/sphere.hpp"

namespace rtx {
  class Scene {
    private:
      rtx::CameraHandler camera;
      rtx::Sphere sphere;
    public:
      Scene();
      bool render(ImageHandler& image);
  };
}

#endif // SCENE_HANDLER_HPP

#ifndef SCENE_HANDLER_HPP
#define SCENE_HANDLER_HPP

#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "../include/image_handler.hpp"
#include "../include/camera_handler.hpp"
#include "../include/point_light.hpp"
#include "../include/sphere.hpp"

namespace rtx {
  class Scene {
    private:
      rtx::CameraHandler camera;
      std::vector<std::shared_ptr<rtx::Shapes>> shapes;
      std::vector<std::shared_ptr<rtx::LightSources>> light_sources;

    public:
      Scene();
      bool render(ImageHandler& image);
  };
}

#endif // SCENE_HANDLER_HPP

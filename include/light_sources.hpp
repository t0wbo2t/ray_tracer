#ifndef LIGHT_SOURCES_HPP
#define LIGHT_SOURCES_HPP

#include <memory>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../include/ray_handler.hpp"
#include "../include/shapes.hpp"

namespace rtx {
  class LightSources {
    public:
      LightSources();
      virtual ~LightSources();

      // Function to compute illumination.
      virtual bool compute_illumination(const glm::dvec3 &intersection_point, const glm::dvec3 &local_normal,
                                        const std::vector<std::shared_ptr<rtx::Shapes>> &shapes,
                                        const std::shared_ptr<rtx::Shapes> &current_shape,
                                        glm::dvec3 &color, double &intensity);

    public:
      glm::dvec3 light_color, light_location;
      double light_intensity;
  };
}

#endif // !LIGHT_SOURCES_HPP

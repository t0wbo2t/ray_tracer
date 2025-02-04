#ifndef RAY_HANDLER_HPP
#define RAY_HANDLER_HPP

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace rtx {
  class RayHandler {
    public:
      RayHandler();
      RayHandler(const glm::dvec3 &_point_ux, const glm::dvec3 &_point_vy);

      glm::dvec3 get_point_ux() const;
      glm::dvec3 get_point_vy() const;

      glm::dvec3 point_ux, point_vy, vector_xy;
  };
}

#endif // RAY_HANDLER_HPP

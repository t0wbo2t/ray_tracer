#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <limits>
#include "../include/ray_handler.hpp"

namespace rtx {
  class Shapes {
    public:
      glm::dvec3 shape_color;

      Shapes();
      virtual ~Shapes();

      virtual bool intersects_with(const RayHandler &ray, glm::dvec3 &int_pt, glm::dvec3 &local_normal, glm::dvec3 &local_color) const;
      bool equal_f(const float f1, const float f2) const;
  };
}
#endif // !SHAPES_HPP

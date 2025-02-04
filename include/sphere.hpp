#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "../include/shapes.hpp"

namespace rtx {
  class Sphere : public Shapes {
    // The default constructor that will define a unit sphere at origin.
    public:
      Sphere();

      virtual ~Sphere() override;
      virtual bool intersects_with(const RayHandler &ray, glm::dvec3 &int_pt, glm::dvec3 &local_normal, glm::dvec3 &local_color) const;
  };
}

#endif 

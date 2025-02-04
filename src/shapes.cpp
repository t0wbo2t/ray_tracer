#include "../include/shapes.hpp"

constexpr double EPS = std::numeric_limits<double>::epsilon();

rtx::Shapes::Shapes() {}

rtx::Shapes::~Shapes() {}

bool rtx::Shapes::intersects_with(const RayHandler &ray, glm::dvec3 &int_pt, glm::dvec3 &local_normal, glm::dvec3 &local_color) const {
  return false;
}

bool rtx::Shapes::equal_f(const float f1, const float f2) const {
  return std::fabs(f1 - f2) < EPS;
}


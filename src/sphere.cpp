#include "sphere.hpp"
#include <cmath>

rtx::Sphere::Sphere() {}

rtx::Sphere::~Sphere() {}

bool rtx::Sphere::intersects_with(const RayHandler &ray, glm::dvec3 &int_pt, glm::dvec3 &local_normal, glm::dvec3 &local_color) const {
  // Compute the values of a, b, and c. [at^2 + bt + c = 0]
  glm::dvec3 v_hat = ray.vector_xy;
  v_hat = glm::normalize(v_hat);

  // a is equal to the squared magnitude of the direction of the ray. [a = 1.0] 
  double b = 2.0 * glm::dot(ray.point_ux, v_hat);

  double c = glm::dot(ray.point_ux, ray.point_ux) - 1.0;

  // Test intersection [b^2 - 4ac > 0]
  double inter_test = (b * b) - 4.0 * c;

  if(inter_test > 0.0) {
    double num_sqrt = std::sqrtf(inter_test);
    double t1 = (-b + num_sqrt) / 2.0;
    double t2 = (-b - num_sqrt) / 2.0;

    // If either t1 or t2 is negative, then at least part of the object
    // is behind the camera and so we ignore it.
    if((t1 < 0.0) || (t2 < 0.0)) {
      return false;
    } else {
      if(t1 < t2) {
        int_pt = ray.point_ux + (v_hat * t1);
      } else {
        int_pt = ray.point_ux + (v_hat * t2);
      }

      local_normal = glm::normalize(int_pt);

      return true;
    }
  } else {
    return false;
  }
}

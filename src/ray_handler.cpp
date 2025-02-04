#include "../include/ray_handler.hpp"

rtx::RayHandler::RayHandler() {
  point_ux = glm::dvec3 {0.0, 0.0, 0.0};
  point_vy = glm::dvec3 {0.0, 0.0, 1.0};
  vector_xy = point_vy - point_ux;
}

rtx::RayHandler::RayHandler(const glm::dvec3 &_point_ux, const glm::dvec3 &_point_vy)
  : point_ux(_point_ux), point_vy(_point_vy) {
    vector_xy = point_vy - point_ux;
}

glm::dvec3 rtx::RayHandler::get_point_ux() const {
  return point_ux;
}

glm::dvec3 rtx::RayHandler::get_point_vy() const {
  return point_vy;
}

#include "../include/point_light.hpp"

rtx::PointLight::PointLight() {
  light_color = glm::dvec3{1.0, 1.0, 1.0};
  light_intensity = 1.0;
}

rtx::PointLight::~PointLight() {}

bool rtx::PointLight::compute_illumination(const glm::dvec3 &intersection_point, const glm::dvec3 &local_normal,
                                        const std::vector<std::shared_ptr<rtx::Shapes>> &shapes,
                                        const std::shared_ptr<rtx::Shapes> &current_shape,
                                        glm::dvec3 &color, double &intensity) {
  
  // Construct a vector pointing from the int_pt to light source
  glm::dvec3 light_direction = glm::normalize(light_location - intersection_point);

  glm::dvec3 start_pt = intersection_point;

  double angle = std::acos(glm::clamp(glm::dot(local_normal, light_direction), -1.0, 1.0));

  // If normal is pointing away from the light [angle > pi/2]
  if(angle > glm::half_pi<double>()) {
    color = light_color;
    intensity = 0.0;

    return false;
  } else {
    color = light_color;
    intensity = light_intensity * (1.0 - (angle / glm::half_pi<double>()));

    return true;
  }
}


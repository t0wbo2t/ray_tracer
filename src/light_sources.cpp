#include "../include/light_sources.hpp"

rtx::LightSources::LightSources() {}
rtx::LightSources::~LightSources() {}

bool rtx::LightSources::compute_illumination(const glm::dvec3 &intersection_point, const glm::dvec3 &local_normal,
                                             const std::vector<std::shared_ptr<rtx::Shapes>> &shapes,
                                             const std::shared_ptr<rtx::Shapes> &current_shape,
                                             glm::dvec3 &color, double &intensity) {
  return false;
}

#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "../include/light_sources.hpp"

namespace rtx {
  class PointLight : public LightSources {
    public:
      PointLight();
      ~PointLight() override;

      virtual bool compute_illumination(const glm::dvec3 &intersection_point, const glm::dvec3 &local_normal,
                                        const std::vector<std::shared_ptr<rtx::Shapes>> &shapes,
                                        const std::shared_ptr<rtx::Shapes> &current_shape,
                                        glm::dvec3 &color, double &intensity) override;
  };
}

#endif // POINT_LIGHT_HPP

#include "../include/scene_handler.hpp"

rtx::Scene::Scene() {
  // Configure the camera
  camera.set_position(glm::dvec3{0.0, -10.0, 0.0});
  camera.set_look_at(glm::dvec3{0.0, 0.0, 0.0});
  camera.set_up(glm::dvec3{0.0, 0.0, 1.0});
  camera.set_screen_width(0.25);
  camera.set_aspect(16.0 / 9.0);
  camera.update_geometry();

  shapes.push_back(std::make_shared<rtx::Sphere>());
  light_sources.push_back(std::make_shared<rtx::PointLight>());
  light_sources.at(0)->light_location = glm::dvec3{5.0, -10.0, -5.0};
  light_sources.at(0)->light_color = glm::dvec3{0xFF, 0xFF, 0xFF};
}

bool rtx::Scene::render(ImageHandler& image) {
  size_t width, height;
  width = image.get_width();
  height = image.get_height();

  // Loop over each pixel in our image.
  rtx::RayHandler camera_ray;
  glm::dvec3 intersection_point;
  glm::dvec3 local_normal;
  glm::dvec3 local_color;

  double scale_x = 1.0 / (static_cast<double>(width) / 2.0);
  double scale_y = 1.0 / (static_cast<double>(height) / 2.0);

  double min_dist = 1e6;
  double max_dist = 0.0;

  for (size_t x = 0; x < width; ++x) {
    for (size_t y = 0; y < height; ++y) {
      // Normalise x and y.
      double x_norm = (static_cast<double>(x) * scale_x) - 1.0;
      double y_norm = (static_cast<double>(y) * scale_y) - 1.0;

      // Geneate ray for this pixel.
      camera.ray_handler(x_norm, y_norm, camera_ray);

      for(auto shape : shapes) {
        bool intersect = shape->intersects_with(camera_ray, intersection_point, local_normal, local_color);

        if(intersect) {
          // Compute intensity
          double intensity;
          glm::dvec3 color;
          bool illumination = false;
          
          for(auto current_light : light_sources) {
            illumination = current_light->compute_illumination(intersection_point, local_normal,
                                                               shapes, shape, color, intensity);
          } 

          // Compute distance between camera and the point of intersection.
          double dist = glm::length(intersection_point - camera_ray.point_ux);
    
          max_dist = std::max(max_dist, dist);
          min_dist = std::min(min_dist, dist);

          if(illumination) {
            image.set_pixel(x, y, 0xFF * intensity, 0.0, 0.0);
          } else {
            image.set_pixel(x, y, 0.0, 0.0, 0.0);
          }
        } else {
          image.set_pixel(x, y, 0.0, 0.0, 0.0);
        }
      }
    }
  }

  return true;
}

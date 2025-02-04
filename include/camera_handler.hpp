#ifndef CAMERA_HANDLER_HPP
#define CAMERA_HANDLER_HPP

#include "../include/ray_handler.hpp"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace rtx {
  class CameraHandler {
    private:
      glm::dvec3 camera_pos;
      glm::dvec3 camera_look_at;
      glm::dvec3 camera_up;
      
      double camera_length;
      double camera_width;
      double camera_aspect;

      glm::dvec3 camera_alignment; // Principle axis of the camera
      glm::dvec3 projection_screen_u;
      glm::dvec3 projection_screen_v;
      glm::dvec3 projection_screen_centre;

    public:
      CameraHandler();

      // Camera Setters
      void set_position(const glm::dvec3 &new_pos);
      void set_look_at(const glm::dvec3 &new_pos);
      void set_up(const glm::dvec3 &new_pos);
      void set_length(const double new_length);     // Distance between projection screen and the camera pinhole.
      void set_screen_width(const double new_width);
      void set_aspect(const double new_aspect);

      // Camera Getters
      glm::dvec3 get_position() const;
      glm::dvec3 get_look_at() const;
      glm::dvec3 get_up() const;
      glm::dvec3 get_vec_u() const;
      glm::dvec3 get_vec_v() const;
      
      glm::dvec3 get_screen_centre() const;
      double get_length() const;
      double get_screen_width() const;
      double get_aspect() const;

      // Function to generate a ray
      bool ray_handler(double point_ux, double point_vy, rtx::RayHandler &camera_ray);     
      void update_geometry();
  };
}

#endif

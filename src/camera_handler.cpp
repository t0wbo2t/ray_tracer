#include "../include/camera_handler.hpp"

rtx::CameraHandler::CameraHandler() {
  camera_pos     = glm::dvec3{0.0, -1.0, 0.0};
  camera_look_at = glm::dvec3{0.0, -1.0, 0.0};
  camera_up      = glm::dvec3{0.0, 0.0, 1.0};
  
  camera_length = 1.0;
  camera_width = 1.0;
  camera_aspect = 1.0;
}


// Camera Setters
void rtx::CameraHandler::set_position(const glm::dvec3 &new_pos) {
  camera_pos = new_pos;
}

void rtx::CameraHandler::set_look_at(const glm::dvec3 &new_pos) {
  camera_look_at = new_pos;
}

void rtx::CameraHandler::set_up(const glm::dvec3 &new_pos) {
  camera_up = new_pos;
}

void rtx::CameraHandler::set_length(const double new_length) {
  camera_length = new_length;
}

void rtx::CameraHandler::set_screen_width(const double new_width) {
  camera_width = new_width;
}

void rtx::CameraHandler::set_aspect(const double new_aspect) {
  camera_aspect = new_aspect;
}


// Camera Getters
glm::dvec3 rtx::CameraHandler::get_position() const {
  return camera_pos;
}

glm::dvec3 rtx::CameraHandler::get_look_at() const {
  return camera_look_at;
}

glm::dvec3 rtx::CameraHandler::get_up() const {
  return camera_up;
}

glm::dvec3 rtx::CameraHandler::get_vec_u() const {
  return projection_screen_u;
}

glm::dvec3 rtx::CameraHandler::get_vec_v() const {
  return projection_screen_v;
}

glm::dvec3 rtx::CameraHandler::get_screen_centre() const {
  return projection_screen_centre;
}

double rtx::CameraHandler::get_length() const {
  return camera_length;
}

double rtx::CameraHandler::get_screen_width() const {
  return camera_width;
}

double rtx::CameraHandler::get_aspect() const {
  return camera_aspect;
}

void rtx::CameraHandler::update_geometry() {
  // Compute the vector from the camera position to the LookAt position.
  camera_alignment = camera_look_at - camera_pos;
  camera_alignment = glm::normalize(camera_alignment);

  // Compute u and v vector of the projection (virtual) screen.
  projection_screen_u = glm::cross(camera_alignment, camera_up); 
  projection_screen_u = glm::normalize(projection_screen_u);

  projection_screen_v = glm::cross(projection_screen_u, camera_alignment);
  projection_screen_v = glm::normalize(projection_screen_v);

  // Compute the centre point of the projection screen.
  // Starting from the position of the camera, we just move in the direction of the alignment vector.

  projection_screen_centre = camera_pos + (camera_length * camera_alignment);

  // Modification: u and v vectors to match size and aspect ratio.
  projection_screen_u = projection_screen_u * camera_width;
  projection_screen_v = projection_screen_v * (camera_width / camera_aspect);
}

// Function to generate a ray
bool rtx::CameraHandler::ray_handler(double point_ux, double point_vy, rtx::RayHandler &camera_ray) {
  // Compute the location of the screen point in world coordinate.
  glm::dvec3 screen_world = projection_screen_centre + (projection_screen_u * point_ux)
                            + (projection_screen_v * point_vy);
  
  // Use this point along with the camera position to compute the ray.
  camera_ray.point_ux = camera_pos;
  camera_ray.point_vy = screen_world;
  camera_ray.vector_xy = screen_world- camera_pos;

  return true;
}

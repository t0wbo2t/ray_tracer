#ifndef RAY_TRACER_HPP
#define RAY_TRACER_HPP

#include <SDL3/SDL.h>
#include "../include/scene_handler.hpp"
#include "../include/camera_handler.hpp"

class RayTracer {
  public:
    RayTracer();

    int on_execute();
    bool on_init();
    void on_event(SDL_Event *event);
    void on_loop();
    void on_render();
    void on_exit();

  private:
    ImageHandler image_handler;
    rtx::Scene scene_handler;

    bool is_active;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    void print_vector(const glm::dvec3& vec) const;
};

#endif

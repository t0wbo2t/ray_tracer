#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>
#include "../include/ray_tracer.hpp"

RayTracer::RayTracer() {
  is_active = true;
  window = nullptr;
  renderer = nullptr;
}

bool RayTracer::on_init() {
  if(!SDL_Init(SDL_INIT_EVENTS)) {
    return false;
  }

  window = SDL_CreateWindow("Simple Ray Tracer", 1280, 720, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);

  if(window != nullptr) {
    renderer = SDL_CreateRenderer(window, nullptr);
    image_handler.render_image(1280, 720, renderer);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    scene_handler.render(image_handler);
    image_handler.display_image();

    SDL_RenderPresent(renderer);

  } else {
    return false;
  }

  return true;
}
 
int RayTracer::on_execute() {
  SDL_Event event;
  
  if(on_init() == false){
    return -1;
  }

  while(is_active) {
    while(SDL_PollEvent(&event)) {
      on_event(&event);
    }

    on_loop();
    on_render();
  }

  on_exit();
  return 0;
}

void RayTracer::on_event(SDL_Event *event) {
  if(event->type == SDL_EVENT_QUIT) {
    is_active = false;
  }
}

void RayTracer::on_render() {
  // Set background colour to White.
  // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // SDL_RenderClear(renderer);

  // scene_handler.render(image_handler);
  // image_handler.display_image();

  // SDL_RenderPresent(renderer);
}

void RayTracer::on_loop(){}

void RayTracer::on_exit() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  window = nullptr;
  SDL_Quit();
}

void RayTracer::print_vector(const glm::dvec3& vec) const {
  std::cout << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
}

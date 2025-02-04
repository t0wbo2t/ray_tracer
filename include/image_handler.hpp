#ifndef IMAGE_HANDLER_HPP
#define IMAGE_HANDLER_HPP 

#include <string>
#include <vector>
#include <SDL3/SDL.h>

class ImageHandler {
  private:
    size_t image_width, image_height;

    SDL_Renderer* image_renderer = nullptr;
    SDL_Texture* image_texture = nullptr;
    
    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;

    uint32_t convert_color(const double red, const double green, const double blue);
    void init_texture();


  public:
    ImageHandler();
    ~ImageHandler();
    
    void render_image(const size_t width, const size_t height, SDL_Renderer* renderer);
    void set_pixel(const size_t x, const size_t y, const double red, const double green, const double blue);
    void display_image();
    size_t get_width() const;
    size_t get_height() const;
};

#endif

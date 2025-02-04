#include "../include/image_handler.hpp"

ImageHandler::ImageHandler() {
  image_width = 0;
  image_height = 0;
  image_renderer = nullptr;
  image_texture = nullptr;
}

ImageHandler::~ImageHandler() {
  if(image_texture) {
    SDL_DestroyTexture(image_texture);
  }
}

void ImageHandler::render_image(const size_t width, const size_t height, SDL_Renderer* renderer){
  m_rChannel.resize(width, std::vector<double>(height, 0.0));
  m_gChannel.resize(width, std::vector<double>(height, 0.0));
  m_bChannel.resize(width, std::vector<double>(height, 0.0));

  image_width = width;
  image_height = height;
  image_renderer = renderer;

  init_texture();
}

size_t ImageHandler::get_width() const {
  return image_width;
}

size_t ImageHandler::get_height() const {
  return image_height;
}

void ImageHandler::set_pixel(const size_t x, const size_t y, const double red, const double green, const double blue){
  m_rChannel.at(x).at(y) = red;
  m_gChannel.at(x).at(y) = green;
  m_bChannel.at(x).at(y) = blue;
}

void ImageHandler::display_image() {
  uint32_t* temp_pixels = new uint32_t[image_width * image_height];
  memset(temp_pixels, 0, image_width * image_height * sizeof(uint32_t));

  for(size_t x = 0; x < image_width; ++x) {
    for(size_t y = 0; y < image_height; ++y) {
      temp_pixels[(y * image_width) + x] = convert_color(m_rChannel.at(x).at(y), m_gChannel.at(x).at(y), m_bChannel.at(x).at(y));
    }
  }

  SDL_UpdateTexture(image_texture, nullptr, temp_pixels, image_width * sizeof(uint32_t));
  delete[] temp_pixels;

  SDL_FRect rectangle, container;
  rectangle.x = 0.0;
  rectangle.y = 0.0;
  rectangle.w = image_width;
  rectangle.h = image_height;

  container = rectangle;

  SDL_RenderTexture(image_renderer, image_texture, &rectangle, &container);
}

void ImageHandler::init_texture() {
  if(image_texture) {
    SDL_DestroyTexture(image_texture);
  }

  SDL_Surface* temp_surface = SDL_CreateSurface(image_width, image_height, SDL_PIXELFORMAT_RGBA8888);
  if(temp_surface) {
    image_texture = SDL_CreateTextureFromSurface(image_renderer, temp_surface);
    SDL_DestroySurface(temp_surface);
  }
}

uint32_t ImageHandler::convert_color(const double red, const double green, const double blue) {
  unsigned char r = static_cast<unsigned char>(red);
  unsigned char g = static_cast<unsigned char>(green);
  unsigned char b = static_cast<unsigned char>(blue);

  uint32_t pixel_color = 0;

  #if SDL_BYTEORDER == SDL_BIG_ENDIAN
    pixel_color = (b << 24) + (g << 16) + (r << 8) + 0xFF;
  #else
    pixel_color = (0xFF << 24) + (r << 16) + (g << 8) + b;
  #endif

  return pixel_color;
}

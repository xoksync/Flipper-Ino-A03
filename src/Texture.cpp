#include "Texture.hpp"

Texture::Texture::Texture(const uint8_t bytes_array[], const uint8_t width, const uint8_t height) noexcept
  : __bytes_array {bytes_array}
{
  this->setHeight(height);
  this->setWidth(width);
}

void Texture::__draw(const U8GLIB_SSD1306_128X64 *u8g) const noexcept
{
  u8g->drawBitmapP(this->getX(), this->getY(), this->getWidth() / 8, this->getHeight(), this->__bytes_array);
}

Texture::~Texture() noexcept
{

}
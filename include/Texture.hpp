#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#pragma once

#include "Drawable.hpp"
#include "Transformable.hpp"

class Texture : public Drawable, public Transformable
{
  public:
    Texture(const uint8_t bytes_array[], const uint8_t, const uint8_t) noexcept;
    ~Texture() noexcept;
  private:
    void __draw(const U8GLIB_SSD1306_128X64 *u8g) const noexcept override;
    
    uint8_t *__bytes_array;
};

#endif
#ifndef TEXT_HPP
#define TEXT_HPP

#pragma once

#include "Drawable.hpp"
#include "Transformable.hpp"

class Text : public Drawable, public Transformable
{
  public:
    Text(const char[], const uint8_t, const uint8_t) noexcept;
    ~Text() noexcept;
  private:
    const char *__text;

    void __draw(const U8GLIB_SSD1306_128X64*) const noexcept override;
};

#endif
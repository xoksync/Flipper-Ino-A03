#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#pragma once

#include <U8glib.h>

#include "Drawable.hpp"

class Display
{
  public:
    Display() noexcept;

    void create() noexcept;
    void draw(const Drawable&) const noexcept;
    void firstPage() noexcept;
    const int nextPage() noexcept;

    ~Display() noexcept;
  private:
    U8GLIB_SSD1306_128X64 *__u8g;
};

#endif
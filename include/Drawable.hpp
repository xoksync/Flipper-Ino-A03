#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#pragma once

#include <U8glib.h>

class Drawable
{
  public:
    virtual ~Drawable() noexcept = default;

    friend class Display;
  private:
    virtual void __draw(const U8GLIB_SSD1306_128X64*) const noexcept = 0;
};

#endif
#ifndef OPTION_HPP
#define OPTION_HPP

#pragma once

#include <Arduino.h>

#include "Drawable.hpp"
#include "Transformable.hpp"
#include "Config.hpp"

namespace Menu
{
  class Option : public Drawable, public Transformable
  {
  public:
    Option() noexcept;
    Option(const String&, const uint8_t[], const uint8_t = OPTION_MARGIN_LEFT, const uint8_t = 0) noexcept;
    Option(const String&, const uint8_t[], void (*on_click)(void), const uint8_t = OPTION_MARGIN_LEFT, const uint8_t = 0) noexcept;

    void setTitle(const String &) noexcept;
    void setIconBitMap(const uint8_t[]) noexcept;

    const String &getTitle() const noexcept;
    void click() noexcept;
    const uint8_t *getIconBitMap() const noexcept;

    ~Option() noexcept;
  private:
    String __title;
    uint8_t *__icon_bitmap;
    void (*__on_click)(void);

    void __draw(const U8GLIB_SSD1306_128X64*) const noexcept override;
  };
};


#endif
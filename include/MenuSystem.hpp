#ifndef MENUSYSTEM_HPP
#define MENUSYSTEM_HPP

#pragma once

#include <Vector.h>

#include "Option.hpp"
#include "Page.hpp"
#include "Display.hpp"
#include "Config.hpp"

class MenuSystem : public Drawable
{
  public:
    MenuSystem() noexcept;
    MenuSystem(Display*) noexcept;

    void addOption(Menu::Option) noexcept;
    void setDisplay(Display*) noexcept;
    void moveCursor(uint8_t) noexcept;
    void click() noexcept;

    ~MenuSystem() noexcept;
  private:
    void __draw(const U8GLIB_SSD1306_128X64*) const noexcept override;

    Menu::Option __storage[MAX_OPTIONS_BY_MENU];
    Display *__display;
    Vector<const Menu::Option> __options;
    mutable uint8_t __cursor_index, __options_y_offset;
};

#endif

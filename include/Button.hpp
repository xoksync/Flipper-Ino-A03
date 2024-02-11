#ifndef BUTTON_HPP
#define BUTTON_HPP

#pragma once

#include <Arduino.h>

class Button
{
  public:
    Button() noexcept;
    Button(const int) noexcept;

    void setPin(const int) noexcept;
    void handle() noexcept;
    void setup() noexcept;
    const bool isPressed() noexcept;

    ~Button() noexcept;
  private:
    unsigned int __pin, __stat, __is_clicked;
    bool __is_pressed;
};

#endif

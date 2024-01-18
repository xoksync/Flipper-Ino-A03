#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP

#pragma once

#include <Arduino.h>

class Transformable
{
  public:
    Transformable() noexcept;
    Transformable(const uint8_t, const uint8_t, const uint8_t, const uint8_t) noexcept;

    void setX(const uint8_t) noexcept;
    void setY(const uint8_t) noexcept;
    void setWidth(const uint8_t) noexcept;
    void setHeight(const uint8_t) noexcept;


    const uint8_t &getX() const noexcept;
    const uint8_t &getY() const noexcept;
    const uint8_t &getWidth() const noexcept;
    const uint8_t &getHeight() const noexcept;

    ~Transformable() noexcept;
  private:
    uint8_t __x, __y, __width, __height;
};

#endif
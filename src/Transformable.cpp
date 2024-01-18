#include "Transformable.hpp"

Transformable::Transformable() noexcept
{
  this->setX(0);
  this->setY(0);
  this->setHeight(12);
  this->setWidth(12);
}
Transformable::Transformable(const uint8_t x, const uint8_t y, const uint8_t width, const uint8_t height) noexcept
{
  this->setX(x);
  this->setY(y);
  this->setWidth(width);
  this->setHeight(height);
}

void Transformable::setX(const uint8_t x) noexcept
{
  this->__x = x;
}
void Transformable::setY(const uint8_t y ) noexcept
{
  this->__y = y;
}
void Transformable::setWidth(const uint8_t width) noexcept
{
  this->__width = width;
}
void Transformable::setHeight(const uint8_t height) noexcept
{
  this->__height = height;
}

const uint8_t &Transformable::getX() const noexcept
{
  return this->__x;
}
const uint8_t &Transformable::getY() const noexcept
{
  return this->__y;
}
const uint8_t &Transformable::getWidth() const noexcept
{
  return this->__width;
}
const uint8_t &Transformable::getHeight() const noexcept
{
  return this->__height;
}

Transformable::~Transformable() noexcept
{
}
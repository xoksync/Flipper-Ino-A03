#include "Text.hpp"

Text::Text(const char text[], const uint8_t x, const uint8_t y) noexcept
  : __text {text}
{
  this->setX(x);
  this->setY(y);
}

void Text::__draw(const U8GLIB_SSD1306_128X64 *u8g) const noexcept
{
  u8g->drawStr(this->getX(), this->getY(), this->__text);
}

Text::~Text()
{
}
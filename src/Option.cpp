#include "Option.hpp"

#include <U8glib.h>
#include "Config.hpp"

using namespace Menu;

Option::Option() noexcept
{
  this->setTitle("<undefined>");
  this->__on_click = []()->void{};
}
Option::Option(const String &title, const uint8_t icon_bitmap[], const uint8_t x, const uint8_t y) noexcept
{
  this->setTitle(title);
  this->setIconBitMap(icon_bitmap);
  this->setX(x);
  this->setY(y);
  this->__on_click = []()->void{};
}
Option::Option(const String &title, const uint8_t icon_bitmap[], void (*on_click)(void), const uint8_t x, const uint8_t y) noexcept
  : Option(title, icon_bitmap, x, y)
{
  this->__on_click = on_click;
}

const String &Option::getTitle() const noexcept
{
  return this->__title;
}
const uint8_t *Option::getIconBitMap() const noexcept
{
  return this->__icon_bitmap;
}
void Option::setTitle(const String &title) noexcept
{
  this->__title = title;
}
void Option::click() noexcept
{
  delay(250);
  this->__on_click();
}
void Option::setIconBitMap(const uint8_t icon_bitmap[]) noexcept
{
  this->__icon_bitmap = icon_bitmap;
}

Option::~Option() noexcept
{
}

void Option::__draw(const U8GLIB_SSD1306_128X64 *u8g) const noexcept
{
  u8g->drawStr(this->getX() + this->getWidth() + TEXT_MARGIN_LEFT, this->getY() + this->getHeight() / 2 + TEXT_MARGIN_TOP, this->getTitle().c_str());
  u8g->drawBitmapP(this->getX(), this->getY(), this->getWidth() / 6, this->getHeight(), this->__icon_bitmap);
}
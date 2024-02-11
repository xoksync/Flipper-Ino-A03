#include "Display.hpp"

#include "Config.hpp"

Display::Display() noexcept
{
}

void Display::create() noexcept
{
  this->__u8g = new DISPLAY_INSTANCE(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST);
  this->__u8g->setColorIndex(1);
  this->__u8g->setFont(FONT_INSTANCE);
}
void Display::draw(const Drawable &drawable) const noexcept
{
  drawable.__draw(this->__u8g);
}
void Display::firstPage() noexcept
{
  this->__u8g->firstPage();
}
const int Display::nextPage() noexcept
{
  return this->__u8g->nextPage();
}

Display::~Display() noexcept
{
  delete this->__u8g;
}

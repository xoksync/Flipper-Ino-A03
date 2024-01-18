#include "MenuSystem.hpp"

#include "Text.hpp"

MenuSystem::MenuSystem() noexcept
  : __cursor_index {1}, __options_y_offset {0}
{
  this->__options.setStorage(this->__storage);
  this->__options.clear();
}
MenuSystem::MenuSystem(Display *display) noexcept
  : MenuSystem()
{
  this->setDisplay(display);
}

void MenuSystem::addOption(Menu::Option option) noexcept
{
  this->__options.push_back(option);
}

void MenuSystem::moveCursor(uint8_t direction) noexcept
{
  this->__cursor_index += direction;
  if((this->__cursor_index > this->__options.size()) && (this->__options_y_offset == 0))
  {
    this->__cursor_index -= direction;
  }
  if(this->__cursor_index > MAX_OPTIONS_BY_PAGE)
  {
    this->__cursor_index = MAX_OPTIONS_BY_PAGE;
    this->__options_y_offset += (this->__cursor_index + this->__options_y_offset) < this->__options.size() ? direction : 0;
  }
  if(this->__cursor_index < 1)
  {
    this->__cursor_index = 1;
    this->__options_y_offset += this->__options_y_offset > 0 ? direction : 0;
  }
}
void MenuSystem::click() noexcept
{
  this->__options.at(this->__options_y_offset + this->__cursor_index - 1).click();
}
void MenuSystem::setDisplay(Display *display) noexcept
{
  this->__display = display;
}

MenuSystem::~MenuSystem() noexcept
{
}

void MenuSystem::__draw(const U8GLIB_SSD1306_128X64 *U8G) const noexcept
{
  const uint8_t OPTION_HEIGHT = (DISPLAY_HEIGHT / MAX_OPTIONS_BY_PAGE + OPTIONS_GAP);
  this->__display->draw(Text("->", 0, OPTION_HEIGHT * this->__cursor_index - CURSOR_MARGIN_BOTTOM));
  
  for(int i = this->__options_y_offset; i < MAX_OPTIONS_BY_PAGE + this->__options_y_offset; i++)
  {
    if(i > this->__options.size() - 1)
      break;
    this->__options.at(i).setY(OPTION_HEIGHT * (i - this->__options_y_offset));
    this->__display->draw(this->__options.at(i));
  }
}
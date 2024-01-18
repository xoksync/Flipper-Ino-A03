#include "Button.hpp"

Button::Button() noexcept
  : __pin {0}, __is_pressed {false}
{
}
Button::Button(const int pin)
  : __is_pressed {false}
{
  this->setPin(pin);
}

void Button::setPin(const int pin) noexcept
{
  this->__pin = pin;
}
void Button::handle() noexcept
{
  this->__stat = digitalRead(this->__pin);
  if ((digitalRead(this->__pin) == LOW) && (this->__is_clicked == 0)) {
    this->__is_clicked = 1;
  }
  if ((digitalRead(this->__pin) == HIGH) && (this->__is_clicked == 1)) { 
    this->__is_clicked = 0;
  }
}
void Button::setup() noexcept
{
  pinMode(this->__pin, INPUT_PULLUP);
}
const bool Button::isPressed() noexcept
{
  this->handle();
  return this->__is_clicked;
}

Button::~Button()
{
}
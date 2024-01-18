#include "Page.hpp"

Page::Page() noexcept
{
}
Page::Page(void (*loop)(), void (*setup)()) noexcept
{
  this->create(loop, setup);
}

void Page::create(void (*loop)(), void (*setup)()) noexcept
{
  this->loop = loop;
  this->setup = setup;
}

Page::~Page() noexcept
{
}
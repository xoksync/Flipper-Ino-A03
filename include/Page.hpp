#ifndef PAGE_HPP
#define PAGE_HPP

#pragma once

class Page final
{
  public:
    Page() noexcept;
    Page(void (*loop)(), void (*setup)()) noexcept;

    void create(void (*loop)(), void (*setup)() = []()->void{}) noexcept;

    ~Page() noexcept;

    void (*loop)();
    void (*setup)();
};

#endif
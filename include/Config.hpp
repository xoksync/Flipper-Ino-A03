#ifndef CONFIG_HPP
#define CONFIG_HPP

#pragma once

#include <Arduino.h>

#define FIRMWARE_NAME "Flipper-Nano"
#define FIRMWARE_VERSION 0x001
#define DISPLAY_INSTANCE U8GLIB_SSD1306_128X64
#define FONT_INSTANCE u8g_font_6x12
#define TEXT_MARGIN_TOP 4
#define TEXT_MARGIN_LEFT 6
#define OPTION_MARGIN_LEFT 14
#define FONT_HEIGHT 12
#define MAX_OPTIONS_BY_PAGE 5
#define MAX_OPTIONS_BY_MENU 7
#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 128
#define OPTIONS_GAP 1
#define CURSOR_MARGIN_BOTTOM 3

#define BASIC_CURSOR_MOVEMENT(up, down, enter, menu) \
    if(down.isPressed())\
			menu.moveCursor(1);\
		if(up.isPressed())\
			menu.moveCursor(-1);\
		if(enter.isPressed())\
			menu.click();

#endif
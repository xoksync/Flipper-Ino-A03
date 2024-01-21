#include <U8glib.h>
#include <Adafruit_Sensor.h> //INCLUSÃO DE BIBLIOTECA
#include <Adafruit_BMP280.h>

#include "Option.hpp"
#include "Display.hpp"
#include "Config.hpp"
#include "Images.hpp"
#include "Texture.hpp"
#include "Text.hpp"
#include "Page.hpp"
#include "MenuSystem.hpp"
#include "Button.hpp"

Display display;
uint32_t system_running_tick;
Button down(4), up(6), enter(5);
MenuSystem menu_system_home, menu_system_tools;
Page *current_page;
Adafruit_BMP280 bmp;

namespace Pages
{ Page home, tools, about, bitcoin, temperature; };

void boot_system() noexcept
{
	display.firstPage(); do {
		display.draw(Texture(SPLASH_SCREEN_BOOT, 128, 64));
	} while( display.nextPage() );

	while(!bmp.begin(0x76)) { delay(100); }

	down.setup();
	up.setup();
	enter.setup();

	delay(2000);
}
void switchPage(Page &page) noexcept
{
	current_page = &page;
}

void setup(void)
{
	display.create();
	switchPage(Pages::home);
	boot_system();

	menu_system_home.setDisplay(&display);
	menu_system_home.addOption(Menu::Option("Tools", ICON_TOOLS, []()->void{switchPage(Pages::tools);}));
	menu_system_home.addOption(Menu::Option("Setting", ICON_SETTING));
	menu_system_home.addOption(Menu::Option("Pluggins", ICON_PLUGGIN));
	menu_system_home.addOption(Menu::Option("Clock Mode", ICON_CLOCK));
	menu_system_home.addOption(Menu::Option("Wi-Fi", ICON_WIFI));
	menu_system_home.addOption(Menu::Option("Encrypt", ICON_ENCRYPT));
	menu_system_home.addOption(Menu::Option("About", ICON_ABOUT,  []()->void{switchPage(Pages::about);}));

	menu_system_tools.setDisplay(&display);
	menu_system_tools.addOption(Menu::Option("Bad USB", ICON_SCRIPT));
	menu_system_tools.addOption(Menu::Option("Wi-Fi Spam", ICON_SCRIPT));
	menu_system_tools.addOption(Menu::Option("DAUTHER", ICON_SCRIPT));
	menu_system_tools.addOption(Menu::Option("Temperature", ICON_SCRIPT, []()->void{switchPage(Pages::temperature);}));
	menu_system_tools.addOption(Menu::Option("Bitcoin Wallet", ICON_SCRIPT, []()->void{switchPage(Pages::bitcoin);}));
	menu_system_tools.addOption(Menu::Option("Back", ICON_BACK, []()->void{switchPage(Pages::home);}));

	Pages::bitcoin.create([]()->void{
		display.firstPage(); do {
			display.draw(Texture(PLEASE_DONT_SEND_BITCOIN, 128, 64));
		} while( display.nextPage() );
		if(enter.isPressed()){ delay(250); switchPage(Pages::tools); }
	});

	Pages::temperature.create([]()->void{
		display.firstPage(); do {
			display.draw(Text(("Temp: " + String(bmp.readTemperature()) + " *C").c_str(), 12, 12));
			display.draw(Text(("Pres: " + String(bmp.readPressure()) + " ").c_str(), 12, 12 * 2));
			display.draw(Text(("Alti: " + String(bmp.readAltitude(1013.25)) + "m").c_str(), 12, 12 * 3));
		} while( display.nextPage() );
		if(enter.isPressed()){ delay(250); switchPage(Pages::tools); }
	});

	Pages::tools.create([]()->void {
		BASIC_CURSOR_MOVEMENT(up, down, enter, menu_system_tools);
		display.firstPage(); do {
			display.draw(menu_system_tools);
		} while( display.nextPage() );
	});

	Pages::about.create([]()->void {
		static int t = 5;
		display.firstPage(); do {
			display.draw(Text("Created by X-okSync", 0, 12));
			display.draw(Text("Pay me a coffee... pls", 0, 12 * 2));
			display.draw(Text(("Exting " + String(t) + "...").c_str(), 0, 12 * 5));
		} while( display.nextPage() );
		delay(1000);
		if(t-- == 1)
		{
			t = 5;
			switchPage(Pages::home);
		}
	});
	
	Pages::home.create([]()->void {
		BASIC_CURSOR_MOVEMENT(up, down, enter, menu_system_home);
		display.firstPage(); do {
			display.draw(menu_system_home);
		} while( display.nextPage());
	});
}

void loop(void)
{
  current_page->loop();
	delay(1000 / 30);
}


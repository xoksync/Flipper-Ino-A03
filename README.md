# Flipper-Ino-A03 - 0.0.1b

## Support Me At
- `bitcoin`: bc1q0dl24vs9w3rkpwplc9wwlhh0qpglu26esw3mrq
  
## What is it?
A firmware to simulate gadget cybersecurity; it's only for study purposes, but you can do real functions using modules like BMP280 with it.
This is an experimental project, it is in the early stages, and I intend to improve it so that we can work with cybersecurity in an inexpensive and comprehensive manner.

## Requirements To Compile
- U8glib [by oliver]
- Vector [by Peter Polidoro]
- arduino-cli [by Arduino] (mandatory)
- Adafruit_BMP280
- Adafruit_Sensor

## Compiling for Arduino Nano ATmega328P (Windows 10)
```shell
arduino-cli.exe compile -b arduino:avr:nano -p COM3 --clean --library .\include\ --upload --build-property build.extra_flags=-O3 --build-property build.extra_flags=-DNDEBUG --build-property build.extra_flags=-s
```

## If You Want to Convert Pixel Art Image, 12x12 or 128x64, to CPP array
- [Image2CPP](https://javl.github.io/image2cpp/)
- [Create Pixel Art](https://www.piskelapp.com/)

## Screenshots
![Screenshot 1](screenshots/1.jpg)
![Screenshot 2](screenshots/2.jpg)
![Screenshot 3](screenshots/3.jpg)

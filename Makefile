all:
	arduino-cli compile -b arduino:avr:nano -p /dev/ttyUSB0 --clean --library ./include --upload --build-property build.extra_flags=-O3 --build-property build.extra_flags=-DNDEBUG --build-property build.extra_flags=-s

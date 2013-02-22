all:
	gcc -Wall ../easyinput.cpp -o easyinput -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/lib/avr/include -I /usr/share/arduino/hardware/arduino/variants/standard

test:
	gcc -D TEST -Wall easyinput_test.cpp ../easyinput.cpp -o easyinput_test && ./easyinput_test

.PHONY:	all test

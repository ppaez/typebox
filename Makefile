all:
	gcc -Wall control.c -o control -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/lib/avr/include -I /usr/share/arduino/hardware/arduino/variants/standard

test:
	gcc -D TEST -Wall control_test.c control.c -o control_test && ./control_test

.PHONY:	all test

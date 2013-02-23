#include <stdio.h>

#include "easyinput.h"

#ifdef TEST
#  include "tests/easyinput_test.h"
#else
#  include <Arduino.h>
#endif

#define CLOCK  8
#define DATA   9
#define BUSY  10

void init_easyinput() {
 pinMode(CLOCK, OUTPUT);
 pinMode(DATA, INPUT);
 pinMode(BUSY, INPUT);
 digitalWrite(CLOCK, HIGH);
 digitalWrite(DATA, LOW);
 digitalWrite(BUSY, LOW);
}

int two_chars_to_byte(char * two_chars) {
 int byte;

 sscanf( two_chars, "%x", &byte );
 return byte;
}

int get_bit(int byte, int n) {
 return (byte & 1 << n) != 0;
}

void shift_out_bit( int bit) {
 while (digitalRead(BUSY)) {
  delayMicroseconds(5);
 }
 pinMode(DATA, OUTPUT);
 digitalWrite(DATA, bit);
 delayMicroseconds(5);
 digitalWrite(CLOCK, LOW);
 while (!digitalRead(BUSY)) {
  delayMicroseconds(5);
 }
 digitalWrite(CLOCK, HIGH);
}

int shift_in_bit() {
 int bit;
 while (digitalRead(BUSY)) {
  delayMicroseconds(5);
 }
 pinMode(DATA, INPUT);
 digitalWrite(CLOCK, LOW);
 while (!digitalRead(BUSY)) {
  delayMicroseconds(5);
 }
 bit = digitalRead(DATA);
 digitalWrite(CLOCK, HIGH);
 while (digitalRead(BUSY)) {
  delayMicroseconds(5);
 }
 return bit;
}


void transfer_packet(int key_byte, int modifier_byte) {
 int i;
 for (i=0; i<8; i++) shift_out_bit(get_bit(key_byte, i));
 for (i=0; i<8; i++) shift_out_bit(get_bit(modifier_byte, i));
 for (i=0; i<3; i++) shift_out_bit(0);
 for (i=0; i<6; i++) shift_in_bit();
}

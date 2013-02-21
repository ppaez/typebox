#include <stdio.h>

#include "control.h"
#include "control_test.h"

#define CLOCK  8
#define DATA   9
#define BUSY  10

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
  delay(1);
 }
 pinMode(DATA, OUTPUT);
 digitalWrite(DATA, bit);
 delay(1);
 digitalWrite(CLOCK, LOW);
 while (!digitalRead(BUSY)) {
  delay(1);
 }
 digitalWrite(CLOCK, HIGH);
 while (digitalRead(BUSY)) {
  delay(1);
 }
 pinMode(DATA, INPUT);
 digitalWrite(DATA, LOW);
}

void shift_in_bit() {
 int bit;
 while (digitalRead(BUSY)) {
  delay(1);
 }
 pinMode(DATA, INPUT);
 digitalWrite(CLOCK, LOW);
 while (!digitalRead(BUSY)) {
  delay(1);
 }
 bit = digitalRead(DATA);
 digitalWrite(CLOCK, HIGH);
 while (digitalRead(BUSY)) {
  delay(1);
 }
}


void transfer_packet(int key_byte, int modifier_byte) {
 int bit = 0;
 int i;
 for (i=0; i<8; i++) shift_out_bit(get_bit(key_byte, i));
 for (i=0; i<8; i++) shift_out_bit(get_bit(modifier_byte, i));
 for (i=0; i<3; i++) shift_out_bit(0);
 for (i=0; i<6; i++) shift_in_bit();
}

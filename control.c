#include <stdio.h>

#include "control.h"
#include <Arduino.h>

#define CLOCK  8
#define DATA   9
#define BUSY  10

int two_chars_to_byte(char * two_chars) {
 int byte;

 sscanf( two_chars, "%x", &byte );
 return byte;
}

void shift_out_bit( int bit) {
 pinMode(DATA, OUTPUT);
 digitalWrite(DATA, bit);
 // wait
 digitalWrite(CLOCK, LOW);
 digitalWrite(CLOCK, HIGH);
}

void shift_in_bit( int bit) {
 pinMode(8, bit);
 digitalRead(8);
}


void transfer_packet(int key_byte, int modifier_byte) {
 int bit = 0;
 int i;
 for (i=0; i++; i<19) shift_out_bit(bit);
 for (i=0; i++; i<6) shift_in_bit(bit);
}

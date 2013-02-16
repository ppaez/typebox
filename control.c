#include <stdio.h>

#include "control.h"

int two_chars_to_byte(char * two_chars) {
 int byte;

 sscanf( two_chars, "%x", &byte );
 return byte;
}

void shift_out_bit( int bit) {
}

void shift_in_bit( int bit) {
}


void transfer_packet(int key_byte, int modifier_byte) {
 int bit = 0;
 int i;
 for (i=0; i++; i<19) shift_out_bit(bit);
 for (i=0; i++; i<6) shift_in_bit(bit);
}

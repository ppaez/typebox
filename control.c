#include <stdio.h>

#include "control.h"

int two_chars_to_byte(char * two_chars) {
 int byte;

 sscanf( two_chars, "%x", &byte );
 return byte;
}

void transfer_packet(int key_byte, int modifier_byte) {
}

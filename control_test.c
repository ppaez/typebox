#include <assert.h>
#include <stdbool.h>

#include "control.h"

static void test_two_chars_to_byte() {
 int byte;
 byte = two_chars_to_byte("31");
 assert( byte == 49 && "test_two_chars_to_byte" );
}

static void test_transfer_packet() {
 int key_byte = 49, modifier_byte = 0;
 int shift_out_bit_ncalled = 0;
 int shift_in_bit_ncalled = 0;
 transfer_packet(key_byte, modifier_byte);
 assert(shift_out_bit_ncalled == 19 && "test_transfer_packet");
 assert(shift_in_bit_ncalled == 6 && "test_transfer_packet");
}

int main(void) {
 test_two_chars_to_byte();
 test_transfer_packet();
 return(0);
}

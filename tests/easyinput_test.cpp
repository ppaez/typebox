#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "../easyinput.h"

int pinMode_ncalled = 0;
int digitalWrite_ncalled = 0;
int digitalRead_ncalled = 0;

void pinMode(uint8_t pin, uint8_t mode) {
 pinMode_ncalled++;
}

void digitalWrite(uint8_t pin, uint8_t value) {
 digitalWrite_ncalled++;
}

int digitalRead(uint8_t pin) {
 digitalRead_ncalled++;
 return digitalRead_ncalled % 2;
}

void delay(unsigned long miliseconds) {
}

void delayMicroseconds(unsigned long microseconds) {
}

void test_init_easyinput() {
 init_easyinput();
 assert( 1 && "test_init_easyinput");
}

static void test_two_chars_to_byte() {
 char two_chars[3] = "31";
 int byte;
 pinMode_ncalled = 0;
 digitalWrite_ncalled = 0;
 byte = two_chars_to_byte(two_chars);
 assert( byte == 49 && "test_two_chars_to_byte" );
}

void test_get_bit() {
 assert( get_bit(0xf1, 0) == 1 && "test_get_bit");
 assert( get_bit(0xf1, 1) == 0 && "test_get_bit");
 assert( get_bit(0xff, 2) == 1 && "test_get_bit");
 assert( get_bit(0xf0, 2) == 0 && "test_get_bit");
 assert( get_bit(0xff, 7) == 1 && "test_get_bit");
}

void test_shift_out_bit() {
 int bit = 0;
 shift_out_bit(bit);
 assert( pinMode_ncalled != 0 && "test_shift_out_bit");
 assert( digitalWrite_ncalled != 0 && "test_shift_out_bit");
}

void test_shift_in_bit() {
 pinMode_ncalled = 0;
 digitalRead_ncalled = 0;
 shift_in_bit();
 assert( pinMode_ncalled != 0 && "test_shift_out_bit");
 assert( digitalRead_ncalled != 0 && "test_shift_out_bit");
}

int main(void) {
 test_init_easyinput();
 test_two_chars_to_byte();
 test_get_bit();
 test_shift_out_bit();
 test_shift_in_bit();
 return(0);
}

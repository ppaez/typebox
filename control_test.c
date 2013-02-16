#include <assert.h>
#include <stdbool.h>

#include "control.h"

static void test_two_chars_to_byte() {
 int byte;
 byte = two_chars_to_byte("31");
 assert( byte == 49 && "test_two_chars_to_byte" );
}

int main(void) {
 test_two_chars_to_byte();
 return(0);
}

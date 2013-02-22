
void init_easyinput();

int two_chars_to_byte(char * two_chars);

int get_bit(int byte, int n);

void shift_out_bit( int bit);

int shift_in_bit();

void transfer_packet(int key_byte, int modifier_byte);

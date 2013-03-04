#include "easyinput.h"

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  init_easyinput();
}

void loop() {
  char value;
  char chars[4];
  int nchars = 0;

  while (nchars < 4) {
    if (Serial.available() > 0) {
            value = Serial.read();
            chars[nchars++] = value;
        }
  }

  int key_byte, modifier_byte;
  char key_chars[3] = "";
  key_chars[0] = chars[2];
  key_chars[1] = chars[3];
  key_chars[2] = '\0';

  char modifier_chars[3] = "";
  modifier_chars[0] = chars[0];
  modifier_chars[1] = chars[1];
  modifier_chars[2] = '\0';

  key_byte = two_chars_to_byte(key_chars);
  modifier_byte = two_chars_to_byte(modifier_chars);

  Serial.print(modifier_chars);
  Serial.print(key_chars);
  Serial.print(" - ");

  Serial.print(modifier_byte);
  Serial.print(" ");
  Serial.print(key_byte);
  Serial.print(" - ");
  Serial.print(modifier_byte, BIN);
  Serial.print(" ");
  Serial.println(key_byte, BIN);

  digitalWrite(ledPin, HIGH);
  transfer_packet(key_byte, modifier_byte);
  digitalWrite(ledPin, LOW);
}

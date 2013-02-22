#include "easyinput.h"

int ledPin = 13;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  char value;
  char chars[3];
  int nchars = 0;

  while (nchars < 4) {
    if (Serial.available() > 0) {
            value = Serial.read();
            chars[nchars++] = value;
        }
    delay(100);
  }

  digitalWrite(ledPin, HIGH);
  Serial.print(chars[0]);
  Serial.print(chars[1]);
  Serial.print(chars[2]);
  Serial.println(chars[3]);

  int key_byte, modifier_byte;
  char key_chars[2] = "";
  key_chars[0] = chars[0];
  key_chars[1] = chars[1];
  key_chars[2] = '\0';

  char modifier_chars[2] = "";
  modifier_chars[0] = chars[2];
  modifier_chars[1] = chars[3];
  modifier_chars[2] = '\0';

  key_byte = two_chars_to_byte(key_chars);
  modifier_byte = two_chars_to_byte(modifier_chars);

  transfer_packet(key_byte, modifier_byte);

  delay(1000);
  digitalWrite(ledPin, LOW);
}

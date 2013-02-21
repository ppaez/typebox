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
  delay(1000);
  digitalWrite(ledPin, LOW);
}

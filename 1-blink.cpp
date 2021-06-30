#include <Arduino.h>

byte red = 5;
byte blue = 7;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    delay(1000);
}
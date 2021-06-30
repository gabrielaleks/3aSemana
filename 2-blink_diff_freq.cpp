#include <Arduino.h>

byte red = 5;
byte blue = 7;

unsigned long previousTimeRed;
unsigned long previousTimeBlue;

unsigned long intervalRed = 1000;
unsigned long intervalBlue = 500;

int ledStateRed = LOW; 
int ledStateBlue = LOW; 

void setup() {
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    unsigned long currentTime = millis();

    // interval/2 = intervalo do blink (acende e apaga)
    if (currentTime - previousTimeRed >= (intervalRed/2)) {
        previousTimeRed = currentTime;
        
        if (ledStateRed == LOW) {
            ledStateRed = HIGH; 
        } else {
            ledStateRed = LOW; 
        }

        digitalWrite(red, ledStateRed);
    }

    if (currentTime - previousTimeBlue >= (intervalBlue/2)) {
        previousTimeBlue = currentTime;
        
        if (ledStateBlue == LOW) {
            ledStateBlue = HIGH; 
        } else {
            ledStateBlue = LOW; 
        }

        digitalWrite(blue, ledStateBlue);
    }    

}
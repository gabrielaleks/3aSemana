#include <Arduino.h>

// LEDs characteristics
struct ledsCarac {
    int ledState;
    unsigned long frequency;
    unsigned long previousMillis;
    int pin;
};

// Declaring an array of the 'ledsCarac' struct 
struct ledsCarac leds[] = {
//  State      Freq     Time      Pin
    {LOW,         3,       0,      10},
    {HIGH,        5,       0,      11},

    // END OF ARRAY - Add other LEDs in the lines above
    {0, 0, 0, -1}
};

void setup() {
    // Declaring pins as output
    for (int i = 0; leds[i].pin > -1; i++) {
        pinMode(leds[i].pin, OUTPUT);
    }
}

void loop() {
    // Starts counting time
    unsigned long currentMillis = millis();

    for (int i = 0; leds[i].pin > -1; i++) {
        if (currentMillis - leds[i].previousMillis >= 1000/leds[i].frequency) {
            // Salva o tempo da última piscada do led
            leds[i].previousMillis = currentMillis;

            // Change LEDs state
            leds[i].ledState = !leds[i].ledState;

            // Led turns on or off based on state
            digitalWrite(leds[i].pin, leds[i].ledState);
        }
    }
} 
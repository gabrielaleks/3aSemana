#include <Arduino.h>

// LEDs characteristics
struct ledsCarac {
    int ledState;
    float frequency;
    unsigned long previousMillis;
    int pin;
};

// Declaring an array of the 'ledsCarac' struct 
// The information stored in this struct would ultimately be added to a separate file, called a configuration file
struct ledsCarac leds[] = {
//  State      Freq     Time      Pin
    {LOW,         0.5,       0,      5},
    {HIGH,        2,       0,      7},

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
        if (currentMillis - leds[i].previousMillis >= 1000/(leds[i].frequency*2)) {
            // Saves the time that the LED changed state
            leds[i].previousMillis = currentMillis;

            // Change LEDs state
            leds[i].ledState = !leds[i].ledState;

            // Led turns on or off based on state
            digitalWrite(leds[i].pin, leds[i].ledState);
        }
    }
} 
// Adaptador MicroSD
// Teste de escrita no cartão microSD
// Data: 30/06/21
// Libs: SD

// CS: 8
// DI: 11
// DO: 12
// SCK: 13

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; 
    }
    Serial.print("Initializing SD card...");
    if (!SD.begin(8, 11, 12, 13)) {
        Serial.println("initialization failed!");
        while (1)
            ;
    }

    Serial.println("initialization done.");
}

void loop() {
    long timeStamp = millis();
    String dataString = "Hello There!";

    myFile = SD.open("bbb.csv", FILE_WRITE);
    if (myFile) {
        myFile.print(timeStamp);
        myFile.print(",");
        myFile.println(dataString);
        myFile.close();
        Serial.print(timeStamp);
        Serial.print(",");
        Serial.println(dataString);
    } else {
        Serial.println("Couldn't open log file");
    }

}
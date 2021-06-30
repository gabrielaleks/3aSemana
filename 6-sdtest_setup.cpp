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
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    Serial.print("Initializing SD card...");
    if (!SD.begin(8, 11, 12, 13))
    {
        Serial.println("initialization failed!");
        while (1)
            ;
    }
    
    Serial.println("initialization done.");
    
    myFile = SD.open("aaa.txt", FILE_WRITE);
    
    if (myFile) {
        Serial.print("Writing to test.txt...");
        myFile.println("--- Inicio ---");
        myFile.println("Data: 27/01/21");
        myFile.println("Autor: Minerva Rockets");
        myFile.println("Esse é um teste da escrita no cartão microSD");
        for (int i = 0; i < 20; i++)
        {
            myFile.println(i);
        }
        myFile.println("--- Fim ---");

        myFile.close();
        Serial.println("done.");
    } else {
        Serial.println("error opening test.txt");
    }
}

void loop() {

}
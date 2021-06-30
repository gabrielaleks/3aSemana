#include <SPI.h>
#include <SD.h>

File myFile;

void initSd();
void openFile(const char* filename);
void closeFile();

struct Sd {
    byte cs;
    byte cd;
}sdPins;

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;    
    }

    initSd();
    openFile("test.txt");
    myFile.println("This text was written in setup");
    closeFile();
}

void loop() {

}

void initSd() {
    sdPins.cs = 10;
    sdPins.cd = 9;

    pinMode(sdPins.cd, INPUT);

    Serial.print("Initializing SD card...");

    if (!digitalRead(sdPins.cd)) {
        Serial.println(F("No card detected. Waiting for card."));
        while (!digitalRead(sdPins.cd));
        delay(250);
    }
    
    if (!SD.begin(sdPins.cs)) {
        Serial.println(" SD initialization failed");
        initSd();
    } else {
        Serial.println(" SD initialization successful");
    }
}

void openFile(const char* filename) {
    myFile = SD.open(filename, FILE_WRITE);
}

void closeFile() {
    myFile.close();
}
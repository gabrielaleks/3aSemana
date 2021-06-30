// BMP280
// Leitura de temperatura, pressão e altitude.
// Data: 30/06/21
// Libs: Adafruit BMP280
// Observação: Lembrar de mudar o parâmetro de bmp.readAltitude()
// de acordo com a pressão do nível do mar local.

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

void initBmp();
void setBmpSettings();
void update();
void printData();

Adafruit_BMP280 bmp;

const float SEALEVELPRESSURE = 1020;
#define SEALEVELPRESSURE 1020

struct bmp {
    float temperature;
    float pressure;
    float altitude;
}bmpData;

void setup() {
    Serial.begin(9600);
    Serial.println("BMP280 test");

    initBmp();
}

void loop() {
    update();
    printData();

    delay(2000);
}

void initBmp() {
    if (!bmp.begin())
    {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
        while (1);
    }

    setBmpSettings();

    Serial.println("Measuring pressure, altitude and temperature with BMP388");
}

void setBmpSettings() {
    /* Default settings from datasheet. */
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void update() {
    bmpData.temperature = bmp.readTemperature();
    bmpData.pressure = bmp.readPressure();
    bmpData.altitude = bmp.readAltitude(SEALEVELPRESSURE);
}

void printData() {
    Serial.print("Temperature = ");
    Serial.print(bmpData.temperature);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmpData.pressure);
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    Serial.print(bmpData.altitude); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();
}
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP280.h>

// Common functions
void initSystem();
void printData();

struct sensorTiming {
    unsigned long frequency;
    unsigned long previousTime;
};

// INA object and functions
Adafruit_INA219 ina219;
void initIna();
void updateIna();
void printDataIna();
#define INA_FREQUENCY 1

struct Ina {
    float shuntVoltage;
    float busVoltage;
    float loadVoltage;
    float current_mA;
    float power_mW;
    sensorTiming timeIna;
}inaData;

// BMP object and functions
Adafruit_BMP280 bmp;
void initBmp();
void setBmpSettings();
void updateBmp();
void printDataBmp();
#define SEALEVELPRESSURE 1020
#define BMP_FREQUENCY 2

struct Bmp {
    float temperature;
    float pressure;
    float altitude;
    float frequency;
    sensorTiming timeBmp;
}bmpData;

void setup() {
    Serial.begin(9600);
    while (!Serial)
    {
        // will pause Zero, Leonardo, etc until serial console opens
        delay(1);
    }

    initSystem();
}

void loop() {
    printData();
}

void initIna() {
    // Initialize the INA219.
    if (!ina219.begin())
    {
        Serial.println("Failed to find INA219 chip");
        while (1)
        {
            delay(10);
        }
    }

    inaData.timeIna.previousTime = 0;
    inaData.timeIna.frequency = INA_FREQUENCY;

    Serial.println("Measuring voltage and current with INA219");
}

void updateIna() {
    inaData.shuntVoltage = ina219.getShuntVoltage_mV();
    inaData.busVoltage = ina219.getBusVoltage_V();
    inaData.loadVoltage = (inaData.shuntVoltage/1000) + inaData.busVoltage;
    inaData.current_mA = ina219.getCurrent_mA();
    inaData.power_mW = ina219.getPower_mW();
}

void printDataIna() {
    Serial.println("***** INA219 *****");
    
    Serial.print("Bus Voltage:   ");
    Serial.print(inaData.busVoltage);
    Serial.println(" V");
    Serial.print("Shunt Voltage: ");
    Serial.print(inaData.shuntVoltage);
    Serial.println(" mV");
    Serial.print("Load Voltage:  ");
    Serial.print(inaData.loadVoltage);
    Serial.println(" V");
    Serial.print("Current:       ");
    Serial.print(inaData.current_mA);
    Serial.println(" mA");
    Serial.print("Power:         ");
    Serial.print(inaData.power_mW);
    Serial.println(" mW");
    Serial.print("Time: ");
    Serial.println(inaData.timeIna.previousTime);

    Serial.println("******************");
    
    Serial.println();

}

void initBmp() {
    if (!bmp.begin())
    {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
        while (1);
    }

    bmpData.timeBmp.previousTime = 0;
    bmpData.frequency = BMP_FREQUENCY;

    setBmpSettings();

    Serial.println("Measuring pressure, altitude and temperature with BMP280");
}

void setBmpSettings() {
    /* Default settings from datasheet. */
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void updateBmp() {
    bmpData.temperature = bmp.readTemperature();
    bmpData.pressure = bmp.readPressure();
    bmpData.altitude = bmp.readAltitude(SEALEVELPRESSURE);
}

void printDataBmp() {
    Serial.println("***** BMP280 *****");

    Serial.print("Temperature = ");
    Serial.print(bmpData.temperature);
    Serial.println(" *C");

    Serial.print("Pressure = ");
    Serial.print(bmpData.pressure);
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    Serial.print(bmpData.altitude); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.print("Time: ");
    Serial.println(bmpData.timeBmp.previousTime);

    Serial.println("******************");

    Serial.println();
}

void initSystem() {
    initIna();
    initBmp();
    Serial.println();
}

void printData() {
    unsigned long currentTime = millis();

    if (currentTime - inaData.timeIna.previousTime >= 1000.0/inaData.timeIna.frequency) {
        inaData.timeIna.previousTime = currentTime;
        updateIna();
        printDataIna();
    }

    if (currentTime - bmpData.timeBmp.previousTime >= 1000.0/bmpData.timeBmp.frequency) {
        bmpData.timeBmp.previousTime = currentTime;
        updateBmp();
        printDataBmp();
    }
}
// INA219
// Leitura de tensão, corrente e potência 
// Data: 30/06/21
// Libs: Adafruit INA219, Adafruit Sensor

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void initIna();
void update();
void printData();

struct Ina {
    float shuntVoltage;
    float busVoltage;
    float loadVoltage;
    float current_mA;
    float power_mW;
}inaData;


void setup() {
    Serial.begin(9600);
    while (!Serial)
    {
        // will pause Zero, Leonardo, etc until serial console opens
        delay(1);
    }

    initIna();
}

void loop() {
    update();
    printData();
    delay(2000);
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

    Serial.println("Measuring voltage and current with INA219");
}

void update() {
    inaData.shuntVoltage = ina219.getShuntVoltage_mV();
    inaData.busVoltage = ina219.getBusVoltage_V();
    inaData.loadVoltage = (inaData.shuntVoltage/1000) + inaData.busVoltage;
    inaData.current_mA = ina219.getCurrent_mA();
    inaData.power_mW = ina219.getPower_mW();
}

void printData() {
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
    Serial.println("");
}
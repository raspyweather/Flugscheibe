#pragma once
#include "Adafruit_BMP3XX.h"
#include "Sensor.h"
#include "pressureSensor.h"
#include "temperatureSensor.h"

class bmp388Sensor : public Sensor,
                     public PressureSensor,
                     public TemperatureSensor
{
private:
    Adafruit_BMP3XX bmp;
    float pressure = 0;
    float temperature = 0;
    int cs;

public:
    bmp388Sensor(int csPin)
    {
        cs = csPin;
    }
    void init()
    {
        Serial.print("Connecting bmp388 ");
        for (int i = 0; i < 10 && !isConnected; i++)
        {
            Serial.print(".");
            isConnected = bmp.begin_SPI(cs);
        }

        Serial.println(isConnected ? "[DONE]" : "[FAIL]");
    }

    void loop()
    {
        temperature = bmp.readTemperature();
        pressure = bmp.readPressure();
    }

    float getTemperature()
    {
        return temperature;
    }
    float getPressure()
    {
        return pressure;
    }
};
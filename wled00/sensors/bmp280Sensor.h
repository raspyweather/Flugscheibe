#pragma once
#include <Adafruit_BMP280.h>
#include "Sensor.h"
#include "temperatureSensor.h"
#include "pressureSensor.h"

class bmp280Sensor : public Sensor, public PressureSensor, public TemperatureSensor
{
private:
    Adafruit_BMP280 bmp;
    float temperature;
    float pressure;
    int idx;

public:
    bmp280Sensor(int cs, int index = 0)
    {
        idx = index;
        bmp = Adafruit_BMP280(cs);
    }

    void init()
    {
        Serial.printf("Connecting bmp280-%02d", idx);

        for (int i = 0; i < 10 && !isConnected; i++)
        {
            isConnected = bmp.begin();
            Serial.print(".");
        }
        Serial.println(isConnected ? "[DONE]" : "[FAIL]");

        if (isConnected)
        {
            bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                            Adafruit_BMP280::SAMPLING_X16,    /* Temp. oversampling */
                            Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                            Adafruit_BMP280::FILTER_X2,       /* Filtering. */
                            Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
        }
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

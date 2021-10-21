#pragma once
#include "Arduino.h"
#include "BMI160Gen.h"
#include "Sensor.h"
#include "accelerationSensor.h"
#include "gyroSensor.h"
#include "temperatureSensor.h"

class Bmi160Sensor :public Sensor, public GyroSensor, public AccelerationSensor, public TemperatureSensor {
private:
    int csPin;

    int lastTemp;
    int xaxisAccel,
        yaxisAccel,
        zaxisAccel,
        xaxisGyro,
        yaxisGyro,
        zaxisGyro;

public:
    Bmi160Sensor(int cs)
    {
        csPin = cs;
    }
    void init();
    void loop();

    float getXAccel()
    {
        return xaxisAccel;
    }
    float getYAccel()
    {
        return yaxisAccel;
    }
    float getZAccel()
    {
        return zaxisAccel;
    }

    float getXGyro()
    {
        return xaxisGyro;
    }
    float getYGyro()
    {
        return yaxisGyro;
    }
    float getZGyro()
    {
        return zaxisGyro;
    }

    float getTemp()
    {
        return lastTemp;
    }
};
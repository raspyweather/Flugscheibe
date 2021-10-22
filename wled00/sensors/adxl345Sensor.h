#pragma once
#include <Adafruit_ADXL345_U.h>
#include "accelerationSensor.h"

class adxl345Sensor : public AccelerationSensor
{
private:
    float lastXAccel = 0;
    float lastYAccel = 0;
    float lastZAccel = 0;
    Adafruit_ADXL345_Unified accel;

public:
    adxl345Sensor() {}
    void Setup()
    {
        accel.begin();
        accel.setDataRate(ADXL345_DATARATE_200_HZ);
        accel.setRange(ADXL345_RANGE_16_G);
    }
    void Loop()
    {
        lastXAccel = accel.getX();
        lastYAccel = accel.getY();
        lastZAccel = accel.getZ();
    }

    float getXAccel()
    {
        return lastXAccel;
    }
    float getYAccel()
    {
        return lastYAccel;
    }
    float getZAccel()
    {
        return lastZAccel;
    }
};
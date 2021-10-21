#pragma once
#include "Sensor.h"

class GyroSensor: public Sensor
{
public:
    virtual float getXGyro() = 0;
    virtual float getYGyro() = 0;
    virtual float getZGyro() = 0;
};
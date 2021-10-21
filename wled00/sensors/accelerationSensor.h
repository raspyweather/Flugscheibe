#pragma once
#include "Sensor.h"

class AccelerationSensor : public Sensor
{
public:
    virtual void Setup() = 0;
    virtual void Loop() = 0;
    virtual float getXAccel() = 0;
    virtual float getYAccel() = 0;
    virtual float getZAccel() = 0;
};

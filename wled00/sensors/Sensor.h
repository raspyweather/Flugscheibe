#pragma once
#include "Adafruit_Sensor.h"

class Sensor
{
protected:
    bool isConnected = false;
public:
    virtual void init() = 0;
    virtual void loop() = 0;
    virtual sensors_event_t getData() = 0;
    virtual bool connected() { return isConnected; };
};
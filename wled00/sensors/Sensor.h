#pragma once
class Sensor
{
protected:
    bool isConnected = false;

public:
    virtual void init() = 0;
    virtual void loop() = 0;
    virtual bool connected() { return isConnected; };
};
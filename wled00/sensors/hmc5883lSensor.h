#include "Adafruit_HMC5883_U.h"
#include "Sensor.h"

class hmc5883lSensor : public Sensor
{
private:
    sensors_event_t data;
    Adafruit_HMC5883_Unified sensor;

public:
    hmc5883lSensor() {}
    void Setup()
    {
        sensor.begin();
        sensor.enableAutoRange(true);
    }
    void Loop()
    {
        sensor.getEvent(&data);
    }
    sensors_event_t getData(){
        return data;
    }
};
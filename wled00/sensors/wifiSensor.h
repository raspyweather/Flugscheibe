#include <Arduino.h>
#include "Sensor.h"

class WifiSensor : public Sensor
{
    public:
        WifiSensor(){
            WiFi.RSSI();
        }
}
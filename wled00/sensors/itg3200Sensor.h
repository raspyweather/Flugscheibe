#include "Sensor.h"
#include "ITG3200.h"

class itg3200Sensor : Sensor
{
private:
    ITG3200 gyro;
    sensors_event_t data;

public:
    void init()
    {
        gyro.init();
        gyro.zeroCalibrate(200, 10);
    }
    void loop()
    {
        data.temperature = gyro.getTemperature();
        int16_t x, y, z;
        gyro.getXYZ(&x, &y, &z);
        data.gyro.x = x;
        data.gyro.y = y;
        data.gyro.z = z;
        gyro.getAngularVelocity(&data.gyro.roll, &data.gyro.pitch, &data.gyro.heading);
    }
};
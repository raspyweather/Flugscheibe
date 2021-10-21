#include "bmi160Sensor.h"

void Bmi160Sensor::init()
{
    Serial.print("Connecting bmi160");
    bool isConnected = false;

    for (int i = 0; i < 10 && !isConnected; i++)
    {
        isConnected = BMI160.begin(csPin,-1);
    }

    Serial.println(isConnected ? "[DONE]" : "[FAIL]");

    if (isConnected)
    {
        BMI160.setGyroRange(BMI160GyroRange::BMI160_GYRO_RANGE_2000);
        BMI160.setGyroRate(BMI160GyroRate::BMI160_GYRO_RATE_3200HZ);

        BMI160.setAccelerometerRange(BMI160AccelRange::BMI160_ACCEL_RANGE_16G);
        BMI160.setAccelerometerRate(BMI160AccelRate::BMI160_ACCEL_RATE_1600HZ);
    }
}

void Bmi160Sensor::loop()
{
    lastTemp = BMI160.readTemperature();

    xaxisAccel = BMI160.readAccelerometer(CurieIMUAxis::X_AXIS);
    yaxisAccel = BMI160.readAccelerometer(CurieIMUAxis::Y_AXIS);
    zaxisAccel = BMI160.readAccelerometer(CurieIMUAxis::Z_AXIS);

    xaxisGyro = BMI160.readGyro(CurieIMUAxis::X_AXIS);
    yaxisGyro = BMI160.readGyro(CurieIMUAxis::Y_AXIS);
    zaxisGyro = BMI160.readGyro(CurieIMUAxis::Z_AXIS);
}

#pragma once
#include "Arduino.h"
#include "Sensor.h"
#include "BMI160Gen.h"

class Bmi160Sensor : public Sensor
{
private:
    int csPin;
    sensors_event_t data;
public:
    Bmi160Sensor(int cs)
    {
        csPin = cs;
    }
    sensors_event_t getData()
    {
        return data;
    }
    void init()
    {
        Serial.print("Connecting bmi160");
        bool isConnected = false;

        for (int i = 0; i < 10 && !isConnected; i++)
        {
            isConnected = BMI160.begin(csPin, -1);
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

    void loop()
    {
        data.type = SENSOR_TYPE_AMBIENT_TEMPERATURE | SENSOR_TYPE_GYROSCOPE | SENSOR_TYPE_ACCELEROMETER;

        data.temperature = BMI160.readTemperature();

        data.acceleration.x = BMI160.readAccelerometer(CurieIMUAxis::X_AXIS);
        data.acceleration.y = BMI160.readAccelerometer(CurieIMUAxis::Y_AXIS);
        data.acceleration.z = BMI160.readAccelerometer(CurieIMUAxis::Z_AXIS);

        data.gyro.x = BMI160.readGyro(CurieIMUAxis::X_AXIS);
        data.gyro.y = BMI160.readGyro(CurieIMUAxis::Y_AXIS);
        data.gyro.z = BMI160.readGyro(CurieIMUAxis::Z_AXIS);
    }
};
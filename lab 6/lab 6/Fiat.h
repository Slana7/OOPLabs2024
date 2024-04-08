#pragma once
#include "Car.h"

class Fiat : public Car
{
private:
    double fuelCapacity = 40.0;
    double fuelConsumption = 8.0;
    double avgSpeedSunny = 70.0;
    double avgSpeedRain = 40.0;
    double avgSpeedSnow = 30.0;
public:
    Fiat();
    virtual const char* getName();
    virtual double calculateTime(double circuitLength, Weather weather);
};
#include "Car.h"
#include <exception>

Car::Car(const String &make, int maxSpeed) : Vehicle(make, maxSpeed)
{
    if (maxSpeed < 180 || maxSpeed > 240)
    {
        // some informative text
        throw std::exception();
    }
}

int Car::getSpeedAccordingToRoadType(RoadType)
{
    return maxSpeed;
}
#include "Minivan.h"
#include <exception>

Minivan::Minivan(const String &make, int maxSpeed) : Vehicle(make, maxSpeed)
{
    if (maxSpeed < 120 || maxSpeed > 160)
    {
        // some informative text
        throw std::exception();
    }
}

int Minivan::getSpeedAccordingToRoadType(RoadType rt)
{
    switch (rt)
    {
    case RoadType::Highway:
        return maxSpeed;
    case RoadType::Speed:
        return maxSpeed / 2;
    case RoadType::ThirdClass:
        return maxSpeed / 3;
    }
}
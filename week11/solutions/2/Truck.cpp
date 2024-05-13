#include "Truck.h"
#include <exception>

Truck::Truck(const String &make, int maxSpeed) : Vehicle(make, maxSpeed)
{
    if (maxSpeed < 80 || maxSpeed > 140)
    {
        // some informative text
        throw std::exception();
    }
}

int Truck::getSpeedAccordingToRoadType(RoadType rt)
{
    switch (rt)
    {
    case RoadType::Highway:
        return maxSpeed / 2;
    case RoadType::Speed:
        return maxSpeed / 4;
    case RoadType::ThirdClass:
        return 10;
    }
}
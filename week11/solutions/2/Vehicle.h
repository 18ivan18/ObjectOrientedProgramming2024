#ifndef VEHICLE_H
#define VEHICLE_H
#include "String.h"
#include "RoadType.h"

class Vehicle
{
protected:
    int maxSpeed;
    String make;

public:
    Vehicle(const String &make, int maxSpeed);
    virtual int getSpeedAccordingToRoadType(RoadType rt) = 0;
};

#endif
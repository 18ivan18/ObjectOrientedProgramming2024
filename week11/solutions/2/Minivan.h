#ifndef MINIVAN_H
#define MINIVAN_H
#include "String.h"
#include "RoadType.h"
#include "Vehicle.h"

class Minivan : public Vehicle
{
public:
    Minivan(const String &make, int maxSpeed);
    int getSpeedAccordingToRoadType(RoadType rt) override;
};

#endif
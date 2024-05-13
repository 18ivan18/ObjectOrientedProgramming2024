#ifndef CAR_H
#define CAR_H
#include "String.h"
#include "Vehicle.h"
#include "RoadType.h"

class Car : public Vehicle
{
public:
    Car(const String &make, int maxSpeed);
    int getSpeedAccordingToRoadType(RoadType rt) override;
};

#endif
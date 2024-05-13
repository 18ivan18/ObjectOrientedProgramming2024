#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : virtual public Vehicle
{
private:
    int loadCapacity;

public:
    Truck(const std::string &regnum, int loadCapacity);
    double getParkingPrice() override;
    Vehicle *clone() override;
    int getLoadCapacity();
};

#endif
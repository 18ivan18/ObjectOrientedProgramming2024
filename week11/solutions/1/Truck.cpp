#include "Truck.h"

Truck::Truck(const std::string &regnum, int loadCapacity) : Vehicle(regnum), loadCapacity{loadCapacity} {}

double Truck::getParkingPrice()
{
    return loadCapacity / 100.0;
}

int Truck::getLoadCapacity()
{
    return loadCapacity;
}

Vehicle *Truck::clone()
{
    return new Truck(*this);
}

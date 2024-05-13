#include "Garage.h"

const std::vector<Vehicle *> Garage::getVehicles() { return vehicles; }

void Garage::addNewVehicle(Vehicle *&v)
{
    vehicles.push_back(v->clone());
}

void Garage::addNewVehicle(Vehicle *&&v)
{
    vehicles.push_back(v);
}

Garage::Garage(const Garage &g)
{
    copy(g);
}

Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

Garage::~Garage()
{
    erase();
}

void Garage::copy(const Garage &g)
{
    for (const auto &vehicle : g.vehicles)
    {
        vehicles.push_back(vehicle->clone());
    }
}
void Garage::erase()
{
    for (const auto &vehicle : vehicles)
    {
        delete vehicle;
    }
    vehicles.clear();
}
#include "Garage.h"
Garage::Garage(int maxCapacity) : vehicles(Vector<Vehicle *>(maxCapacity)) {}

Garage::Garage(const Garage &other) : vehicles(other.vehicles) {}

Garage &Garage::operator=(const Garage &rhs)
{
    if (this != &rhs)
    {
        // deep copy
        vehicles = rhs.vehicles;
    }
    return *this;
}

Garage::~Garage()
{
    for (int i = 0; i < vehicles.size(); i++)
    {
        delete vehicles[i];
    }
}

void Garage::addNewVehicle(Vehicle *&v)
{
    vehicles.add(v);
}

void Garage::addNewVehicle(Vehicle *&&v)
{
    vehicles.add(v);
}

int Garage::getAllVehiclesThatCanTravelRoad(int highwayLength, int speedLength, int thirdrateLength, int time)
{
    int cnt = 0;
    for (int i = 0; i < vehicles.size(); i++)
    {
        double speedHightway = vehicles[i]->getSpeedAccordingToRoadType(RoadType::Highway);
        double speedSpeedRoad = vehicles[i]->getSpeedAccordingToRoadType(RoadType::Speed);
        double speedThirdRate = vehicles[i]->getSpeedAccordingToRoadType(RoadType::ThirdClass);
        int t = highwayLength / speedHightway + speedLength / speedSpeedRoad + thirdrateLength / speedThirdRate;
        cnt += t < time;
    }
    return cnt;
}

#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"
#include "Vector.h"

class Garage
{
private:
    Vector<Vehicle *> vehicles;

public:
    Garage(int maxCapacity);
    Garage(const Garage &other);
    Garage &operator=(const Garage &rhs);
    ~Garage();

    void addNewVehicle(Vehicle *&);
    void addNewVehicle(Vehicle *&&);

    int getAllVehiclesThatCanTravelRoad(int highway, int speed, int thirdrate, int len);
};

#endif
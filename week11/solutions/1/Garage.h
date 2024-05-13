#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"
#include <vector>

class Garage
{
private:
    std::vector<Vehicle *> vehicles;
    void copy(const Garage &);
    void erase();

public:
    Garage() = default;
    Garage(const Garage &);
    Garage &operator=(const Garage &);

    const std::vector<Vehicle *> getVehicles();
    void addNewVehicle(Vehicle *&);
    void addNewVehicle(Vehicle *&&);

    ~Garage();
};

#endif
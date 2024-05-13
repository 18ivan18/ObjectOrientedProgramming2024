#ifndef MINIBUS_H
#define MINIBUS_H
#include "Car.h"
#include "Truck.h"

class Minibus : public Car, public Truck
{
private:
    int numberOfDoors;

public:
    Minibus(const std::string &regnum, bool isPolite, int numOfPassengers, int load, int doors);
    double getParkingPrice() override;
    Vehicle *clone() override;
};

#endif
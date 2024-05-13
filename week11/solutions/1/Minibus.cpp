#include "Minibus.h"

Minibus::Minibus(const std::string &regnum, bool isPolite, int numOfPassengers, int load, int doors) : Vehicle(regnum), Car(regnum, isPolite, numOfPassengers), Truck(regnum, load), numberOfDoors{doors} {}

double Minibus::getParkingPrice()
{
    return (Car::getParkingPrice() + Truck::getParkingPrice()) / 2.0;
}

Vehicle *Minibus::clone()
{
    return new Minibus(*this);
}

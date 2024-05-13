#include "Car.h"

Car::Car(const std::string &regnum, bool isPolite, int numOfPassengers) : Vehicle(regnum), isPolite{isPolite}, numOfPassengers{numOfPassengers} {}

double Car::getParkingPrice()
{
    return isPolite ? 1 : rand() % 8 + 2;
}

Vehicle *Car::clone()
{
    return new Car(*this);
}

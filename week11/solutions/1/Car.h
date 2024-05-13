#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : virtual public Vehicle
{
private:
    bool isPolite;
    int numOfPassengers;

public:
    Car(const std::string &regnum, bool isPolite, int numOfPassengers);
    double getParkingPrice() override;
    Vehicle *clone() override;
};

#endif
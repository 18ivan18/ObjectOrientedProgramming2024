#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../utils/doctest.h"
#include "Garage.h"
#include "Car.h"
#include "Truck.h"
#include "Minibus.h"

TEST_SUITE("Garage")
{
    TEST_CASE("vehicles pay for staying in the garage")
    {
        Garage g;
        g.addNewVehicle(new Car("PB 1234 SX", true, 2));
        g.addNewVehicle(new Minibus("PB 1234 SX", true, 2, 100, 5));
        g.addNewVehicle(new Truck("PB 1234 SX", 200));
        g.addNewVehicle(new Car("PB 1234 SX", true, 2));
        int payment = 0;
        for (auto vehicle : g.getVehicles())
        {
            payment += vehicle->getParkingPrice();
        }
        CHECK(payment == 5);
    }
}
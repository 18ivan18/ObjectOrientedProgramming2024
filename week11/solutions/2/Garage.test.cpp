#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../utils/doctest.h"
#include "Garage.h"
#include "Car.h"
#include "Truck.h"
#include "Minivan.h"

TEST_SUITE("Garage")
{
    TEST_CASE("vehicles that can run the course in time")
    {
        Garage g(5);
        g.addNewVehicle(new Car("Audi A7", 230));
        g.addNewVehicle(new Truck("Kamion", 100));
        g.addNewVehicle(new Minivan("Van", 150));

        CHECK(g.getAllVehiclesThatCanTravelRoad(100, 120, 40, 2) == 5);
    }
}
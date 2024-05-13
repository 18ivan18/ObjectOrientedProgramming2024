#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../utils/doctest.h"
#include "Car.h"

TEST_SUITE("Car")
{
    TEST_CASE("can be created")
    {
        Car c("PB 9458 SS", true, 3);
        CHECK("PB 9458 SS" == c.getRegnum());
    }

    TEST_CASE("Pays 1lv for parking if the driver is polite")
    {
        Car c("PB 9458 SS", true, 3);
        CHECK(c.getParkingPrice() == 1);
    }

    TEST_CASE("Pays between 2 and 10 leva if the driver is not polite")
    {
        Car c("PB 9458 SS", false, 3);
        double parkingPrice = c.getParkingPrice();
        CHECK(parkingPrice >= 2);
        CHECK(parkingPrice <= 10);
    }
}
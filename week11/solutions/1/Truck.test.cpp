#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../../utils/doctest.h"
#include "Truck.h"

TEST_SUITE("Truck")
{
    TEST_CASE("can be created")
    {
        Truck c("PB 9458 SS", 150);
        CHECK("PB 9458 SS" == c.getRegnum());
    }

    TEST_CASE("Pays for parking")
    {
        Truck c("PB 9458 SS", 150);
        CHECK(c.getParkingPrice() == 1.5);
    }
}
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "streamBMSData.h"
#include "stdbool.h"


TEST_CASE("TestCase1 : Stream Number of Valid Data From Sensor is above 50") {
    int temp[2] = {-20, 50};
    int soc[2] = {10, 70};
    int Range = 150;
    REQUIRE(processBMSStreamData(Range, temp, soc) == true);
}

TEST_CASE("TestCase2 : Stream Number of Valid Data From Sensor is below 50") {
    int temp[2] = {-30, 50};
    int soc[2] = {10, 100};
    int Range = 10;
    REQUIRE(processBMSStreamData(Range, temp, soc) == false);
}

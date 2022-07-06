#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "streamBMSData.h"


TEST_CASE("TestCase1 : Stream Valid Data From Sensor") {

    float tempArray[] = {-12.0, 20.0, 40.0, 30.0};
    int socArray[] = {60, 50, 45, 80};
    int Range = 4;
    REQUIRE(processBMSStreamData(LEAD, tempArray, socArray, Range)==4);
}

TEST_CASE("TestCase2 : Stream InValid Data From Sensor and check if the invalid values are ignored") {

    float tempSensorDataInvalid[] = {50.2, 20.5, -40.0, 9.62};
    int socSensorDataInvalid[] = {20, 65, 45, 10};
    int Range = 4;
    REQUIRE(processBMSStreamData(NICKEL, tempSensorDataInvalid, socSensorDataInvalid, Range)==1);
}

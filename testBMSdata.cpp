#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <stdlib.h>

TEST_CASE("TestCase1 : Stream Valid Data From Sensor") {

    char batteryType = "Lead";
    float tempArray[] = {-12.0, 20.0, 40.0, 30.0};
    int socArray[] = {60, 50, 45, 80};
    REQUIRE(processBMSStreamData(batteryType, tempArray, socArray)==4);
}

TEST_CASE("TestCase2 : Stream InValid Data From Sensor and check if the invalid values are ignored") {

    char batteryType = "Nickel";
    float tempSensorDataInvalid[] = {50.2, 20.5, -40.0, 9.62};
    float socSensorDataInvalid[] = {20, 65, 45, 10};
    REQUIRE(streamMainFunction(batteryType, tempSensorDataInvalid, socSensorDataInvalid)==1);
}

#include <stdio.h>


typedef enum
{
    LEAD = 0,
    NICKEL
}batteryType_t;

void generateRandomNumbers(int tempMin, int tempMax, int * Array, int Range);
int processBMSStreamData(batteryType_t batType, int Range, int * tempRange, int *socRange);
bool checkThresholdLimit(int minVal, int maxVal, int temp);
void printOnConsole(int temp, int soc);
bool checkTempinRange(batteryType_t batteryType, float temp);
bool checkSOCinRange(int soc);
bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange);
bool randomValuesRangeCheck(int noOfValidValues)

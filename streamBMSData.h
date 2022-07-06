#include <stdio.h>
typedef enum
{
    LEAD = 0u;
    NICKEL
}batteryType_t;

void printOnConsole(float temp, float soc);
bool checkTempinRange(batteryType_t batteryType, float temp);
bool checkThresholdLimit(float minVal, float maxVal, float temp);
bool checkSOCinRange(int soc);
bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange);
void processBMSStreamData(batteryType_t batType, float tempArray[], int SOCArray[], int Range);


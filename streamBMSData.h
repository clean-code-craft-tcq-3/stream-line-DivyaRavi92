#include <stdio.h>

void printOnConsole(float temp, float soc);
bool checkTempinRange(char batteryType, float temp);
bool checkThresholdLimit(float minVal, float maxVal, float temp);
bool checkSOCinRange(int soc);
bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange);
void processBMSStreamData(char batType, float tempArray[], int SOCArray[], int Range);


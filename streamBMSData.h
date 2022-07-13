#include <stdio.h>

void generateRandomNumbers(int tempMin, int tempMax, int * Array, int Range);
bool processBMSStreamData(int Range, int * tempRange, int *socRange);
bool checkThresholdLimit(int minVal, int maxVal, int temp);
void printOnConsole(int temp[], int soc[]);
bool checkTempinRange(int temp);
bool checkSOCinRange(int soc);
bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange);
bool randomValuesRangeCheck(int noOfValidValues);

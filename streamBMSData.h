#include <stdio.h>

void generateRandomNumbers(int parameterMinVal, int parameterMaxVal, int * Array, int Range );
bool processBMSStreamData(int Range, int * tempRange, int *socRange);
bool checkThresholdLimit(int minVal, int maxVal, int parameter);
void printOnConsole(int temp[], int soc[]);
bool checkTempinRange(int temp);
bool checkSOCinRange(int soc);
bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange);
bool randomValuesRangeCheck(int noOfValidValues);
void checkAndAssigntoArray(int *tempValidArray, int *socValidArray, int temp, int SOC, int noOfValidValues);

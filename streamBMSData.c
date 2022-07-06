#include "streamBMSData.h"
#include "stdbool.h"
#include "stdlib.h"

void printOnConsole(int temp, int soc)
{
    printf("Temperature = %d, ", temp);
    printf("SOC = %d \n", soc);

}

bool checkTempinRange(batteryType_t batteryType, int temp)
{
    bool isTempInRange;
    switch(batteryType)
    {
        case LEAD: 
        isTempInRange = checkThresholdLimit(-20, 50, temp);
        break;
        case NICKEL:
        isTempInRange = checkThresholdLimit(-20, 65, temp);
        break;
        default:
        isTempInRange = false;
        break;
    }
    return isTempInRange;
}

bool checkThresholdLimit(int minVal, int maxVal, int temp)
{
    if(temp >= minVal  && temp <= maxVal)
    {
        return true;
    }
    return false;
}

bool checkSOCinRange(int soc)
{
    if(soc >= 40  && soc <= 90)
    {
        return true;
    }
    return false;
}

bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange)
{
    bool isValInRange = false;
    if(isTempValueInRange && isSOCValinRange)
    {
        isValInRange = true;
    }
    return isValInRange;    
}

void generateRandomNumbers(int tempMin, int tempMax, int * Array, int Range )
{
    for(int i =0; i < Range; i++)
    {
        Array[i] = (rand() % (tempMax - tempMin+1) + tempMin);
    }
}

bool processBMSStreamData(batteryType_t batType, int Range, int * tempRange, int *socRange)
{
    int data;
    int tempMin = tempRange[0];
    int tempMax = tempRange[1];
    int socMin = socRange[0];
    int socMax = socRange[1];
    int tempArray[Range], SOCArray[Range];
    bool checkValidityOfRange;
    
    generateRandomNumbers(tempMin, tempMax, tempArray, Range);
    generateRandomNumbers(socMin, socMax, SOCArray, Range);

    bool isTempValueInRange, isSOCValinRange, isValInRange;
    int noOfValidValues;
    for(data = 0; data < Range ; data++)
    {
        isTempValueInRange = checkTempinRange(batType, tempArray[data]);
        isSOCValinRange = checkSOCinRange(SOCArray[data]);
        isValInRange = checkValueInRange(isTempValueInRange, isSOCValinRange);
        if(isValInRange)
        {
            printOnConsole(tempArray[data], SOCArray[data]);
            noOfValidValues++;
        }
    }

    checkValidityOfRange = randomValuesRangeCheck(noOfValidValues);
    return checkValidityOfRange;
}

bool randomValuesRangeCheck(int noOfValidValues)
{
    if(noOfValidValues >= 50)
    {
        return true;
    }
    else
    {
        return false;
    }
}


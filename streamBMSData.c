#include "streamBMSData.h"
#include "stdbool.h"

void printOnConsole(float temp, float soc)
{
    printf("Temperature = %0.2f, ", temp);
    printf("SOC = %d \%", soc \n);

}

bool checkTempinRange(batteryType_t batteryType, float temp)
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
        isTempInRange = FALSE;
        break;
    }
    return isTempInRange;
}

bool checkThresholdLimit(float minVal, float maxVal, float temp)
{
    if(temp >= minVal  && temp <= maxVal)
    {
        return TRUE;
    }
    return FALSE;
}

bool checkSOCinRange(int soc)
{
    if(soc >= 40  && soc <= 90)
    {
        return TRUE;
    }
    return FALSE;
}

bool checkValueInRange(bool isTempValueInRange, bool isSOCValinRange)
{
    bool isValInRange = FALSE;
    if(isTempValueInRange && isSOCValinRange)
    {
        isValInRange = TRUE;
    }
    return isValInRange;    
}


int processBMSStreamData(batteryType_t batType, float tempArray[], int SOCArray[], int Range)
{
    int data;
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
    return noOfValidValues;
}


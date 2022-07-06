#include "streamBMSData.h"

void printOnConsole(float temp, float soc)
{
    printf("Temperature = %0.2f, ", temp);
    printf("SOC = %d %", soc \n);

}

bool checkTempinRange(char batteryType, float temp)
{
    bool isTempInRange;
    switch(batteryType)
    {
        case "Lead": 
        isTempInRange = checkThresholdLimit(-20, 50, temp);
        break;
        case "Nickel":
        isTempInRange = checkThresholdLimit(-20, 65, temp);
        break;
        case "Lithium": 
        isTempInRange = checkThresholdLimit(-20, 60, temp);
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


void processBMSStreamData(char batType, float tempArray[], int SOCArray[], int Range)
{
    int data;
    bool isTempValueInRange, isSOCValinRange, isValInRange;
    for(data = 0; data < Range ; data++)
    {
        isTempValueInRange = checkTempinRange(batType, tempArray[data]);
        isSOCValinRange = checkSOCinRange(SOCArray[data]);
        isValInRange = checkValueInRange(isTempValueInRange, isSOCValinRange);
        if(isValInRange)
        {
            printOnConsole(tempArray[data], SOCArray[data]);
        }
    }
}

#include "streamBMSData.h"
include "stdbool.h"
#include "stdlib.h"

void printOnConsole(int temp[], int soc[])
{
    int data = 0;
    printf("\nTemperature Array\n");
    for(data =0;data < 50; data ++)
    {
        printf("%d ", temp[data]);
    }
    printf("\nSOC Array\n");
    for(data =0; data < 50; data ++)
    {
        printf("%d ", soc[data]);
    }
}
bool checkThresholdLimit(int minVal, int maxVal, int temp)
{
    if(temp >= minVal  && temp <= maxVal)
    {
        return true;
    }
    return false;
}

bool checkTempinRange(int temp)
{
    bool isTempInRange;
    isTempInRange = checkThresholdLimit(-20, 50, temp);
    return isTempInRange;
}


bool checkSOCinRange(int soc)
{
    if(soc >= 40  && soc <= 90)
    {
        return true;
    }
    return false;
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

bool processBMSStreamData(int Range, int  *tempRange, int *socRange)
{
    int data;
    int tempMin = tempRange[0];
    int tempMax = tempRange[1];
    int socMin = socRange[0];
    int socMax = socRange[1];
    int tempArray[Range], SOCArray[Range], tempValidArray[50], socValidArray[50];
    bool checkValidityOfRange;
    
    generateRandomNumbers(tempMin, tempMax, tempArray, Range);
    generateRandomNumbers(socMin, socMax, SOCArray, Range);

    bool isTempValueInRange, isSOCValinRange, isValInRange;
    int noOfValidValues = 0, totalValidValues = 0;
    for(data = 0; data < Range ; data++)
    {
        isTempValueInRange = checkTempinRange(tempArray[data]);
        isSOCValinRange = checkSOCinRange(SOCArray[data]);
        isValInRange = checkValueInRange(isTempValueInRange, isSOCValinRange);
        if(isValInRange)
        {
            checkAndAssigntoArray(tempValidArray, socValidArray, tempArray[data], SOCArray[data], noOfValidValues);
        }    
        
        totalValidValues++;
    }

    checkValidityOfRange = randomValuesRangeCheck(totalValidValues);
    return checkValidityOfRange;
}

void checkAndAssigntoArray(int *tempValidArray, int *socValidArray, int tempArray[data], int SOCArray[data], int * noOfValidValues);
{
    if(noOfValidValues < 50)
    {
        tempValidArray[noOfValidValues] =tempArray[data];
        socValidArray[noOfValidValues] = SOCArray[data];
        *noOfValidValues++;
    }
    else
    {
        printOnConsole(tempValidArray, socValidArray);
        *noOfValidValues = 0;   
    }
    
}

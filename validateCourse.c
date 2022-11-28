#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "validateCourse.h"

/*****************************************************************************
Function Name: validateCourse
Purpose: The function takes the passed course ID and ensures it is in the correct format
Function in parameters: coursePtr, length, index, courseIndex, validateIndex
Function out parameter: validInput
Version: 1
Author: XYZ
*****************************************************************************/
int validateCourse(char *coursePtr, int index, int courseIndex, int validateIndex)
{
    int alphaCounter = 0, digitCounter = 0, validInput = 0;

    /*Loop up to courseArray and increment*/
    for (; validateIndex < coursePtr[courseIndex]; validateIndex++)
    {
        /*If its not a digit increment alphaCounter*/
        if (!isdigit(coursePtr[courseIndex]))
        {
            alphaCounter++;
        }
        /*If its not a alpha increment alphaCounter*/
        if (!isalpha(coursePtr[courseIndex]))
        {
            digitCounter++;
        }
        /*Increment courseIndex for course Array*/
        courseIndex++;
    }
    /*If digitCounter is less than or more than 4 OR alphaCounter is less than ore more than 3 print error and validInput = 0*/
    if ((digitCounter > 4 || digitCounter < 4) || (alphaCounter > 3 || alphaCounter < 3))
    {
        printf("Incorect Course Id input [3-Alphas][4-digits]\n");
        printf("Enter the course index[");
        printf("%d", index);
        printf("] course id [3-Alphas][4-digits]: ");
        validInput = 0;
    }
    /*Return 1*/
    else
    {
        validInput = 1;
    }

    return validInput;
}
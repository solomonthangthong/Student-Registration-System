#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "validateStuNum.h"

/*****************************************************************************
Function Name: validateStudent
Purpose: Pass index, and other parameters to validate the student number that is in the array.
Function in parameters: studentPtr, length, index, countIndex, validateIndex, innerIndex
Function out parameter: validInput
Version: 1
Author: XYZ
*****************************************************************************/
int validateStudent(char *studentPtr, int length, int index, long int validateIndex, long int innerIndex)
{
    int validInput = 2;
    int numberOfDigits = 0;

    /*Loop from passed index value to student Array with passed Index and increment*/
    for (; validateIndex < studentPtr[innerIndex]; validateIndex++)
    {
        /*If its not a digit validInput becomes 0*/
        if (!isdigit(studentPtr[innerIndex]))
        {
            validInput = 0;
        }
        /*Increment numberOfDigits and innerIndex*/
        else
        {
            numberOfDigits++;
            innerIndex++;
        }
        /*if innerIndex is equal to length validInput is 1*/
        if (innerIndex == length)
        {
            validInput = 1;
        }
        /*If validInput is 0, check if innerIndex is 0. If its not decrement*/
        if (validInput == 0)
        {
            if (innerIndex == 0)
            {
            }
            else
            {
                innerIndex--;
                numberOfDigits--;
            }
            break;
        }
    }
    /*If number of digits is 5 validInput is 1 */
    if (numberOfDigits == 5)
    {
        validInput = 1;
    }
    /*If numberofDigits is less  than 5 or greater OR validInput is 0 print screen and return 0.*/
    if ((numberOfDigits > 5 || numberOfDigits < 5) || validInput == 0)
    {
        printf("Student ID must be 5 digits\n");
        printf("Enter the student index[");
        printf("%d", index);
        printf("] student id [5-digits]: ");

        if (innerIndex == 0)
        {
        }
        else
        {
            innerIndex--;
            validInput = 0;
        }
    }
    return validInput;
}

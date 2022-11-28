#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registerStudent.h"

/*****************************************************************************
Function Name: registerStudent
Purpose: Go through 2D array and insert index of Student ID, index of Course ID, and registration status.
Function in parameters: void
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void registerStudent(int **regTable, int studentPos, int coursePos, int col, int index, char *studentPtr, char *coursePtr)
{
    int innerIndex;
    int thisFunctionIndex, breakVar = 1;
    /*Add one to the passed Index so that the loop only increments by 1*/
    index = index + 1;
    /*Loop up to the passed Index value and increment*/
    for (thisFunctionIndex = 0; thisFunctionIndex <= index; thisFunctionIndex++)
    {

        /*Looping from row index and checking each column*/
        for (innerIndex = 0; innerIndex < col; innerIndex++)
        {
            /*if its the first column*/
            if (innerIndex == 0)
            {
                /*If the index value is less than 0*/
                if (regTable[thisFunctionIndex][innerIndex] < 0)
                {
                    regTable[thisFunctionIndex][innerIndex] = studentPos;
                }
            }
            /*If its the second column*/
            if (innerIndex == 1)
            {
                /*If the index value is less than 0*/
                if (regTable[thisFunctionIndex][innerIndex] < 0)
                {
                    regTable[thisFunctionIndex][innerIndex] = coursePos;
                }
            }
            /*If its the third column*/
            if (innerIndex == 2)
            {
                /*If this 2D array[rowIndex][columnIndex] == 1 (registered) && 2D array[rowIndex][studentID column] == student Index && 2D array[rowIndex][courseID column] == course ID*/
                if (regTable[thisFunctionIndex][innerIndex] == 1 && regTable[thisFunctionIndex][0] == studentPos && regTable[thisFunctionIndex][1] == coursePos)
                {
                    int length = 0;
                    int lessThanIndex = 0;
                    length = studentPos;
                    lessThanIndex = length + 5;

                    printf("Already on record.\n");
                    printf("Student ID ");
                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", studentPtr[length]);
                    }
                    printf(" cannot register to ");

                    length = coursePos;
                    lessThanIndex = length + 7;

                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", coursePtr[length]);
                    }
                    printf("\n");

                    printf("Registration Unsucessful");

                    breakVar = 0;

                    if (breakVar != 1)
                    {
                        break;
                    }
                }

                /*If this 2D array[rowIndex][columnIndex] == 2 (unregistered) && 2D array[rowIndex][studentID column] == student Index*/
                if (regTable[thisFunctionIndex][innerIndex] == 2 && regTable[thisFunctionIndex][0] == studentPos)
                {
                    regTable[thisFunctionIndex][innerIndex] = 1;
                    printf("Registration Successful");
                    breakVar = 0;
                }
                /*If this 2D array[rowIndex][columnIndex] == 0 (dropped) && 2D array[rowIndex][studentID column] == student Index && 2D array[rowIndex][courseID column] == course ID*/
                if (regTable[thisFunctionIndex][innerIndex] == 0 && regTable[thisFunctionIndex][0] == studentPos && regTable[thisFunctionIndex][1] == coursePos)
                {
                    int length = 0;
                    int lessThanIndex = 0;
                    length = studentPos;
                    lessThanIndex = length + 5;

                    printf("Student ID ");
                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", studentPtr[length]);
                    }
                    printf(" have dropped out from course ");

                    length = coursePos;
                    lessThanIndex = length + 7;

                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", coursePtr[length]);
                    }
                    printf("\n");

                    length = studentPos;
                    lessThanIndex = length + 5;

                    printf("Student ID ");
                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", studentPtr[length]);
                    }
                    printf(" cannot register to course ");

                    length = coursePos;
                    lessThanIndex = length + 7;

                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", coursePtr[length]);
                    }
                    breakVar = 0;
                }
            }
        }

        if (breakVar != 1)
        {
            break;
        }
    }

    printf("\n");
}
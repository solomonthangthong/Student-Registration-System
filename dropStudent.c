#include "dropStudent.h"
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************
Function Name: dropStudent
Purpose: Go through 2D array and find the student and course that is being dropped.
Function in parameters: void
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void dropStudent(int **regTable, int row, int col)
{
    int innerIndex, index, selection;

    printf("\nPlease select Index number to drop student registration: ");
    scanf("%d", &selection);
    /*Loop up to the number of rows*/
    for (index = 0; index < row; index++)
    {
        /*If the index matches the index user wants to drop*/
        if (index == selection)
        {
            /*Loop up to column*/
            for (innerIndex = 0; innerIndex < col; innerIndex++)
            {
                /*once it reaches third column */
                if (innerIndex == 2)
                {
                    /*Change 1 to 0*/
                    if (regTable[index][innerIndex] == 1)
                    {
                        regTable[index][innerIndex] = 0;
                    }
                }
            }
        }
    }
}
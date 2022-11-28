#include "printTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
Function Name: printTable
Purpose: The function prints the registration table.
Function in parameters: regTable, row, col, studentPtr, couresPtr
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void printTable(int **regTable, int row, int col, char *studentPtr, char *coursePtr)
{
    int index, innerIndex = 0;
    printf("%s%s%s", "               ", "        Registration Table", "               ");
    printf("%s%s%s%s", "\nRegistration Index     ", "Student ID       ", "Course ID        ", "Registration Status\n");
    /*Loop up until row*/
    for (index = 0; index < row; index++)
    {
        /*If the index is equal or greather than 0 && regTable 2D array has a value equal or greater than 0*/
        if (index >= 0 && regTable[index][innerIndex] >= 0)
        {
            printf("%s%d%s", "         ", index, "             ");
        }
        /*Loop up to the number of columns*/
        for (; innerIndex < col; innerIndex++)
        {
            /*If 2D array value is equal or greater than 0*/
            if (regTable[index][innerIndex] >= 0)
            {
                /*If index is 0 then its the first column index */
                if (innerIndex == 0)
                {
                    int length = 0;
                    int lessThanIndex = 0;
                    length = regTable[index][innerIndex];
                    lessThanIndex = length + 5;

                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", studentPtr[length]);
                    }
                    printf("            ");
                }

                /*If index is 1 then its the second column index */
                if (innerIndex == 1)
                {
                    int length = 0;
                    int lessThanIndex = 0;
                    length = regTable[index][innerIndex];
                    lessThanIndex = length + 7;

                    for (; length < lessThanIndex; length++)
                    {
                        printf("%c", coursePtr[length]);
                    }
                    printf("          ");
                }
                /*If index is 2 then its the third column index*/
                if (innerIndex == 2)
                {
                    if (regTable[index][innerIndex] == 1)
                    {
                        printf("R");
                    }

                    if (regTable[index][innerIndex] == 0)
                    {
                        printf("D");
                    }
                    printf("            ");
                }
            }
        }
        innerIndex = 0;
        if (regTable[index][innerIndex] >= 0)
        {
            printf("\n");
        }
    }
}
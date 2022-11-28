#include "free2D.h"
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************
Function Name: numOfStudents
Purpose: Free memory from 2D malloc allocated memory
Function in parameters: void
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void free2DMalloc(int **regTable, int row)
{
    int index;
    /*Loop up to the number of rows and free each column*/
    for (index = 0; index < row; index++)
    {
        free(regTable[index]);
    }
    /*Free the rows*/
    free(regTable);
}
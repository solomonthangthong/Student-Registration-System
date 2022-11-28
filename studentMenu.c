#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "studentMenu.h"

/*****************************************************************************
Function Name: studentMenu
Purpose: The function asks users input the student IDs for their table.
Function in parameters: studentPtr, studentSize
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void studentMenu(char *studentPtr, int studentSize)
{
    int index, validInput, length;
    long int validateIndex = 0, innerIndex = 0, studentMemArrayIndex = 0;
    char temp, *pointLocation;
    char tempHolder[35];

    /*Loop up to studentSize*/
    for (index = 0; index < studentSize; index++)
    {
        printf("Enter the student index[");
        printf("%d", index);
        printf("] student id [5-digits]: ");

        do
        {
            scanf("%c", &temp);
            scanf("%[^\n]", tempHolder);
            length = strlen(tempHolder);
            validInput = validateStudent(tempHolder, length, index, validateIndex, innerIndex);
            /*if ValidInput is not 0 increment these values*/
            if (validInput != 0)
            {

                pointLocation = strstr(studentPtr, tempHolder);
                /*if its null the ID was not found in the Array*/
                if (pointLocation != NULL)
                {
                    validInput = 0;
                    printf("Student ID already registered. Please enter a new Student ID: ");
                }

                else
                {
                    validInput = 1;
                    memcpy(&studentPtr[studentMemArrayIndex], tempHolder, sizeof(tempHolder));
                    studentMemArrayIndex += 5;
                }
            }
        } while (validInput != 1);
    }
}
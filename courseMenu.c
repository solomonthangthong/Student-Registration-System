#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "courseMenu.h"

/*****************************************************************************
Function Name: courseMenu
Purpose: The function asks users input the course IDs for their table.
Function in parameters: coursePtr, courseNumSize
Function out parameter: void
Version: 1
Author: XYZ
*****************************************************************************/
void courseMenu(char *coursePtr, int courseNumSize)
{
    int courseIndex = 0, index, validInput, length, validateIndex = 0, courseMemArrayIndex = 0;
    char temp, *pointLocation;
    char tempHolder[35];

    /*Loop up to the number of Courses*/
    for (index = 0; index < courseNumSize; index++)
    {
        printf("Enter the course index[");
        printf("%d", index);
        printf("] course id [3-Alphas][4-digits]: ");

        do
        {
            scanf("%c", &temp);
            scanf("%[^\n]", tempHolder);
            length = strlen(tempHolder);
            /*If user enters a course ID with length less than 7 OR greater than 7*/
            if (length > 7 || length < 7)
            {
                printf("Incorrect Course ID length [7-caharacter ID]\n");
                printf("Enter the course index[");
                printf("%d", index);
                printf("] course id [3-Alphas][4-digits]: ");
                validInput = 0;
            }
            /*If length matches 7 send it off to be validated*/
            if (length == 7)
            {
                validInput = validateCourse(tempHolder, index, courseIndex, validateIndex);
                if (validInput != 0)
                {
                    pointLocation = strstr(coursePtr, tempHolder);

                    if (pointLocation != NULL)
                    {
                        validInput = 0;
                        printf("Course ID already registered. Please enter a new Course ID: ");
                    }
                    else
                    {
                        validInput = 1;
                        memcpy(&coursePtr[courseMemArrayIndex], tempHolder, sizeof(tempHolder));
                        courseMemArrayIndex += 7;
                    }
                }
                else
                {
                }
            }

        } while (validInput != 1);
    }
}
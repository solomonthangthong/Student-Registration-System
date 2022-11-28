#include <stdio.h>
#include <string.h>
#include "course2Course.h"

/*****************************************************************************
Function Name: courseToCourse
Purpose: The function lists the course ID that are available, and then asks users
which one they would like to register into. The enter value is then compared to the
Course ID array and if it matches, the index of the course ID is returned.
Function in parameters: coursePtr, courseNumSize
Function out parameter: return postion index of Course
Version: 1
Author: XYZ
*****************************************************************************/
int courseToCourse(char *coursePtr, int courseNumSize)
{
    int index, printIndex = 0, courseIndex = 7, length, validInput, position, validateIndex = 0;
    char temp;
    char tempHolder[42];
    char *pointLocation;

    printf("List of Available Course ID\n");
    /*Loop up to the number of Courses*/
    for (index = 0; index < courseNumSize; index++)
    {
        printf("Index %d", index);
        printf("   ");
        /*Loop up to the courseIndex and print each individual index*/
        for (; printIndex < courseIndex; printIndex++)
        {
            printf("%c", coursePtr[printIndex]);
        }
        printf("\n");
        courseIndex += 7;
    }

    printf("Enter the Course ID [3-Alpha][4-Digits]: ");

    do
    {
        scanf("%c", &temp);
        scanf("%[^\n]", tempHolder);
        length = strlen(tempHolder);
        if (length > 7 || length < 7)
        {
            printf("Incorrect Course ID length [7-caharacter ID]\n");
            printf("Enter the course index[");
            printf("%d", index);
            printf("] course id [3-Alphas][4-digits]: ");
            validInput = 0;
        }

        if (length == 7)
        {
            validInput = validateCourse(tempHolder, index, 0, 7);
            if (validInput != 0)
            {
                pointLocation = strstr(coursePtr, tempHolder);

                if (pointLocation != NULL)
                {
                    position = pointLocation - coursePtr;
                    validateIndex += 7;
                }

                else
                {
                    validInput = 0;
                    printf("Course ID not found. Please enter a registered course.\n");
                    printf("Enter the Course ID to register a course: ");
                }
            }
        }

    } while (validInput != 1);

    return position;
}
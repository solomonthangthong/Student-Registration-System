#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "student2Course.h"

/*****************************************************************************
Function Name: studentToCourse
Purpose: The function lists the student ID that are available, and then asks users
which one they would like to register into. The enter value is then compared to the
student ID array and if it matches, the index of the student ID is returned.
Function in parameters: studentPtr, studentSize
Function out parameter: return postion index of Course
Version: 1
Author: XYZ
*****************************************************************************/
int studentToCourse(char *studentPtr, int studentSize)
{
    int index, studentIndex = 5, length, validInput, position;
    long int validateIndex = 0, innerIndex = 0;
    char temp;
    char *pointLocation;
    char tempHolder[35];

    printf("List of Student ID\n");

    /*Loop up to studentSize*/
    for (index = 0; index < studentSize; index++)
    {
        printf("Index %d", index);
        printf("   ");
        /*Loop up to studentIndex and print each value in the student Array index*/
        for (; innerIndex < studentIndex; innerIndex++)
        {
            printf("%c", studentPtr[innerIndex]);
        }
        printf("\n");

        /*Increment by 5 to get the next student ID*/
        studentIndex += 5;
    }

    innerIndex = 0;

    printf("Enter the Student's ID to register a course: ");

    do
    {
        scanf("%c", &temp);
        scanf("%[^\n]", tempHolder);
        length = strlen(tempHolder);
        validInput = validateStudent(tempHolder, length, index, validateIndex, innerIndex);
        /*if ValidInput is not 0 use strstr to see if it can be found in student Array*/
        if (validInput != 0)
        {
            pointLocation = strstr(studentPtr, tempHolder);
            /*if its null the ID was not found in the Array*/
            if (pointLocation != NULL)
            {
                position = pointLocation - studentPtr;
                validInput = 1;
            }

            else
            {
                validInput = 0;
                printf("Student ID not found. Please enter a registered student.\n");
                printf("Enter the Student's ID to register a course: ");
            }
        }

    } while (validInput != 1);
    /*Return index positon found*/
    return position;
}
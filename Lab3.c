/*
 * Student Registration System
 * @Author: Solomon Thangthong 041023691
 */
#include <stdio.h>
#include <stdlib.h>
#include "studentMenu.h"
#include "mainMenu.h"
#include "courseMenu.h"
#include "student2Course.h"
#include "course2Course.h"
#include "validateStuNum.h"
#include "validateCourse.h"
#include "registerStudent.h"
#include "printTable.h"
#include "dropStudent.h"
#include "free2D.h"

/*****************************************************************************
Function Name: numOfStudents
Purpose: Accept user input for number of student to register
Function in parameters: int
Function out parameter: return convertNum
Version: 1
Author: XYZ
*****************************************************************************/
int numOfStudents()
{
    int wrongInputCounter = 1;
    char validInput = 1;
    int num = 0;

    printf("Welcome to the Student Registration System.\n");
    printf("\nEnter the number of students to register: ");
    do
    {
        /*If its 0 run this so that scanf temp can take the \n*/
        if (validInput == 0)
        {
            scanf("%d", &num);
            validInput = 1;
        }
        else
        {
            scanf("%d", &num);
        }
        /*If input is not a digit*/
        if (isalpha(num))
        {
            validInput = 0;
            wrongInputCounter++;
            printf("Please enter a numeric value: ");
        }
        else
        {
            validInput = 1;
        }
    } while (validInput != 1);

    return num;
}
/*****************************************************************************
Function Name: numOfCourses
Purpose: Accept user input for number of courses to register
Function in parameters: int
Function out parameter: return convertNum
Version: 1
Author: XYZ
*****************************************************************************/
int numOfCourses()
{
    char *num;
    char validInput = 1, convertNum = 0, temp;
    int wrongInputCounter = 1;
    num = (char *)malloc(wrongInputCounter * sizeof(char));

    printf("\nEnter the number of courses available: ");
    do
    {
        if (validInput == 0)
        {
            num = (char *)realloc(num, (wrongInputCounter * sizeof(char *)));
            scanf("%c", &temp);
            scanf("%[^\n]", num);
            validInput = 1;
        }
        else
        {
            scanf("%c", &temp);
            scanf("%[^\n]", num);
        }

        /*if not a digit */
        if (!isdigit(*num))
        {
            validInput = 0;
            wrongInputCounter++;
            printf("Please enter a numeric value: \n");
        }
        else
        {
            validInput = 1;
        }
    } while (validInput != 1);

    /*convert to int */
    convertNum = atoi(num);
    free(num);
    return convertNum;
}

/*****************************************************************************
Function Name: **registrationTable
Purpose: Populate 2D array with bytes using malloc
Function in parameters: int
Function out parameter: return pointTable
Version: 1
Author: XYZ
*****************************************************************************/
int **registrationTable(int row, int col)
{
    int **pointTable, index, innerIndex;
    /*Malloc the number of rows in 2D Array*/
    pointTable = (int **)malloc((row * 2) * sizeof(int *));
    /*Loop up to the number of rows and malloc each colum in the row*/
    for (index = 0; index < row; index++)
    {
        pointTable[index] = (int *)malloc(col * sizeof(int *));
    }
    /*Loop up to the number of rows*/
    for (index = 0; index < row; index++)
    {
        /*Loop up to the number of columns*/
        for (innerIndex = 0; innerIndex < col; innerIndex++)
        {
            /*If innerIndex = 0, first column put -1*/
            if (innerIndex == 0)
            {
                pointTable[index][innerIndex] = -1;
            }
            /*If innerIndex = 1, second column put -2*/
            if (innerIndex == 1)
            {
                pointTable[index][innerIndex] = -1;
            }
            /*If innerIndex = 3, third column put 2*/
            if (innerIndex == 2)
            {
                pointTable[index][innerIndex] = 2;
            }
        }
    }

    return pointTable;
}

int main()
{

    int index = 0, input, col = 3, courseNumSize, row, stuPos, coursePos;
    int **regTable;
    char *coursePtr;
    /*Number of students*/
    int studentSize = numOfStudents();
    /*Allocating space for studentPtr to point to studentSize of characters. AN ARRAY OF POINTERS TO CHARACTERS*/
    char *studentPtr = (char *)malloc((studentSize * 2) * sizeof(char *));
    /*Set values to 0 in Student Array*/
    memset(studentPtr, 0, sizeof(char));
    /*Function to enter Student ID*/
    studentMenu(studentPtr, studentSize);
    courseNumSize = numOfCourses();
    /*Row size for 2D Array*/
    row = studentSize * courseNumSize;
    /*Allocating bytes to course Array*/
    coursePtr = (char *)malloc((courseNumSize * 2) * sizeof(char *));
    /*Function to enter Course ID*/
    courseMenu(coursePtr, courseNumSize);
    regTable = registrationTable(row, col);
    /*Loop until 4 is entered*/
    do
    {
        mainMenu();
        printf("Enter an option from the menu: ");
        scanf("%d", &input);

        switch (input)
        {

        case 1:
            stuPos = studentToCourse(studentPtr, studentSize);
            coursePos = courseToCourse(coursePtr, courseNumSize);
            registerStudent(regTable, stuPos, coursePos, col, index, studentPtr, coursePtr);
            index++;
            break;
        case 2:
            printTable(regTable, row, col, studentPtr, coursePtr);
            dropStudent(regTable, row, col);
            index--;
            break;
        case 3:
            printTable(regTable, row, col, studentPtr, coursePtr);
            break;
        case 4:
            free2DMalloc(regTable, row);
            free(studentPtr);
            free(coursePtr);
            break;

        default:
            printf("Please select a number from 1 - 4\n");
            break;
        }
    } while (input != 4);

    return EXIT_SUCCESS;
}
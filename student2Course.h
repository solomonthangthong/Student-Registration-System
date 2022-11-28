#include <stdio.h>
#include <ctype.h>
#include <string.h>
#ifndef STUDENT_TO_COURSE
#define STUDENT_TO_COURSE

int validateStudent(char *studentPtr, int length, int index, long int validateIndex, long int innerIndex);
int studentToCourse(char *studentPtr, int studentSize);

#endif
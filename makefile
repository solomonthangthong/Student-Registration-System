CC = gcc
CC_FLAGS =  -g -pedantic -W -Wall
FILES = course2Course.c courseMenu.c dropStudent.c free2D.c Main.c mainMenu.c printTable.c registerStudent.c student2Course.c studentMenu.c validateCourse.c validateStuNum.c
OUT_EXE = Lab3

build: $(FILES)
	   $(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

clean: rm -f *.o core *.exe *~

rebuild: clean build
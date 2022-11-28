# Student-Registration-System
This application serves a purpose of creating a table with registered students and courses. Users are allowed to create a number of students, alongside course codes that match
Three Alpha and Four digits system. The program also allows you to drop students, after you drop a student they cannot be registered back into the course.
## How to run this application
Windows   
- Download source files
- Compile with makefile
- Run exe file
Linux
- Download source files
- Compile with command make
- ./Main in terminal

### Example
This is an example of adding an item into the inventory & displaying the item afterwards.
``` 
Welcome to the Student Registration System.

Enter the number of students to register: 3
Enter the student index[0] student id [5-digits]: 23456 
Enter the student index[1] student id [5-digits]: 65432
Enter the student index[2] student id [5-digits]: 34567 

Enter the number of courses available: 3
Enter the course index[0] course id [3-Alphas][4-digits]: CST1000
Enter the course index[1] course id [3-Alphas][4-digits]: CST3245
Enter the course index[2] course id [3-Alphas][4-digits]: CST6577

Main Menu:
 [1] Register a student into a course.
 [2] Drop a student from a course.
 [3] Display Registration table.
 [4] Exit.
Enter an option from the menu: 1
List of Student ID
Index 0   23456
Index 1   65432
Index 2   34567
Enter the Student's ID to register a course: 23456
List of Available Course ID
Index 0   CST1000
Index 1   CST3245
Index 2   CST6577
Enter the Course ID [3-Alpha][4-Digits]: CST6577
Registration Successful

Main Menu:
 [1] Register a student into a course.
 [2] Drop a student from a course.
 [3] Display Registration table.
 [4] Exit.
Enter an option from the menu: 3
                       Registration Table
Registration Index     Student ID       Course ID        Registration Status
         0             23456            CST6577          R

Main Menu:
 [1] Register a student into a course.
 [2] Drop a student from a course.
 [3] Display Registration table.
 [4] Exit.
Enter an option from the menu: 2
                       Registration Table
Registration Index     Student ID       Course ID        Registration Status
         0             23456            CST6577          R

Please select Index number to drop student registration: 0

Main Menu:
 [1] Register a student into a course.
 [2] Drop a student from a course.
 [3] Display Registration table.
 [4] Exit.
Enter an option from the menu: 3
                       Registration Table
Registration Index     Student ID       Course ID        Registration Status
         0             23456            CST6577          D

Main Menu:
 [1] Register a student into a course.
 [2] Drop a student from a course.
 [3] Display Registration table.
 [4] Exit.
Enter an option from the menu: 4
```

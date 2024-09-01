# **Student Data Management System**
### **Overview**
The **Student Data Management System** is a C++ application designed to efficiently manage student records using a **Binary Search Tree (BST).** This system allows users to perform various operations on the student database 🫙, such as searching 🔍, inserting new records ➕, and printing records based on different criteria.

### **Features**
**1. Search for a Student**: Find a student record by their UNIQUE ID.
**2. Insert a New Student**: Add a new student record to the system, provided the ID is unique.
**3. Grade-Based Filtering**: Display students whose grades match certain criteria (greater than, less than, or equal to a specified grade).
**4. Inorder, Preorder, and Postorder Traversal**: Print all student records by traversing the BST in different orders.
**5. Persistent Storage**: Student data is stored in and retrieved from a file named *sample.data*.

Project Structure
BinTreeElemType: A class to represent an element in the BST, storing the student's ID and record number.
Node: A class representing a node in the BST, with pointers to left and right children.
Student: A class to store the details of a student (ID, name, gender, cohort, year, grade).
Core Functions:
Binary Search Tree Operations: Functions to create, insert, search, and traverse the BST.
File Handling: Functions to build the BST from a file and print student details based on record numbers.
Grade-Based Operations: Functions to filter and display students based on their grades.
File Descriptions
sample.data: A comma-separated file that stores the student records. Each line represents a student with the following fields: ID, last name, first name, gender, cohort, year, and grade.
main.cpp: The main C++ source file that contains the implementation of the entire system.
How to Use
Compile the Program: Use a C++ compiler to compile main.cpp. For example:

bash
Copy code
g++ main.cpp -o student_data_management
Run the Program:

bash
Copy code
./student_data_management
Choose an Option: The program presents a menu where you can:

Search for a student by ID.
Insert a new student record.
Print students based on grade criteria.
Traverse the BST to display all students in different orders.
Quit the application.
Input Data Format
sample.data should contain student records in the following format:
sql
Copy code
ID,LastName,FirstName,Gender,Cohort,Year,Grade
Example:
r
Copy code
101,Doe,John,M,CS,2023,85.5
102,Smith,Jane,F,EE,2022,92.0
Sample Output
Search for a Student:

rust
Copy code
Give student's ID: 101
101,John,Doe,M,CS,2023,85.5
Insert a New Student:

rust
Copy code
Give student's ID: 103
Give Student's lastName: White
Give Student's firstName: Alice
Give student's gender M/F: F
Give Student's cohort: ME
Give student's registration year: 2023
Give student's grade (0-100): 88.0
Print Students with Grade >= 85:

r
Copy code
Give the grade: 85
101,John,Doe,M,CS,2023,85.5
102,Jane,Smith,F,EE,2022,92.0
Dependencies
C++ Compiler: A standard C++ compiler like g++ is required to compile the source code.
Limitations
File Dependency: The system depends on the sample.data file being present in the same directory.
Basic Error Handling: The program handles some errors (e.g., file not found, invalid input), but improvements could be made.
Future Enhancements
Improved Error Handling: Add more robust error handling and user input validation.
User Interface: Implement a more user-friendly interface, potentially with a graphical interface.
Additional Features: Expand functionality, such as deleting a student record, updating existing records, or advanced searching options.
License
This project is licensed under the MIT License. Feel free to modify and use it as per your needs.
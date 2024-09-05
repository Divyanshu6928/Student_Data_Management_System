# **Student Data Management System**
### **Overview**
The **Student Data Management System** is a C++ application designed to efficiently manage student records using a **Binary Search Tree (BST).** This system allows users to perform various operations on the student database 🫙, such as searching 🔍, inserting new records ➕, and printing records based on different criteria.

### **Features**
**1. Search for a Student 🔎**: Find a student record by their UNIQUE ID.

**2. Insert a New Student ➕**: Add a new student record to the system, provided the ID is unique.

**3. Grade-Based Filtering 🔠**: Display students whose grades match certain criteria (greater than, less than, or equal to a specified grade).

**4. Inorder, Preorder, and Postorder Traversal ⬆️⬇️➡️**: Print all student records by traversing the BST in different orders.

**5. Persistent Storage 🖥️**: Student data is stored in and retrieved from a file named *sample.data*.

### **Project Structure**
**1. BinTreeElemType**: A class to represent an element in the BST, storing the student's ID and record number.

**2. Node**: A class representing a node in the BST, with pointers to left and right children.

**3. Student**: A class to store the details of a student (ID, name, gender, cohort, year, grade).

### **Core Functions:**

**1. Binary Search Tree Operations**: Functions to create, insert, search, and traverse the BST.

**2. File Handling**: Functions to build the BST from a file and print student details based on record numbers.

**3. Grade-Based Operations**: Functions to filter and display students based on their grades.

### **File Descriptions**
**sample.data**: A comma-separated file that stores the student records. Each line represents a student with the following fields: ID, last name, first name, gender, cohort, year, and grade.

**main.cpp**: The main C++ source file that contains the implementation of the entire system.

## How to Use ❓❓

**Choose an Option**: The program presents a menu where you can:

**Search for a student by ID.**

**Insert a new student record.**

**Print students based on grade criteria.**

**Traverse the BST to display all students in different orders.**

**Quit the application.**
#### Input Data Format
sample.data should contain student records in the following format:

sql

ID,LastName,FirstName,Gender,Cohort,Year,Grade
#### **Example:**

![image](https://github.com/user-attachments/assets/40dd951e-933b-4622-bb48-da33134a3511)

**SEARCH**

![image](https://github.com/user-attachments/assets/4af8753e-de83-49af-bae1-c4dba56765ef)

**INORDER TRAVERSAL**

![image](https://github.com/user-attachments/assets/dfd5c9c9-d559-4f9d-9c38-1ac260601490)

**ON BASIS OF GRADE**

![image](https://github.com/user-attachments/assets/9901f874-c163-4a3b-bfd9-650e2685007f)

![image](https://github.com/user-attachments/assets/b696f48c-047c-4bdc-82c0-9beec53417b4)



### **Dependencies**
C++ Compiler: A standard C++ compiler like g++ is required to compile the source code.

### **Limitations**
**File Dependency**: The system depends on the sample.data file being present in the same directory.

**Basic Error Handling**: The program handles some errors (e.g., file not found, invalid input), but improvements could be made.


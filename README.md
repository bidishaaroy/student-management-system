# Student Management System

This is a simple student management system that allows the user to add student information such as name, student ID, GPA and program information. The user is able to update, edit and delete student information and also sort students by name (alphabetically) and GPA (highest to lowest).

**Features**

• Add a new student
• List all students
• Search for a student by ID
• Update student information (name, program, GPA)
• Delete a student
• Sort students by GPA (highest to lowest)
• Sort students by name (A–Z)
• Save student data to a file
• Load student data from a file


**How It Works:**

The system stores students in a vector<Student>. Data is saved to and loaded from a text file. Then, using bubble sort, the data is sorted. The program runs in a loop until the user chooses the exit option

**How to Compile and Run:**

Once you are in the project directory, you can run the following command:

g++ main.cpp Student.cpp StudentManager.cpp -o studentmgmt
./studentmgmt

The program will then run the Student Management System. Enjoy!

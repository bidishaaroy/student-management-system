#include <iostream>
#include <vector>
#include "studentmanager.h"

using namespace std;

int main() {
    vector<Student> students;
    const string filename = "students.txt";

    load(students, filename);

    while (true) {
        cout << "\n==== Student Management System ====\n"
             << "1. Add a student\n"
             << "2. Show list of all students\n"
             << "3. Search by ID\n"
             << "4. Update student information\n"
             << "5. Delete student\n"
             << "6. Sort by GPA\n"
             << "7. Sort by name\n"
             << "8. Save to file\n"
             << "9. Load from file\n"
             << "0. Exit\n"
             << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) addstudent(students);
        else if (choice == 2) showall(students);
        else if (choice == 3) searchbyID(students);
        else if (choice == 4) updatestudent(students);
        else if (choice == 5) deletestudent(students);
        else if (choice == 6) sortbyGPA(students);
        else if (choice == 7) sortbyname(students);
        else if (choice == 8) save(students, filename);
        else if (choice == 9) load(students, filename);
        else if (choice == 0) {
            char ans;
            cout << "Save before exit? (y/n): ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y') save(students, filename);
            cout << "Bye.\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

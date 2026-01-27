#include "studentmanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

int findStudentIndexById(const vector<Student>& students, int id) {
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].id == id) return i;
    }
    return -1;
}

void addstudent(vector<Student>& students) {
    Student s;

    cout << "Enter ID: ";
    cin >> s.id;

    if (findStudentIndexById(students, s.id) != -1) {
        cout << "This ID already exists.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter program: ";
    getline(cin, s.program);

    cout << "Enter GPA: ";
    cin >> s.gpa;

    students.push_back(s);
    cout << "Student added.\n";
}

void showall(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "---- Student List ----\n";
    for (const auto& s : students) {
        cout << "ID: " << s.id << " | Name: " << s.name << " | Program: " << s.program << " | GPA: " << s.gpa << "\n";
    }
}

void searchbyID(const vector<Student>& students) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    int idx = findStudentIndexById(students, id);
    if (idx == -1) {
        cout << "Student not found.\n";
    } else {
        cout << "Found: ID=" << students[idx].id
             << ", Name =" << students[idx].name
             << ", Program =" << students[idx].program
             << ", GPA =" << students[idx].gpa << "\n";
    }
}

void updatestudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    int idx = findStudentIndexById(students, id);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "1) Update name\n";
    cout << "2) Update GPA\n";
    cout << "Choose: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new name: ";
        getline(cin, students[idx].name);
        cout << "Name updated.\n";
    } else if (choice == 2) {
        cout << "Enter new GPA: ";
        cin >> students[idx].gpa;
        cout << "GPA updated.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}

void deletestudent(vector<Student>& students) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    int idx = findStudentIndexById(students, id);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }

    students.erase(students.begin() + idx);
    cout << "Student deleted.\n";
}

void save(const vector<Student>& students, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Could not open file for writing.\n";
        return;
    }

    for (const auto& s : students) {
        fout << s.id << "|" << s.name << "|" << s.program << "|"<< s.gpa << "\n";
    }

    cout << "Saved to " << filename << "\n";
}

void load(vector<Student>& students, const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "No file found to load.\n";
        return;
    }

    students.clear();

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string part;

        Student s;
        getline(ss, part, '|');
        s.id = stoi(part);

        getline(ss, s.name, '|');

        getline(ss, s.program, '|');

        getline(ss, part, '|');
        s.gpa = stof(part);

        students.push_back(s);
    }

    cout << "Loaded " << students.size() << " students from " << filename << "\n";
}


void sortbyGPA(vector<Student>& students) {
    if (students.size() < 2) {
        cout << "Not enough students to sort.\n";
        return;
    }

    // bubble sort
    for (int pass = 0; pass < (int)students.size() - 1; pass++) {
        for (int i = 0; i < (int)students.size() - 1 - pass; i++) {
            if (students[i].gpa < students[i + 1].gpa) {
                Student temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
            }
        }
    }

    cout << "Sorted by GPA (highest to lowest).\n";
}

void sortbyname(vector<Student>& students) {
    if (students.size() < 2) {
        cout << "Not enough students to sort.\n";
        return;
    }

    // bubble sort
    for (int pass = 0; pass < (int)students.size() - 1; pass++) {
        for (int i = 0; i < (int)students.size() - 1 - pass; i++) {
            if (students[i].name > students[i + 1].name) {
                Student temp = students[i];
                students[i] = students[i + 1];
                students[i + 1] = temp;
            }
        }
    }

    cout << "Sorted by name (A-Z).\n";
}

#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include <string>
#include "student.h"

using namespace std;

int findStudentIndexById(const vector<Student>& students, int id);

void addstudent(vector<Student>& students);
void showall(const vector<Student>& students);
void searchbyID(const vector<Student>& students);
void updatestudent(vector<Student>& students);
void deletestudent(vector<Student>& students);

void save(const vector<Student>& students, const string& filename);
void load(vector<Student>& students, const string& filename);

void sortbyGPA(vector<Student>& students);  
void sortbyname(vector<Student>& students); 

#endif

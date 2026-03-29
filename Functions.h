#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
// #include <fstream>

using namespace std;

// struct Category {
//     string assignment;
//     float grade;
// };
// struct Calculator {
//     Category category [20];
//     float percentage;
//     string name;
//     int currAssignment;
//     int points;//points per category
// };
//function prototypes
// void readFromFile(Calculator [], int&, bool&, int&);
// void addNewCategory(Calculator [], int&, bool, int&, int&, int&);
// void addGrade(Calculator [], int&);
// int printGrades(Calculator [], int&, string);
// void calculateGrade();
// void saveToFile(Calculator [], int&, string, bool, int&);
// void editMenu(Calculator [], int&, bool, int&, int&, int&);
// void editCategory();
// void deleteCategory();
// void editAssignment();
// void deleteGrade();
// void editCName();
// void editPandP();

int integerUserValidation(int, int);
string twoStringsUserValidation(string, string);
int lessThanZeroUserValidation(int);
#endif
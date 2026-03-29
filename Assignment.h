#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include <fstream>
using namespace std;

class Assignment {
    private:
        string name;
        float grade;
        string comments;
        bool graded;
    public:
        //CURRENTLY ALL FUNCTIONS DONE EXCEPT FOR DESTRUCTOR
        //Constructor and maybe Destructor
        Assignment(string, float, string);
        //~Assignment();//Do I really need a destructor if there is nothing dynamically allocated?
        //Actual Functions
        void displayAssignment();
        //Setters
        void setName(string);
        void setGrade(float);
        void setComments(string);
        //Getters
        string getName();
        float getGrade();
        string getComments();
        bool getGraded();
};

#endif
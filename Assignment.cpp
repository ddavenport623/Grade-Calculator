#include "Assignment.h"

//DONE
Assignment::Assignment(string newName, float newGrade, string newComments){
    name = newName;
    grade = newGrade;
    comments = newComments;
    // graded = isGraded;
}

//DONE
void Assignment::setName(string newName){
    name = newName;
}

//DONE
void Assignment::setGrade(float newGrade){
    grade = newGrade;
}

//DONE
void Assignment::setComments(string newComments){
    comments = newComments;
}

//DONE
string Assignment::getName(){
    return name;
}

//DONE
float Assignment::getGrade(){
    return grade;
}

//DONE
string Assignment::getComments(){
    return comments;
}

//DONE
bool Assignment::getGraded(){
    return graded;
}

//TEST
void Assignment::displayAssignment(){
    cout << "       Assignment Name:\t" << name << endl;
    cout << "                 Grade:\t" << grade << endl;
    cout << "              Comments:\t" << comments << endl << endl << endl;
}
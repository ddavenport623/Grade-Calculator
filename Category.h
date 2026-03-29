#ifndef CATEGORY_H
#define CATEGORY_H
#include "Assignment.h"
#include "Functions.h"
#include <cmath>

class Category {
    private:
        string categoryName;
        float weight;
        int maxAssignments;
        int numAssignments;
        float averageGrade;
    public:
        //Assignment Array
        Assignment** assignmentArray;
        //Constructor and Destructor
        Category(string, float);
        ~Category();
        //Actual functions
        void resizeAssignmentArray();
        void displayAssignmentNames();
        void addNewAssignment();
        void deleteAssignment();
        void calculateCategoryGrade();
        //Getters
        string getName();
        float getWeight();
        int getNumAssignments();
        int getMaxAssignments();
        //Setters
        void incrementNumAssignments();//Technically a setter
        void setCategoryName(string);
        void setWeight(float);
};

#endif
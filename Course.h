#ifndef COURSE_H
#define COURSE_H
#include "Category.h"


class Course {
    private:
        string courseName;//holds the name of the course
        int maxCategories;//Holds the number of space allocated for the current array
        int numCategories;//tracks current number of categories
        int totalweight;//tracks the total weight of the combinged categories
    public:
        //Category array
        Category** categoryArray;
        //Constructor and Destructor
        Course();
        ~Course();
        //Actual Functions
        int getMenuChoice();
        void calculateFinalGrade();
        void resizeCategoryArray();
        void addNewCategory();
        void readFromFile();
        void saveToFile();
        void displayCategoryNames();
        void displayCourse();
        void editMenu();
        void deleteCategory(int);
        //Getters and Setters
        int getNumCategories();
        string getName();
        void setName(string);
};

#endif
// KEY!!!
// TEST - DONE BUT NEEDS TO BE TESTED.
// DONE - COMPLETELY DONE AND TESTED.
// NOT STARTED - NEEDS TO BE COMPLETED.
// FIX - NEED TO GO BACK AND FIX ISSUE.
// IN PROGRESS - STARTED BUT NOT COMPLETED.
// REMOVE - REMOVE LATER, MOSTLY FOR BUG LOCATION
// /**/ - USE FOR BUG DOCUMENTATION. NOT FOR FORMAT FIXES.


/*TO DO LIST
1) Fix read info from file function
2) Create calculate grade function
3) Finish edit menu
*/

#include "Functions.h"
#include "Course.h"

//NOT FINISHED
//NEED TO FIX BEGINNING QUESTIONS
int main(){
    float totalPoints = 0;
    int currentPoints = 0;
    int currentCategory = 0;//tracks num of categories
    bool percent;//holds if course is based on percents or points

    Course *currentClass = new Course();//dynamically allocates the course object
    string strUserInput;//string user input


    cout << "\nHello! Welcome to the grade calculator! Would you like to import a course from a file or create a new one?(Enter FILE or NEW)\n";
    strUserInput = twoStringsUserValidation("FILE", "NEW");
    if (strUserInput == "FILE"){//if user chooses FILE then the information will be read in from a file
       currentClass->readFromFile();
    }
    else {//Otherwise a new course will be created
        string name;//holds courseName
        cout << "What is the name of the Course you are creating?\nENTER: ";
        getline(cin, name);
        currentClass->setName(name);
        // cout << "Are the categories in " << currentClass->getName() << " based on percentages or points?" << endl;
        // strUserInput = twoStringsUserValidation("PERCENT", "POINTS");
        // if(strUserInput == "PERCENT"){
        //     percent = true;
        // }
        // else {
        //     percent = false;
        //     cout << "How many total points are there for the course? ";
        //     cin >> totalPoints;
        //     cin.ignore();
        // }
        //TOO COMPLICATED AT THE MOMENT. I AM JUST GOING TO FOCUS ON PERCENTS RIGHT NOW
    }
    bool quit = false;//Keeps the while loop continuing until user chooses to stop
    while (!quit){
        switch(currentClass->getMenuChoice()){
            case 1://Add new Category
                currentClass->addNewCategory();
                break;
            case 2://Add new assignment
                if(currentClass->getNumCategories() == 0){//If there are no categories then the user should not be able to add an assignment
                    cout << "You must add a category before you add an assignment!\n";
                    break;
                }
                cout << "\nWhich Category would you like to add an assignment to?\n";
                currentClass->displayCategoryNames();
                cout << endl;
                int choice;
                choice = integerUserValidation(1, currentClass->getNumCategories());
                currentClass->categoryArray[choice]->addNewAssignment();
                break;
            case 3://Print out info
                currentClass->displayCourse();
                break;
            case 4://Calculate final grades
                //calculateGrade(/*course, currentCategory*/);
                break;
            case 5://Edit or delete a category or assignment
                currentClass->editMenu();
                //editMenu (course, currentCategory, percent, totalPercentage, totalPoints, currentPoints);
                break;
            case 6://ends program
                quit = true;//exits while loop
        }
    }
    currentClass->saveToFile();
    cout << "\nThanks for using the grade calculator! Good luck with your semester and have a nice day!";
}
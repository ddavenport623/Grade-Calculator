#include "Course.h"
#include "Functions.h"
#include <fstream>

//DONE
int Course::getMenuChoice(){
    cout << "\nWhat would you like to do?" << endl;
    cout << "\t1.\tAdd a new category of assignments\n";
    cout << "\t2.\tAdd a new assignment\n";
    cout << "\t3.\tPrint out current grades\n";
    cout << "\t4.\tCalculate final grade(DOES NOT WORK)\n";
    cout << "\t5.\tEdit or delete a category or assignment(DOES NOT WORK)\n";
    cout << "\t6.\tQuit and save the program because I realized I'm too stupid and I'm going to fail anyway\n";
    return integerUserValidation(1, 6);
}

void Course::calculateFinalGrade(){
    float finalGrade;
    for(int i=0; i<numCategories; i++){
        categoryArray[i]->calculateCategoryGrade();
    }
}

//DONE
Course::Course(){
    courseName = "";
    numCategories = 0;
    maxCategories = 3;
    categoryArray = new Category*();/*Fixed addCategory bug*/
    totalweight = 0;
}

//TEST
Course::~Course(){
    for(int i=0; i<numCategories; i++){
        delete categoryArray[i];
    }
}

//TEST
void Course::resizeCategoryArray(){
    //doubles the size of the array
    Category** newArray = new Category*[maxCategories + 5];
    for (int i = 0; i < maxCategories; i++){//copies old array to new array
        newArray[i] = categoryArray[i];
    }
    delete [] categoryArray;
    categoryArray = newArray;
    maxCategories += 5;//corrects the new max
}

void Course::addNewCategory(){
    string tempName;
    float tempWeight;
    
    cout << "What is the name of this category? ";
    getline(cin, tempName);

    cout << "\nWhat percentage is this course weighted? ";
    cin >> tempWeight;
    cin.ignore();

    totalweight += tempWeight;
    if(totalweight > 100){
        totalweight -=tempWeight;
        cout << "\nCombined weight from the categories exceeds 100%! Try again with a different weight or edit the weight of a different category\n";
        return;
    }

    if(numCategories == maxCategories){//checks if array needs to be expanded
        resizeCategoryArray();
    }
    /*problem: with dynamic allocation
    tried dynamically allocating the Category array
    fixed problem*/
    categoryArray[numCategories] = new Category(tempName, tempWeight);
    numCategories++;
    cout << endl;
}

//FIX
//problem reading in data
void Course::readFromFile(){
    string fileName;
    ifstream file;
    string categoryName;
    string temp;
    float categoryWeight;
    string assignmentName;
    float assignmentGrade;
    string assignmentComments;
    bool assignmentGraded;
    cout << "\nWhat is the name of the file you would like to read from?(ex. Calculus.txt)\nENTER: ";
    getline(cin, fileName);
    fstream MyFile(fileName);
    // file.open(fileName);
    if(!file.is_open()){//checks if file opened properly
        cout << "ERROR there was a problem opening the file\n";
        return;
    }
    getline(file, courseName, '*');
    while(getline(file, categoryName, '#')){
        getline(file, temp, '#');
        categoryWeight = stof(temp);
        if(numCategories == maxCategories){//checks if array needs to be expanded
            resizeCategoryArray();
        }
        categoryArray[numCategories] = new Category(categoryName, categoryWeight);
        numCategories++;
        cout << "\nNew category added\n";//REMOVE
        while(getline(file, assignmentName, '$')){/*Problem might be because there is no $ sign so it is reading the rest of the information and reaches the end of file*/
            cout << "\nGetting Assignment\n";//REMOVE
            getline(file, temp, '$');
            assignmentGrade = stof(temp);
            getline(file, assignmentComments, '$');
            getline(file, temp, '$');
            if(temp == "yes"){
                assignmentGraded = true;
            }
            else{
                assignmentGraded = false;
            }
            if(categoryArray[numCategories]->getNumAssignments() == categoryArray[numCategories]->getMaxAssignments()){
                categoryArray[numCategories]->resizeAssignmentArray();
            }
            categoryArray[numCategories]->assignmentArray[categoryArray[numCategories]->getNumAssignments()] = new Assignment(assignmentName, assignmentGrade, assignmentComments);
            categoryArray[numCategories]->incrementNumAssignments();
            cout << "\nNew Assignment added\n";//REMOVE
            /*Program stops reading in new information here*/
        }
    }
    cout << endl;
}

//TEST
//Might need to change stuff to fix readFromFile
void Course::saveToFile(){
    string saveFileName;
    ofstream file;
    cout << "\nWhat is the name of the file you would like to save to?\nENTER: ";
    getline(cin, saveFileName);
    file.open(saveFileName);
    if(!file.is_open()){//checks if file opened properly
        cout << "ERROR there was a problem opening the file\n";
        return;
    }
    file << courseName << "*";
    for(int i=0; i<numCategories; i++){
        file << categoryArray[i]->getName() << "#";
        file << categoryArray[i]->getWeight() << "#";
        for(int j=0; j<categoryArray[i]->getNumAssignments(); j++){
            file << categoryArray[i]->assignmentArray[j]->getName() << "$";
            file << categoryArray[i]->assignmentArray[j]->getGrade() << "$";
            file << categoryArray[i]->assignmentArray[j]->getComments() << "$";
            if(categoryArray[i]->assignmentArray[j]->getGraded()){
                file << "yes$";
            }
            else{
                file << "no$";
            }
        }
    }
    cout << "\nFile saved successfully\n";
}

//TEST
void Course::displayCategoryNames(){
    for(int i=0; i < numCategories; i++){
        cout << "\nCategory " << i + 1 << ": " << categoryArray[i]->getName() << " - " << categoryArray[i]->getWeight();
    }
}

//TEST
void Course::displayCourse(){
    cout << "\n\n\n" << courseName << endl;
    for (int i=0; i < numCategories; i++){
        cout << "\t" << categoryArray[i]->getName() << " worth " << categoryArray[i]->getWeight() << "%\n";
        for(int j=0; j<categoryArray[i]->getNumAssignments(); j++){
            cout << "\t\t" << categoryArray[i]->assignmentArray[j]->getName() << " - ";
            if(categoryArray[i]->assignmentArray[j]->getGraded()){
                cout << categoryArray[i]->assignmentArray[j]->getGrade() << endl;
                cout << "\t\t\t" << categoryArray[i]->assignmentArray[j]->getComments();
            }
            else{
                cout << "UNGRADED";
            }
            cout << endl;
        }
    }
    cout << "\n\n\n";
}

//IN PROGRESS
void Course::editMenu(){
    int choice;
    cout << "\n\nHow would you like to edit your course?\n";
    cout << "\t1.\tEdit a Category\n";
    cout << "\t2.\tDelete a Category\n";
    cout << "\t3.\tEdit an Assignment\n";
    cout << "\t4.\tDelete an Assignment\n";
    cout << "\t5.\tEdit Course name\n";
    choice = integerUserValidation(1, 5);

    switch(choice){
        case 1://Edit category
        //DONE
            int categoryChoice;
            int category;
            cout << "\n\nWhich Category would you like to edit?\n";//gets which Category the user wants to change
            displayCategoryNames();
            category = integerUserValidation(1, numCategories) - 1;//gets the actual position of the category in the array

            cout << "\n\nHow would you like to edit your course?\n";//gets how the user wants to edit the course
            cout << "\t1.\tEdit Category name\n";
            cout << "\t2.\tEdit Category weight\n";
            categoryChoice = integerUserValidation(1, 2);
            if(categoryChoice == 1){//Edit category name
                string newName;
                cout << "\nWhat name would you like to change " << categoryArray[category]->getName() << " to?\nENTER: ";
                getline(cin, newName);
                categoryArray[category]->setCategoryName(newName);
            }
            else{//edit category weight
                float newWeight;
                cout << "\nWhat weight would you like to change " << categoryArray[category]->getWeight() << " to?\nENTER: ";
                cin >> newWeight;
                totalweight -= categoryArray[category]->getWeight();
                totalweight += newWeight;
                if(totalweight > 100){//checks if total weight from categories is greater than 100
                    cout << "\nInvalid weight! Total weight noe exceeds 100%. Please try again with a lower number\n";
                    totalweight -= newWeight;
                    totalweight += categoryArray[category]->getWeight();
                    return;
                }
                categoryArray[category]->setWeight(newWeight);
            }
            break;
        case 2://delete a category
            int category;
            int deleteOrStop;
            cout << "\n\nWhich Category would you to delete?\n";//gets which Category the user wants to delete
            displayCategoryNames();
            category = integerUserValidation(1, numCategories) - 1;//gets the actual position of the category in the array
            if(categoryArray[category]->getNumAssignments() > 0){
                cout << "\nDeleting this category will delete " << categoryArray[category]->getNumAssignments() << " assignment";
                if(categoryArray[category]->getNumAssignments() != 1){
                    cout << "s";
                }
                cout << ". Would you like to continue and delete this catgory along with the assignments(1) or quit(2)?\n";
                deleteOrStop = integerUserValidation(1, 2);
                if(deleteOrStop == 1){
                    deleteCategory(category);
                }
                else{
                    return;
                }
            }
            break;
        case 3://edit an assignment
            break;
        case 4://delete an assignment
            break;
        case 5://edit course name
            break;
    }
}

//NOT STARTED
void Course::deleteCategory(int position){}

//DONE
int Course::getNumCategories(){
    return numCategories;
}

//DONE
string Course::getName(){
    return courseName;
}

//DONE
void Course::setName(string newName){
    courseName = newName;
}


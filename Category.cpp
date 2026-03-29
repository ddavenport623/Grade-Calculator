#include "Category.h"

//DONE
Category::Category(string cName, float cWeight){
    categoryName = cName;
    weight = cWeight;
    numAssignments = 0;
    maxAssignments = 5;
    assignmentArray = new Assignment*();/*Added to try and fix bug in addNewAssignment*/
}

//TEST
Category::~Category(){
    for(int i=0; i<numAssignments; i++){
        delete assignmentArray[i];
    }
    delete [] assignmentArray;
    numAssignments = 0;
}

//TEST
void Category::resizeAssignmentArray(){
    //doubles the size of the array
    Assignment** newArray = new Assignment*[maxAssignments * 2];//FIX
    for (int i = 0; i < maxAssignments; i++){//copies old array to new array
        newArray[i] = assignmentArray[i];
    }
    delete [] assignmentArray;
    assignmentArray = newArray;
    maxAssignments *= 2;//corrects the new max
}

//TEST
void Category::displayAssignmentNames(){
    for (int i=0; i < numAssignments; i++){
        cout << "\nAssignment " << i+1 <<": " << assignmentArray[i]->getName();
    }
    cout << endl << endl;
}

//TEST
void Category::addNewAssignment(){
    string tempName;
    float tempGrade;
    string tempComments;

    cout << "\nWhat is the name of the Assignment? ";
    getline(cin, tempName);
    cout << "What grade did you get on this Assignment? ";
    cin >> tempGrade;
    cin.ignore();
    /*PROBLEM: program crashes after this point
    */
    cout << "\nWhat comments were on your assignment?(if no comments put \"no comments\") ";
    getline(cin, tempComments);
    // cout << "\ncomments recieved\n";//REMOVE

    if(numAssignments == maxAssignments){
        resizeAssignmentArray();
    }

    assignmentArray[numAssignments] = new Assignment(tempName, tempGrade, tempComments);
}

//TEST
void Category::deleteAssignment(){
    cout << "Which Assignment would you like to delete?\n";
    displayAssignmentNames();
    int choice = integerUserValidation(1, numAssignments - 1);
    delete assignmentArray[choice - 1];//deletes the info where user chose
    for(int i = choice-1; i < numAssignments - 1; i++){
        assignmentArray[i] = assignmentArray[i+1];//moves everything to the left
    }
    delete assignmentArray[numAssignments-1];
    numAssignments--;
}

//TEST
void Category::calculateCategoryGrade(){
    float total;
    for (int i=0; i<numAssignments; i++){
        total += assignmentArray[i]->getGrade();
    }
    averageGrade = total / numAssignments;
}

//DONE
string Category::getName(){
    return categoryName;
}

//DONE
int Category::getNumAssignments(){
    return numAssignments;
}

//DONE
float Category::getWeight(){
    return weight;
}

//DONE
int Category::getMaxAssignments(){
    return maxAssignments;
}

//DONE
void Category::incrementNumAssignments(){
    numAssignments++;
}

//DONE
void Category::setCategoryName(string newName){
    categoryName = newName;
}

//DONE
void Category::setWeight(float newWeight){
    weight = newWeight;
}
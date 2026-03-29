#include "Functions.h"

//NEEDS TO BE TESTED
//needs to be moved to Course.h
// void addNewCategory(Calculator course [], int& currentCategory, bool percent, int& totalPercentage, int& totalPoints, int& currentPoints){
//     bool stop = false;
//     string answer;
//     while (!stop) {
//         cout << "What is the name of the category you would like to add: ";
//         getline(cin, course[currentCategory].name);
//         if (percent) {//does the calculation if the final grade is made up of percentages
//             cout << "\nWhat percentage of your final grade is " << course[currentCategory].name << " worth: ";
//             cin >> course[currentCategory].percentage;
//             cin.ignore();
//             totalPercentage += course[currentCategory].percentage;
//             course[currentCategory].percentage = lessThanZeroUserValidation(course[currentCategory].percentage);
//             while (totalPercentage > 100){
//                 cout << "Invalid percentage! Total percentage for all categories exceeds 100%. Please enter a new percentage.\n";
//                 totalPercentage -= course[currentCategory].percentage;
//                 cout << "Enter: ";
//                 cin >> course[currentCategory].percentage;
//                 cin.ignore();
//                 totalPercentage += course[currentCategory].percentage;
//             }
//         }
//         else {//deos the calcultaion if the final grade is made up of points
//             cout << "\nHow many points is this category worth: ";
//             cin >> course[currentCategory].points;
//             cin.ignore();
//             totalPoints += course[currentCategory].points;
//             course[currentCategory].points = lessThanZeroUserValidation(course[currentCategory].points);
//             while (totalPoints < currentPoints){
//                 totalPoints -= course[currentCategory].points;
//                 cout << "Invalid number of points! Current number of points for the category exceeds total possible number of points for the course. Please enter a new number of points.\n";
//                 cout << "Enter: ";
//                 cin >> course[currentCategory].points;
//                 cin.ignore();
//                 totalPoints += course[currentCategory].points;
//             }
//         }
//         course[currentCategory].currAssignment = 0;
//         currentCategory++;
//         cout << "\nWould you like to add another category? Answer with yes or no\n";
//         cout << "Enter: ";//TO DO switch to userValidation function
//         getline(cin, answer);
//         while(!((answer == "yes") || (answer == "no"))) {
//             cout << "Invalid Input! Please answer with yes or no\n";
//             cout << "Enter: ";
//             getline(cin, answer);
//         }
//         if (answer == "no"){
//             stop = true;
//         }
//     }
// }

// //TESTING BUT FINE SO FAR
// //needs to be added to Category.h
// // // void addGrade(Calculator course [], int& currentCategory){
// //     if (currentCategory == 0){
// //         cout << "Please enter a category first before adding in a grade";
// //     }
// //     else {
// //         bool stop = false;
// //         string answer;
// //         while (!stop) {
// //             cout << "Which category does this assignment fall under?\n";
// //             for (int i=0; i<currentCategory; i++) {
// //                 cout << "\t" << i+1 << ")\t" << course[i].name << "\n";
// //             }
// //             int choice;
// //             cout << "Enter: ";
// //             cin >> choice;
// //             cin.ignore();
// //             cout << "What is the name of the assignment? ";
// //             getline(cin, course[choice - 1].category[course[choice-1].currAssignment].assignment);
// //             cout << "What was your grade for this assignment? ";
// //             cin >> course[choice-1].category[course[choice-1].currAssignment].grade;
// //             cin.ignore();
// //             while(course[choice-1].category[course[choice-1].currAssignment].grade < 0){
// //                 cout << "Invalid grade! Please enter a grade that is 0 or greater.\n";
// //                 cout << "ENTER: ";
// //                 cin >> course[choice-1].category[course[choice-1].currAssignment].grade;
// //                 cin.ignore();
// //             }
// //             course[choice-1].currAssignment++;
// //             cout << "Would you like to add another assignment? Answer with yes or no\nEnter: ";
// //             getline(cin, answer);
// //             while(!((answer == "yes") || (answer == "no"))) {
// //                 cout << "Invalid Input! Please answer with yes or no\n";
// //                 cout << "Enter: ";
// //                 getline(cin, answer);
// //             }
// //             if (answer == "no"){
// //                 stop = true;
// //             }
// //         }
// //     }
// // }

// //TESTING BUT FINE SO FAR
// //stay here maybe
// // int printGrades(Calculator course [], int& currentCategory, string courseName){
// //     if (currentCategory == 0){
// //         cout << "Please enter a category first before trying to print grades.\n";
// //         return 0;
// //     }
// //     cout << courseName << endl;
// //     for (int i=0; i<currentCategory; i++){
// //         cout << "\t" << course[i].name << " worth " << course[i].percentage << "%\n";
// //         for (int j=0; j<course[i].currAssignment; j++){
// //             cout << "\t\t" << j+1 << ".\t"<< course[i].category[j].assignment << "-" << course[i].category[j].grade << endl;
// //         }
// //     }
// //     return 0;
// // }

// //NOT STARTED
// //stay here maybe
// void calculateGrade(){}

// //BROKEN
// //DOES NOT WORK FOR CATEGORIES AFTER #1
// //going to be in Course.h
// // void readFromFile(Calculator course [], int& currentCategory, bool& percent){
// //     cout << "What is the name of the file that you would like to read in?\nENTER: ";
// //     string temp;
// //     string filename;
// //     ifstream infile;
// //     getline(cin, filename);
// //     infile.open(filename);
// //     while (!(infile.is_open())) {//verifies file is open
// //         cout << "Error. File could not be opened. Please enter again" << endl;
// //         cout << "FILENAME: ";
// //         getline(cin, filename);
// //         infile.open(filename);
// //     }
// //     while(!infile.eof()){
// //         getline(infile, course[currentCategory].name, '-');
// //         getline(infile, temp, ' ');
// //         if(temp == "PERCENT"){
// //             percent = true;
// //         }
// //         else {
// //             percent = false;
// //         }
// //         while(getline(infile, course[currentCategory].category[course[currentCategory].currAssignment].assignment, '$')){
// //             getline(infile, temp, '!');
// //             course[currentCategory].category[course[currentCategory].currAssignment].grade = stoi(temp);
// //             course[currentCategory].currAssignment++;
// //         }
// //         currentCategory++;
// //     }
// //     infile.close();
// //     cout << "Information recieved successfully!\n";
// // }

// //TESTING
// //Worked once! YAY
// //going to be in Course.h
// // void saveToFile(Calculator course [], int& currentCategory, string courseName, bool percent, int& totalPoints){
// //     cout << "Enter the name of the file you wish to save to." << endl;
// //     cout << "FILENAME: ";
// //     string filename;
// //     getline(cin, filename);
// //     ofstream outfile;
// //     outfile.open(filename);
// //     while (!(outfile.is_open())) {//validates file opened
// //         cout << "Error. File could not be opened. Please enter again" << endl;
// //         cout << "FILENAME: ";
// //         getline(cin, filename);
// //         outfile.open(filename);
// //     }
// //     outfile << courseName;
// //     if (percent) {//outputs points or percent. Might need to change beginning questions
// //         outfile << "-PERCENT \n\n";
// //     }
// //     else {
// //         outfile << "-POINTS \n\n";
// //         outfile << totalPoints;
// //     }
// //     for (int i=0; i < currentCategory; i++){
// //         outfile << course[i].name << "-";
// //         if (percent){
// //             outfile << course[i].percentage << "\n";
// //         }
// //         else {
// //             outfile << course[i].points << "\n";
// //         }
// //         if (course[i].currAssignment != 0) {
// //             for (int j=0; j<=course[i].currAssignment; j++){
// //                 outfile << "\t" << course[i].category[j].assignment << "-";
// //                 outfile << course[i].category[j].grade << "\n";
// //             }
// //         }
// //     }
// //     outfile.close();
// //     cout << "Grades saved to " << filename << " successfully!\n";
// // }

// //NEEDS TO BE TESTED
// //UPDATED
// //stay here
// void editMenu (Calculator course [], int& currentCategory, bool percent, int& totalPercentage, int& totalPoints, int& currentPoints) {
//     cout << "What would you like to do?\n";
//     cout << "\t1.\tEdit a Category\n";
//     cout << "\t2.\tDelete a Category\n";
//     cout << "\t3.\tEdit an Assignment\n";
//     cout << "\t4.\tDelete an Assignment\n";
//     cout << "\t5.\tEdit Course name\n";
//     cout << "\t6.\tEdit Points vs Percent\n";
//     cout << "\t7.\tNothing I'm the dumbest person to ever live\n";
//     int userI;//holds user menu choice
//     cin >> userI;
//     cin.ignore();
//     switch(userI){
//         case 1://needs to ask what category
//             editCategory();
//             break;
//         case 2:
//             deleteCategory();
//             break;
//         case 3://needs to ask what assignment
//             editAssignment();
//             break;
//         case 4:
//             deleteGrade();
//             break;
//         case 5:
//             editCName();
//             break;
//         case 6:
//             editPandP();
//             break;
//         default:
//             cout << "\nThanks for wasting my time loser! I hope you fail this course!\n";
//             break;
//     }
// }

// //NOT STARTED
// //maybe going to Category.h
// void editCategory() {}

// //NOT STARTED
// //maybe Course.h
// void deleteCategory(){}

// //NOT STARTED
// //going to Assignment.h
// void editAssignment() {}

// //NOT STARTED
// //maybe going to Category.h
// void deleteGrade(){}

// //NOT STARTED
// //WILL BE EASY
// //To be replaced by setName in Course.h
// void editCName() {}

// //NOT STARTED
// //GOING TO BE A NIGHTMARE
// //will probably need to change the categories along with this
// //maybe moved to Course.h
// void editPandP() {}


//USER VALIDATION FUNCTIONS!!!!!!

//Validates user input over the span of the 2 integers
//stays
int integerUserValidation (int low, int high) {
    int userInput;
    cout << "Enter: ";
    cin >> userInput;
    cin.ignore();
    while(userInput < low || userInput > high) {
        cout << "Invalid input! Please enter a number between " << low << " and " << high << ".\nEnter: ";
        cin >> userInput;
        cin.ignore();
    }
    return userInput;
}

//Validates user input between the 2 strings provided
//stays
string twoStringsUserValidation (string option1, string option2) {
    string temp;
    cout << "ENTER " << option1 << " or " << option2 << ": ";
    getline(cin, temp);
    while ((temp != option1) && (temp != option2)) {
        cout << "Invalid input! Please enter " << option1 <<" or " << option2 << "!\nEnter: ";
        getline(cin, temp);    
    }
    return temp;
}

//Validates user input is positive
int lessThanZeroUserValidation(int input){
    while (input <= 0){
        cout << "Invalid Input! Please enter a number greater than 0!\nEnter: ";
        cin >> input;
        cin.ignore();
    }
    return input;
}
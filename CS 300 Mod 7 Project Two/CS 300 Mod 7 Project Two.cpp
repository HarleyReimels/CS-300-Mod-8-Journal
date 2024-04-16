// CS 300 Mod 7 Project Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Harley Reimels
// 4/14/2024

#include <iostream> // Input / Output
#include <string> // String functions
#include <vector> // Where we store our Class object
#include <fstream> // Reads data from csv
#include <sstream> // Used for inserting / Extracting
#include <cstring> // Keeps char data in string
#include <algorithm> // Used to Sort Classes

// Saves my fingers from developing blisters
using namespace std;

// Structure for the classes information
struct CourseInfo {
    string courseNumber;
    string name;
    string prereqOne;
    string prereqTwo;
};

// Class object that will store the CourseInfo structure
class Courses {
public:
    
    CourseInfo courseinformation;
    
    // Prints the course number and course name when called
    void print() {
        cout << courseinformation.courseNumber << ", "<< courseinformation.name << endl;
    }


    };


// Create a vector the takes in Course objects
// We then populate that vector by loading in the csv
vector<Courses> load_csv() {

    // Create a ifstream instance name myfile
    ifstream myfile;
    
    // Read in csv data
    myfile.open("classes.csv", ios::in);

    // Create an Courses object named my_classes
    Courses my_classes;

    // Create the vector that will eventually hold onto each of my_classes instances
    vector<Courses> vec_classes;

    // Some string variables to help track loading and parsing the csv
    string line, word, temp;

    // Only run the following code if the csv actally opens
    if (myfile.good()) {
        // If we are not at the end of the file
        while (getline(myfile, line)) {
            // Allows for temp to extract from line
            stringstream temp(line);
            // Keeps tracks of how many items are on each line, resets upon entering the next line
            int counter = 0;
            // Set the delimiter, so each item between , is an indivual item
            while (getline(temp, word, ',')) {
                // First item assigned to course number
                if (counter == 0) {
                    my_classes.courseinformation.courseNumber = word;
                    counter += 1;
                }
                // Second item assigned to name
                else if (counter == 1) {
                    my_classes.courseinformation.name = word;
                    counter += 1;
                }
                // Third item assigned to prereqOne
                else if (counter == 2) {
                    my_classes.courseinformation.prereqOne = word;
                    counter += 1;
                }
                else if (counter == 3) {
                // Fourht item assigned to prereqTwo
                    my_classes.courseinformation.prereqTwo = word;
                    counter += 1;
                }
                // If there are any more then notify the user
                else {
                    cout << "To many arguments";
                    counter += 1;
                }    
            }
            // Assign the fully built class object into the vector
            vec_classes.push_back(my_classes);
        }
    }
    // Close file
    myfile.close();
    // Return vector for other uses
    return vec_classes;
}

// Sorts our classes by thier numerical value
bool compareCourses(const Courses& a, const Courses& b) {
    return a.courseinformation.courseNumber < b.courseinformation.courseNumber;
}

// Prints all the classes, by number and name
void print_classes(vector<Courses> vec) {
   
    for (int i = 0; i < vec.size(); ++i)
    {
        vec.at(i).print();
    }
}

// Allows for seatching for a specific class
void search_classes(vector<Courses> vec, string courseNumber) {

    // Allows for case insensitive searching
    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);

    // Changes the course name to be all upper case *it already is, but this is for future proofing*
    for (int i = 0; i < vec.size(); ++i){
        transform(vec.at(i).courseinformation.courseNumber.begin(),
            vec.at(i).courseinformation.courseNumber.end(),
            vec.at(i).courseinformation.courseNumber.begin(), ::toupper);
    
        // If the Course the user is searching for, matches, print the name, number and prereqs
        if (vec.at(i).courseinformation.courseNumber == courseNumber) {
            cout << vec.at(i).courseinformation.courseNumber << ", " << vec.at(i).courseinformation.name << endl;
            cout << "Prerequisites: " << vec.at(i).courseinformation.prereqOne << ", "
                << vec.at(i).courseinformation.prereqTwo << endl;
            return;
        }
    }
    // If the course is not found
     cout << "I am sorry but we can not find that course." << endl;
     return;


}

// Menu function, will be called constantly, helps reduce bloat, returns the users choice
int menu() {

    cout << "Welcome to the course planner.\n";
    cout << "1. Load Data Structure.\n";
    cout << "2. Print Course List.\n";
    cout << "3. Print Course.\n";
    cout << "9. Exit\n";
    
    int number;
    cout << "What would you like to do: ";
    cin >> number;
    
    return number;

}
// Main function
int main() {
    // Create our vector
    vector<Courses> my_classes;
    // Create a string object for searching
    string class_name;
    // Establish a int number that is non 9 to runt he loop
    int menu_choice = 0;
    // While the user does not enter 9, repeat
    while (menu_choice != 9) {
        // Print the menu
        menu_choice = menu();
        // Choose the case the user picked
        switch (menu_choice) {
        // Loads the csv, and then sorts
        case 1:
            cout << "Here \n";
            my_classes = load_csv();
            sort(my_classes.begin(), my_classes.end(), compareCourses);
            break;
            // Prints the class number and name
        case 2:
            print_classes(my_classes);
            break;
        case 3:
            // Ask user for course, and then searches for it
            cout << "What course do you want to know about: ";
            cin >> class_name;
            search_classes(my_classes, class_name);
            cin.clear();
            break;
            // End loop
        case 9:
            return 9;
            // Anything besides 1,2,3,9
        default:
            cout << menu_choice << " is not a valid option. Please choose from the menu.";
        }
    }
}

/*
CSC 134
M3LAB2 - Number Grade to Letter Grade
Olivia DeLellis
10/27/25
*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    double numericalGrade; // Variable to store the user's grade 
    string letterGrade;
    // Prompt user for input 
    cout << "Enter your numerical grade (0-100): ";
    cin >> numericalGrade;

     // Validate input
    if (cin.fail() || numericalGrade < 0 || numericalGrade > 100); {
    }

 

    // Determine the letter grade using if-else statements
    if (numericalGrade >= 90 && numericalGrade <= 100) {
        letterGrade = 'A';
    } else if (numericalGrade >= 80 && numericalGrade < 90) {
        letterGrade = 'B';
    } else if (numericalGrade >= 70 && numericalGrade < 80) {
        letterGrade = 'C';
    } else if (numericalGrade >= 60 && numericalGrade < 70) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    // Display the result
    cout << "Your letter grade is: " << letterGrade << endl;

    return 0; 
}
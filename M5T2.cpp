/*
CSC 134 
Olivia DeLellis 
M5T2
November 7, 2025 
*/

#include <iostream>
using namespace std; 

// Given 2 numbers, print them out nicely on a line. 
void printResult(int number, int result) {
    cout << number << " squared= " << result << endl;
}

// Given a number, return the square of it
int square(int number){
    int result; 
    result = number * number; // squared 
    return result;
}

int main () {
    // count some numbers
    // and find a result for each
int count = 1;
int result;

// this version will be squares
while (count <= 10) {
    result = square(count);
    printResult(count, result); 
    count++;
}

}
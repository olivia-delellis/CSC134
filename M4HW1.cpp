/*
CSC 134
M4HW1
Olivia DeLellis
11/02/2025
*/


#include <iostream>
using namespace std; 

int main() {

   // declare variables 
   int firstNum, secondNum, answer; 
   firstNum = 1; 
   // secondNum = 1; 
   // answer = firstNum * secondNum; 
   
    for (int i=1; i<= 12; i++) {
    answer = firstNum * i; 
    cout << firstNum << " times " << i << " is " << answer << endl; 
    }

/*
CSC 134 
Olivia DeLellis 
M5T1
Nov. 7, 2025
*/

#include <iostream> 
#include <string>
using namespace std; 

// declare our functions
string formatAnswer(int answer);
void printAnswer(string msg);

int main() {
 int answer = 10;
 string message;

 message = formatAnswer(answer);
 printAnswer(message);
 return 0;
}
// define functions
string formatAnswer (int answer) {
    
 // Make a nice looking string containing the answer
 string answerMessage;
 answerMessage = "The answer is ";
 answerMessage += to_string(answer);
 return answerMessage;
}
void printAnswer(string msg) {
 // display our message
 cout << msg << endl;
}
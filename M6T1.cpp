/*
CSC 134
M6T1
Olivia DeLellis
12/01/2025
*/

#include <iostream>
using namespace std;

// Function declarations 
void method1();
void method2();

int main (){
    // Count cars Monday-Friday, two different ways 
    method1();
    method2();

    return 0;
}

// Method 1 - No arrays 
void method1(){
    cout << "\nPart 1: Car Count (No arrays)\n";
    cout << "Enter cars counted each day." << endl;
    cout << "Day 0 = Monday, December 1 = Friday" << endl;

    const int SIZE = 5;
    int day = 0;
    int cars_today = 0; 
    int car_total = 0;
    double car_avg = 0.0; 

    while (day < SIZE) {
        cout << "Day " << day << ": ";
        cin >> cars_today; 

        car_total += cars_today;
        day++;
    }

    car_avg = (double) car_total / SIZE; 

    cout << "Total cars = " << car_total << endl;
    cout << "Average per day = " << car_avg << endl;
}
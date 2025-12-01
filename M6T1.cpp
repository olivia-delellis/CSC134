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

void method2() {
    cout << "\nPart 2: Car Count (Arrays + Graph)\n";

    const int SIZE = 5;
    string days[SIZE] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    int cars[SIZE];
    int car_total = 0;
    double car_avg = 0.0;

    for (int i = 0; i < SIZE; i++) {
        cout << "Cars on " << days[i] << ": ";
        cin >> cars[i];
    }

    cout << "\nDay\tCars" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << days[i] << "\t" << cars[i] << endl;
        car_total += cars[i];
    }

    car_avg = (double) car_total / SIZE;

    cout << "\nTotal cars = " << car_total << endl;
    cout << "Average per day = " << car_avg << endl;


    cout << "\nASCII Graph (1 star = 10 cars)" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << days[i] << " | ";

        int stars = cars[i] / 10;  // scale so chart isn't huge
        for (int s = 0; s < stars; s++) {
            cout << "*";
        }
        cout << endl;
    }
}
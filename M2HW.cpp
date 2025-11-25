/*
CSC 134
M2HW1 - Gold
Olivia DeLellis
November 13, 2025
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main() {

    // QUESTION 1 – Banking Simulation

    cout << "---- Question 1 ----" << endl;

    string name;
    double startBal, deposit, withdrawal;

    cout << "Enter name on the account: ";
    getline(cin, name);              // allows spaces

    cout << "Enter starting balance: ";
    cin >> startBal;
    cout << "Enter deposit amount: ";
    cin >> deposit;
    cout << "Enter withdrawal amount: ";
    cin >> withdrawal;

    // generate a simple account number
    int accountNum = rand() % 900000 + 100000;

    double finalBal = startBal + deposit - withdrawal;

    cout << fixed << setprecision(2);
    cout << "Name: " << name << endl;
    cout << "Account Number: " << accountNum << endl;
    cout << "Final Balance: $" << finalBal << endl << endl;


    // flush leftover newline
    cin.ignore();


   
    // QUESTION 2 – Crate Storage Cost Update
   
    cout << "---- Question 2 ----" << endl;

    double length, width, height;
    const double costPerCubicFoot = 0.30;     // updated
    const double chargePerCubicFoot = 0.52;   // max allowed

    cout << "Enter crate length: ";
    cin >> length;
    cout << "Enter crate width: ";
    cin >> width;
    cout << "Enter crate height: ";
    cin >> height;

    double volume = length * width * height;
    double cost = volume * costPerCubicFoot;
    double charge = volume * chargePerCubicFoot;
    double profit = charge - cost;

    cout << fixed << setprecision(2);
    cout << "Volume: " << volume << " cubic ft" << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Charge: $" << charge << endl;
    cout << "Profit: $" << profit << endl << endl;


   
    // QUESTION 3 – Pizza Party
   
    cout << "---- Question 3 ----" << endl;

    int pizzas, slicesPerPizza, visitors;
    cout << "How many pizzas? ";
    cin >> pizzas;
    cout << "How many slices per pizza? ";
    cin >> slicesPerPizza;
    cout << "How many visitors? ";
    cin >> visitors;

    int totalSlices = pizzas * slicesPerPizza;
    int needed = visitors * 3;
    int leftover = totalSlices - needed;

    cout << "Leftover slices: " << leftover << endl << endl;


    
    // QUESTION 4 – Cheering Program
    
    cout << "---- Question 4 ----" << endl;

    string letsGo, school, team, cheerOne, cheerTwo;

    letsGo = "Let's go ";
    school = "FTCC";
    team = "Trojans";

    // build the cheers with concatenation (bonus requirement)
    cheerOne = letsGo + school;
    cheerTwo = letsGo + team;

    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerOne << endl;
    cout << cheerTwo << endl;

    return 0;
}

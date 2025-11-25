/*
CSC 134 
M1Lab1 - *Apple* Sales 
oliviadelellis 
9/13/2025

*/

#include <iostream>
using namespace std;

int main() {
    // This program acts like a storefront. 
    // Set up our variables 
    string item_name = "surfboards"; 
    int number_of_items = 15;
    double cost_each = 150; // $150.00
    double total_cost;

    // Greet the customer 
    cout << "Welcome to the " << item_name << " store!" << endl;

    // Ask for the order 
    // assume they'll buy  everything 
    cout << "We have " << number_of_items << " " << item_name << endl;
    cout << "We have all types of styles" << endl;
    cout << "Each costs $" << cost_each << endl;
    
    // Calculate the total price 
    total_cost = number_of_items * cost_each;

    // Output the reults 
    cout << "To purchase all " << number_of_items << " will cost $" << total_cost << " total." << endl;
    cout << "Thank you for shopping with us!" << endl;
    cout << "Enjoy the waves!" << endl;
    
    return 0; // no errors
}
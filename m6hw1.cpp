/*
CSC 134 
Olivia DeLellis
M6HW1
7 November 2025
*/

#include <iostream>
using namespace std;


void main_menu();
void choice_front_door();
void choice_back_door();
void choice_go_home();
void choice_order_pizza();
void choice_watch_movie();

int main() {
    main_menu();
    return 0;
}

void main_menu() {
    cout << "Main Menu" << endl;
    cout << "You're in front of a spooky old house..." << endl;
    cout << "Do you:" << endl;
    cout << "1. Try the front door" << endl;
    cout << "2. Sneak around back" << endl;
    cout << "3. Forget it, and go home" << endl;
    cout << "4. [Quit]" << endl;
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        choice_front_door();
    } else if (choice == 2) {
        choice_back_door();
    } else if (choice == 3) {
        choice_go_home();
    } else if (choice == 4) {
        cout << "OK, quitting game." << endl;
    } else {
        cout << "That's not a valid choice. Try again." << endl;
        main_menu(); // restart menu
    }
}

void choice_front_door() {
    cout << "You open the front door and step inside..." << endl;
    cout << "There's a ghost!" << endl;
}

void choice_back_door() {
    cout << "You sneak around the back and find a hidden path..." << endl;
    cout << "It's locked...try the window!" << endl; 
    cout << "The window is unlocked" << endl; 
    cout << "You go inside and find a cool set of stairs" << endl;
}

void choice_go_home() {
    cout << "You decide it's safer to go home." << endl;
    cout << "1. Order some pizza" << endl;
    cout << "2. Watch a movie" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    // 1, pizza, 2, movie
    if (choice == 1) {
        choice_order_pizza();
    }
    if (choice == 2) {
        choice_watch_movie();
    }

}
void choice_order_pizza() {
    cout << "You just ordered pizza!" << endl;
}
void choice_watch_movie(){
    cout << "You decided to watch The Conjuring";
}
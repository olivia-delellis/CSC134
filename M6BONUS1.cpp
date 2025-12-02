#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    ENTRANCE_HALL = 0,
    LIBRARY = 1,
    KITCHEN = 2,
    GARDEN = 3,
    BASEMENT = 4,
    NUM_ROOMS = 5
};

// Linked list node to track the path the player takes
struct PathNode {
    int roomIndex;
    PathNode* next;
    PathNode(int r, PathNode* n = nullptr) : roomIndex(r), next(n) {}
};

int main() {
    // Room names using vector instead of array
    vector<string> roomNames = {
        "Entrance Hall",
        "Library",
        "Kitchen",
        "Garden",
        "Basement"
    };
    
    // Room descriptions using vector instead of array
    vector<string> roomDescriptions = {
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious kitchen with an old stove and wooden counter.",
        "An overgrown garden with stone pathways and a small fountain.",
        "A dark, damp basement with cobwebs in the corners."
    };
    
    // Adjacency list using a 2D vector
    // connections[from_room][direction] = to_room or -1 if no connection
    vector<vector<int>> connections(
        NUM_ROOMS,
        vector<int>(NUM_DIRECTIONS, -1)
    );
    
    // Define the connections between rooms using the Room enum
    
    // Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[ENTRANCE_HALL][EAST]  = KITCHEN;    // Entrance Hall -> East -> Kitchen
    connections[ENTRANCE_HALL][SOUTH] = -1;         // No connection south
    connections[ENTRANCE_HALL][WEST]  = GARDEN;     // Entrance Hall -> West -> Garden
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST]  = -1;               // No connection east
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST]  = -1;               // No connection west
    
    // Kitchen connections
    connections[KITCHEN][NORTH] = -1;               // No connection north
    connections[KITCHEN][EAST]  = -1;               // No connection east
    connections[KITCHEN][SOUTH] = BASEMENT;         // Kitchen -> South -> Basement
    connections[KITCHEN][WEST]  = ENTRANCE_HALL;    // Kitchen -> West -> Entrance Hall
    
    // Garden connections
    connections[GARDEN][NORTH] = -1;                // No connection north
    connections[GARDEN][EAST]  = ENTRANCE_HALL;     // Garden -> East -> Entrance Hall
    connections[GARDEN][SOUTH] = -1;                // No connection south
    connections[GARDEN][WEST]  = -1;                // No connection west
    
    // Basement connections
    connections[BASEMENT][NORTH] = KITCHEN;         // Basement -> North -> Kitchen
    connections[BASEMENT][EAST]  = -1;              // No connection east
    connections[BASEMENT][SOUTH] = -1;              // No connection south
    connections[BASEMENT][WEST]  = -1;              // No connection west
    
    // Game state
    int currentRoom = ENTRANCE_HALL; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Linked list head: tracks the path (most recent room at the front)
    PathNode* pathHead = new PathNode(currentRoom);

    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        int nextRoom = -1;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            nextRoom = connections[currentRoom][NORTH];
        } else if (command == "east" || command == "e") {
            nextRoom = connections[currentRoom][EAST];
        } else if (command == "south" || command == "s") {
            nextRoom = connections[currentRoom][SOUTH];
        } else if (command == "west" || command == "w") {
            nextRoom = connections[currentRoom][WEST];
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
        
        // Handle movement if a direction was chosen
        if (gameRunning && nextRoom != -1) {
            currentRoom = nextRoom;
            // Add this room visit to the front of the linked list
            pathHead = new PathNode(currentRoom, pathHead);
        } else if (gameRunning && nextRoom == -1 && 
                   (command == "north" || command == "n" ||
                    command == "east"  || command == "e" ||
                    command == "south" || command == "s" ||
                    command == "west"  || command == "w")) {
            cout << "You can't go that way." << endl;
        }
    }
    
    cout << "\nThanks for playing!" << endl;

    // Print the path the player took using the linked list
    cout << "You visited the rooms in this order (from start to finish):" << endl;
    // The linked list is stored newest-first, so copy to a vector to reverse
    vector<int> path;
    PathNode* current = pathHead;
    while (current != nullptr) {
        path.push_back(current->roomIndex);
        current = current->next;
    }
    // path now contains rooms from last to first, so print in reverse
    for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i) {
        cout << roomNames[path[i]];
        if (i > 0) cout << " -> ";
    }
    cout << endl;

    // Clean up linked list memory
    current = pathHead;
    while (current != nullptr) {
        PathNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    return 0;
}
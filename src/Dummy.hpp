#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <vector>
#include "raylib.h"

class vehicle {
public:
    vehicle(int x, int y, int size, int speed); // Constructor
    void update(); // Update vehicle positions
    void draw();   // Draw vehicles
private:
    int x, y; // Position
    int size; // Size of the vehicle
    int speed; // Speed of the vehicle
    std::vector<int> arr; // Y positions of vehicles
    std::vector<bool> isActive; // Activity status of vehicles
    int state; // Number of vehicles (read from file)
    int light;// Reads the light condition from the file
    void readStateFromFile(); // Read the number of vehicles from file
};

#endif


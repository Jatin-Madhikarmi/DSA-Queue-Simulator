#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <vector>
#include "raylib.h"

class vehicle {
public:
    vehicle(int x1, int y1, int x2,int y2,int speed, int size); // Constructor
    void update(); // Update vehicle positions
    void draw();   // Draw vehicles
private:
    int x1, y1; // X Y coordinates of the vehicle that are free to turn 
    int x2,y2;// X Y coordinates of the vehicles the move to the lane B
    int size; // Size of the vehicle
    int speed; // Speed of the vehicle
    std::vector<int> arr1; // X positions of vehicles that are free to turn left
    std::vector<int> brr1; // Y positions of vehicles that are free to turn left
    std::vector<int> arr2; // X positions of vehicles that move to the lane B
    std::vector<int> brr2; // Y positions of vehicles that mive to the lane B
    std::vector<bool> isActive1; // Activity status of vehicles that are free to turn left lane
    std::vector<bool> isActive2; // Activity status of vehicles that are move to the B lane
    int state; // Number of vehicles (read from file)
    int light;// Reads the light condition from the file
    void readStateFromFile(); // Read the number of vehicles from file
};

#endif


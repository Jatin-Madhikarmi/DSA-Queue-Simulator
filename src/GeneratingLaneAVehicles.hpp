#ifndef GENERATING_LANE_A_VEHICLES_HPP
#define GENERATING_LANE_A_VEHICLES_HPP

#include<vector>
#include<raylib.h>
class LaneA
{
    public:
    LaneA(int x1,int y1,int x2,int y2,int speed,int size);
    void draw();
    void update();

    private:
    int x1,y1;
    int x2;
    int y2;
    int speed=5;
    int size=50;

    std::vector<int> arr1; // X positions of vehicles in the left lane
    std::vector<int> brr1; // Y positions of vehicles in the left lane
    std::vector<int> arr2; // X positions of vehicles in the outgoing lane
    std::vector<int> brr2; // Y positions of vehicles in the outgoing lane
    std::vector<bool> isActive1; // Activity status of vehicles in the left turn lane
    std::vector<bool> isActive2; // Activity status of vehicles in the ourgoing lane
    int state; // Number of vehicles (read from file)
    int light;// Reads the light condition from the file
    int Time;// Reads the time for the light from the file
    void readStateFromFile(); // Read the number of vehicles from file
};

#endif
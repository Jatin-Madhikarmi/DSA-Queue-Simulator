#pragma once
#include<vector>

class vehicle
{
    public:
    vehicle();
    void update();
    void draw();
    private:
    int x;
    int y;
    int size;
    int speed;
    bool isActive1=true;
    bool isActive2=true;
    std::vector<int> vehicleYPositions;
    std::vector<bool> vehicleActiveStates;
    
    int trafficState=0;
};
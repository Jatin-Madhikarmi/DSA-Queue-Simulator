#pragma once
#include<chrono>
#include<thread>

class LaneC
{
    public:
    LaneC();
    void draw();
    void update();

    private:
    int x1;
    int y1;
    int x2;
    int y2;
    int speed=5;
    int size=50;
    bool isActive1=true;
    bool isActive2=true;
    int state=1;
    int startTime =0;
    int timerStarted=0;
    float lastToggleTime = 0.0f;
    bool toggleAllowed=true;
};
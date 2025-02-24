#pragma once

class LaneA
{
    public:
    LaneA();
    void draw();
    void update();
    private:
    int x1;
    int y1;
    int x2;
    int y2;
    int speed;
    int size;
    bool isActive1=true;
    bool isActive2=true;
};
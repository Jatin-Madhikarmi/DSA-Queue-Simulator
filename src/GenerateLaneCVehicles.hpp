#pragma once

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

};
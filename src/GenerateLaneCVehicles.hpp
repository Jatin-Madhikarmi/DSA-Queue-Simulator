#pragma once

class LaneC
{
    public:
    LaneC();
    void draw();
    void update();

    private:
    int x;
    int y;
    int speed=5;
    int size=50;
    bool isActive=true;

};
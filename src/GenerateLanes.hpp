#pragma once

class Lanes
{
    public:
    void Update();
    void Draw();
    Lanes();
    private:
    int x1;
    int y1;
    int x2;
    int y2;
    bool trafficLightDC;
    bool trafficLightAB;
};
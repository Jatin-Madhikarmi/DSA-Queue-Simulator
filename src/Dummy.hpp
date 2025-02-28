#pragma once

class Dummy
{
    public:
    void Update(int);
    void Draw();
    Dummy();
    private:
    int x1;
    int y1;
    int x2;
    int y2;
    bool trafficLightDC;
    bool trafficLightAB;
    int light=1;
};
#include<raylib.h>
#include "GenerateLanes.hpp"
#include<istream>
#include<fstream>

Lanes::Lanes() : x1(575),y1(0),x2(0),y2(175)
{
}

void Lanes::Update()
{
    std::ifstream file("D&CTrafficLight.txt");
    if(file.is_open())
    {
        file>>trafficLightDC;
        file.close();
    }
    else
    {
        trafficLightDC=1;
        TraceLog(LOG_WARNING,"Unable to open the file.\n");
    }
}

void Lanes::Draw()
{
    const Color Grey={ 180, 180, 180, 255 };
    const int screenWidth=GetScreenWidth();
    DrawRectangle(x1,y1,450,800,Grey);
    DrawRectangle(x2,y2,screenWidth,450,Grey);
    if(trafficLightDC==1)
    {
        DrawRectangle(475,175,100,450,GREEN);
        DrawRectangle(1025,175,100,450,GREEN);
    }
    else
    {
        DrawRectangle(475,175,100,450,RED);
        DrawRectangle(1025,175,100,450,RED);
    }
}
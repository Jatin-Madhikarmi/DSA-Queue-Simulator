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
    std::ifstream File("A&BTrafficLight.txt");
    if(File.is_open())
    {
        File>>trafficLightAB;
        File.close();
    }
    else
    {
        trafficLightAB=0;
        TraceLog(LOG_WARNING,"Unable to open the file.\n");
    }
}

void Lanes::Draw()
{
    const Color Grey={ 180, 180, 180, 255 };
    const int screenWidth=GetScreenWidth();
    const int screenHeight=GetScreenHeight();
    DrawRectangle(x1,y1,450,screenHeight,Grey);
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
    if(trafficLightAB==1)
    {
        DrawRectangle(575,75,450,100,GREEN);
        DrawRectangle(575,625,450,100,GREEN);
    }
    else
    {
        DrawRectangle(575,75,450,100,RED);
        DrawRectangle(575,625,450,100,RED);
    }
}
#include<raylib.h>
#include "Dummy.hpp"
#include<istream>
#include<fstream>
#include <ctime>
#include<iostream>

Dummy::Dummy() : x1(575),y1(0),x2(0),y2(175)
{
}

void Dummy::Update(int traffictime)
{
    const int originalTime = traffictime;
    int VehiclesAno = 0;  // No need for static
    bool isPriority = false;
    
    // Read vehicle count
    std::ifstream VehiclesA("VehiclesNoA.txt");
    if (VehiclesA.is_open())
    {
        VehiclesA >> VehiclesAno;
        VehiclesA.close();
    }
    else
    {
        TraceLog(LOG_INFO, "Unable to open VehiclesNoA.txt file for reading purposes.\n");
        return;
    }

    // Check for priority condition
    if (VehiclesAno > 5)
    {
        std::ifstream fileTime("PriorityLaneTimer.txt");
        if (fileTime.is_open())
        {
            isPriority = true;
            fileTime >> traffictime;
            fileTime.close();
        }
        else
        {
            TraceLog(LOG_INFO, "Unable to open the priority lane time file for reading purposes.\n");
        }
    }

    // Update traffic light states
    if (isPriority)
    {
        trafficLightAB = 1;
        trafficLightDC = 0;

        // Write to files
        std::ofstream SetAB("A&BTrafficLight.txt");
        if (SetAB.is_open())
        {
            SetAB << trafficLightAB;
            TraceLog(LOG_INFO, "TrafficLightAB: %d written to A&BTrafficLight.txt.\n", trafficLightAB);
            SetAB.close();
        }

        std::ofstream SetDC("D&CTrafficLight.txt");
        if (SetDC.is_open())
        {
            SetDC << trafficLightDC;
            TraceLog(LOG_INFO, "TrafficLightDC: %d written to D&CTrafficLight.txt.\n", trafficLightDC);
            SetDC.close();
        }

        // Reduce vehicles count
        std::ofstream Updation("VehiclesNoA.txt");
        if (Updation.is_open())
        {
            VehiclesAno = 5;  // Reset VehiclesAno to 5 to avoid infinite loop
            Updation << VehiclesAno;
            Updation.close();
        }
        else
        {
            TraceLog(LOG_WARNING, "Unable to open VehiclesNoA.txt for updating the new value.\n");
        }

        if (VehiclesAno <= 5)
        {
            isPriority = false;
            traffictime = originalTime;
        }
    }

    // Toggle lights at intervals
    static float LastUpdatedTime = GetTime();
    float currentTime = GetTime();

    if (currentTime - LastUpdatedTime >= traffictime)
    {
        light = !light;
        trafficLightAB = light;
        trafficLightDC = !light;

        // Write updated light states
        std::ofstream trafficfile("A&BTrafficLight.txt");
        if (trafficfile.is_open())
        {
            trafficfile << trafficLightAB;
            trafficfile.close();
        }

        std::ofstream trafficFile("D&CTrafficLight.txt");
        if (trafficFile.is_open())
        {
            trafficFile << trafficLightDC;
            trafficFile.close();
        }

        LastUpdatedTime = currentTime;
    }
}




void Dummy::Draw()
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

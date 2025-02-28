#include<raylib.h>
#include "GenerateLanes.hpp"
#include<istream>
#include<fstream>
#include <ctime>
#include<iostream>

Lanes::Lanes() : x1(575),y1(0),x2(0),y2(175)
{
}



//Working Update function();
// void Lanes::Update(int traffictime)
// {
//     static float LastUpdatedTime=GetTime();
    
//     float currentTime=GetTime();
//     if(currentTime-LastUpdatedTime>=traffictime)
//     {
//         std::ofstream trafficfile("A&BTrafficLight.txt");
//         if (trafficfile.is_open()) 
//         {
//             trafficfile << light;
//             trafficfile.close();
//         } 
//         else 
//         {
//             printf("Failed to open A&BTrafficLight.txt for writing.\n");
//         }

//         std::ifstream File("A&BTrafficLight.txt");
//         if(File.is_open())
//         {
//             File>>trafficLightAB;
//             File.close();
//         }
//         else
//         {
//             trafficLightAB=0;
//             TraceLog(LOG_WARNING,"Unable to open the file.\n");
//         }

//         light=(light==0) ? 1 : 0;

//         std::ofstream trafficFile("D&CTrafficLight.txt");
//         if (trafficFile.is_open()) 
//         {
//             trafficFile << light;
//             trafficFile.close();
//         } 
//         else 
//         {
//             printf("Failed to open A&BTrafficLight.txt for writing.\n");
//         }

//         std::ifstream file("D&CTrafficLight.txt");
//         if(file.is_open())
//         {
//             file>>trafficLightDC;
//             file.close();
//         }
//         else
//         {
//             trafficLightDC=1;
//             TraceLog(LOG_WARNING,"Unable to open the file.\n");
//         }
//         LastUpdatedTime = currentTime;

//     }
// }


void Lanes::Update(int traffictime)
{
    static float LastUpdatedTime = GetTime();

    // Read initial value from A&BTrafficLight.txt
    std::ifstream Setval("A&BTrafficLight.txt");
    if (Setval.is_open())
    {
        Setval >> light;
        TraceLog(LOG_INFO, "traffiLightAB %d and light %d.\n", trafficLightAB, light);
        Setval.close();
    }
    else
    {
        TraceLog(LOG_WARNING, "Unable to open A&BTrafficLight.txt for initializing the value of light.\n");
    }

    trafficLightAB = light;
    trafficLightDC = !light;

    float currentTime = GetTime();
    if (currentTime - LastUpdatedTime >= traffictime)
    {
        // Toggle the light state
        light = (light == 0) ? 1 : 0;

        // Update A&BTrafficLight.txt
        std::ofstream trafficfile("A&BTrafficLight.txt");
        if (trafficfile.is_open()) 
        {
            trafficfile << light;
            //trafficfile.flush();  // Ensure the data is written to disk immediately
            trafficfile.close();
            TraceLog(LOG_INFO, "Updated A&BTrafficLight.txt: %d\n", light);
        } 
        else 
        {
            TraceLog(LOG_WARNING, "Failed to open A&BTrafficLight.txt for writing.\n");
        }

        trafficLightAB=light;

        light = (light == 0) ? 1 : 0;
        // Write the same updated value to D&CTrafficLight.txt
        std::ofstream trafficFile("D&CTrafficLight.txt");
        if (trafficFile.is_open()) 
        {
            trafficFile << trafficLightAB;
            //trafficFile.flush();  // Ensure the data is written to disk immediately
            trafficFile.close();
            TraceLog(LOG_INFO, "Updated D&CTrafficLight.txt: %d\n", trafficLightAB);
        } 
        else 
        {
            TraceLog(LOG_WARNING, "Failed to open D&CTrafficLight.txt for writing.\n");
        }

        trafficLightDC=light;

        // Update the last updated time
        LastUpdatedTime = currentTime;
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

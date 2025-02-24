#include<raylib.h>
#include "GenerateLaneCVehicles.hpp"
#include<fstream>
#include<istream>
#include<chrono>
#include<thread>

LaneC::LaneC():
x1(1500),
y1(525),
x2(1500),
y2(425),
speed(5),
size(50)
{
}

void LaneC::update()
{
    //const int screenWidth = GetScreenWidth();
    // const int screenHeight = GetScreenHeight();

    // std::ifstream File("D&CTrafficLight.txt");
    // File>>state;
    // File>>state;
    // File.close();


    // // Debugging output
    // if(state==1)
    // {
    // if(isActive1)
    // {
    //     if (x1 == 925) 
    //     {
    //         y1 += speed;
    //         x1 = 925;
            
    //         if ((y1 + size>= screenHeight) || (y1 + size<= 0)) 
    //         {
    //             isActive1=false;  
    //         }
    //     }
    //     else
    //     x1-=speed;
    // }

    // if(isActive2)
    // {
    //     x2-= speed;
    //     if ((x2<= 0)) 
    //         {
    //             isActive2=false;  
    //         }
    // }

    // }
    // else {  // Traffic light is RED
    //     TraceLog(LOG_INFO, "Traffic Light is RED. Vehicles are stopped.");

    //     // Start the timer if it hasn't started yet
    //     if (!timerStarted) {
    //         startTime = GetTime();
    //         timerStarted = true;
    //     }

    //     // If 5 seconds have passed, change the traffic light state
    //     if (GetTime() - startTime >= 5.0f) {
    //         state = 1;  // Change to GREEN

    //         // Write the new state to the file
    //         std::ofstream fileOut("D&CTrafficLight.txt");
    //         if (fileOut.is_open()) {
    //             fileOut << state;
    //             fileOut.close();
    //             TraceLog(LOG_INFO, "Traffic Light changed to GREEN after 5 seconds.");
    //         } else {
    //             TraceLog(LOG_WARNING, "Could not open traffic light file for writing!");
    //         }

    //         timerStarted = false;  // Reset timer for next cycle
    //     }
    int screenHeight = GetScreenHeight();

    // Read traffic light state from file
    std::ifstream fileIn("D&CTrafficLight.txt");
    if (fileIn.is_open()) {
        fileIn >> state;
        fileIn.close();
    } else {
        TraceLog(LOG_WARNING, "Could not open traffic light file for reading!");
        return;
    }

    // **Stop toggling when x1 or x2 reaches 175 or 625**
    if ((x1 == 175 || x1 == 625) || (x2 == 175 || x2 == 625)) {
        toggleAllowed = false;
    }

    // Toggle traffic light state every 5 seconds (only if toggling is allowed)
    if (toggleAllowed && (GetTime() - lastToggleTime >= 5.0f)) {
        state = (state == 0) ? 1 : 0;  // Toggle 0 <--> 1

        // Write updated state to file
        std::ofstream fileOut("D&CTrafficLight.txt");
        if (fileOut.is_open()) {
            fileOut << state;
            fileOut.close();
            TraceLog(LOG_INFO, "Traffic Light state changed to: %d", state);
        } else {
            TraceLog(LOG_WARNING, "Could not open traffic light file for writing!");
        }

        lastToggleTime = GetTime();  // Reset the timer
    }

    // **Vehicle Movement Logic (Only if traffic light is GREEN)**
    if (state == 1) {
        if (isActive1) {
            if (x1 == 925) {
                y1 += speed;
                x1 = 925;
                
                if ((y1 + size >= screenHeight) || (y1 + size <= 0)) {
                    isActive1 = false;
                }
            } else {
                x1 -= speed;
            }
        }

        if (isActive2) {
            x2 -= speed;
            if (x2 <= 0) {
                isActive2 = false;
            }
        }
    } else {
        TraceLog(LOG_INFO, "Traffic Light is RED. Vehicles are stopped.");
    }
}


void LaneC::draw()
{
    if(isActive1)
    DrawRectangle(x1,y1,size,size,RED);
    if(isActive2)
    DrawRectangle(x2,y2,size,size,RED);
}

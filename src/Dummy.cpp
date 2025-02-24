#include "Dummy.hpp"
#include <fstream>

// Constructor
vehicle::vehicle(int x, int y, int size, int speed)
    : x(x), y(y), size(size), speed(speed) {
    readStateFromFile(); // Read the number of vehicles from file
    // Initialize Y positions
    arr.resize(state,y);
    int coordinates=0;
    for(int i=0;i<state;i++)
    {
        arr[i]=y+coordinates;
        coordinates+=100;
    }
    isActive.resize(state, true); // Initialize activity status
}

// Read the number of vehicles from file
void vehicle::readStateFromFile() {
    std::ifstream file("VehiclesNo.txt");
    if (file.is_open()) {
        file >> state;
        TraceLog(LOG_INFO, "Number of vehicles: %d", state);
        file.close();
    } else {
        TraceLog(LOG_WARNING, "Unable to read the file.");
        state = 0; // Default to 0 if file cannot be read
    }

    std::ifstream File("D&CTrafficLight.txt");
    if (File.is_open()) {
        File >> light;
        TraceLog(LOG_INFO, "Number of vehicles: %d", state);
        File.close();
    } else {
        TraceLog(LOG_WARNING, "Unable to read the file.");
        light = 0; // Default to 0 if file cannot be read
    }
}

// Update vehicle positions
void vehicle::update() {
    const int screenHeight = GetScreenHeight();
    static float LastUpdatedTime=GetTime();
    const int Y=75;

    float currentTime=GetTime();
    if(currentTime-LastUpdatedTime>=10)
    {
        light=(light==0) ? 1 : 0;

        std::ofstream trafficFile("D&CTrafficLight.txt");
        if (trafficFile.is_open()) 
        {
            trafficFile << light;
            trafficFile.close();
        } 
        else 
        {
            printf("Failed to open D&CTrafficLight.txt for writing.\n");
        }
        LastUpdatedTime = currentTime;
    }
    for (int i = 0; i < state; i++) 
    {        
        if (isActive[i] == true) 
        {
            // Check if the vehicle has crossed the traffic light
            bool hasCrossedTrafficLight = (arr[i] >= Y);
            
            // If the vehicle has crossed the traffic light, it moves freely
            if (hasCrossedTrafficLight) 
            {
                arr[i] += speed;
            }
            // If the vehicle hasn't crossed the traffic light, it stops during red light
            else 
            {
                if (light == 1) 
                {  // Green light: move vehicles
                     arr[i] += speed;
                }
            }
            // Check if the vehicle has collided with the bottom of the screen
            if (arr[i] + size >= screenHeight) {
                printf("Collision detected for the vehicle %d\n", i);
                isActive[i] = false;
            }
        }
    }
}

// Draw vehicles
void vehicle::draw() 
{
    if(light==1)
    {
        DrawRectangle(575,75,450,100,GREEN);
    }
    else
    DrawRectangle(575,75,450,100,RED);
    for (int i = 0; i < state; i++) 
    {
        if (isActive[i]) 
        {
            DrawRectangle(x, arr[i], size, size, BLUE); // Draw the vehicle
        }
    }
}

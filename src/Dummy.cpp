#include "Dummy.hpp"
#include <fstream>

// Constructor
vehicle::vehicle(int x1, int y1,int x2,int y2,int speed, int size):
x1(x1), 
y1(y1),
x2(x2),
y2(y2),
size(size), 
speed(speed) {
    readStateFromFile(); // Read the number of vehicles from file
    // Initialize Y positions
    arr1.resize(state,x1);
    brr1.resize(state,y1);
    arr2.resize(state,x2);
    brr2.resize(state,y2);
    int coordinates1=0;
    int coordinates2=0;
    for(int i=0;i<state;i++)
    {
        brr1[i]=y1-coordinates1;
        coordinates1+=100;
    }
    isActive1.resize(state, true); // Initialize activity status
    isActive2.resize(state, true); // Initialize activity status
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

    std::ifstream File("A&BTrafficLight.txt");
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
    const int screenWidth = GetScreenWidth();
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
        // if (isActive[i] == true) 
        // {
        //     // Check if the vehicle has crossed the traffic light
        //     bool hasCrossedTrafficLight = (arr[i] >= Y);
            
        //     // If the vehicle has crossed the traffic light, it moves freely
        //     if (hasCrossedTrafficLight) 
        //     {
        //         arr[i] += speed;
        //     }
        //     // If the vehicle hasn't crossed the traffic light, it stops during red light
        //     else 
        //     {
        //         if (light == 1) 
        //         {  // Green light: move vehicles
        //              arr[i] += speed;
        //         }
        //     }
        //     // Check if the vehicle has collided with the bottom of the screen
        //     if (arr[i] + size >= screenHeight) {
        //         printf("Collision detected for the vehicle %d\n", i);
        //         isActive[i] = false;
        //     }
        // }
        if(isActive1[i]==true)
        {
            if(brr1[i]==275)
            {
                brr1[i]=275;
                arr1[i]+=speed;
                if(arr1[i] + size >= screenWidth)
                isActive1[i]=false;
            }
            else 
            brr1[i]+=speed;

        }
    }
}

// Draw vehicles
void vehicle::draw() 
{
    for (int i = 0; i < state; i++) 
    {
        if (isActive1[i]) 
        {
            DrawRectangle(arr1[i], brr1[i], size, size, BLACK); // Draw the vehicle
        }
    }
}

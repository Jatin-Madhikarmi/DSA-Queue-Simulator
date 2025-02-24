#include<raylib.h>
#include "Dummy.hpp"
#include<istream>
#include<fstream>

vehicle::vehicle():
x(675),
y(0),
size(50),
speed(1)
{
}

void vehicle::update() {
    const int screenHeight = GetScreenHeight();
    static float lastUpdateTime = GetTime();  // Static variable to store the last update time
    int state = 0;

    // Read the number of vehicles
    std::ifstream file("VehiclesNo.txt");
    if (file.is_open()) {
        file >> state;
        file.close();
    } else {
        TraceLog(LOG_WARNING, "Could not open traffic light file for reading!");
        return;
    }
    vehicleActiveStates.resize(state, true);

    // Read the current traffic state
    std::ifstream trafficFile("D&CTrafficLight.txt");
    if (trafficFile.is_open()) {
        trafficFile >> trafficState;
        trafficFile.close();
    } else {
        TraceLog(LOG_WARNING, "Couldn't able to open D&CTrafficLight.txt");
        return;
    }

    // Check if 10 seconds have passed since the last update
    float currentTime = GetTime();
    if (currentTime - lastUpdateTime >= 10) {
        // Toggle the traffic state
        trafficState = (trafficState == 0) ? 1 : 0;

        // Update the traffic state in the file
        std::ofstream trafficFile("D&CTrafficLight.txt");
        if (trafficFile.is_open()) {
            trafficFile << trafficState;
            trafficFile.close();
        } else {
            printf("Failed to open D&CTrafficLight.txt for writing.\n");
        }

        // Update the last update time
        lastUpdateTime = currentTime;
    }

    // If traffic state is 1, move the vehicles
    if (trafficState == 1) {
        for (int i = 0; i < state; i++) {
            if (vehicleActiveStates[i] == true) {
                vehicleYPositions[i] += speed;
                if (vehicleYPositions[i] + size >= screenHeight) {
                    printf("Collision detected for the vehicle %d\n", i);
                    vehicleActiveStates[i] = false;
                }
            }
        }
    }
}
//here the update function collision's only detected when the the last vehicle goes out of the scope then the whole collison is detected 
//and the vehicle are no longer rendered onto the screen
    
    void vehicle::draw() {
    int state = 0;
        std::ifstream file("VehiclesNo.txt");
        if (file.is_open()) 
        {
            file >> state;
            file.close();
        } else 
        {
            TraceLog(LOG_WARNING, "Could not open traffic light file for reading!");
            return;
        }
        int coordinates=0;
        vehicleActiveStates.resize(state,true);
        vehicleYPositions.resize(state,y);
        for(int i=0;i<state;i++)
        {
            if(vehicleActiveStates[i])
            DrawRectangle(x,vehicleYPositions[i]+coordinates,size,size,RED);
            coordinates+=100;
        }
}
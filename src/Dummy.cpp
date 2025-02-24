#include<raylib.h>
#include "Dummy.hpp"
#include<istream>
#include<fstream>

vehicle::vehicle():
x(675),
y(0),
size(50),
speed(2)
{
}

void vehicle:: update() {
    const int screenHeight = GetScreenHeight();
        int state = 0;
        std::ifstream file("VehiclesNo.txt");
        if (file.is_open()) {
            file >> state;
            file.close();
        } else {
            TraceLog(LOG_WARNING, "Could not open traffic light file for reading!");
            return;
        }
        vehicleActiveStates.resize(state,true);

        std::ifstream File("D&CTrafficLight.txt");
        if(File.is_open())
        {
            printf("The file D&CTrafficLight is open and read properly.\n");
            File>>trafficState;
            printf("trafficState from the file is : %d\n",trafficState);
            File.close();
        }
        else
        {
            TraceLog(LOG_WARNING,"Couldn't able to open D&CTrafficLight.txt");
            return;
        }
        printf("trafficState: %d\n", trafficState);
        if (trafficState==1)
        {
            for(int i=0;i<state;i++)
            {
                if(vehicleActiveStates[i]==true)
                {
                    vehicleYPositions[i]+=speed;
                    if(vehicleYPositions[i]+size>=screenHeight)
                    {
                        printf("Collision detected for the vehicle %d\n",i);
                        vehicleActiveStates[i]=false;
                    }
                }
    
            }

        }
        else
        {
            int timeelapsed=GetTime();
            if()
        }
//here the update function collision's only detected when the the last vehicle goes out of the scope then the whole collison is detected 
//and the vehicle are no longer rendered onto the screen

}

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
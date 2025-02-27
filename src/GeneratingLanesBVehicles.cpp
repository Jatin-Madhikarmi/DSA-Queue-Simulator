#include<raylib.h>
#include"GeneratingLanesBVehicles.hpp"
#include<fstream>
#include<istream>

LaneB::LaneB(int x1,int y1,int x2,int y2,int size,int speed,int time):
x1(625),
y1(700),
x2(825),
y2(700),
speed(5),
size(50),
traffictime(time)
{
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
        brr1[i]=y1+coordinates1;
        coordinates1+=100;
        brr2[i]=x2+coordinates2;
        coordinates2+=100;
    }
    isActive1.resize(state, true); // Initialize activity status 
    isActive2.resize(state, true); // Initialize activity status
}

void LaneB::readStateFromFile() {
    std::ifstream F("Time.txt");
    if (F.is_open()) {
        F >> trafficTime;
        TraceLog(LOG_INFO,"The value of Time retreived from the file for lane B is %d.\n",trafficTime);
        F.close();
    } else {
        TraceLog(LOG_WARNING, "Unable to read the file.");
    }

    std::ifstream file("VehiclesNoB.txt");
    if (file.is_open()) {
        file >> state;
        TraceLog(LOG_INFO, "Number of vehicles for lane B : %d", state);
        file.close();
    } else {
        TraceLog(LOG_WARNING, "Unable to read the file.");
        state = 0; // Default to 0 if file cannot be read
    }

    std::ifstream File("A&BTrafficLight.txt");
    if (File.is_open()) {
        File >> light;
        TraceLog(LOG_INFO, "Traffic Light state for lane B is : %d", light);
        File.close();
    } else {
        TraceLog(LOG_WARNING, "Unable to read the file.");
        light = 0; // Default to 0 if file cannot be read
    }

}

void LaneB::update()
{
    const int screenWidth=GetScreenWidth();
    static float LastUpdatedTime=GetTime();
    const int Y=625;

    float currentTime=GetTime();
    if(currentTime-LastUpdatedTime>=10)
    {
        std::ofstream File("D&CTrafficLight.txt");
        {
            if(File.is_open())
            {
                File << light;
                File.close();
            }
            else
            TraceLog(LOG_WARNING,"Unable to open the file.\n");

        }

        light=(light==0) ? 1 : 0;

        std::ofstream trafficFile("A&BTrafficLight.txt");
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
        if (isActive1[i] == true) 
        {
            if(brr1[i]==525)
            {
                brr1[i]=525;
                arr1[i]-=speed;
                if(arr1[i] <= 0)
                {
                    isActive1[i]=false;
                }
            }
            else
            {
                brr1[i]-=speed;
            }
        }

        if(isActive2[i] == true)
        {
            if(i%2!=0 && brr2[i]==425)
            {
                brr2[i]=425;
                arr2[i]+=speed;
                if(arr2[i] + size >= screenWidth)
                isActive2[i]=false;
            }
            else
            {
                // Check if the vehicle has crossed the traffic light
                bool hasCrossedTrafficLight = (brr2[i] <= Y);
                
                // If the vehicle has crossed the traffic light, it moves freely
                if (hasCrossedTrafficLight) 
                {
                    brr2[i] -= speed;
                }
                // If the vehicle hasn't crossed the traffic light, it stops during red light
                else 
                {
                    if (light == 1) 
                    {  // Green light: move vehicles
                        brr2[i] -= speed;
                    }
                }
                // Check if the vehicle has collided with the bottom of the screen
                if (brr2[i]<= 0 ) {
                    printf("Collision detected for the vehicle %d\n", i);
                    isActive2[i] = false;
                }
            }
        }
        
    }
}


void LaneB::draw()
{
    for (int i = 0; i < state; i++) 
    {
        if (isActive1[i]) 
        {
            DrawRectangle(arr1[i], brr1[i], size, size, BLUE); // Draw the vehicle
        }
        if (isActive2[i]) 
        {
            DrawRectangle(arr2[i], brr2[i], size, size, BLUE); // Draw the vehicle
        }
    }
}

#include<raylib.h>
#include"GenerateLanes.hpp"
#include"GeneratingLaneAVehicles.hpp"
#include"GeneratingLanesBVehicles.hpp"
#include"GenerateLaneCVehicles.hpp"
#include"GenerateLaneDVehicles.hpp"
#include<string.h>
#include<istream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>


void UpdateFile(int , std::string );
int GetRandomValue();
int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    const int screenWidth=1600.0f;
    const int screenHeight=800.0f;
    float traffictime=0;


    std::string PriorityTimer;
    PriorityTimer="PriorityLaneTimer.txt";
    
    std::vector <std::string> fileNames={"VehiclesNoA.txt","VehiclesNoB.txt","VehiclesNoC.txt","VehiclesNoD.txt"};
    
    std::vector<int>randomValue(fileNames.size());
    
    float priorityLaneTime=0.0f;
    
    for(int i=0;i<4;i++)
    {
        randomValue[i]=GetRandomValue();
        if(i!=0)
        {
            traffictime+=(randomValue[i]); // The traffic light timings are only considered for the roads B,C and D 
        }
        else
        {
            priorityLaneTime=randomValue[i];
            if(priorityLaneTime > 10)
            {
                priorityLaneTime=priorityLaneTime * 2;
                UpdateFile(priorityLaneTime,PriorityTimer);
            }
            
        }
        UpdateFile(randomValue[i],fileNames[i]);
    }
    //Condition when the priority lane is inacitve;
    traffictime=traffictime/3;
    traffictime=traffictime*2;

    Lanes lanes;
    LaneA vehicleA(925, 0,750,0, 3, 50);
    LaneB vehicleB(625,700,825,700,3,50);
    LaneC vehicleC(1500,525,1500,300,3,50);
    LaneD vehicleD(100,200,50,425,3,50);


    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
        lanes.Update(traffictime);
        vehicleA.update();
        vehicleB.update();
        vehicleC.update();
        vehicleD.update();

        BeginDrawing();
        ClearBackground(BLACK);
        lanes.Draw();
        vehicleA.draw();
        vehicleB.draw();
        vehicleC.draw();
        vehicleD.draw();
        EndDrawing();
    }
    CloseWindow();
}

void UpdateFile(int val, std::string fileName)
{
    std::ofstream File(fileName);
    if(File.is_open())
    {
        File << val;
        File.close();
    }
    else
    {
        TraceLog(LOG_WARNING,"Unable to open the file.\n");
    }
}

int GetRandomValue()
{
    return(std::rand() %9 + 5);// Genrates a random number between 5 adn 13
}

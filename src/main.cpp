#include<raylib.h>
#include"GenerateLaneDVehicles.hpp"
#include"GenerateLanes.hpp"
#include"GenerateLaneCVehicles.hpp"
#include"GeneratingLaneAVehicles.hpp"
#include"GeneratingLanesBVehicles.hpp"
#include"Dummy.hpp"
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
    int traffictime=0;
    std::string trafficTime;
    //trafficTime="Time.txt";

    std::vector <std::string> fileNames={"VehiclesNoA.txt","VehiclesNoB.txt","VehiclesNoC.txt","VehiclesNoD.txt"};

    std::vector<int>randomValue(fileNames.size());

    for(int i=0;i<4;i++)
    {
        randomValue[i]=GetRandomValue();
        traffictime+=(randomValue[i]);
        UpdateFile(randomValue[i],fileNames[i]);
    }
    traffictime=traffictime/3;
    traffictime=traffictime*2;
    //UpdateFile(traffictime,trafficTime);
    
    Lanes lanes;
    LaneA vehicleA(925, 0,750,0, 3, 50,traffictime);
    LaneB vehicleB(625,700,825,700,3,50,traffictime);
    LaneC vehicleC(1500,525,1500,300,3,50,traffictime);
    LaneD vehicleD(100,200,50,425,3,50,traffictime);
    
    Vehicles random(925, 0,725,0, 3, 50);

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(20);
    while(WindowShouldClose()==false)
    {
        lanes.Update();
        vehicleA.update();
        vehicleB.update();
        vehicleC.update();
        vehicleD.update();

        random.update();
        BeginDrawing();
        ClearBackground(BLACK);
        lanes.Draw();
        vehicleA.draw();
        vehicleB.draw();
        vehicleC.draw();
        vehicleD.draw();
        //random.draw();
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
    return(std::rand() %9 +1);
}

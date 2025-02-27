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

    std::vector <std::string> fileNames={"VehiclesNoA.txt","VehiclesNoB.txt","VehiclesNoC.txt","VehiclesNoD.txt"};

    std::vector<int>randomValue(fileNames.size());

    for(int i=0;i<4;i++)
    {
        randomValue[i]=GetRandomValue();
        UpdateFile(randomValue[i],fileNames[i]);
    }
   
    LaneD vehicleD(100,200,50,300,3,50);
    Lanes lanes;
    LaneC vehicleC(1500,525,1500,425,3,50);
    LaneA vehicleA(925, 0,825,0, 3, 50);
    LaneB vehicleB(625,700,750,700,3,50);

    Vehicles random(925, 0,825,0, 3, 50);

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(20);
    while(WindowShouldClose()==false)
    {
        lanes.Update();
        vehicleD.update();
        vehicleC.update();
        vehicleA.update();
        vehicleB.update();

        random.update();
        BeginDrawing();
        ClearBackground(BLACK);
        lanes.Draw();
        vehicleA.draw();
        vehicleD.draw();
        vehicleC.draw();
        vehicleB.draw();
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

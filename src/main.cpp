#include<raylib.h>
#include<fstream>
#include<thread>
#include<chrono>
#include"GenerateVehicles.hpp"
#include"GenerateLanes.hpp"
#include"GenerateLaneCVehicles.hpp"
#include"GeneratingLaneAVehicles.hpp"
#include"GeneratingLanesBVehicles.hpp"
#include"Dummy.hpp"

int main()
{
    const int screenWidth=1600.0f;
    const int screenHeight=800.0f;


    Vehicles vehicles;
    Lanes lanes;
    LaneC vehicleC;
    LaneA vehicleA;
    LaneB vehicleB;
    vehicle random;

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
        lanes.Draw();
        // vehicles.Draw();
        // vehicles.Update();
        // vehicleC.update();
        // vehicleC.draw();
        // vehicleA.update();
        // vehicleA.draw();
        // vehicleB.update();
        // vehicleB.draw();
        random.draw();
        random.update();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}
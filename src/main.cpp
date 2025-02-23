#include<raylib.h>
#include"GenerateVehicles.hpp"
#include"GenerateLanes.hpp"
#include"GenerateLaneCVehicles.hpp"

int main()
{
    const int screenWidth=1600.0f;
    const int screenHeight=800.0f;


    Vehicles vehicles;
    Lanes lanes;
    LaneC vehicleC;

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        lanes.Draw();
        vehicles.Draw();
        vehicles.Update();
        vehicleC.update();
        vehicleC.draw();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}
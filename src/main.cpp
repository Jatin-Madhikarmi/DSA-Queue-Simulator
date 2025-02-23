#include<raylib.h>
#include"GenerateVehicles.hpp"
#include"GenerateLanes.hpp"

int main()
{
    const int screenWidth=1660.0f;
    const int screenHeight=800.0f;


    Vehicles vehicles;
    Lanes lanes;

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(60);
    while(WindowShouldClose()==false)
    {
        lanes.Draw();
        vehicles.Draw();
        vehicles.Update();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}
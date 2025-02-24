#include<raylib.h>
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
    LaneC vehicleC(1500,525,1500,425,50,3);
    LaneA vehicleA;
    LaneB vehicleB;
    vehicle random(650, 0, 50, 3);

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
        lanes.Draw();
        // vehicles.Draw();
        // vehicles.Update();
        vehicleC.update();
        // vehicleA.update();
        // vehicleA.draw();
        // vehicleB.update();
        // vehicleB.draw();
        //random.update();
        BeginDrawing();
        ClearBackground(BLACK);
        vehicleC.draw();
        //random.draw();
        EndDrawing();
    }
    CloseWindow();
}

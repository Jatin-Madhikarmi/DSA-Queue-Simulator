#include<raylib.h>
#include"GenerateLaneDVehicles.hpp"
#include"GenerateLanes.hpp"
#include"GenerateLaneCVehicles.hpp"
#include"GeneratingLaneAVehicles.hpp"
#include"GeneratingLanesBVehicles.hpp"
#include"Dummy.hpp"

int main()
{
    const int screenWidth=1600.0f;
    const int screenHeight=800.0f;


    LaneD vehicleD(100,200,100,300,3,50);
    Lanes lanes;
    LaneC vehicleC(1500,525,1500,425,3,50);
    LaneA vehicleA;
    LaneB vehicleB;
    vehicle random(650, 0, 50, 3);

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
        lanes.Draw();
        vehicleD.update();
        vehicleC.update();
        // vehicleA.update();
        // vehicleA.draw();
        // vehicleB.update();
        // vehicleB.draw();
        //random.update();
        BeginDrawing();
        ClearBackground(BLACK);
        vehicleD.draw();
        vehicleC.draw();
        //random.draw();
        EndDrawing();
    }
    CloseWindow();
}

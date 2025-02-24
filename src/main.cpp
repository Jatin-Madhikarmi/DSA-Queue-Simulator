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
    LaneB vehicleB(625,700,750,700,3,50);
    vehicle random(650, 0, 50, 3);

    InitWindow(screenWidth,screenHeight,"MAIN SCREEN");
    SetTargetFPS(30);
    while(WindowShouldClose()==false)
    {
        lanes.Update();
        vehicleD.update();
        vehicleC.update();
        // vehicleA.update();
        // vehicleA.draw();
        vehicleB.update();
        //random.update();
        BeginDrawing();
        lanes.Draw();
        ClearBackground(BLACK);
        vehicleD.draw();
        vehicleC.draw();
        vehicleB.draw();
        //random.draw();
        EndDrawing();
    }
    CloseWindow();
}

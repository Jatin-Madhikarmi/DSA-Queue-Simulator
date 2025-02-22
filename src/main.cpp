// #include <raylib.h>
// #include "ball.h"

// int main() 
// {
//     const Color darkGreen = {20, 160, 133, 255};
    
//     constexpr int screenWidth = 800;
//     constexpr int screenHeight = 600;
    
//     Ball ball;
    
//     InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
//     SetTargetFPS(60);
    
//     while (!WindowShouldClose())
//     {
//         ball.Update();
        
//         BeginDrawing();
//             ClearBackground(darkGreen);
//             ball.Draw();
//         EndDrawing();
//     }
    
//     CloseWindow();
// }
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
        vehicles.Update();
        vehicles.Draw();
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}
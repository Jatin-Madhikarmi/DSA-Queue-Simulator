#include<raylib.h>
#include "GenerateLaneCVehicles.hpp"

LaneC::LaneC():
x(1500),
y(525),
speed(5),
size(50)
{
}

void LaneC::update()
{
    const int screenHeight=GetScreenHeight();
    if(isActive)
    {
        if (x == 925) 
        {
            y += speed;
            x = 925;
            
            if ((y + size>= screenHeight) || (y + size<= 0)) 
            {
                isActive=false;  
            }
        }
        else
        x-=speed;
    }
}

void LaneC::draw()
{
    if(isActive)
    DrawRectangle(x,y,size,size,RED);
}

#include<raylib.h>
#include "GenerateLaneCVehicles.hpp"

LaneC::LaneC():
x1(1500),
y1(525),
x2(1500),
y2(425),
speed(5),
size(50)
{
}

void LaneC::update()
{
    const int screenHeight=GetScreenHeight();
    if(isActive1)
    {
        if (x1 == 925) 
        {
            y1 += speed;
            x1 = 925;
            
            if ((y1 + size>= screenHeight) || (y1 + size<= 0)) 
            {
                isActive1=false;  
            }
        }
        else
        x1-=speed;
    }

    if(isActive2)
    {
        x2-= speed;
        if ((x2<= 0)) 
            {
                isActive2=false;  
            }
    }
}

void LaneC::draw()
{
    if(isActive1)
    DrawRectangle(x1,y1,size,size,RED);
    if(isActive2)
    DrawRectangle(x2,y2,size,size,RED);
}

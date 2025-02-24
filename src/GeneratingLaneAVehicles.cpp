#include<raylib.h>
#include "GeneratingLaneAVehicles.hpp"

LaneA::LaneA():
x1(925),
y1(0),
x2(825),
y2(0),
speed(5),
size(50)
{}

void LaneA::draw()
{
    if(isActive1)
    DrawRectangle(x1,y1,size,size,BLUE);
    if(isActive2)
    DrawRectangle(x2,y2,size,size,BLUE);
}

void LaneA::update()
{
    const int screenWidth=GetScreenWidth();
    const int screenHeight=GetScreenHeight();
    if(isActive1)
    {
        if (y1 == 225) 
        {
            x1 += speed;
            y1 = 225;
            
            if ((x1 +size >= screenWidth)) 
            {
                isActive1=false;  
            }
        }
        else
        y1+=speed;
    }

    if(isActive2)
    {
        y2+= speed;
        if ((y2 +size >= screenHeight)) 
            {
                isActive2=false;  
            }
    }
}

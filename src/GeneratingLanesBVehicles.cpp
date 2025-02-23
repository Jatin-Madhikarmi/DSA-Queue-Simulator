#include<raylib.h>
#include "GeneratingLanesBVehicles.hpp"

LaneB::LaneB():
x1(675),
y1(700),
x2(775),
y2(700),
speed(5),
size(50)
{
}

void LaneB::draw()
{
    if(isActive1)
    DrawRectangle(x1,y1,size,size,GREEN);
    if(isActive2)
    DrawRectangle(x2,y2,size,size,GREEN);
}

void LaneB::update()
{
    if(isActive1)
    {
        if (y1 == 525) 
        {
            x1 -= speed;
            y1 = 525;
            
            if ((x1 <= 0)) 
            {
                isActive1=false;  
            }
        }
        else
        y1-=speed;
    }

    if(isActive2)
    {
        y2-= speed;
        if ((y2<= 0)) 
            {
                isActive2=false;  
            }
    }
}
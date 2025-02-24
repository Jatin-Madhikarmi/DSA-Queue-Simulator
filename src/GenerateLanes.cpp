#include<raylib.h>
#include "GenerateLanes.hpp"


Lanes::Lanes() : x1(575),y1(0),x2(0),y2(175)
{
}

void Lanes::Draw()
{
    const Color Grey={ 180, 180, 180, 255 };
    const int screenWidth=GetScreenWidth();
    DrawRectangle(x1,y1,450,800,Grey);
    DrawRectangle(x2,y2,screenWidth,450,Grey);
}
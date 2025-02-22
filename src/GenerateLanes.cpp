#include<raylib.h>
#include "GenerateLanes.hpp"


Lanes::Lanes() : x1(600),y1(0),x2(0),y2(200)
{
}

void Lanes::Draw()
{
    const Color Grey={20, 160, 133, 255};
    const int screenWidth=GetScreenWidth();
    DrawRectangle(x1,y1,400,800,Grey);
    DrawRectangle(x2,y2,screenWidth,400,Grey);
}
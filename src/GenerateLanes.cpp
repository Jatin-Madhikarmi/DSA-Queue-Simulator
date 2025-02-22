#include<raylib.h>
#include "GenerateLanes.hpp"


Lanes::Lanes() : x1(800),y1(0)
{
}

void Lanes::Draw()
{
    DrawRectangle(x1,y1,400,800,GREEN);

}
#include<raylib.h>
#include "GenerateVehicles.hpp"

Vehicles::Vehicles(): x(100),y(100),speed(5),size(50)
{
}

void Vehicles::Update()
{
    x+=speed;

    const int screenWidth=GetScreenWidth();

    if((x+size >= screenWidth) || (x-size)<=0)
    speed*=-1;
}

void Vehicles::Draw()
{
    DrawRectangle(x,y,50,50,WHITE);
}
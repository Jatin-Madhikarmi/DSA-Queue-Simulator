#include<raylib.h>
#include "GenerateVehicles.hpp"

Vehicles::Vehicles():speed(5),
size(50),

DL3x(100),
DL3y(200),
DL3Speed(5),
DL2Ox(100),
DL2Oy(350)
{
}

void Vehicles::Update()
{

    const int screenWidth=GetScreenWidth();
    const int screenHeight=GetScreenHeight();
    if(DL3Active)
    {
        if (DL3x == 620) 
        {
            DL3y -= DL3Speed;
            DL3x = 620;
            
            if ((DL3y -size>= screenHeight) || (DL3y + size<= 0)) 
            {
                DL3Active=false;  
            }
        }
        else
        DL3x+=speed;
    }
    
    if(DL2OActive)
    {
        DL2Ox+=speed;
    
        if((DL2Ox+size >= screenWidth) || (DL2Ox-size)<=0)
        DL2OActive=false;

    }
}

void Vehicles::Draw()
{
    if(DL3Active)
        DrawRectangle(DL3x,DL3y+50,50,50,WHITE);

    if(DL2OActive)
        DrawRectangle(DL2Ox,DL2Oy,50,50,WHITE);
}
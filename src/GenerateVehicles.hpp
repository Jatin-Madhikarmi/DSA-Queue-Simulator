#pragma once

class Vehicles
{
    public:
    Vehicles();
    void Update();
    void Draw();

    private:
    int DL3x;//Represents the x-coordinate of the lane DL3
    int DL3y;//Represents the y-coordinates of the lane DL3
    int DL3Speed;//Represents the speed of the vehicles that turns left
    // The lane DL3 represens the lane which is free to turn left.
    bool DL3Active=true;//When the vehicles goes out of scope the vehicles are no longer drawn on the screen

    int DL2Ox;//Represents the x-cordiante of the lane DL2 and O represetsn the outgoing vehicles.
    int DL2Oy;//Represents the y-cordiante of the lane DL2 and O represetsn the outgoing vehicles.
    int DL2OSpeed;
    bool DL2OActive=true;
    int speed;
    int size;
};
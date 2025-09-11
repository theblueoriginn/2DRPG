#pragma once
#include "Character.h"
class Player;
class Enemy :
    public Character
{
private:
    int speed;
    int health;
public:
    void Move(int xdir, int ydir);
    
    Enemy();
};


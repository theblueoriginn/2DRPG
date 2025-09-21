#pragma once
#include "Character.h"
#include "scene.h"
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


#pragma once
#include "Character.h"

#include <iostream>
class Enemy;
class Player :
    public Character
{
private:
    int step;
    int health;
public:
    void Move(int xdir,int ydir);
    bool checkCollision(Enemy enemy, int xdir, int ydir);
    bool checkCollision(sf::FloatRect rect, int xdir, int ydir);
    
    bool checkCollision(Enemy enemy);
    
    Player();
};


#pragma once
#include "Character.h"
#include <map>
#include <iostream>
class Enemy;
class Player :
    public Character
{
private:
    int speed;
    int health;
    std::string state;
    int frame;
public:
    //movement logic
    
    void Move(int xdir, int ydir, float dt);
    bool checkCollision(Enemy enemy, int xdir, int ydir, float dt);
   
    bool checkCollision(sf::FloatRect rect, int xdir, int ydir, float dt);
    

    //animation logic and state logic.
    bool startedAnim{ false };
    std::string changeState(std::string state);
    int nextFrame();
    sf::Sprite* getCurrentSprite();
    
    sf::Texture idleSpriteSheet;
    std::map<int,sf::Sprite* > idle_frames;

    sf::Texture walkSpriteSheet;
    std::map<int, sf::Sprite* > walk_frames;
    
    Player();
};


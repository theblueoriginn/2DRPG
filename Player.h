#pragma once
#include "Character.h"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"

#include <iostream>
class Enemy;
class Player :
    public Character
{
private:
    int speed;
    int health;
    int currentIndex;
  

    int spriteWidth;
    int spriteHeight;
    
    sf::Texture* idleTex;
    sf::Texture* idleLeftTex;
    sf::Texture* walkTex;

    //step sound.
    sf::SoundBuffer stepBuf;
    sf::Sound* stepSound;
    
public:
    void Move(int xdir,int ydir, float dt);
    bool checkCollision(Enemy enemy, int xdir, int ydir, float dt);
    bool checkCollision(sf::FloatRect rect, int xdir, int ydir, float dt);
    
    bool checkCollision(Enemy enemy);
    
    std::string changeState(std::string state, int xdir, int ydir);
    int nextFrame(int xdir, int ydir);


    Player(std::string idleSheet, std::string walkSheet, int spriteWidth, int spriteHeight);
};


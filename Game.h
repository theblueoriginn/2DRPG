#pragma once
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>

#include <string>

#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class Game
{
private:
	//window and view
	sf::RenderWindow window;
	sf::View view;

	//delta time & clock
	//TODO Reset time / get time in beginning of each update cycle.
	sf::Time time = sf::seconds(0.f);
	sf::Clock clock;
	sf::Time dt = sf::seconds(1.f / 60.f);
	float deltaElapsed{0.f};

	bool gameIsOpen{ false };

	sf::Texture map_tx;
	sf::Sprite* map_sp;


	//players and enemies.

	
	
	Player player;

	int xdir = 0;
	int ydir = 0;
	Enemy enemy;
	Enemy enemy2;
	std::vector<Enemy> enemies;

	void initWindow();
	void initVars();
	void initTime();
	void initResources();

	//update functions
	void pollEvents();

	//Constructor
public:
	bool getGameIsOpen();
	void update();
	void render();
	Game();
	~Game();

};


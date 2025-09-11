#pragma once
#include <SFML/Window.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>

#include <string>

#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <map>
#include "tinytmx/tinytmx.hpp"


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

	std::map<int  , sf::Texture*>tileTextures;

	//players and enemies.

	
	
	Player* player;

	int xdir = 0;
	int ydir = 0;
	Enemy enemy;
	Enemy enemy2;
	std::vector<Enemy> enemies;

	void initWindow();
	void initVars();
	void initTime();
	void initResources();
	void parseMap();
	std::vector<sf::Sprite> sprites;
	std::vector<sf::FloatRect> collidables;
	//update functions
	void pollEvents();
	bool keyHold{false};

	//Constructor
public:
	bool getGameIsOpen();
	void update(float dt);
	void update_fixed(float timestep);
	void render(float dt);

	Game();
	~Game();

};


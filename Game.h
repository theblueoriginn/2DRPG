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
#include <sstream>


class Game
{
private:
	//window and view
	sf::RenderWindow window;
	sf::View view;



	//fps
	float fps;
	sf::Font* hudFont;
	sf::Text* fpsText;
	std::stringstream stream;

	bool gameIsOpen{ false };

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


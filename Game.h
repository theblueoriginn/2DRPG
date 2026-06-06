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

#include "scene.h"
typedef sf::Vector2f v2f;
#define INTERACTION_DISTANCE 64.f

class Game
{
private:
	//window and view
	sf::RenderWindow window;
	sf::View view;
	//scene
	scene gameScene;


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
	void pollEvents(float dt);
	bool nearEnemies(float dt, Enemy enemy);
	bool keyHold{false};

	bool collidesEnemies(float dt);

	//Constructor
public:
	bool getGameIsOpen();
	void update(float dt);
	void update_fixed(float timestep);
	void render(float dt);

	Game();
	~Game();

};


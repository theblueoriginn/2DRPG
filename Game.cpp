#include "Game.h"
bool Game::getGameIsOpen()
{
	return gameIsOpen;
}
void Game::update()
{
	//TODO time logic

	//pollevents and update xdir, ydir.
	this->pollEvents();
	//move if no collision
	if (xdir != 0 || ydir != 0) {
		bool collision = false;

		for (auto it = enemies.begin(); it != enemies.end(); it++) {
			//if collision, set it true to prevent movement. Then, break loop
			if (player.checkCollision(*it,xdir,ydir)) { 
				
				collision = true; 
				
				break; 
			
			} //todo custom hp-
		}
		
		
		//if no collision, keep the regular movement going.
		if (!collision) { player.Move(xdir, ydir); }
		xdir = 0, ydir=0;

	}
	
	/*std::cout << player.getPosition().x << " " << player.getPosition().y << std::endl;*/
	//center the camera to the character.
	if (view.getCenter() != player.getPosition()) { view.setCenter(player.getPosition()); }
	
	
}
void Game::render()
{
	this->window.clear();
	this->window.setView(this->view);
	this->window.draw(*this->map_sp);
	
	this->window.draw(*player.getSprite());
	for (auto it = enemies.begin(); it != enemies.end(); it++) {
		this->window.draw( (*it->getSprite()) );
	}

	this->window.display();
	
}
void Game::initWindow()
{
	this->window.create(sf::VideoMode({ 48*16,48*16 }), "Window");
	this->window.setFramerateLimit(60);

    this->view.setCenter(static_cast<sf::Vector2f>(sf::Vector2u(this->window.getSize().x / 2, this->window.getSize().y / 2)));
	this->view.setSize(static_cast<sf::Vector2f>(sf::Vector2u(this->window.getSize().x , this->window.getSize().y ) ));
}
void Game::initVars()
{
	this->gameIsOpen = true;
}
void Game::initResources()
{
	//CHARACTERS
	this->player.setSprite("res\\img\\character.png");
	this->player.setPosition(sf::Vector2f({ 96,96 }));
	
	this->enemy.setSprite("res\\img\\character.png");
	this->enemy.setPosition(sf::Vector2f({ 144,144 }));
	this->enemies.push_back(this->enemy);

	this->enemy2.setSprite("res\\img\\character.png");
	this->enemy2.setPosition(sf::Vector2f({ 192,192 }));
	this->enemies.push_back(this->enemy2);

	
	//MAP
	if (!this->map_tx.loadFromFile("res\\img\\map0.png")) {
		std::cout << "error loading map texture!" << std::endl;
	}
	//TODO ADD RESOURCES AND SPRITES HERE

	this->map_sp = new sf::Sprite(map_tx);

}
void Game::pollEvents()
{
	auto ev = this->window.pollEvent();
	if (auto key = ev->getIf<sf::Event::KeyPressed>()) {
		if (key->scancode == sf::Keyboard::Scancode::Left) { xdir = -1; ydir = 0; }
		else if (key->scancode == sf::Keyboard::Scancode::Right) { xdir = 1; ydir = 0; }
		else if (key->scancode == sf::Keyboard::Scancode::Up) {
			xdir = 0;ydir = -1;
		}
		else if (key->scancode == sf::Keyboard::Scancode::Down) {
			xdir = 0;ydir = 1;
		}
		
	}
}

//Constructor
Game::Game()
{

	this->initWindow();
	
	this->initResources();
	this->initVars();

}

Game::~Game()
{
	
}

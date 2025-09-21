#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "scene.h"
class Character
{
protected:
	
	sf::Vector2f position;
	
	sf::Texture texture;
	sf::Sprite* sprite;
	scene sc;
public:
	//getters
	
	sf::Vector2f getPosition();
	sf::Sprite* getSprite();
	sf::Texture getTexture();
	scene getScene();
	//setters
	void setSprite(std::string textureAdress);
	void setPosition(sf::Vector2f pos);
	
	void setScene(scene sc);

	Character(std::string textureAdress, sf::Vector2f startingPosition);
	Character(std::string textureAdress);
	Character();
};


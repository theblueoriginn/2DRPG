#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Character
{
protected:
	
	sf::Vector2f position;
	
	sf::Texture texture;
	sf::Sprite* sprite;
public:
	
	sf::Vector2f getPosition();
	sf::Sprite* getSprite();
	sf::Texture getTexture();
	void setSprite(std::string textureAdress);
	void setPosition(sf::Vector2f pos);
	Character(std::string textureAdress, sf::Vector2f startingPosition);
	Character(std::string textureAdress);
	Character();
};


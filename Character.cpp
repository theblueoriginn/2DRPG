#include "Character.h"
#include <iostream>




sf::Sprite* Character::getSprite() { 
	
	return sprite;
	
	
}
sf::Texture Character::getTexture()
{
	
	return this->texture;
}
scene Character::getScene()
{
	return this->sc;
}
sf::Vector2f Character::getPosition() {
	
	return position;

}


void Character::setSprite(std::string textureAdress)
{
	if (this->texture.loadFromFile(textureAdress)) {}
	this->sprite = new sf::Sprite(texture);
}
void Character::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	if (this->sprite !=nullptr) { this->getSprite()->setPosition(pos); }
	
}
void Character::setScene(scene sc)
{
	this->sc = sc;
}

//create a character with texture of adress  and set its location
Character::Character(std::string textureAdress, sf::Vector2f startingPosition = sf::Vector2f({0.f,0.f})) : position(startingPosition)
{
	//load the texture.
	if(this->texture.loadFromFile(textureAdress)){}
	this->sprite = new sf::Sprite(this->texture);
	this->setPosition(this->position);
	this->setScene(scene::map);

	
}
//create a character with texture of adress  and default location 0.f 0.f
Character::Character(std::string textureAdress) : position(sf::Vector2f({ 0.f,0.f }))
{
	//load the texture.
	if (this->texture.loadFromFile(textureAdress)) {}
	this->sprite = new sf::Sprite(texture);
	this->setPosition(this->position);
	this->setScene(scene::map);
	


}
//Default constructor. Note that characters created with these should be bind sprites with setSprite() immediately.
Character::Character() : sprite(nullptr) , position(sf::Vector2f({ 0.f,0.f }))
{
	
	this->setPosition(this->position);
	this->setScene(scene::map);
	
	

}

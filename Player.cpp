#include "Player.h"
#include "Enemy.h"
void Player::Move(int xdir, int ydir)
{
	
	this->setPosition(this->getPosition() + static_cast<sf::Vector2f>(sf::Vector2i({ xdir * step ,ydir * step }))   );
	
	//this->sprite->setPosition(this->position);
	
	
}

bool Player::checkCollision(Enemy enemy,int xdir,int ydir)
{
	sf::Vector2f nextPos = this->getPosition() + static_cast<sf::Vector2f>(sf::Vector2i({ xdir * step ,ydir * step }));
	return enemy.getSprite()->getGlobalBounds().contains(nextPos);
	
	
	
}

Player::Player()
{
	//super call
	this->step = 48;
	this->health = 100;
}



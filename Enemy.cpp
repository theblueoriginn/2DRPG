#include "Enemy.h"
void Enemy::Move(int xdir, int ydir)
{

	this->setPosition(this->getPosition() + static_cast<sf::Vector2f>(sf::Vector2i({ xdir * speed ,ydir * speed })));

	//this->sprite->setPosition(this->position);


}
Enemy::Enemy() {
	this->speed = 48;
	this->health = 30;
}
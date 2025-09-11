#include "Player.h"
#include "Enemy.h"
void Player::Move(int xdir, int ydir, float dt)
{

	this->setPosition(this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt }));
	for (auto idle : this->idle_frames) { idle.second->setPosition(this->position); }
	for (auto walk : this->walk_frames) { walk.second->setPosition(this->position); }
	
	//this->sprite->setPosition(this->position);
	


}

bool Player::checkCollision(Enemy enemy, int xdir, int ydir, float dt)
{
	sf::Vector2f nextPos = this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt });
	return enemy.getSprite()->getGlobalBounds().contains(nextPos);



}
bool Player::checkCollision(sf::FloatRect rect, int xdir, int ydir, float dt)
{
	sf::Vector2f nextPos = this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt });

	return (rect.contains(nextPos));


}
std::string Player::changeState(std::string state)
{
	
	//return to anim. frame 0 
	this->frame = 0;
	this->startedAnim = true;
	this->state = state;
	if (state == "idle") {
		this->sprite = idle_frames.at(0);
	}
	else if (state == "walk") {
		this->sprite = walk_frames.at(0);
	}
	return state;
}

int Player::nextFrame()
{
		
		
	if (this->state == "idle") {
		if (startedAnim) { this->frame = 0; this->startedAnim = false;}
		else if (this->frame < idle_frames.size() - 1) {
			this->frame++;
		}
		else {
			//reset to loop.
			this->frame = 0;
		}
		this->sprite = idle_frames.at(this->frame);
	}
	else if (this->state == "walk") {
		if (startedAnim) { this->frame = 0; this->startedAnim = false; }
		else if (this->frame < walk_frames.size() - 1) {
			this->frame++;
		}
		else {
			this->frame = 0;
		}
		this->sprite = walk_frames.at(this->frame);
	}


	return this->frame;

}

sf::Sprite* Player::getCurrentSprite()
{
	return this->sprite;
	

}
Player::Player()
{
	//super call
	this->speed = 48;
	this->health = 100;
	this->state = "idle";


	if (!idleSpriteSheet.loadFromFile("res\\img\\soldier-idle.png")) { std::cerr << "can't load the soldier-idle.png texture."; }
	//load the sprites...
	for (int i = 0;i < idleSpriteSheet.getSize().x / 32; i += 1) {
		auto frameAtI =new sf::Sprite(idleSpriteSheet, sf::IntRect(sf::Vector2i(i * 32, 0), sf::Vector2i(32, 32)));
		idle_frames.insert(std::pair(i, frameAtI));
	}

	if (!walkSpriteSheet.loadFromFile("res\\img\\soldier-walkright.png")) { std::cerr << "can't load the soldier-walkright.png texture."; }
	//load the sprites...
	for (int i = 0;i < walkSpriteSheet.getSize().x / 32; i += 1) {
		auto frameAtI = new sf::Sprite (walkSpriteSheet, sf::IntRect(sf::Vector2i(i * 32, 0), sf::Vector2i(32, 32)));
		walk_frames.insert(std::pair(i, frameAtI));
	}

	this->sprite = idle_frames.at(0);

}



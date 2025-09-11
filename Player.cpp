#include "Player.h"
#include "Enemy.h"
void Player::Move(int xdir, int ydir, float dt)
{

	this->setPosition(this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt }));

	//this->sprite->setPosition(this->position);


}

bool Player::checkCollision(Enemy enemy, int xdir, int ydir, float dt)
{
	auto nextPos = this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt });
	return enemy.getSprite()->getGlobalBounds().contains(nextPos);



}
bool Player::checkCollision(sf::FloatRect rect, int xdir, int ydir, float dt)
{
	auto nextPos = this->getPosition() + sf::Vector2f({ xdir * speed * dt ,ydir * speed * dt });

	return (rect.contains(nextPos));


}
std::string Player::changeState(std::string state, int xdir, int ydir)
{
		if(xdir !=0)
			this->sprite->setScale({static_cast<float>(xdir),static_cast<float>(1) });
	if (state == "idle") {
		this->sprite->setTexture(*idleTex);

		
	}
	else if (state == "walk") {
		this->sprite->setTexture(*walkTex);
	}
	this->currentIndex = 0;

	return state;
}
int Player::nextFrame(int xdir, int ydir)
{
	auto frames = this->sprite->getTexture().getSize().x / this->spriteWidth;
	//sets the next frame with +1.
	this->sprite->setTextureRect(sf::IntRect({ (this->currentIndex % static_cast<int>(frames)) * this->spriteWidth ,0 }, { this->spriteWidth,this->spriteHeight }));
	//TODO DIRECTION LOGIC


	return currentIndex++ % frames;
}
//spreadSheets must be a character sprite sheet file (png).
//This Constructor loads spread sheet from given strings and sets 1st argument(idle)'s texture as sprites'.
//spriteWidth width of each frame.
Player::Player(std::string idleSheet, std::string walkSheet, int spriteWidth, int spriteHeight) : spriteWidth(spriteWidth), spriteHeight(spriteWidth)
{
	//super call
	this->speed = 32;
	this->health = 100;
	this->currentIndex = 0;

	idleTex = new sf::Texture();

	if (!this->idleTex->loadFromFile(idleSheet)) {
		std::cerr << "GAME: PLAYER(): cant load " << idleSheet << std::endl;
	}
	//idleLeftTex = new sf::Texture(*idleTex);

	walkTex = new sf::Texture();
	if (!this->walkTex->loadFromFile(walkSheet)) {
		std::cerr << "GAME: PLAYER(): cant load " << walkSheet << std::endl;
	}
	//set idleTex as initial texture.
	this->sprite = new sf::Sprite(*idleTex);
	//cut it to the first frame.
	this->sprite->setTextureRect(sf::IntRect({ 0,0 }, { this->spriteWidth,this->spriteHeight }));
	this->sprite->setOrigin({ float(this->spriteWidth/2), float(this->spriteHeight/2) });

}



#include "Game.h"
#ifndef PLAYER_WIDTH
#define PLAYER_WIDTH 32
#endif
#ifndef PLAYER_HEIGHT
#define PLAYER_HEIGHT 32
#endif

bool Game::getGameIsOpen()
{
	return gameIsOpen;
}
void Game::update(float dt)
{
	this->pollEvents();
	if (xdir != 0 || ydir != 0) {
		bool collision = false;

		for (auto it = enemies.begin(); it != enemies.end(); it++) {
			//if collision, set it true to prevent movement. Then, break loop
			if (player->checkCollision(*it, xdir, ydir, dt)) {

				collision = true;

				break;

			} //todo custom hp-
		}
		for (auto collidable : collidables) {
			if (player->checkCollision(collidable, xdir, ydir, dt)) {
				collision = true;

				break;
			}
		}




		//if no collision, keep the regular movement going.
		if (!collision) { player->Move(xdir, ydir, dt); }


	}


	//center the camera to the character.
	if (view.getCenter() != player->getPosition()) { view.setCenter(player->getPosition()); }
	this->fps = 1 / dt;

	this->stream << "fps: " << std::fixed << std::setprecision(2) << this->fps;

	this->fpsText->setString(this->stream.str());
	this->fpsText->setPosition({ this->view.getCenter().x - 200 , this->view.getCenter().y - 200 });
	this->stream.str(std::string());
}
void Game::update_fixed(float timestep) {
	std::cout << "GAME::UPDATE current frame: " << this->player->nextFrame(xdir, ydir) << std::endl;
}
void Game::render(float dt)
{
	this->window.clear();

	this->window.setView(this->view);
	//give the sfml drawable tiles here.
	for (auto sprite : sprites) {
		this->window.draw(sprite);
	}
	for (auto it = enemies.begin(); it != enemies.end(); it++) {
		this->window.draw((*it->getSprite()));
	}

	this->window.draw(*player->getSprite());
	this->window.draw(*fpsText);


	this->window.display();

}
void Game::initWindow()
{
	this->window.create(sf::VideoMode({ 48 * 16,48 * 16 }), "Window");
	this->window.setFramerateLimit(60);

	this->view.setCenter(static_cast<sf::Vector2f>(sf::Vector2u(this->window.getSize().x / 2, this->window.getSize().y / 2)));
	this->view.setSize(static_cast<sf::Vector2f>(sf::Vector2u(this->window.getSize().x, this->window.getSize().y)));
	this->view.zoom(0.50f);



}
void Game::initVars()
{

	this->gameIsOpen = true;




}
void Game::initResources()
{
	//CHARACTERS
	this->player = new Player("res/img/soldier-idle.png", "res/img/soldier-walk.png", PLAYER_WIDTH, PLAYER_HEIGHT);

	this->enemy.setSprite("res\\img\\character.png");
	this->enemy.setPosition(sf::Vector2f({ 144,144 }));
	this->enemies.push_back(this->enemy);


	//HUD AND TEXTS
	try { this->hudFont = new sf::Font("res\\fonts\\arial.ttf"); }
	catch (int e) { std::cout << e; }
	this->fpsText = new sf::Text(*hudFont, "fps:");

}
void Game::parseMap()
{
	//parse the map file.
	tinytmx::Map* map = new tinytmx::Map();
	std::string fileName = "res/maps/map.tmx";
	map->ParseFile(fileName);
	//add all textures of tilesets

	for (auto ts : map->GetTilesets()) {
		//getsource returns the relative path of tileset to the map.

		int cnt = ts->GetFirstGid();
		sf::Texture* tileTexture = new sf::Texture();

		if (!tileTexture->loadFromFile("res/maps/" + ts->GetImage()->GetSource())) {
			std::cerr << "Failed to load texture: "
				<< ts->GetImage()->GetSource() << std::endl;
			delete tileTexture;
			continue;
		}
		else {

			tileTextures[cnt] = tileTexture;
		}


	}
	auto tileLayers = map->GetTileLayers();
	for (auto layer : tileLayers) {
		//we get the chunks
		auto chunks = layer->GetDataTileFiniteMap();
		for (int y = 0;y < chunks->GetHeight();y++) {
			for (int x = 0;x < chunks->GetWidth();x++) {

				auto tileGID = chunks->GetTileGid(x, y);
				auto tileset = map->FindTileset(tileGID);
				if (!tileset) { continue; }
				auto tileID = tileGID - tileset->GetFirstGid();
				//get floatRect for this tileID so we can add it as a sprite.

				//get tileset for this tile.


				auto row = static_cast<int> (tileID / tileset->GetColumns());
				auto column = static_cast<int> (tileID % tileset->GetColumns());
				auto height = static_cast<int>(tileset->GetTileHeight());
				auto width = static_cast<int>(tileset->GetTileWidth());

				tinytmx::Tile tile(tileID);
				for (auto tx : tileTextures) {

					if (tileset->GetFirstGid() == tx.first) {

						sf::Sprite sprite(*tx.second, sf::IntRect(sf::Vector2i({ column * width,row * height }), sf::Vector2i({ width,height })));
						sprite.setPosition(static_cast<sf::Vector2f>(sf::Vector2i({ x * width,y * width })));
						sprites.push_back(sprite);

					}

				}



			}
		}
	}
	auto objectGroups = map->GetObjectGroups();
	for (auto objectGroup : objectGroups) {
		auto objects = objectGroup->GetObjects();

		for (auto object : objects) {
			//all the vertices on the polygon.

			float leftX = object->GetX();
			float upY = object->GetY();
			float width;
			float height;
			for (auto point : object->GetPolygon()->GetPoints()) {
				std::cout << "points inside the polygon: " << point.x << " , " << point.y << " " << std::endl;
				if (point.x > 0.f) {
					width = point.x;
				}

				if (point.y > 0.f) {
					height = point.y;
				}
			}

			sf::FloatRect objectRect(sf::Vector2f(leftX, upY), sf::Vector2f(width, height));

			std::cout << "Left Top Most Coordinates: " << leftX << "," << upY << "Width: " << width << "Height: " << height << std::endl;
			collidables.push_back(objectRect);
		}
	}

}
void Game::pollEvents()
{
	if (const auto ev = this->window.pollEvent()) {
		if (const auto* key = ev->getIf<sf::Event::KeyPressed>()) {
			if (key->scancode == sf::Keyboard::Scancode::Left && !keyHold) { xdir = -1; ydir = 0; std::cout << "GAME:pollEvents change state: " << this->player->changeState("walk", xdir, ydir) << std::endl; keyHold = true; }
			else if (key->scancode == sf::Keyboard::Scancode::Right && !keyHold) {
				xdir = 1; ydir = 0;std::cout << "GAME:pollEvents change state: " << this->player->changeState("walk", xdir, ydir) << std::endl;keyHold = true;
			}
			else if (key->scancode == sf::Keyboard::Scancode::Up && !keyHold) {
				xdir = 0;ydir = -1;std::cout << "GAME:pollEvents change state: " << this->player->changeState("walk", xdir, ydir) << std::endl;keyHold = true;
			}
			else if (key->scancode == sf::Keyboard::Scancode::Down && !keyHold) {
				xdir = 0;ydir = 1;std::cout << "GAME:pollEvents change state: " << this->player->changeState("walk", xdir, ydir) << std::endl;keyHold = true;
			}
		}
		else if (const auto* key = ev->getIf<sf::Event::KeyReleased>()) {
			if (key->scancode == sf::Keyboard::Scancode::Left || key->scancode == sf::Keyboard::Scancode::Right || key->scancode == sf::Keyboard::Scancode::Up || key->scancode == sf::Keyboard::Scancode::Down) {
				xdir = 0; ydir = 0; std::cout << "GAME:pollEvents change state: " << this->player->changeState("idle", xdir, ydir) << std::endl; keyHold = false;

			}
		}
	}
}

//Constructor
Game::Game()
{

	this->initWindow();

	this->initResources();
	this->initVars();
	this->parseMap();

}

Game::~Game()
{
	//delete all tiletextures and sprites.
	for (auto& tileTexture : tileTextures) {
		delete tileTexture.second;
		tileTextures.erase(tileTexture.first);

	}
	sprites.clear();
}

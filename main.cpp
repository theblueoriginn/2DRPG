#include "Game.h"

int main()
{
	Game game;
	sf::Clock clock;
	clock.restart();
	float timestep = 1.f / 8.f;
	float dt = 0.f;
	float lastTick = 0.f;
	float time = 0.f;
	float dt_acc = 0.f;

	while(game.getGameIsOpen() ) {
		time = clock.getElapsedTime().asSeconds();
		dt = time - lastTick;
		lastTick = time;
		dt_acc += dt;

		game.update(dt);
		//do this every 8th of a second.The higher timestep,the less it takes from main loop.
		if (dt_acc >= timestep) {
			
			game.update_fixed(timestep);
			dt_acc -= timestep;
		}

		game.render(dt);
	}
	return 0;
}
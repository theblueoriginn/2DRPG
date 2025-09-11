#include "Game.h"
#include "main.h"

int main()
{
	Game game;

	
	float time=0.f;
	float lastTick=0.f;
	sf::Clock clock;
	clock.start();
	
	float dt=0.f;
	float dt_accum = 0.f;
	float timestep = 1.f / 8.f;  //each frame takes 125ms
	while(game.getGameIsOpen() ) {
		time = clock.getElapsedTime().asSeconds();
		dt = time - lastTick;
		lastTick = time;
		dt_accum += dt;
		
		//std::cout << "dt: " << dt <<" secs" << dt*1000 << "/ms" << " fps: " << 1.f / dt << std::endl;
		
		//TODO add dt to this functions.
		
		game.update(dt);
		while (dt_accum >= timestep) {
			dt_accum -= timestep;
			//do something on fixed timestep... //it has to be something inexpensive.
			
			game.update_fixed(timestep);

		}
		game.render(dt);
	}
	return 0;
}


/*	sf::Texture map0Text;
	if(map0Text.loadFromFile("res\\img\\map0.png",false,sf::IntRect({0,0},{48*30,48*30}))) {}
	
	sf::Sprite map0(map0Text);
	sf::RectangleShape rect;
	rect.setSize( sf::Vector2f{48.f,48.f});
	rect.setPosition(sf::Vector2f{240,240});
	rect.setFillColor(sf::Color::Red);
	sf::RenderWindow window(sf::VideoMode({48*8,48*8}), "Window");
	sf::View view(sf::FloatRect({ 48.f, 48.f }, { 48.f*8, 48.f*8 }));

	
	int i = 0;
	while(window.isOpen()){

		i++;
		if(i%1000 == 0){
			view.move(sf::Vector2f( {48.f,48.f } ));
		}
		

		window.clear();
		
		window.setView(view);
		window.draw(map0);
		rect.setPosition( window.getView().getCenter()  );
		window.draw(rect);
		window.display();
		
		
	
	}*/
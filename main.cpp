#include "Game.h"

int main()
{
	Game game;
	while(game.getGameIsOpen() ) {
		game.update();
		game.render();
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
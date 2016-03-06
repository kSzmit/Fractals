#include <SFML/Graphics.hpp>
#include "Aplikacja.hpp"


int main(int argc, char *argv[]){
	int sizeX = 1500, sizeY = 1000;
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;

	//sf::VideoMode(sizeX, sizeY, 32)
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Przeglad fraktali", sf::Style::Fullscreen, settings);

	sf::Clock clock;
	Aplikacja app(window, clock);

	while (window.isOpen()){
			app.handleEvents();
			app.draw();
			window.display();
		}

	return 0;
}
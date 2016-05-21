#include <SFML/Graphics.hpp>
#include "Application.hpp"


int main(int argc, char *argv[]){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 2;

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Przeglad fraktali", 0, settings);
	sf::Clock clock;
	Application app(window, clock);

	while (window.isOpen()){
			app.handleEvents();
			app.draw();
			window.display();
		}
	return 0;
}
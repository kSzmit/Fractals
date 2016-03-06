#pragma once
#include <SFML/Graphics.hpp>

class Triangle
{
	int m_sizeX;
	int m_sizeY;

	sf::Vector2f m_A;
	sf::Vector2f m_B;
	sf::Vector2f m_C;

	sf::RectangleShape m_point;
public:
	Triangle();

	Triangle(int sizeX, int sizeY);
	void iterPoint();
	void setColor(sf::Color color);
	void drawFractal(sf::RenderWindow& window);
};


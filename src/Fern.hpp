#pragma once
#include <SFML/Graphics.hpp>

class Fern
{
	int m_sizeX;
	int m_sizeY;
	const float minX = -2.1820f, maxX = 2.6558f, minY = 0.0f, maxY = 9.9983f;
	float m_coordX;
	float m_coordY;

	sf::RectangleShape m_point;

	sf::Vector2f m_D;
public:
	Fern();

	Fern(int sizeX, int sizeY);
	void iterPoint();
	void setColor(sf::Color kolor);
	void drawFractal(sf::RenderWindow& window);
	sf::Vector2i getSize();
};


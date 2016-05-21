#pragma once
#include <SFML/Graphics.hpp>
#include "IFSFractal.hpp"

class Fern :
	public IFSFractal
{
	const float minX = -2.1820f, maxX = 2.6558f, minY = 0.0f, maxY = 9.9983f;
	float m_coordX;
	float m_coordY;
	sf::Vector2f m_D;
public:
	Fern(int sizeX, int sizeY);
	
	void iterPoint() override;

	void drawFractal(sf::RenderWindow& window) override;

	sf::Vector2i getSize();
};


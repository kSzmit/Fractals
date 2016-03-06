#pragma once
#include <SFML/Graphics.hpp>


class Cantor
{
	int m_sizeX;
	int m_sizeY;
	int m_iteration;
	sf::VertexArray m_cantorSet;
public:
	Cantor();

	Cantor(int sizeX, int sizeY);
	void setIter(int iter);
	void split();
	void assemble();
	void setColor(sf::Color color);
	void drawFractal(sf::RenderWindow& window);
};

#pragma once
#include <SFML/Graphics.hpp>

class SierpinskiCarpet
{
	int m_size;
	int m_scale;
	int m_iter;

private:
	bool belongToSet(int x, int y);

public:
	SierpinskiCarpet(int sizeX, int sizeY);

	int getIter();

	int getMaxIter();

	void setIter(int iter);

	int getSize();

	void drawFractal(sf::RenderWindow& window);
};


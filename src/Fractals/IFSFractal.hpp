#pragma once
#include <SFML/Graphics.hpp>

class IFSFractal
{
protected:
	int m_sizeX;
	int m_sizeY;
	int m_iter;
	sf::RectangleShape m_point;
public:
	virtual void iterPoint() = 0;

	void setColor(sf::Color color);

	virtual void drawFractal(sf::RenderWindow& window);

	void clearIter();

	int getIter();
};


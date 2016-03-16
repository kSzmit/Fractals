#pragma once
#include <SFML/Graphics.hpp>

class IterativeFractal
{
protected:
	int m_sizeX;
	int m_sizeY;
	int m_iteration;
	sf::VertexArray m_fractal;

public:
	IterativeFractal();

	virtual void assemble() = 0;
	virtual void split() = 0;

	void setIter(int iter);
	void setColor(sf::Color kolor);
	void drawFractal(sf::RenderWindow& window);
};


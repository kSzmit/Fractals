#pragma once
#include <SFML/Graphics.hpp>

class Mandelbrot
{
	int m_sizeX, m_sizeY;
	long double m_minX, m_maxX, m_minY, m_maxY;
	int m_iteration;
	int m_paletteSize;
	sf::Vector3f m_palette[2047];
	int m_colorDensity;
private:
	float lerp(float x, float y, float t);

public:
	Mandelbrot(int sizeX, int sizeY);
	void drawFractal(sf::RenderWindow& window);
	sf::Vector3f calcColor(int coordX, int coordY);
	void handleEvents(sf::Event event);
	void setIter(int inter);
	void createPalette();
};


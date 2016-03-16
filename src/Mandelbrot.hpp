#pragma once
#include <SFML/Graphics.hpp>


class Mandelbrot{	
protected:
	int m_sizeX, m_sizeY;
	long double m_minX, m_maxX, m_minY, m_maxY;
	int m_iteration;
	int m_paletteSize;
	sf::Vector3f m_palette[2048];
	int m_colorDensity;
	float lerp(float x, float y, float t);

public:
	Mandelbrot();
	Mandelbrot(int sizeX, int sizeY);
	void drawFractal(sf::RenderWindow& window);
	virtual sf::Vector3f calcColor(int coordX, int coordY);
	void handleEvents(sf::Event event);
	void setIter(int inter);
	void createPalette(std::string fileName);
};


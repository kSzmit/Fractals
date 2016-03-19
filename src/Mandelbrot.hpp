#pragma once
#include <SFML/Graphics.hpp>
#include <tbb\tbb.h>


class Mandelbrot{	
protected:
	sf::RenderWindow& m_appWindow;

	int m_sizeX, m_sizeY;
	long double sMinX, sMaxX, sMinY, sMaxY;
	long double m_zoom;
	int m_zoomPower;
	long double m_X, m_Y;

	int m_iteration;
	int m_paletteSize;
	sf::Vector3f m_palette[2048];
	int m_colorDensity;
	float lerp(float x, float y, float t);

	void zoom(bool zoomIn);
	void moveHorizontal(bool moveLeft);
	void moveVertical(bool moveUp);

public:
	Mandelbrot(sf::RenderWindow& window);
	void drawFractal(sf::RenderWindow& appWindow);
	virtual sf::Vector3f calcColor(int coordX, int coordY);
	void handleEvents(sf::Event event);
	void setIter(int inter);
	void createPalette(std::string fileName);
	long double getX();
	long double getY();
	int getZoomPower();
};


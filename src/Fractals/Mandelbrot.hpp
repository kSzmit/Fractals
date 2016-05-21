#pragma once
#include <SFML/Graphics.hpp>
#include <tbb\tbb.h>



class Mandelbrot{	
protected:
	sf::RenderWindow& m_appWindow;

	int m_sizeX, m_sizeY;
	long double m_MinX, m_MaxX, m_MinY, m_MaxY;
	long double m_zoom;
	int m_zoomPower;
	long double m_X, m_Y;

	int m_iteration;
	int m_paletteSize;
	sf::Vector3f m_palette[2048];
	int m_colorDensity;

	float lerp(float x, float y, float t);

	void zoom(bool zoomIn);


public:
	Mandelbrot(sf::RenderWindow& appWindow);

	void drawFractal(sf::RenderWindow& window);

	virtual sf::Vector3f calcColor(int coordX, int coordY);

	void handleEvents(sf::Event event);

	void setIter(int iter);

	void createPalette(std::string fileName);

	long double getX();

	long double getY();

	int getZoomPower();
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Mandelbrot.hpp"

class Julia :
	public Mandelbrot
{
	double m_cY;
	double m_cX;
public:
	Julia(int sizeX, int sizeY);
	sf::Vector3f calcColor(int coord_X, int coord_Y) override;
	void setC(sf::Vector2f coord);
};


#pragma once
#include <SFML/Graphics.hpp>
#include "IterativeFractal.hpp"

class Koch :
	public IterativeFractal
{
	sf::Vector2f apex(float x1, float y1, float x2, float y2);
public:
	Koch();
	Koch(int sizeX, int sizeY);
	void assemble() override;
	void split() override;
};


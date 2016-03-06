#pragma once
#include <SFML/Graphics.hpp>

class Koch
{
	int m_sizeX;
	int m_sizeY;
	int m_iteration;
	sf::VertexArray m_kochCurve;

private:
	sf::Vector2f apex(float x1, float y1, float x2, float y2);

public:
	Koch();

	Koch(int sizeX, int sizeY);
	void setIter(int iter);
	void assemble();
	void split();
	void setColor(sf::Color kolor);
	void drawFractal(sf::RenderWindow& window);
};


#pragma once
#include <SFML/Graphics.hpp>
#include "IFSFractal.hpp"

class Triangle :
	public IFSFractal
{
	sf::Vector2f m_A;
	sf::Vector2f m_B;
	sf::Vector2f m_C;
public:
	Triangle();
	Triangle(int sizeX, int sizeY);
	void iterPoint() override;
};


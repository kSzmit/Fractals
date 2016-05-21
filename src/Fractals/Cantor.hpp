#pragma once
#include <SFML/Graphics.hpp>
#include "IterativeFractal.hpp"

class Cantor :
	public IterativeFractal
{
public:
	Cantor(int sizeX, int sizeY);

	void split() override;


	void assemble() override;
};

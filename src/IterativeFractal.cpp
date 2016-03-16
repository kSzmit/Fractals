#include "IterativeFractal.hpp"


IterativeFractal::IterativeFractal(){
}


void IterativeFractal::setColor(sf::Color kolor){
	for (int i = 0; i < m_fractal.getVertexCount(); i++){
		m_fractal[i].color = kolor;
	}
}

void IterativeFractal::setIter(int iter){
	if (iter>m_iteration){
		for (; m_iteration != iter; m_iteration++){
			split();
		}
	}
	else{
		for (; m_iteration != iter; m_iteration--)
		{
			assemble();
		}
	}
}

void IterativeFractal::drawFractal(sf::RenderWindow& window){
	window.clear(sf::Color::White);
	setColor(sf::Color::Black);
	window.draw(m_fractal);
}
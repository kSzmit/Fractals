#include "IFSFractal.hpp"


void IFSFractal::setColor(sf::Color color){
	m_point.setFillColor(color);
}

void IFSFractal::drawFractal(sf::RenderWindow& window){
	iterPoint();
	m_iter += 1;
	window.draw(m_point);
}


void IFSFractal::clearIter(){
	m_iter = 0;
}

int IFSFractal::getIter(){
	return m_iter;
}
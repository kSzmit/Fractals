#include "IFSFractal.hpp"


IFSFractal::IFSFractal()
{
}

void IFSFractal::setColor(sf::Color kolor){
	m_point.setFillColor(kolor);
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
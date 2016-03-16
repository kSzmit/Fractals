#include "Fern.hpp"
#include <random>


Fern::Fern(){
}

Fern::Fern(int sizeX, int sizeY) {
	m_point = sf::RectangleShape(sf::Vector2f(1, 1));
	if (sizeX > sizeY / 2){
		m_sizeX = sizeY / 2;
	}
	else{
		m_sizeX = sizeX;
	}
	m_sizeY = 0.8*sizeY;
	m_coordX = 0.0f;
	m_coordY = 0.0f;
	sf::Vector2f m_D((m_coordX - minX) * sizeX / (maxX - minX), sizeY - m_coordY*sizeY / maxY);
	m_point.setPosition(m_D);
	setColor(sf::Color::Green);
}

void Fern::iterPoint(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 100.0);

	m_D = sf::Vector2f((m_coordX - minX) * m_sizeX / (maxX - minX), m_sizeY - m_coordY*m_sizeY / maxY);
	m_point.setPosition(m_D);

	double rand = dist(mt);

	if (rand <= 1){
		m_coordX = 0.0f;
		m_coordY = 0.16f*m_coordY;
	}
	else if (rand <= 8){

		float tmp = 0.2f*m_coordX - 0.26f*m_coordY;
		m_coordY = 0.23f*m_coordX + 0.22f*m_coordY + 1.6f;
		m_coordX = tmp;
	}
	else if (rand <= 15){
		float tmp = -0.15f*m_coordX + 0.28f*m_coordY;
		m_coordY = 0.26f*m_coordX + 0.24f*m_coordY + 0.44f;
		m_coordX = tmp;
	}
	else{
		float tmp = 0.85f*m_coordX + 0.04f*m_coordY;
		m_coordY = -0.04f*m_coordX + 0.85f*m_coordY + 1.6f;
		m_coordX = tmp;
	}
}

void Fern::drawFractal(sf::RenderWindow& window){
	iterPoint();
	m_iter += 1;
	sf::RectangleShape tmpPoint = m_point;
	tmpPoint.move((window.getSize().x - getSize().x) / 2, window.getSize().y / 10);
	window.draw(tmpPoint);
}

sf::Vector2i Fern::getSize(){
	return sf::Vector2i(m_sizeX, m_sizeY);
}

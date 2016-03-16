#include "Triangle.hpp"
#include <random>

Triangle::Triangle()
{
}

Triangle::Triangle(int sizeX, int sizeY){
	m_point = sf::RectangleShape(sf::Vector2f(1, 1));
	m_sizeX = sizeX;
	m_sizeY = sizeX;
	int tmp = 1.1*(sizeX - sizeY);
	if (tmp < 400)
		tmp = 400;
	m_A = sf::Vector2f(tmp / 2, sizeY - 100);
	m_B = sf::Vector2f(sizeX - tmp / 2, sizeY - 100);
	m_C = sf::Vector2f(sizeX / 2, sizeY - 100 - (sizeX - tmp)*sqrt(3) / 2);
	m_point.setPosition(m_A);
	setColor(sf::Color::Blue);
}

void Triangle::iterPoint(){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 3.0);
	sf::Vector2f D = m_point.getPosition();

	double rand = dist(mt);
	if (rand <= 1){
		D.x = (D.x + m_A.x) / 2;
		D.y = (D.y + m_A.y) / 2;
	}
	else if (rand <= 2){
		D.x = (D.x + m_B.x) / 2;
		D.y = (D.y + m_B.y) / 2;
	}
	else {
		D.x = (D.x + m_C.x) / 2;
		D.y = (D.y + m_C.y) / 2;
	}
	m_point.setPosition(D);
}

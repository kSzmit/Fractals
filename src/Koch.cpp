#include "Koch.hpp"


Koch::Koch(){
}

Koch::Koch(int sizeX, int sizeY) : m_kochCurve(sf::LinesStrip, 4){
	m_iteration = 0;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	int tmp = 1.4*(sizeX - sizeY);
	if (tmp < 400)
		tmp = 400;
	m_kochCurve[0].position = sf::Vector2f(sizeX - tmp / 2, sizeY * 7.5 / 10);
	m_kochCurve[1].position = sf::Vector2f(tmp / 2, sizeY * 7.5 / 10);
	m_kochCurve[2].position = apex(tmp / 2, sizeY * 7.5 / 10, sizeX - tmp / 2, sizeY * 7.5 / 10);
	m_kochCurve[3].position = sf::Vector2f(sizeX - tmp / 2, sizeY * 7.5 / 10);
}

void Koch::assemble(){
	int sizeCurve = m_kochCurve.getVertexCount();
	sf::VertexArray assembledCurve(sf::LinesStrip, (sizeCurve + 3) / 4);

	for (int i = 0; i < sizeCurve; i += 4){
		assembledCurve[i / 4] = sf::Vector2f(m_kochCurve[i].position.x, m_kochCurve[i].position.y);
	}
	m_kochCurve = assembledCurve;
}

void Koch::split(){
	int sizeCurve = m_kochCurve.getVertexCount();

	sf::VertexArray splitCurve(sf::LinesStrip, (sizeCurve - 1) * 3 + sizeCurve);
	for (int i = 0; i < sizeCurve - 1; i++){
		splitCurve[i * 4].position = sf::Vector2f(m_kochCurve[i].position.x, m_kochCurve[i].position.y);
		splitCurve[i * 4 + 1].position = sf::Vector2f(m_kochCurve[i].position.x - (m_kochCurve[i].position.x - m_kochCurve[i + 1].position.x) / 3,
														m_kochCurve[i].position.y - (m_kochCurve[i].position.y - m_kochCurve[i + 1].position.y) / 3);
		splitCurve[i * 4 + 3].position = sf::Vector2f(m_kochCurve[i].position.x - (m_kochCurve[i].position.x - m_kochCurve[i + 1].position.x) * 2 / 3,
														m_kochCurve[i].position.y - (m_kochCurve[i].position.y - m_kochCurve[i + 1].position.y) * 2 / 3);
		splitCurve[i * 4 + 2].position = apex(splitCurve[i * 4 + 1].position.x, splitCurve[i * 4 + 1].position.y, 
												splitCurve[i * 4 + 3].position.x, splitCurve[i * 4 + 3].position.y);
		splitCurve[i * 4 + 4].position = sf::Vector2f(m_kochCurve[i + 1].position.x, m_kochCurve[i + 1].position.y);
	}
	m_kochCurve = splitCurve;
}

void Koch::setColor(sf::Color kolor){
	for (int i = 0; i < m_kochCurve.getVertexCount(); i++){
		m_kochCurve[i].color = kolor;
	}
}

void Koch::setIter(int iter){
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

void Koch::drawFractal(sf::RenderWindow& window){
	window.clear(sf::Color::White);
	setColor(sf::Color::Black);
	window.draw(m_kochCurve);
}

sf::Vector2f Koch::apex(float x1, float y1, float x2, float y2)
{
	/*
	float Xc = (x1 + x2) / 2;
	float Yc = (y1 + y2) / 2;
	float m = (y2 - y1) / (x2 - x1);
	float d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	float u = d*sqrt(3) / 2;

	if (x1 > x2)
	u = -u;

	float x = Xc + m*u / sqrt(1 + m*m);
	float y = Yc - u / sqrt(1 + m*m);
	*/

	return sf::Vector2f((x1 + x2 - sqrt(3)*(y1 - y2)) / 2, (y1 + y2 + sqrt(3)*(x1 - x2)) / 2);
}
#include "Cantor.hpp"

Cantor::Cantor(){
}

Cantor::Cantor(int sizeX, int sizeY) : m_cantorSet(sf::Quads, 4){
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_iteration = 0;
	m_cantorSet[0].position = sf::Vector2f(50, sizeY / 2 + 50);
	m_cantorSet[1].position = sf::Vector2f(50, sizeY / 2 - 50);
	m_cantorSet[2].position = sf::Vector2f(sizeX - 50, sizeY / 2 - 50);
	m_cantorSet[3].position = sf::Vector2f(sizeX - 50, sizeY / 2 + 50);
}

void Cantor::split(){
	int curveSize = m_cantorSet.getVertexCount();

	sf::VertexArray splitCurve(sf::Quads, curveSize * 2);
	for (int i = 0; i < curveSize - 1; i += 4){
		splitCurve[2 * i] = sf::Vector2f(m_cantorSet[i].position.x, m_cantorSet[i].position.y);
		splitCurve[2 * i + 1] = sf::Vector2f(m_cantorSet[i + 1].position.x, m_cantorSet[i + 1].position.y);
		splitCurve[2 * i + 2] = sf::Vector2f(m_cantorSet[i].position.x - (m_cantorSet[i].position.x - m_cantorSet[i + 2].position.x) / 3, m_cantorSet[i + 1].position.y);
		splitCurve[2 * i + 3] = sf::Vector2f(m_cantorSet[i].position.x - (m_cantorSet[i].position.x - m_cantorSet[i + 2].position.x) / 3, m_cantorSet[i].position.y);
		splitCurve[2 * i + 4] = sf::Vector2f(m_cantorSet[i].position.x - (m_cantorSet[i].position.x - m_cantorSet[i + 2].position.x) * 2 / 3, m_cantorSet[i + 3].position.y);
		splitCurve[2 * i + 5] = sf::Vector2f(m_cantorSet[i].position.x - (m_cantorSet[i].position.x - m_cantorSet[i + 2].position.x) * 2 / 3, m_cantorSet[i + 2].position.y);
		splitCurve[2 * i + 6] = sf::Vector2f(m_cantorSet[i + 2].position.x, m_cantorSet[i + 2].position.y);
		splitCurve[2 * i + 7] = sf::Vector2f(m_cantorSet[i + 3].position.x, m_cantorSet[i + 3].position.y);
	}
	m_cantorSet = splitCurve;
}

void Cantor::assemble(){
	int curveSize = m_cantorSet.getVertexCount();

	sf::VertexArray assembledCurve(sf::Quads, curveSize / 2);
	for (int i = 0; i < curveSize - 1; i += 8){
		assembledCurve[i / 2] = sf::Vector2f(m_cantorSet[i].position.x, m_cantorSet[i].position.y);
		assembledCurve[i / 2 + 1] = sf::Vector2f(m_cantorSet[i + 1].position.x, m_cantorSet[i + 1].position.y);
		assembledCurve[i / 2 + 2] = sf::Vector2f(m_cantorSet[i + 6].position.x, m_cantorSet[i + 6].position.y);
		assembledCurve[i / 2 + 3] = sf::Vector2f(m_cantorSet[i + 7].position.x, m_cantorSet[i + 7].position.y);
	}
	m_cantorSet = assembledCurve;
}

void Cantor::setColor(sf::Color color){
	for (int i = 0; i < m_cantorSet.getVertexCount(); i++){
		m_cantorSet[i].color = color;
	}
}

void Cantor::setIter(int iter){
	if (iter>m_iteration){
		for (; m_iteration != iter; m_iteration++){
			split();
		}
	}
	else{
		for (; m_iteration != iter; m_iteration--){
			assemble();
		}
	}
}

void Cantor::drawFractal(sf::RenderWindow& window){
	window.clear(sf::Color::White);
	setColor(sf::Color::Black);
	window.draw(m_cantorSet);
}

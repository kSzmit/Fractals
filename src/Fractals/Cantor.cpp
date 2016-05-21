#include "Cantor.hpp"


Cantor::Cantor(int sizeX, int sizeY){
	m_fractal = sf::VertexArray(sf::Quads, 4);
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_iteration = 0;
	m_fractal[0].position = sf::Vector2f(50, sizeY / 2 + 50);
	m_fractal[1].position = sf::Vector2f(50, sizeY / 2 - 50);
	m_fractal[2].position = sf::Vector2f(sizeX - 50, sizeY / 2 - 50);
	m_fractal[3].position = sf::Vector2f(sizeX - 50, sizeY / 2 + 50);
}

void Cantor::split(){
	int curveSize = m_fractal.getVertexCount();

	sf::VertexArray splitCurve(sf::Quads, curveSize * 2);
	for (int i = 0; i < curveSize - 1; i += 4){
		splitCurve[2 * i] = sf::Vector2f(m_fractal[i].position.x, m_fractal[i].position.y);
		splitCurve[2 * i + 1] = sf::Vector2f(m_fractal[i + 1].position.x, m_fractal[i + 1].position.y);
		splitCurve[2 * i + 2] = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 2].position.x) / 3, m_fractal[i + 1].position.y);
		splitCurve[2 * i + 3] = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 2].position.x) / 3, m_fractal[i].position.y);
		splitCurve[2 * i + 4] = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 2].position.x) * 2 / 3, m_fractal[i + 3].position.y);
		splitCurve[2 * i + 5] = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 2].position.x) * 2 / 3, m_fractal[i + 2].position.y);
		splitCurve[2 * i + 6] = sf::Vector2f(m_fractal[i + 2].position.x, m_fractal[i + 2].position.y);
		splitCurve[2 * i + 7] = sf::Vector2f(m_fractal[i + 3].position.x, m_fractal[i + 3].position.y);
	}
	m_fractal = splitCurve;
}

void Cantor::assemble(){
	int curveSize = m_fractal.getVertexCount();

	sf::VertexArray assembledCurve(sf::Quads, curveSize / 2);
	for (int i = 0; i < curveSize - 1; i += 8){
		assembledCurve[i / 2] = sf::Vector2f(m_fractal[i].position.x, m_fractal[i].position.y);
		assembledCurve[i / 2 + 1] = sf::Vector2f(m_fractal[i + 1].position.x, m_fractal[i + 1].position.y);
		assembledCurve[i / 2 + 2] = sf::Vector2f(m_fractal[i + 6].position.x, m_fractal[i + 6].position.y);
		assembledCurve[i / 2 + 3] = sf::Vector2f(m_fractal[i + 7].position.x, m_fractal[i + 7].position.y);
	}
	m_fractal = assembledCurve;
}

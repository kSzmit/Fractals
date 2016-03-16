#include "Koch.hpp"


Koch::Koch(){
}

Koch::Koch(int sizeX, int sizeY){
	m_fractal = sf::VertexArray(sf::LinesStrip, 4);
	m_iteration = 0;
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	int tmp = 1.4*(sizeX - sizeY);
	if (tmp < 400)
		tmp = 400;
	m_fractal[0].position = sf::Vector2f(sizeX - tmp / 2, sizeY * 7.5 / 10);
	m_fractal[1].position = sf::Vector2f(tmp / 2, sizeY * 7.5 / 10);
	m_fractal[2].position = apex(tmp / 2, sizeY * 7.5 / 10, sizeX - tmp / 2, sizeY * 7.5 / 10);
	m_fractal[3].position = sf::Vector2f(sizeX - tmp / 2, sizeY * 7.5 / 10);
}

void Koch::assemble(){
	int sizeCurve = m_fractal.getVertexCount();
	sf::VertexArray assembledCurve(sf::LinesStrip, (sizeCurve + 3) / 4);

	for (int i = 0; i < sizeCurve; i += 4){
		assembledCurve[i / 4] = sf::Vector2f(m_fractal[i].position.x, m_fractal[i].position.y);
	}
	m_fractal = assembledCurve;
}

void Koch::split(){
	int sizeCurve = m_fractal.getVertexCount();

	sf::VertexArray splitCurve(sf::LinesStrip, (sizeCurve - 1) * 3 + sizeCurve);
	for (int i = 0; i < sizeCurve - 1; i++){
		splitCurve[i * 4].position = sf::Vector2f(m_fractal[i].position.x, m_fractal[i].position.y);
		splitCurve[i * 4 + 1].position = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 1].position.x) / 3,
			m_fractal[i].position.y - (m_fractal[i].position.y - m_fractal[i + 1].position.y) / 3);
		splitCurve[i * 4 + 3].position = sf::Vector2f(m_fractal[i].position.x - (m_fractal[i].position.x - m_fractal[i + 1].position.x) * 2 / 3,
			m_fractal[i].position.y - (m_fractal[i].position.y - m_fractal[i + 1].position.y) * 2 / 3);
		splitCurve[i * 4 + 2].position = apex(splitCurve[i * 4 + 1].position.x, splitCurve[i * 4 + 1].position.y,
			splitCurve[i * 4 + 3].position.x, splitCurve[i * 4 + 3].position.y);
		splitCurve[i * 4 + 4].position = sf::Vector2f(m_fractal[i + 1].position.x, m_fractal[i + 1].position.y);
	}
	m_fractal = splitCurve;
}


sf::Vector2f Koch::apex(float x1, float y1, float x2, float y2){
	return sf::Vector2f((x1 + x2 - sqrt(3)*(y1 - y2)) / 2, (y1 + y2 + sqrt(3)*(x1 - x2)) / 2);
}
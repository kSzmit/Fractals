#include "TerrainTexture.hpp"
#include <iostream>

TerrainTexture::TerrainTexture(int size, float roughness, int windowWidth, int windowHeight){
	m_size = int(pow(2, size) + 1);
	m_max = m_size - 1;
	m_heightMap = new float[m_size*m_size];
	m_waterLevel = m_size*0.15;
	m_windowHeight = windowHeight;
	m_windowWidth = windowWidth;

	generate(roughness);
}

float TerrainTexture::getMapPoint(int x, int y){
	if (x < 0 || x > m_max || y < 0 || y > m_max)
		return -1;
	return m_heightMap[x + m_size * y];
}

void TerrainTexture::setMapPoint(int x, int y, float val) {
	m_heightMap[x + m_size * y] = val;
}

float TerrainTexture::random(float min, float max){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	float ret = min + (max - min)*dist(mt);
	return min + (max - min)*dist(mt);
}

void TerrainTexture::generate(float roughness) {
	m_roughness = roughness;
	setMapPoint(0, 0, m_max);
	setMapPoint(m_max, 0, m_max / 2);
	setMapPoint(m_max, m_max, 0);
	setMapPoint(0, m_max, m_max / 2);
	divide(m_max);
}

void TerrainTexture::divide(int size) {
	int x, y, half = size / 2;
	if (half < 1) 
		return;
	float scale = m_roughness * size;
	if (size < m_size / 8)
		scale *= 0.5;

	for (y = half; y < m_max; y += size) {
		for (x = half; x < m_max; x += size) {
			square(x, y, half, random(-scale, scale));
		}
	}
	for (y = 0; y <= m_max; y += half) {
		for (x = (y + half) % size; x <= m_max; x += size) {
			diamond(x, y, half, random(-scale, scale));
		}
	}
	divide(size / 2);
}

float TerrainTexture::averageOfFour(float values[]) {
	int valid = 0;
	float total = 0;
	for (int i = 0; i < 4; i++) {
		if (values[i] != -1) {
			valid++;
			total += values[i];
		}
	}
	if (valid != 0)
		return total / valid;
	else
		return 0;
}

void TerrainTexture::square(int x, int y, int size, float offset) {
	float around[4] = {
		getMapPoint(x - size, y - size), getMapPoint(x + size, y - size),
		getMapPoint(x + size, y + size), getMapPoint(x - size, y + size)};
	float average = averageOfFour(around);
	setMapPoint(x, y, average + offset);
}

void TerrainTexture::diamond(int x, int y, int size, float offset) {
	float around[4] = {
		getMapPoint(x, y - size), getMapPoint(x + size, y),
		getMapPoint(x, y + size), getMapPoint(x - size, y)};
	float average = averageOfFour(around);
	setMapPoint(x, y, average + offset);
}

sf::Vector2f TerrainTexture::isometricProject(float x, float y, float z) {
	sf::Vector2f point = sf::Vector2f(0.5 * (m_size + x - y), 0.5 * (x + y));

	float x0 = m_windowWidth * 0.5;
	float y0 = m_windowHeight * 0.4;
	float newZ = m_size * 0.5 - z + point.y * 0.75;
	float newX = (point.x - m_size * 0.5) * 6;
	float newY = (m_size - point.y) * 0.005 + 1;

	return sf::Vector2f(x0 + newX / newY, y0 + newZ / newY);
}

sf::Color TerrainTexture::genColor(float x, float y, float slope) {
	if (y == m_max || x == m_max)
		return sf::Color(0, 0, 0, 255);
	int brightness = slope * 50 + 128;
	if (brightness < 0)
		brightness = 0;
	if (brightness>255)
		brightness = 255;
	return sf::Color(brightness / 1.7, brightness / 2.2, brightness / 3.5, 255);
}

void TerrainTexture::draw(sf::RenderWindow& window){
	window.clear(sf::Color(233, 233, 255, 255));
	sf::RectangleShape line(sf::Vector2f(1, 1));
	line.setRotation(90);

	sf::Vector2f top, bottom, water;
	sf::Color terrainColor, waterColor;

	for (int y = 0; y < m_size; y++) {
		for (int x = 0; x < m_size; x++) {
			float val = getMapPoint(x, y);

			top = isometricProject(x, y, val);
			bottom = isometricProject(x + 1, y, 0);
			water = isometricProject(x, y, m_waterLevel);

			terrainColor = genColor(x, y, getMapPoint(x + 1, y) - val);
			waterColor = sf::Color(100, 204, 255, 100);

			line.setPosition(top);
			line.setSize(sf::Vector2f(sqrt((top.y - bottom.y)*(top.y - bottom.y)), sqrt((top.x - bottom.x)*(top.x - bottom.x))));
			line.setFillColor(terrainColor);
			if (val > 0)
				window.draw(line);
			if ((x != m_max && y != m_max)){
				line.setPosition(water);
				line.setSize(sf::Vector2f(sqrt((water.y - bottom.y)*(water.y - bottom.y)), sqrt((water.x - bottom.x)*(water.x - bottom.x))));
				line.setFillColor(waterColor);
				window.draw(line);
			}
			else if (m_waterLevel > val){
				line.setPosition(water);
				if (val < 0)
					top.y = bottom.y;
				line.setSize(sf::Vector2f(sqrt((top.y - water.y)*(top.y - water.y)), sqrt((bottom.x - water.x)*(bottom.x - water.x))));
				waterColor = sf::Color(100, 100, 255, 100);
				line.setFillColor(waterColor);
				window.draw(line);
			}
		}
	}
}
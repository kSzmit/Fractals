#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>


class TerrainTexture
{
	int m_size, m_max;
	float m_roughness;
	float m_waterLevel;
	float* m_heightMap;
	int m_windowWidth, m_windowHeight;

	float getMapPoint(int x, int y);

	void setMapPoint(int x, int y, float val);

	void divide(int size);

	float averageOfFour(float table[]);

	float random(float min, float max);

	void square(int x, int y, int size, float offset);

	void diamond(int x, int y, int size, float offset);

	sf::Vector2f isometricProject(float x, float y, float z);

	sf::Color genColor(float x, float y, float slope);
public:
	TerrainTexture(int size, float roughness, int windowWidth, int windowHeight);

	void generate(float roughness);

	void draw(sf::RenderWindow& window);
};


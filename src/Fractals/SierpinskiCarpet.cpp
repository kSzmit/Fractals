#include "SierpinskiCarpet.hpp"
#include <algorithm>
#include <cmath>

SierpinskiCarpet::SierpinskiCarpet(int sizeX, int sizeY){
	m_size = pow(3, floor((log(std::min(sizeX, sizeY)) / log(3))));
	m_scale = 1;
	m_iter = 0;
}


int SierpinskiCarpet::getSize(){
	return m_size;
}

int SierpinskiCarpet::getIter(){
	return m_iter;
}

int SierpinskiCarpet::getMaxIter(){
	return ((log(m_size) / log(3)) + 0.5);
}

void SierpinskiCarpet::setIter(int iter){
	if (iter <= getMaxIter() && iter >= 0)
		m_scale = pow(3, iter);
}

bool SierpinskiCarpet::belongToSet(int x, int y){
	while (x > 0 && y > 0){
		if (x % 3 == 1 && y % 3 == 1){
			return false;	
		}
		x /= 3;
		y /= 3;
	}
	return true;
}

void SierpinskiCarpet::drawFractal(sf::RenderWindow& window){
	sf::Uint8 *pixels = new sf::Uint8[m_size * m_size * 4];

	for (int x = 0; x < m_scale; x++){
		for (int y = 0; y < m_scale; y++){
			if (belongToSet(x, y))
			{
				for (int k = 0; k < m_size / m_scale; k++){
					for (int m = 0; m < m_size / m_scale; m++){
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4] = 0;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 1] = 0;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 2] = 0;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 3] = 255;
					}
				}
			}
			else{
				for (int k = 0; k < m_size / m_scale; k++){
					for (int m = 0; m < m_size / m_scale; m++){
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4] = 255;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 1] = 255;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 2] = 255;
						pixels[((m_size / m_scale*x + k) + (m_size / m_scale*y + m) * m_size) * 4 + 3] = 255;
					}
				}
			}
		}
	}
	sf::Texture texture;
	sf::Image image;

	image.create(m_size, m_size, pixels);
	delete[] pixels;
	texture.loadFromImage(image);
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((window.getSize().x - getSize()) / 2, (window.getSize().y - getSize()) / 2));
	window.clear(sf::Color::White);
	window.draw(sprite);
}

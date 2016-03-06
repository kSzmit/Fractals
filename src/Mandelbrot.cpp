#include "Mandelbrot.hpp"
#include <tbb\tbb.h>

Mandelbrot::Mandelbrot(int sizeX, int sizeY){
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_maxX = 0.7*sizeX / sizeY;
	m_minX = -2.2*sizeX / sizeY;
	m_maxY = 1.45;
	m_minY = -1.45;
	m_iteration = 55;
	m_paletteSize = 2048;
	createPalette();
	m_colorDensity = 2;
}

void Mandelbrot::createPalette(){
	sf::Image gradient;
	if (!gradient.loadFromFile("gradientM.png"))
		return;
	sf::Vector3f tmpPalette[16];
	for (int i = 0; i < 16; i++){
		tmpPalette[i] = sf::Vector3f(gradient.getPixel((gradient.getSize().x)*i / 15, (gradient.getSize().y) / 2).r,
			gradient.getPixel((gradient.getSize().x)*i / 15, (gradient.getSize().y) / 2).g, 
			gradient.getPixel((gradient.getSize().x)*i / 15, (gradient.getSize().y) / 2).b);
	}
	for (int i = 0; i < 16; i++){
		for (int j = 0; j < 128; j++){
			m_palette[i * 128 + j] = sf::Vector3f(lerp(tmpPalette[i].x, tmpPalette[(i + 1) % 16].x, (float)j / 128.f),
				lerp(tmpPalette[i].y, tmpPalette[(i + 1) % 16].y, (float)j / 128.f),
				lerp(tmpPalette[i].z, tmpPalette[(i + 1) % 16].z, (float)j / 128.f));
		}
	}

}

sf::Vector3f Mandelbrot::calcColor(int coordX, int coordY){
	long double step_x = (m_maxX - m_minX) / (long double)m_sizeX;
	long double step_y = (m_maxY - m_minY) / (long double)m_sizeY;
	long double x0 = m_minX + coordX*step_x;
	long double y0 = m_maxY - coordY*step_y;
	long double x = 0;
	long double y = 0;
	long double xTemp = 0;
	long double yTemp = 0;
	int i = 0;
	while (x*x + y*y <2000 && i < m_iteration)
	{
		xTemp = x*x - y*y + x0;
		yTemp = 2 * x*y + y0;
		if (x == xTemp  &&  y == yTemp){
			i = m_iteration;
			break;
		}
		y = yTemp;
		x = xTemp;
		i++;
	}

	if (i < m_iteration)
	{

		float log_zn = log(x*x + y*y) / 2;
		float nu = log(log_zn/log(2)) / log(2);
		float colorScale = (i + 1 - nu)*m_paletteSize/m_iteration;
		//colorScale = i*m_paletteSize / m_iteration;
		float fractionalPart = colorScale - (int)colorScale;
		int intPart = (int)colorScale;

		return sf::Vector3f(lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].x, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].x, fractionalPart),
							lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].y, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].y, fractionalPart),
							lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].z, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].z, fractionalPart));
	}
	else
	{
		return sf::Vector3f(2000,2000,2000);
	}
}

void Mandelbrot::drawFractal(sf::RenderWindow& window){

	sf::Uint8 *pixels = new sf::Uint8[m_sizeX * m_sizeY * 4];


	tbb::parallel_for(0, m_sizeX, 1, [=](int x){
		for (int y = 0; y < m_sizeY; y++){
			sf::Vector3f color = calcColor(x, y);
			if (color.x == 2000)
			{
				pixels[(x + y * m_sizeX) * 4] = 255; // R
				pixels[(x + y * m_sizeX) * 4 + 1] = 255; // G
				pixels[(x + y * m_sizeX) * 4 + 2] = 255; // B
				pixels[(x + y * m_sizeX) * 4 + 3] = 0; // A
			}
			else
			{
				pixels[(x + y * m_sizeX) * 4] = color.x; //palette[color][0];
				pixels[(x + y * m_sizeX) * 4 + 1] = color.y; //palette[color][1];
				pixels[(x + y * m_sizeX) * 4 + 2] = color.z; //palette[color][2];
				pixels[(x + y * m_sizeX) * 4 + 3] = 255;
			}

		}
	});

	sf::Image image;
	sf::Texture texture;

	image.create(m_sizeX, m_sizeY, pixels);
	delete[] pixels;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	window.clear();
	window.draw(sprite);
}

float Mandelbrot::lerp(float x, float y, float t){
	return (1 - t)*x + t*y;
}

void Mandelbrot::setIter(int iter){
	m_iteration = iter;
}

void Mandelbrot::handleEvents(sf::Event event){

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Add 
		|| (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta > 0)){
		m_minX += (m_maxX - m_minX)*0.15;
		m_maxX -= (m_maxX - m_minX)*0.15;
		m_minY += (m_maxY - m_minY)*0.15;
		m_maxY -= (m_maxY - m_minY)*0.15;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Subtract
		|| (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta < 0)){
		m_minX -= (m_maxX - m_minX)*0.15;
		m_maxX += (m_maxX - m_minX)*0.15;
		m_minY -= (m_maxY - m_minY)*0.15;
		m_maxY += (m_maxY - m_minY)*0.15;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
		m_minX -= (m_maxX - m_minX)*0.1;
		m_maxX -= (m_maxX - m_minX)*0.1;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
		m_minX += (m_maxX - m_minX)*0.1;
		m_maxX += (m_maxX - m_minX)*0.1;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
		m_minY += (m_maxY - m_minY)*0.1;
		m_maxY += (m_maxY - m_minY)*0.1;
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
		m_minY -= (m_maxY - m_minY)*0.1;
		m_maxY -= (m_maxY - m_minY)*0.1;
	}
}
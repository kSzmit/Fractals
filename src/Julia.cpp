#include "Julia.hpp"
#include <tbb\tbb.h>


Julia::Julia(int sizeX, int sizeY){
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_maxX = 0.7*sizeX / sizeY;
	m_minX = -2.2*sizeX / sizeY;
	m_maxY = 1.45;
	m_minY = -1.45;
	m_iteration = 500;
	m_paletteSize = 2048;
	m_cY = 0.11;
	m_cX = -0.75;
	m_colorDensity = 2;
	createPalette("gradientJ.png");
}

sf::Vector3f Julia::calcColor(int coord_X, int coord_Y){
	long double step_x = (m_maxX - m_minX) / (long double)m_sizeX;
	long double step_y = (m_maxY - m_minY) / (long double)m_sizeY;
	long double Zx = m_minX + coord_X*step_x;
	long double Zy = m_maxY - coord_Y*step_y;
	long double Zx2 = Zx*Zx;
	long double Zy2 = Zy*Zy;
	int i = 0;
	// SLOWER BUT BETTER COLORING
	//double smoothcolor = exp(-sqrt(Zx2 + Zy2));
	while (Zx2 + Zy2 < 100 && i < m_iteration)
	{
		Zy = 2 * Zx*Zy + m_cY;
		Zx = Zx2 - Zy2 + m_cX;
		Zx2 = Zx*Zx;
		Zy2 = Zy*Zy;
		i += 1;
		// SLOWER BUT BETTER COLORING
		//smoothcolor += exp(-sqrt(Zx2 + Zy2));
	}
	// FASTER
	
	if (i < m_iteration){
		float Zn = log2(sqrt(Zx2 + Zy2));
		int nu = log2(Zn);
		float colorScale = (i + 1 - nu)*m_paletteSize / m_iteration;

		float fractionalPart = colorScale - (int)colorScale;
		int intPart = (int)colorScale;

		return sf::Vector3f(lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].x, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].x, fractionalPart),
							lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].y, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].y, fractionalPart),
							lerp(m_palette[(intPart*m_colorDensity) % m_paletteSize].z, m_palette[((intPart + 1)*m_colorDensity) % m_paletteSize].z, fractionalPart));
	}
	else{
		return sf::Vector3f(2000, 2000, 2000);
	}
	// SLOWER BUT BETTER COLORING
	/*
	if (i < m_iteration){
		float colorScale = smoothcolor*m_paletteSize / m_iteration;

		float fractionalPart = colorScale - (int)colorScale;
		int intPart = (int)colorScale;

		return sf::Vector3f(lerp(palette[(intPart*m_colorDensity) % m_paletteSize].x, palette[((intPart + 1)*m_colorDensity) % m_paletteSize].x, fractionalPart),
			lerp(palette[(intPart*m_colorDensity) % m_paletteSize].y, palette[((intPart + 1)*m_colorDensity) % m_paletteSize].y, fractionalPart),
			lerp(palette[(intPart*m_colorDensity) % m_paletteSize].z, palette[((intPart + 1)*m_colorDensity) % m_paletteSize].z, fractionalPart));
	}
	else{
		return sf::Vector3f(2000, 2000, 2000);
	}
	*/
}


void Julia::setC(sf::Vector2f coord){
	m_cX = coord.x;
	m_cY = coord.y;
}

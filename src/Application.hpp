#pragma once
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include "Fractals/Mandelbrot.hpp"
#include "Fractals/Julia.hpp"
#include "Fractals/SierpinskiCarpet.hpp"
#include "Fractals/Koch.hpp"
#include "Fractals/Cantor.hpp"
#include "Fractals/Triangle.hpp"
#include "Fractals/Fern.hpp"
#include "Interface/Interface.hpp"
#include "Fractals/TerrainTexture.hpp"

class Application{
	sfg::SFGUI m_sfgui;

	int m_fractalType;
	bool drawFrame;
	
	sf::RenderWindow& m_window;
	sf::Clock& m_clock;

	Mandelbrot m_mandelbrot;
	Julia m_julia;
	SierpinskiCarpet m_carpet;
	Koch m_koch;
	Cantor m_cantor;
	Triangle m_triangle;
	Fern m_fern;
	Interface m_gui;
	TerrainTexture m_terrain;

	enum fraq {
		kCantor,
		kKoch,
		kSierpinskiCarpet,
		kTriangle,
		kFern,
		kMandel,
		kJuli,
		kTerrain
	};
public:
	Application(sf::RenderWindow& window, sf::Clock& clock);
	
	void handleEvents();
	
	void draw();

	sf::RenderWindow& getWindow();
};


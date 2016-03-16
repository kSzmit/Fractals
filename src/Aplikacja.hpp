#pragma once
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include "Mandelbrot.hpp"
#include "Julia.hpp"
#include "SierpinskiCarpet.hpp"
#include "Koch.hpp"
#include "Cantor.hpp"
#include "Triangle.hpp"
#include "Fern.hpp"
#include "Interface.hpp"

class Aplikacja{
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


	enum fraq {
		kCantor,
		kKoch,
		kSierpinskiCarpet,
		kTriangle,
		kFern,
		kMandel,
		kJuli
	};
public:
	Aplikacja();
	Aplikacja(sf::RenderWindow& window, sf::Clock& clock);

	void handleEvents();
	void draw();
};


#include "Aplikacja.hpp"

Aplikacja::Aplikacja(sf::RenderWindow& window, sf::Clock& clock) :
m_window(window),
m_clock(clock),
m_fern(window.getSize().x, window.getSize().y),
m_julia(window.getSize().x, window.getSize().y),
m_mandelbrot(window.getSize().x, window.getSize().y),
m_carpet(window.getSize().x, window.getSize().y),
m_koch(window.getSize().x, window.getSize().y),
m_cantor(window.getSize().x, window.getSize().y),
m_triangle(window.getSize().x, window.getSize().y),
m_gui(window, m_fractalType)
{
	drawFrame = true;
	m_fractalType = kJuli;
}

void Aplikacja::draw(){
	m_gui.update(m_clock);
	if (drawFrame && m_fractalType != kFern && m_fractalType != kTriangle){
		switch (m_fractalType){
		case kMandel:
			m_mandelbrot.setIter(m_gui.mandelGetIter());
			m_mandelbrot.drawFractal(m_window);
			break;
		case kJuli:
			m_julia.setIter(m_gui.juliGetIter());
			m_julia.setC(m_gui.juliGetC());
			m_julia.drawFractal(m_window);
			break;
		case kSierpinskiCarpet:
			m_carpet.setIter(m_gui.carpetGetIter());
			m_carpet.drawFractal(m_window);
			break;
		case kKoch:
			m_koch.setIter(m_gui.kochGetIter());
			m_koch.drawFractal(m_window);
			break;
		case kCantor:
			m_cantor.setIter(m_gui.cantorGetIter());
			m_cantor.drawFractal(m_window);
			break;
		}
		drawFrame = false;
	}
	else {
		switch (m_fractalType){
		case kTriangle:
			m_triangle.drawFractal(m_window);
			break;
		case kFern:	
			m_fern.drawFractal(m_window);
			break;
		}
	}
	m_sfgui.Display(m_window);
}

void Aplikacja::handleEvents(){
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed
			|| event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::KeyReleased 
			|| event.type == sf::Event::MouseWheelMoved){
			drawFrame = true;
		}
		m_gui.handleEvent(event);
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
			m_window.close();
		}
		if (event.type == sf::Event::Closed){
			m_window.close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R){
			switch (m_fractalType){
			case kMandel:
				m_window.clear();
				m_mandelbrot = Mandelbrot(m_window.getSize().x, m_window.getSize().y);
				break;
			case kJuli:
				m_window.clear();
				m_julia = Julia(m_window.getSize().x, m_window.getSize().y);
				break;
			case kSierpinskiCarpet:
				m_window.clear();
				m_carpet = SierpinskiCarpet(m_window.getSize().x, m_window.getSize().y);
				break;
			case kKoch:
				m_window.clear();
				m_koch = Koch(m_window.getSize().x, m_window.getSize().y);
				break;
			case kCantor:
				m_window.clear();
				m_cantor = Cantor(m_window.getSize().x, m_window.getSize().y);
				break;
			case kTriangle:
				m_window.clear();
				m_cantor = Cantor(m_window.getSize().x, m_window.getSize().y);
				break;
			case kFern:
				m_window.clear();
				Fern m_fern(m_window.getSize().x, m_window.getSize().y);
				break;
			}
		}
		switch (m_fractalType){
		case kMandel:
			m_mandelbrot.handleEvents(event);
			break;
		case kJuli:
			m_julia.handleEvents(event);
			break;
		}
	}
}
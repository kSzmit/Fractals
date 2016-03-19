#include "Aplikacja.hpp"

Aplikacja::Aplikacja(sf::RenderWindow& window, sf::Clock& clock) :
m_sfgui(),
m_window(window),
m_clock(clock),
m_fern(window.getSize().x, window.getSize().y),
m_julia(window),
m_mandelbrot(window),
m_carpet(window.getSize().x, window.getSize().y),
m_koch(window.getSize().x, window.getSize().y),
m_cantor(window.getSize().x, window.getSize().y),
m_triangle(window.getSize().x, window.getSize().y),
m_fractalType(kJuli),
drawFrame(true),
m_gui(this, m_fractalType)
{
}

void Aplikacja::draw(){
	m_gui.update(m_clock);

	if (m_fractalType != m_gui.getFractalType()){
		if (m_fractalType == kFern){
			m_fern.clearIter();
		}
		if (m_fractalType == kTriangle){
			m_triangle.clearIter();
		}
		m_fractalType = m_gui.getFractalType();
	}

	m_fractalType = m_gui.getFractalType();
	if (drawFrame && m_fractalType != kFern && m_fractalType != kTriangle){
		switch (m_fractalType){
		case kMandel:
			m_gui.mandelbrotUpdate(m_mandelbrot.getX(), m_mandelbrot.getY(), m_mandelbrot.getZoomPower());
			m_mandelbrot.setIter(m_gui.mandelGetIter());
			m_mandelbrot.drawFractal(m_window);
			break;
		case kJuli:
			m_gui.juliaUpdate(m_julia.getX(), m_julia.getY(), m_julia.getZoomPower());
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
			m_gui.triangleUpdate(m_triangle.getIter());
			m_triangle.drawFractal(m_window);
			break;
		case kFern:	
			m_gui.fernUpdate(m_fern.getIter());
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

sf::RenderWindow& Aplikacja::getWindow(){
	return m_window;
}
#include "Interface.hpp"
#include "Aplikacja.hpp"

Interface::Interface(){
}

Interface::Interface(Aplikacja* appPtr, int fractalType) : m_fractalType(fractalType), m_appPtr(appPtr){
	m_kochWindow = IterWindow(0, 10, 1);
	int carpetMaxIter = floor((log(std::min(appPtr->getWindow().getSize().x, appPtr->getWindow().getSize().y)) / log(3)));
	m_carpetWindow = IterWindow(0, carpetMaxIter, 1);
	m_cantorWindow = IterWindow(0, 10, 1);
	m_mandelWindow = IterWindowMandelbrot(5, 1000, 2, this);
	m_mandelWindow.setIter(50);
	m_juliWindow = JuliaIterWindow(5, 1000, 10, this);
	m_juliWindow.setIter(500);
	m_juliWindow.show(true);
	m_fernWindow = IterCounterWindow();
	m_triangleWindow = IterCounterWindow();

	m_switchWindow = TopMenu(this);

	m_desktop.Add(m_carpetWindow.getWindow());
	m_desktop.Add(m_mandelWindow.getWindow());
	m_desktop.Add(m_juliWindow.getWindow());
	m_desktop.Add(m_cantorWindow.getWindow());
	m_desktop.Add(m_kochWindow.getWindow());
	m_desktop.Add(m_fernWindow.getWindow());
	m_desktop.Add(m_triangleWindow.getWindow());
	m_desktop.Add(m_switchWindow.getWindow());
	m_desktop.Update(0.0f);
}

void Interface::showHideWindows(int show){
	switch (m_fractalType){
	case kCantor:
		m_cantorWindow.show(false);
		break;
	case kKoch:
		m_kochWindow.show(false);
		break;
	case kJuli:
		m_juliWindow.show(false);
		break;
	case kMandel:
		m_mandelWindow.show(false);
		break;
	case kSierpinskiCarpet:
		m_carpetWindow.show(false);
		break;
	case kFern:
		m_fernWindow.show(false);
		break;
	case kTriangle:
		m_triangleWindow.show(false);
		break;
	}

	switch (show){
	case kCantor:
		m_cantorWindow.show(true);
		break;
	case kKoch:
		m_kochWindow.show(true);
		break;
	case kJuli:
		m_juliWindow.show(true);
		break;
	case kMandel:
		m_mandelWindow.show(true);
		break;
	case kSierpinskiCarpet:
		m_carpetWindow.show(true);
		break;
	case kFern:
		m_fernWindow.show(true);
		break;
	case kTriangle:
		m_triangleWindow.show(true);
		break;
	}
	setFractalType(show);
	clearWindow(sf::Color::White);
}

void Interface::update(sf::Clock& clock){
	if (clock.getElapsedTime().asMicroseconds() >= 5000) {
		// Update() takes the elapsed time in seconds.
		auto microseconds = clock.getElapsedTime().asMicroseconds();
		m_desktop.Update(static_cast<float>(microseconds) / 1000000.f);

		clock.restart();
	}
}

void Interface::handleEvent(sf::Event event){
	m_desktop.HandleEvent(event);
}

int Interface::kochGetIter(){
	return m_kochWindow.getIter();
}

int Interface::cantorGetIter(){
	return m_cantorWindow.getIter();
}

int Interface::juliGetIter(){
	return m_juliWindow.getIter();
}

int Interface::mandelGetIter(){
	return m_mandelWindow.getIter();
}

int Interface::carpetGetIter(){
	return m_carpetWindow.getIter();
}

sf::Vector2f Interface::juliGetC(){
	return m_juliWindow.GetC();
}

void Interface::fernUpdate(int iter){
	m_fernWindow.setIter(iter);
}

void Interface::triangleUpdate(int iter){
	m_triangleWindow.setIter(iter);
}

void Interface::mandelbrotUpdate(long double x, long double y, int zoomPower){
	m_mandelWindow.update(x, y, zoomPower);
}

void Interface::juliaUpdate(long double x, long double y, int zoomPower){
	m_juliWindow.update(x, y, zoomPower);
}

void Interface::setFractalType(int num){
	m_fractalType = num;
}

void Interface::clearWindow(sf::Color color){
	m_appPtr->getWindow().clear(color);
}

int Interface::getFractalType(){
	return m_fractalType;
}

sf::RenderWindow& Interface::getInterfaceWindow(){
	return m_appPtr->getWindow();
}
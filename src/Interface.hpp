#pragma once
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include "IterWindow.hpp"
#include "JuliaIterWindow.hpp"
#include "SwitchWindow.hpp"
#include "IterCounterWindow.hpp"

class Interface
{
	sf::RenderWindow& m_window;

	sfg::Desktop m_desktop;
	
	SwitchWindow m_switchWindow;

	IterWindow m_kochWindow;
	IterWindow m_cantorWindow;
	IterWindow m_mandelWindow;
	IterWindow m_carpetWindow;
	JuliaIterWindow m_juliWindow;
	IterCounterWindow m_fernWindow;
	IterCounterWindow m_triangleWindow;

	int m_fractalType;

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
	Interface();
	Interface(sf::RenderWindow& window, int fractalType);

	void clearWindow(sf::Color color);

	void setFractalType(int num);
	int getFractalType();

	void update(sf::Clock& clock);
	void handleEvent(sf::Event event);
	void showHideWindows(int show);

	int kochGetIter();
	int cantorGetIter();
	int juliGetIter();
	int mandelGetIter();
	int carpetGetIter();
	void fernSetIter(int iter);
	void triangleSetIter(int iter);
	sf::Vector2f juliGetC();

};


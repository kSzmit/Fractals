#pragma once
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include "Windows/IterWindow.hpp"
#include "Windows/JuliaIterWindow.hpp"
#include "TopMenu.hpp"
#include "Windows/IterCounterWindow.hpp"
#include "Windows/IterWindowMandelbrot.hpp"
#include "Windows/TerrainWindow.hpp"

class Application;

class Interface
{
	Application* m_appPtr;

	sfg::Desktop m_desktop;
	
	TopMenu m_switchWindow;

	IterWindow m_kochWindow;
	IterWindow m_cantorWindow;
	IterWindowMandelbrot m_mandelWindow;
	IterWindow m_carpetWindow;
	JuliaIterWindow m_juliWindow;
	IterCounterWindow m_fernWindow;
	IterCounterWindow m_triangleWindow;
	TerrainWindow m_terrainWindow;

	int m_fractalType;

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

	Interface(Application* appPtr, int fractalType);

	void clearWindow(sf::Color color);

	void setFractalType(int num);

	int getFractalType();

	sf::RenderWindow& getInterfaceWindow();

	void update(sf::Clock& clock);

	void handleEvent(sf::Event event);

	void showHideWindows(int show);

	int kochGetIter();

	int cantorGetIter();

	int mandelGetIter();

	int juliGetIter();

	sf::Vector2f juliGetC();

	int carpetGetIter();

	bool terrainGenerate();

	void fernUpdate(int iter);

	void triangleUpdate(int iter);

	void mandelbrotUpdate(long double x, long double y, int zoomPower);

	void juliaUpdate(long double x, long double y, int zoomPower);

};


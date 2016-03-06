#pragma once
#include <SFML/Graphics.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Interface
{
	int& m_fractalType;
	sf::RenderWindow& m_window;

	sfg::Desktop m_desktop;
	
	// ----------------------------------------------

	sfg::Button::Ptr m_switchButtonKantor;
	sfg::Button::Ptr m_switchButtonKoch;
	sfg::Button::Ptr m_switchButtonCarpet;
	sfg::Button::Ptr m_switchButtonTriangle;
	sfg::Button::Ptr m_switchButtonFern;
	sfg::Button::Ptr m_switchButtonMandel;
	sfg::Button::Ptr m_switchButtonJuli;
	sfg::Box::Ptr m_switchBoxFractal;
	sfg::Window::Ptr m_switchWindowFractal;

	//-----------------------------------------------

	sfg::SpinButton::Ptr m_kochButtonIter;
	sfg::Box::Ptr m_kochBox;
	sfg::Window::Ptr m_kochWindow;
	sfg::Label::Ptr m_kochLabelIter;

	//-----------------------------------------------

	sfg::SpinButton::Ptr m_cantorButtonIter;
	sfg::Box::Ptr m_cantorBox;
	sfg::Window::Ptr m_cantorWindow;
	sfg::Label::Ptr m_cantorLabelIter;

	//-----------------------------------------------

	sfg::SpinButton::Ptr m_juliButtonCx;
	sfg::SpinButton::Ptr m_juliButtonCy;
	sfg::SpinButton::Ptr m_juliButtonIter;
	sfg::Label::Ptr m_juliLabelCx;
	sfg::Label::Ptr m_juliLabelCy;
	sfg::Label::Ptr m_juliLabelIter;
	sfg::Box::Ptr m_juliBox;
	sfg::Window::Ptr m_juliWindow;

	//-----------------------------------------------
	
	sfg::SpinButton::Ptr m_mandelButtonIter;
	sfg::Box::Ptr m_mandelBox;
	sfg::Window::Ptr m_mandelWindow;
	sfg::Label::Ptr m_mandelLabelIter;

	//-----------------------------------------------

	sfg::SpinButton::Ptr m_carpetButtonIter;
	sfg::Box::Ptr m_carpetBox;
	sfg::Window::Ptr m_carpetWindow;
	sfg::Label::Ptr m_carpetLabelIter;

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
	Interface(sf::RenderWindow& okno, int& rodzajFraktala);

	void update(sf::Clock& clock);
	void handleEvent(sf::Event event);
	void buttonSwitchClick(int switchTo);
	void showHideWindows(int show);
	int kochGetIter();
	int cantorGetIter();
	int juliGetIter();
	int mandelGetIter();
	int carpetGetIter();
	sf::Vector2f juliGetC();

};


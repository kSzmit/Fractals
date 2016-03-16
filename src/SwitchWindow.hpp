#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Interface;

class SwitchWindow
{
	sfg::Button::Ptr m_buttonKantor;
	sfg::Button::Ptr m_buttonKoch;
	sfg::Button::Ptr m_buttonCarpet;
	sfg::Button::Ptr m_buttonTriangle;
	sfg::Button::Ptr m_buttonFern;
	sfg::Button::Ptr m_buttonMandel;
	sfg::Button::Ptr m_buttonJuli;
	sfg::Box::Ptr m_boxFractal;
	sfg::Window::Ptr m_windowFractal;

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
	SwitchWindow();
	SwitchWindow(Interface* interface);
	void buttonSwitchClick(int switchTo, Interface* interface);
	sfg::Window::Ptr getWindow();
};


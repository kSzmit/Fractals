#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <iomanip>
#include <ctime>

class Interface;

class TopMenu
{
	sfg::Button::Ptr m_buttonKantor;
	sfg::Button::Ptr m_buttonKoch;
	sfg::Button::Ptr m_buttonCarpet;
	sfg::Button::Ptr m_buttonTriangle;
	sfg::Button::Ptr m_buttonFern;
	sfg::Button::Ptr m_buttonMandel;
	sfg::Button::Ptr m_buttonJuli;

	sfg::Button::Ptr m_buttonScreenshot;

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
	TopMenu();
	TopMenu(Interface* interface);
	void buttonSwitchClick(int switchTo, Interface* interface);
	void buttonScreenshotClick(Interface* interface);
	sfg::Window::Ptr getWindow();
};


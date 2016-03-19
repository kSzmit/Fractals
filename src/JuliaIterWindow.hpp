#pragma once
#include "IterWindowMandelbrot.hpp"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class Interface;

class JuliaIterWindow :
	public IterWindowMandelbrot
{
	sfg::SpinButton::Ptr m_buttonCx;
	sfg::SpinButton::Ptr m_buttonCy;
	sfg::Label::Ptr m_labelCx;
	sfg::Label::Ptr m_labelCy;

public:
	JuliaIterWindow();
	JuliaIterWindow(int min, int max, int step, Interface* interface);
	sf::Vector2f GetC();
};


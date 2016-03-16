#pragma once
#include "IterWindow.hpp"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class JuliaIterWindow :
	public IterWindow
{
	sfg::SpinButton::Ptr m_buttonCx;
	sfg::SpinButton::Ptr m_buttonCy;
	sfg::Label::Ptr m_labelCx;
	sfg::Label::Ptr m_labelCy;

public:
	JuliaIterWindow();
	JuliaIterWindow(int min, int max, int step);
	sf::Vector2f GetC();

};


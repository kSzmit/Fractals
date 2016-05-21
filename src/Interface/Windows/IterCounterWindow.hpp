#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class IterCounterWindow
{
	sfg::Window::Ptr m_window;
	sfg::Box::Ptr m_box;
	sfg::Label::Ptr m_labelIterNum;

public:
	IterCounterWindow();

	void setIter(int iter);

	void show(bool show);

	sfg::Window::Ptr getWindow();
};


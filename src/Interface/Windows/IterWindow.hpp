#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

class IterWindow
{
protected:
	sfg::SpinButton::Ptr m_buttonIter;
	sfg::Box::Ptr m_box;
	sfg::Window::Ptr m_window;
	sfg::Label::Ptr m_labelIter;
public:
	IterWindow();

	IterWindow(int min,int max, int step);

	void show(bool show);

	void setIter(int iter);

	int getIter();

	sfg::Window::Ptr getWindow();
};


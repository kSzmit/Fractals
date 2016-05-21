#pragma once
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>


class TerrainWindow
{
	sfg::Box::Ptr m_box;
	sfg::Window::Ptr m_window;
	sfg::Button::Ptr m_generateButton;
	bool m_generate;
public:
	TerrainWindow();

	void show(bool show);

	void generateButtonClick(TerrainWindow* window);

	void setGenerate(bool generate);

	bool checkGenerate();

	sfg::Window::Ptr getWindow();
};


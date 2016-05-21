#pragma once
#include "IterWindow.hpp"
#include <iomanip>

class Interface;

class IterWindowMandelbrot :
	public IterWindow
{
protected:
	sfg::Label::Ptr m_labelX;
	sfg::Label::Ptr m_labelY;
	sfg::Label::Ptr m_labelZoomPower;
public:
	IterWindowMandelbrot();

	IterWindowMandelbrot(int min, int max, int step, Interface* interface);

	void update(long double x, long double y, int zoomPower);

	std::string convertLDtoStr(long double longDouble);
};

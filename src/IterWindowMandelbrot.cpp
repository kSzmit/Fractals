#include "IterWindowMandelbrot.hpp"
#include "Interface.hpp"


IterWindowMandelbrot::IterWindowMandelbrot()
{
}

IterWindowMandelbrot::IterWindowMandelbrot(int min, int max, int step, Interface* interface){
	m_window = sfg::Window::Create();
	m_window->SetTitle("Ustawienia");
	m_window->SetStyle(2);
	m_window->SetRequisition(sf::Vector2f(600, 30));

	m_box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 20.f);

	m_labelIter = sfg::Label::Create("Ile iteracji: ");
	m_buttonIter = sfg::SpinButton::Create(min, max, step);
	m_buttonIter->SetRequisition(sf::Vector2f(60.f, 0.f));
	m_buttonIter->SetDigits(0);

	m_labelX = sfg::Label::Create("X: ");
	m_labelX->SetRequisition(sf::Vector2f(180, 0));
	m_labelY = sfg::Label::Create("Y: ");
	m_labelY->SetRequisition(sf::Vector2f(180, 0));
	m_labelZoomPower = sfg::Label::Create("Przyblizenie: ");

	m_box->Pack(m_labelIter);
	m_box->Pack(m_buttonIter);
	m_box->Pack(m_labelX);
	m_box->Pack(m_labelY);
	m_box->Pack(m_labelZoomPower);
	m_window->Add(m_box);

	m_window->SetPosition(sf::Vector2f(0, 200));

	m_window->SetPosition(sf::Vector2f(0, interface->getInterfaceWindow().getSize().y - m_window->GetRequisition().y));
	m_window->Show(false);
}

void IterWindowMandelbrot::update(long double x, long double y, int zoomPower){
	m_labelX->SetText("X: " + convertLDtoStr(x));
	m_labelY->SetText("Y: " + convertLDtoStr(y));
	m_labelZoomPower->SetText("Przyblizenie: " + std::to_string(zoomPower));
}

std::string IterWindowMandelbrot::convertLDtoStr(long double longDouble){
	std::string convert(long double longDouble);
	std::stringstream stream;
	stream << std::setprecision(20)<< longDouble;
	return stream.str();
}
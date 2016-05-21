#include "JuliaIterWindow.hpp"
#include "../Interface.hpp"


JuliaIterWindow::JuliaIterWindow()
{
}

JuliaIterWindow::JuliaIterWindow(int min, int max, int step, Interface* interface){
	m_window = sfg::Window::Create();
	m_window->SetTitle("Ustawienia");
	m_window->SetStyle(2);
	m_window->SetRequisition(sf::Vector2f(1000, 30));

	m_box = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 20.f);

	m_labelIter = sfg::Label::Create("Ile iteracji: ");
	m_buttonIter = sfg::SpinButton::Create(min, max, step);
	m_buttonIter->SetDigits(0);

	m_buttonCx = sfg::SpinButton::Create(-2.f, 2.f, 0.001f);
	m_buttonCy = sfg::SpinButton::Create(-2.f, 2.f, 0.001f);
	m_buttonIter = sfg::SpinButton::Create(min, max, step);
	m_buttonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_buttonCx->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_buttonCy->SetRequisition(sf::Vector2f(80.f, 0.f));

	m_buttonIter->SetDigits(0);
	m_buttonCx->SetDigits(3);
	m_buttonCy->SetDigits(3);

	m_buttonCx->SetValue(-0.75f);
	m_buttonCy->SetValue(0.11f);

	m_labelIter = sfg::Label::Create("Ile iteracji");
	m_labelCx = sfg::Label::Create("wartosc Cx");
	m_labelCy = sfg::Label::Create("wartosc Cy");

	m_labelX = sfg::Label::Create("X: ");
	m_labelX->SetRequisition(sf::Vector2f(180, 0));
	m_labelY = sfg::Label::Create("Y: ");
	m_labelY->SetRequisition(sf::Vector2f(180, 0));
	m_labelZoomPower = sfg::Label::Create("Przyblizenie: ");

	m_box->Pack(m_labelIter);
	m_box->Pack(m_buttonIter);
	m_box->Pack(m_labelCx);
	m_box->Pack(m_buttonCx);
	m_box->Pack(m_labelCy);
	m_box->Pack(m_buttonCy);
	m_box->Pack(m_labelX);
	m_box->Pack(m_labelY);
	m_box->Pack(m_labelZoomPower);
	m_window->Add(m_box);

	m_window->SetPosition(sf::Vector2f(0, interface->getInterfaceWindow().getSize().y - m_window->GetRequisition().y));
	m_window->Show(false);
}

sf::Vector2f JuliaIterWindow::GetC(){
	return sf::Vector2f(m_buttonCx->GetValue(), m_buttonCy->GetValue());
}
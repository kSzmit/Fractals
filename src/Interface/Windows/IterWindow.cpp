#include "IterWindow.hpp"

IterWindow::IterWindow(){
}

IterWindow::IterWindow(int min, int max, int step){
	m_window = sfg::Window::Create();
	m_window->SetTitle("Ustawienia");
	m_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_labelIter = sfg::Label::Create("Iteracja");
	m_buttonIter = sfg::SpinButton::Create(min, max, step);
	m_buttonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_buttonIter->SetDigits(0);

	m_box->Pack(m_labelIter);
	m_box->Pack(m_buttonIter);
	m_window->Add(m_box);

	m_window->SetPosition(sf::Vector2f(0, 200));
	m_window->Show(false);
}


void IterWindow::show(bool show){
	m_window->Show(show);
}

int IterWindow::getIter(){
	return m_buttonIter->GetValue();
}

void IterWindow::setIter(int iter){
	m_buttonIter->SetValue(iter);
}

sfg::Window::Ptr IterWindow::getWindow(){
	return m_window;
}
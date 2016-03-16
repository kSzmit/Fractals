#include "IterCounterWindow.hpp"


IterCounterWindow::IterCounterWindow(){
	m_window = sfg::Window::Create();
	m_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_labelIterNum = sfg::Label::Create("Iteracja: 0");

	m_box->Pack(m_labelIterNum);
	m_window->Add(m_box);

	m_window->SetPosition(sf::Vector2f(0, 200));

	m_window->Show(false);
	m_window->SetStyle(2);
}

void IterCounterWindow::setIter(int iter){
	m_labelIterNum->SetText("Iteracja: " + std::to_string(iter));
}

void IterCounterWindow::show(bool show){
	m_window->Show(show);
}

sfg::Window::Ptr IterCounterWindow::getWindow(){
	return m_window;
}
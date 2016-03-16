#include "SwitchWindow.hpp"
#include "Interface.hpp"

SwitchWindow::SwitchWindow(){

}

SwitchWindow::SwitchWindow(Interface* interface){
	m_windowFractal = sfg::Window::Create(2);
	m_boxFractal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 10.f);

	m_buttonKoch = sfg::Button::Create("Gwiazdka Kocha");
	m_buttonCarpet = sfg::Button::Create("Dywan Sierpinskiego");
	m_buttonJuli = sfg::Button::Create("Zbior Julii");
	m_buttonFern = sfg::Button::Create("Paproc Barnsleya");
	m_buttonMandel = sfg::Button::Create("Zbior Mandelbrota");
	m_buttonKantor = sfg::Button::Create("Zbior Cantora");
	m_buttonTriangle = sfg::Button::Create("Trojkat Sierpinskiego");

	m_boxFractal->Pack(m_buttonKoch);
	m_boxFractal->Pack(m_buttonCarpet);
	m_boxFractal->Pack(m_buttonJuli);
	m_boxFractal->Pack(m_buttonFern);
	m_boxFractal->Pack(m_buttonMandel);
	m_boxFractal->Pack(m_buttonKantor);
	m_boxFractal->Pack(m_buttonTriangle);

	m_buttonKoch->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kKoch, interface));
	m_buttonCarpet->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kSierpinskiCarpet, interface));
	m_buttonJuli->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kJuli, interface));
	m_buttonFern->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kFern, interface));
	m_buttonMandel->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kMandel, interface));
	m_buttonKantor->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kCantor, interface));
	m_buttonTriangle->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&SwitchWindow::buttonSwitchClick, this, kTriangle, interface));

	m_windowFractal->Add(m_boxFractal);
}

void SwitchWindow::buttonSwitchClick(int switchTo, Interface* interface){
	interface->showHideWindows(switchTo);
}

sfg::Window::Ptr SwitchWindow::getWindow(){
	return m_windowFractal;
}

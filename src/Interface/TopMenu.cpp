#include "TopMenu.hpp"
#include "Interface.hpp"

TopMenu::TopMenu(){

}

TopMenu::TopMenu(Interface* interface){
	m_windowFractal = sfg::Window::Create(2);
	m_boxFractal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 10.f);

	m_buttonKoch = sfg::Button::Create("Gwiazdka Kocha");
	m_buttonCarpet = sfg::Button::Create("Dywan Sierpinskiego");
	m_buttonJuli = sfg::Button::Create("Zbior Julii");
	m_buttonFern = sfg::Button::Create("Paproc Barnsleya");
	m_buttonMandel = sfg::Button::Create("Zbior Mandelbrota");
	m_buttonKantor = sfg::Button::Create("Zbior Cantora");
	m_buttonTriangle = sfg::Button::Create("Trojkat Sierpinskiego");
	m_buttonTexture = sfg::Button::Create("Tekstura terenu");

	m_buttonScreenshot = sfg::Button::Create("Zrzut ekranu");
	sfg::Label::Ptr empty = sfg::Label::Create("												");

	m_boxFractal->Pack(m_buttonKoch);
	m_boxFractal->Pack(m_buttonCarpet);
	m_boxFractal->Pack(m_buttonJuli);
	m_boxFractal->Pack(m_buttonFern);
	m_boxFractal->Pack(m_buttonMandel);
	m_boxFractal->Pack(m_buttonKantor);
	m_boxFractal->Pack(m_buttonTriangle);
	m_boxFractal->Pack(m_buttonTexture);
	m_boxFractal->Pack(empty);
	m_boxFractal->Pack(m_buttonScreenshot);


	m_buttonKoch->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kKoch, interface));
	m_buttonCarpet->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kSierpinskiCarpet, interface));
	m_buttonJuli->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kJuli, interface));
	m_buttonFern->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kFern, interface));
	m_buttonMandel->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kMandel, interface));
	m_buttonKantor->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kCantor, interface));
	m_buttonTriangle->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kTriangle, interface));
	m_buttonTexture->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonSwitchClick, this, kTerrain, interface));

	m_buttonScreenshot->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TopMenu::buttonScreenshotClick, this, interface));

	m_windowFractal->Add(m_boxFractal);
	m_windowFractal->SetRequisition(sf::Vector2f(interface->getInterfaceWindow().getSize().x, 0.f));
}

void TopMenu::buttonSwitchClick(int switchTo, Interface* interface){
	interface->showHideWindows(switchTo);
}

void TopMenu::buttonScreenshotClick(Interface* interface){
	sf::Image currentImageOnWindow = interface->getInterfaceWindow().capture();
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream stream;
	stream << std::put_time(&tm, "%Y-%m-%d %H.%M.%S");


	std::string fileName = "Screenshot " + stream.str() + ".png";
	currentImageOnWindow.saveToFile(fileName);
}

sfg::Window::Ptr TopMenu::getWindow(){
	return m_windowFractal;
}
